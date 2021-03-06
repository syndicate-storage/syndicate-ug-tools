/*
   Copyright 2015 The Trustees of Princeton University

   Licensed under the Apache License, Version 2.0 (the "License" );
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/**
 * @file syndicate-ls.cpp
 * @brief Contains main() function (i.e. entry point) for the syndicate-ls tool
 *
 * @see syndicate-ls.h,
 * @ref syndicate-ls
 *
 * @author Jude Nelson
 */

#include "syndicate-ls.h"

/**
 * @brief syndicate-ls entry point
 *
 */
int main( int argc, char** argv ) {
   
   int rc = 0;
   struct UG_state* ug = NULL;
   struct SG_gateway* gateway = NULL;
   UG_handle_t* dirh = NULL;
   struct md_entry** dirents = NULL;
   char* path = NULL;
   int path_optind = 0;
   struct tool_opts opts;
  
   uint64_t* times = NULL; 
   struct timespec ts_begin;
   struct timespec ts_end;
   
   memset( &opts, 0, sizeof(tool_opts) );
   
   argc = parse_args( argc, argv, &opts );
   if( argc < 0 ) {
      
      usage( argv[0], "dir [dir...]" );
      md_common_usage();
      exit(1);
   }
   
   // setup...
   ug = UG_init( argc, argv );
   if( ug == NULL ) {
      
      SG_error("%s", "UG_init failed\n" );
      exit(1);
   }
   
   gateway = UG_state_gateway( ug );
   
   // get the directory path 
   path_optind = SG_gateway_first_arg_optind( gateway );
   if( path_optind == argc ) {
      
      usage( argv[0], "dir [dir...]" );
      md_common_usage();
      UG_shutdown( ug );
      exit(1);
   }
   
   if( opts.benchmark ) {
      times = SG_CALLOC( uint64_t, argc - path_optind + 1 );
      if( times == NULL ) {
          UG_shutdown( ug );
          SG_error("%s", "Out of memory\n");
          exit(1);
      }
   }

   for( int i = path_optind; i < argc; i++ ) {
            
        path = argv[ i ];
        struct md_entry dirent;

        // load up...
        rc = UG_stat_raw( ug, path, &dirent );
        if( rc != 0 ) {
            
            fprintf(stderr, "Failed to stat '%s': %s\n", path, strerror( abs(rc) ) );
            continue;
        }

        if( dirent.type == MD_ENTRY_FILE ) {
            
            // regular file
            print_entry( &dirent );
            md_entry_free( &dirent );
        }
        else {

            // directory 
            md_entry_free( &dirent );

            clock_gettime(CLOCK_MONOTONIC, &ts_begin);

            dirh = UG_opendir( ug, path, &rc );
            if( dirh == NULL ) {
            
                fprintf(stderr, "Failed to open directory '%s': %s\n", path, strerror( abs(rc) ) );
                
                UG_shutdown( ug );
                exit(1);
            }
            
            while( true ) {
                
                rc = UG_readdir( ug, &dirents, 1, dirh );
                if( rc != 0 ) {
                    
                    fprintf(stderr, "Failed to read directory '%s': %s\n", path, strerror( abs(rc) ) );
                    
                    rc = UG_closedir( ug, dirh );
                    if( rc != 0 ) {
                        
                        fprintf(stderr, "Failed to close directory '%s': %s\n", path, strerror( abs(rc) ) );
                    }
                    
                    UG_shutdown( ug );
                    exit(1);
                }
                
                if( dirents != NULL ) {
                        
                    if( dirents[0] == NULL ) {
                        
                        // EOF 
                        UG_free_dir_listing( dirents );
                        break;
                    }
                    
                    for( unsigned int j = 0; dirents[j] != NULL; j++ ) {
                        
                        print_entry( dirents[j] );
                    }
                    
                    UG_free_dir_listing( dirents );
                    dirents = NULL;
                }
                else {
                    
                    // no data
                    break;
                }
            }
            
            rc = UG_closedir( ug, dirh );
            if( rc != 0 ) {
                
                fprintf(stderr, "Failed to close directory '%s': %s\n", path, strerror( abs(rc) ) );
                
                UG_shutdown( ug );
                exit(1);
            }

            clock_gettime(CLOCK_MONOTONIC, &ts_end);

            // record 
            if( times != NULL ) {
               times[i - path_optind] = md_timespec_diff( &ts_end, &ts_begin );
            }
        }
   }

   if( times != NULL ) {
    
      printf("@@@@@");
      for( int i = path_optind; i < argc - 1; i++ ) {
         printf("%" PRIu64 ",", times[i - path_optind] );
      }
      printf("%" PRIu64 "@@@@@\n", times[argc - 1 - path_optind] );

      SG_safe_free( times );
   }

   UG_shutdown( ug );
   exit(0);
}

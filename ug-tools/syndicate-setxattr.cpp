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
 * @file syndicate-setxattr.cpp
 * @brief Contains main() function (i.e. entry point) for the syndicate-setxattr tool
 *
 * @see syndicate-setxattr.h,
 * @ref syndicate-setxattr
 *
 * @author Jude Nelson
 */

#include "syndicate-setxattr.h"

/**
 * @brief syndicate-setxattr entry point
 *
 */
int main( int argc, char** argv ) {
   
   int rc = 0;
   struct UG_state* ug = NULL;
   struct SG_gateway* gateway = NULL;
   char* path = NULL;
   char* xattr_name = NULL;
   char* xattr_value = NULL;
   int path_optind = 0;
   struct tool_opts opts;
  
   uint64_t* times = NULL; 
   struct timespec ts_begin;
   struct timespec ts_end;
   
   memset( &opts, 0, sizeof(tool_opts) );
   
   argc = parse_args( argc, argv, &opts );
   if( argc < 0 ) {
      
      usage( argv[0], "path xattr value [xattr value...]" );
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
   
   // get the path 
   path_optind = SG_gateway_first_arg_optind( gateway );
   if( path_optind + 2 >= argc || (path_optind) % 2 == 0 ) {
     
      usage( argv[0], "path xattr value [xattr value...]" );
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

   path = argv[path_optind];
   for( int i = path_optind + 1; i < argc; i+=2 ) {
            
        xattr_name = argv[ i ];
        xattr_value = argv[i+1];

        // load up...
        clock_gettime( CLOCK_MONOTONIC, &ts_begin );

        rc = UG_setxattr( ug, path, xattr_name, xattr_value, strlen(xattr_value), 0 );
        if( rc < 0 ) {
           fprintf(stderr, "Failed to setxattr '%s' '%s' = '%s': %s\n", path, xattr_name, xattr_value, strerror(abs(rc)) );
           rc = 1;
           break;
        }
        else {
           rc = 0;
        }

        clock_gettime( CLOCK_MONOTONIC, &ts_end );

        if( times != NULL ) {
            times[i - path_optind] = md_timespec_diff( &ts_end, &ts_begin );
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
   exit(rc);
}

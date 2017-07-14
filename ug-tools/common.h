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
 * @file common.h
 * @author Jude Nelson
 * @date 9 Mar 2016
 *
 * @brief common header file
 *
 * @author Jude Nelson
 *
 * @see common.cpp
 */

#ifndef _SYNDICATE_COMMON_H_
#define _SYNDICATE_COMMON_H_

#include <libsyndicate-ug/client.h>
#include <libsyndicate-ug/core.h>

/**
 * @brief Available options
 *
 * Options are to enable or disable benchmarking
 */
struct tool_opts {
    
    bool benchmark; ///< if true, gather benchmark stats
};

/**
 * @brief 
 * Print a single entry
 *
 * @param[in] dirent Entry
 * @return 0
 */
int print_entry( struct md_entry* dirent );

/**
 * @brief 
 * Parse args for common tool options
 *
 * @param[in] argc Number of arguments
 * @param[in] argv Arguments
 * @param[in] opts Options (benchmarking)
 * @return The new argc
 */
int parse_args( int argc, char** argv, struct tool_opts* opts );

/**
 * @brief 
 * Print formatted usage
 *
 * @param[in] progname Command name
 * @param[in] args Arguments specific to the command
 * @return 0
 */
int usage( char const* progname, char const* args );

#endif

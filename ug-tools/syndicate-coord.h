/*
   Copyright 2016 The Trustees of Princeton University

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

// file documentation
/**
 * @file syndicate-coord.h
 * @author Jude Nelson
 * @date 9 Mar 2016
 *
 * @brief syndicate-coord header file
 *
 * @author Jude Nelson
 *
 * @see syndicate-coord.cpp,
 * @ref syndicate-coord
 */

// man page and related pages documentation
/**
 * @page syndicate-coord
 * @brief Coordinate multiple user writes to a file
 *
 * @section synopsis SYNOPSIS
 * syndicate-coord -u USERNAME -v VOLUME_NAME -g GATEWAY_NAME [OPTION]... /FILE...
 *
 * @section description DESCRIPTION
 * Coordinate multiple writes to the same file across a group of users.  Useful for testing or when users are separated by one or more NATs.  One user can run a syndicate-coord instance that is publicly-routable by all users, such that the owner of the syndicate-coord process is the coordinator for the shared write files, thus allowing everyone to write even if not everyone is visible to each other.
 *
 * @copydetails md_common_usage()
 *
 * @section example EXAMPLES
 * syndicate-coord -u syndicate@example.com -v syndicate_volume -g syndicate_gateway -d2 -f -c "syndicate.conf" /file1
 *
 * @section author AUTHOR
 * Written by Jude Nelson
 *
 * @section bugs REPORTING BUGS
 * Online help is available at http://www.syndicate-storage.org
 *
 * @section copyright COPYRIGHT
 *
 * @copydetails md_print_copywrite()
 *
 * @copydetails md_print_license()
 *
 * @section see SEE ALSO
 * syndicate-coord.cpp(3)
 * syndicate-coord.h(3)
 */

#ifndef _SYNDICATE_COORD_H_
#define _SYNDICATE_COORD_H_

#include <libsyndicate-ug/client.h>
#include <libsyndicate-ug/core.h>

#include "common.h"

#endif

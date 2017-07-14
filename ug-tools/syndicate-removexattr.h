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

// file documentation
/**
 * @file syndicate-removexattr.h
 * @author Jude Nelson
 * @date 9 Mar 2016
 *
 * @brief syndicate-removexattr header file
 *
 * @author Jude Nelson
 *
 * @see syndicate-removexattr.cpp,
 * @ref syndicate-removexattr
 */

// man page and related pages documentation
/**
 * @page syndicate-removexattr
 * @brief Remove an extended attribute
 *
 * @section synopsis SYNOPSIS
 * syndicate-removexattr -u USERNAME -v VOLUME_NAME -g GATEWAY_NAME [OPTION]... /FILE NAMESPACE.ATTRIBUTE
 *
 * @section description DESCRIPTION
 * Removes the extended attribute identified by NAMESPACE.ATTRIBUTE and associated with the given FILE or path
 *
 * @copydetails md_common_usage()
 *
 * @section example EXAMPLES
 * syndicate-removexattr -u syndicate@example.com -v syndicate_volume -g syndicate_gateway -d2 -f -c "syndicate.conf" /file1 user.syndicate_cached_blocks
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
 * syndicate-removexattr.cpp(3)
 * syndicate-removexattr.h(3)
 */

#ifndef _SYNDICATE_STAT_H_
#define _SYNDICATE_STAT_H_

#include <libsyndicate-ug/client.h>
#include <libsyndicate-ug/core.h>

#include "common.h"

#endif

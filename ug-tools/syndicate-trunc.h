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
 * @file syndicate-trunc.h
 * @author Jude Nelson
 * @date 9 Mar 2016
 *
 * @brief syndicate-trunc header file
 *
 * @author Jude Nelson
 *
 * @see syndicate-trunc.cpp,
 * @ref syndicate-trunc
 */

// man page and related pages documentation
/**
 * @page syndicate-trunc
 * @brief Truncate a file
 *
 * @section synopsis SYNOPSIS
 * syndicate-trunc -u USERNAME -v VOLUME_NAME -g GATEWAY_NAME [OPTION]... /FILE SIZE
 *
 * @section description DESCRIPTION
 * Truncate a file (in bytes)
 *
 * @copydetails md_common_usage()
 *
 * @section example EXAMPLES
 * syndicate-trunc -u syndicate@example.com -v syndicate_volume -g syndicate_gateway -d2 -f -c "syndicate.conf" /file1 1000
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
 * syndicate-trunc.cpp(3)
 * syndicate-trunc.h(3)
 */


#ifndef _SYNDICATE_TRUNC_H_
#define _SYNDICATE_TRUNC_H_

#include <libsyndicate-ug/client.h>
#include <libsyndicate-ug/core.h>

#include "common.h"

#endif

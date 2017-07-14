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
 * @file syndicate-unlink.h
 * @author Jude Nelson
 * @date 9 Mar 2016
 *
 * @brief syndicate-unlink header file
 *
 * @author Jude Nelson
 *
 * @see syndicate-unlink.cpp,
 * @ref syndicate-unlink
 */

// man page and related pages documentation
/**
 * @page syndicate-unlink
 * @brief Remove the specified file
 *
 * @section synopsis SYNOPSIS
 * syndicate-unlink -u USERNAME -v VOLUME_NAME -g GATEWAY_NAME [OPTION]... /FILE...
 *
 * @section description DESCRIPTION
 * Remove the specified FILE
 *
 * @copydetails md_common_usage()
 *
 * @section example EXAMPLES
 * syndicate-unlink -u syndicate@example.com -v syndicate_volume -g syndicate_gateway -d2 -f -c "syndicate.conf" /file1
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
 * syndicate-unlink.cpp(3)
 * syndicate-unlink.h(3)
 */


#ifndef _SYNDICATE_UNLINK_H_
#define _SYNDICATE_UNLINK_H_

#include <libsyndicate-ug/client.h>
#include <libsyndicate-ug/core.h>

#include "common.h"

#endif

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
 * @file syndicate-vacuum.h
 * @author Jude Nelson
 * @date 9 Mar 2016
 *
 * @brief syndicate-vacuum header file
 *
 * @author Jude Nelson
 *
 * @see syndicate-vacuum.cpp,
 * @ref syndicate-vacuum
 */

// man page and related pages documentation
/**
 * @page syndicate-vacuum
 * @brief Remove unlinked blocks and manifests
 *
 * @section synopsis SYNOPSIS
 * syndicate-vacuum -u USERNAME -v VOLUME_NAME -g GATEWAY_NAME [OPTION]... /FILE
 *
 * @section description DESCRIPTION
 * An administrative tool that removes unlinked manifests and blocks from running RG's that are associated with the FILE provided.\n\n  This tool is useful if a user's UG were to crash prior to cleaning (or a "vacuum" of) manifests and blocks associated with a deleted/unlinked file, and if the user also does not restart a gateway, which would normally also complete the vacuum process.
 *
 * @copydetails md_common_usage()
 *
 * @section example EXAMPLES
 * syndicate-vacuum -u syndicate@example.com -v syndicate_volume -g syndicate_gateway -d2 -f -c "syndicate.conf" /file1
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
 * syndicate-vacuum.cpp(3)
 * syndicate-vacuum.h(3)
 */

#ifndef _SYNDICATE_VACUUM_H_
#define _SYNDICATE_VACUUM_H_

#include <libsyndicate-ug/client.h>
#include <libsyndicate-ug/core.h>

#include "common.h"

#endif

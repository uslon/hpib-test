/*
 * (C) Copyright University of New Hampshire, 2006
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with 
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple 
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 * Author(s):
 *     Meghana Srivatsavai <mjn77@unh.edu>
*/

#include "InvalidResource.h"

using namespace ns_saHpiFumiSpecInfoGet;

/*****************************************************************************
 * Constructor
 *****************************************************************************/

InvalidResource::InvalidResource(char *line) : HpiInvalidResourceTestCase(line) {
}

/*****************************************************************************
 * Run the Test.
 *****************************************************************************/

HpiTestStatus InvalidResource::runSessionTest(SaHpiSessionIdT sessionId) {
    HpiTestStatus status;
    SaHpiFumiSpecInfoT info;

    SaErrorT error = saHpiFumiSpecInfoGet(sessionId,
                                          getInvalidResourceId(),getValidFumiNum() ,&info);
    if (error == SA_ERR_HPI_INVALID_RESOURCE) {
        status.assertPass();
    } else {
        status.assertFailure(TRACE, FUMI_SPEC_INFO_GET, 
                             SA_ERR_HPI_INVALID_RESOURCE, error);
    } 

    return status;
}


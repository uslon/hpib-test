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
 * 
 * Changes:
 * 09/12/28 Lars Wetzel <larswetzel@users.sourceforge.net>
 * 	        Integrate the test case into hpitest 
 */

#include "FumiNotPresent.h"

using namespace ns_saHpiFumiAutoRollbackDisableSet;

/*****************************************************************************
 * Constructor
 *****************************************************************************/

FumiNotPresent::FumiNotPresent(char *line) : HpiResourceTestCase(line) {
}

/*****************************************************************************
 * Return the name of the test case.
 *****************************************************************************/

const char *FumiNotPresent::getName() {
    return "FumiNotPresent";
}

/*****************************************************************************
 * Return the description of the test case.
 *****************************************************************************/

const char *FumiNotPresent::getDescription() {
    return "The fumi is not present.";
}

/*****************************************************************************
 * Return the precondition of the test case.
 *****************************************************************************/

const char *FumiNotPresent::getPrecondition() {
    return "Requires a resource that supports a fumi.";
}

/*****************************************************************************
 * Return the expected error code.
 *****************************************************************************/

SaErrorT FumiNotPresent::getExpectedReturn() {
    return SA_ERR_HPI_NOT_PRESENT;
}

/*****************************************************************************
 * Run the test.
 *****************************************************************************/

HpiTestStatus FumiNotPresent::runResourceTest(SaHpiSessionIdT sessionId,
                                              SaHpiRptEntryT *rptEntry) {
    HpiTestStatus status;

    if (!hasFumiCapability(rptEntry)) {
        status.assertNotSupport();
    } else {
        SaErrorT error = saHpiFumiAutoRollbackDisableSet(sessionId,
                                                         rptEntry->ResourceId, 
                                                         getInvalidFumiNum(),
                                                         SAHPI_FALSE);
                                                
        if (error == SA_ERR_HPI_NOT_PRESENT) {
            status.assertPass();
        } else {
            status.assertFailure(TRACE, FUMI_AUTO_ROLLBACK_DISABLE_SET,
                                 SA_ERR_HPI_NOT_PRESENT, error);
        }
    }

    return status;
}

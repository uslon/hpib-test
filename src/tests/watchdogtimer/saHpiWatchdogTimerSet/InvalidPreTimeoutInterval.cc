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
 *     Donald A. Barre <dbarre@unh.edu>
 */

#include "InvalidPreTimeoutInterval.h"
#include "WatchdogHelper.h"

using namespace ns_saHpiWatchdogTimerSet;

/*****************************************************************************
 * Constructor
 *****************************************************************************/

InvalidPreTimeoutInterval::InvalidPreTimeoutInterval(char *line)
: WatchdogTestCase(line, false) {
}

/*****************************************************************************
 * Return the name of the test case.
 *****************************************************************************/

const char *InvalidPreTimeoutInterval::getName() {
    return "InvalidPreTimeoutInterval";
}

/*****************************************************************************
 * Return the description of the test case.
 *****************************************************************************/

const char *InvalidPreTimeoutInterval::getDescription() {
    return "The value of <i>Watchdog->PreTimeoutInterval</i> is greater\n"
           "than the value of <i>Watchdog->InitialCount</i>.";
}

/*****************************************************************************
 * Return the precondition of the test case.
 *****************************************************************************/

const char *InvalidPreTimeoutInterval::getPrecondition() {
    return "Requires one or more watchdog timers that are not running.";
}

/*****************************************************************************
 * Return the expected error code.
 *****************************************************************************/

SaErrorT InvalidPreTimeoutInterval::getExpectedReturn() {
    return SA_ERR_HPI_INVALID_DATA;
}

/*****************************************************************************
 * Run the test.
 *****************************************************************************/

HpiTestStatus InvalidPreTimeoutInterval::runWatchdogTest(SaHpiSessionIdT sessionId,
                                                         SaHpiRptEntryT *rptEntry,
                                                         SaHpiWatchdogRecT *watchdogRec) {
    HpiTestStatus status;
    SaHpiWatchdogT watchdog;

    WatchdogHelper::fill(&watchdog);
    watchdog.InitialCount = 100;
    watchdog.PreTimeoutInterval = 500;

    SaErrorT error = saHpiWatchdogTimerSet(sessionId, rptEntry->ResourceId, 
                                           watchdogRec->WatchdogNum, &watchdog);
    if (error == SA_ERR_HPI_INVALID_DATA) {
        status.assertPass();
    } else {
        status.assertFailure(TRACE, WATCHDOG_TIMER_SET,
                             SA_ERR_HPI_INVALID_DATA, error);
    }

    return status;
}

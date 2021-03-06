/*      
 * (C) Copyright Emerson Corp. 2009
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  This
 * file and program are licensed under a BSD style license.  See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 * You should have received a copy of the GNU General Public License along with 
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple 
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 *  Authors:
 *  Lars Wetzel <Lars.Wetzel.com>
 */

#ifndef __FAILEDREMOVE_H__
#define __FAILEDREMOVE_H__

#include "SafTest.h"
#include "HpiSessionTestCase.h"
#include "EventHandler.h"
#include "ResourcesList.h"
#include "IdList.h"

/*****************************************************************************
 * Constants
 *****************************************************************************/
// Times in sec 
// how long the test case waits for events after calling saHpiFailedRemove
#ifndef MAX_EVENTWAITTIME
#define MAX_EVENTWAITTIME 10
#endif
// how long the test case waits until the removal of the resources is checked
#ifndef MAX_RPTWAITTIME
#define MAX_RPTWAITTIME 1
#endif

/*****************************************************************************
 * No FRU Capability Test Case
 *****************************************************************************/

namespace ns_saHpiResourceFailedRemove
{
    class FailedRemove : public HpiSessionTestCase, public EventHandler
    {
    private:
        ResourcesList *origRPT;
        IdList *failedList;
        IdList *rootList;
        IdList *foundFailedResources;
        
        void findAllRootEntities();
        HpiTestStatus testFailedResources(SaHpiSessionIdT sessionId);	
        HpiTestStatus pollEvents(SaHpiSessionIdT sessionId, long timeout);
        HpiTestStatus handleEvent(SaHpiSessionIdT sessionId, SaHpiEventT *event);
        bool isEventProcessingDone();
        	
    public:
        FailedRemove(char *line);

        HpiTestStatus runSessionTest(SaHpiSessionIdT sessionId);

        const char *getName();

        const char *getDescription();

        const char *getPrecondition();

        SaErrorT getExpectedReturn();
    };
}

#endif

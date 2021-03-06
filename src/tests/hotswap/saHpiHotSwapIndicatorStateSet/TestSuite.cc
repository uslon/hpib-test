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

#include "TestSuite.h"
#include "SetState.h"
#include "NoHotSwapCapability.h"
#include "NoIndicatorCapability.h"
#include "InvalidState.h"
#include "InvalidResource.h"
#include "InvalidSession.h"

using namespace ns_saHpiHotSwapIndicatorStateSet;

/*****************************************************************************
 * Constructor
 *****************************************************************************/

TestSuite::TestSuite() {
    /*add(new SetState("P150-16:P150-16;P150-23:P150-24"));
    add(new NoHotSwapCapability("P150-18:P150-18"));
    add(new NoIndicatorCapability("P150-19:P150-20"));
    add(new InvalidState("P150-21:P150-21"));
    add(new InvalidResource("P29-40:P29-42"));
    add(new InvalidSession("P29-43:P29-45"));
*/

    add(new SetState("B.02|P205-16:P205-16;P205-23:P205-24"));
    add(new NoHotSwapCapability("B.02|P205-18:P205-18"));
    add(new NoIndicatorCapability("B.02|P205-19:P205-20"));
    add(new InvalidState("B.02|P205-21:P205-21"));
    add(new InvalidResource("B.02|P36-15:P36-16"));
    add(new InvalidSession("B.02|P36-17:P36-18"));

}

/*****************************************************************************
 * Return the name of the test suite.
 *****************************************************************************/

const char *TestSuite::getName() {
    return "saHpiHotSwapIndicatorStateSet";
}

/*****************************************************************************
 * Return the description of the test suite.
 *****************************************************************************/

const char *TestSuite::getDescription() {
    return "Conformance test suite for saHpiHotSwapIndicatorStateSet().";
}

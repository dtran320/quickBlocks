#pragma once
/*-------------------------------------------------------------------------------------------
 * qblocks - fast, easily-accessible, fully-decentralized data from blockchains
 * copyright (c) 2018 Great Hill Corporation (http://greathill.com)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include <vector>
#include <map>
#include "logentry.h"

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
class COnWithdrawAndDistributeEvent : public CLogEntry {
public:
    address_t playerAddress;
    string_q playerName;
    biguint_t ethOut;
    biguint_t compressedData;
    biguint_t compressedIDs;
    address_t winnerAddr;
    string_q winnerName;
    biguint_t amountWon;
    biguint_t newPot;
    biguint_t P3DAmount;
    biguint_t genAmount;

public:
    COnWithdrawAndDistributeEvent(void);
    COnWithdrawAndDistributeEvent(const COnWithdrawAndDistributeEvent& on);
    virtual ~COnWithdrawAndDistributeEvent(void);
    COnWithdrawAndDistributeEvent& operator=(const COnWithdrawAndDistributeEvent& on);

    DECLARE_NODE(COnWithdrawAndDistributeEvent);

    // EXISTING_CODE
    // EXISTING_CODE
    bool operator==(const COnWithdrawAndDistributeEvent& item) const;
    bool operator!=(const COnWithdrawAndDistributeEvent& item) const { return !operator==(item); }
    friend bool operator<(const COnWithdrawAndDistributeEvent& v1, const COnWithdrawAndDistributeEvent& v2);
    friend ostream& operator<<(ostream& os, const COnWithdrawAndDistributeEvent& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const COnWithdrawAndDistributeEvent& on);
    bool readBackLevel(CArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline COnWithdrawAndDistributeEvent::COnWithdrawAndDistributeEvent(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline COnWithdrawAndDistributeEvent::COnWithdrawAndDistributeEvent(const COnWithdrawAndDistributeEvent& on) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(on);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline COnWithdrawAndDistributeEvent::~COnWithdrawAndDistributeEvent(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void COnWithdrawAndDistributeEvent::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void COnWithdrawAndDistributeEvent::initialize(void) {
    CLogEntry::initialize();

    playerAddress = "";
    playerName = "";
    ethOut = 0;
    compressedData = 0;
    compressedIDs = 0;
    winnerAddr = "";
    winnerName = "";
    amountWon = 0;
    newPot = 0;
    P3DAmount = 0;
    genAmount = 0;

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void COnWithdrawAndDistributeEvent::duplicate(const COnWithdrawAndDistributeEvent& on) {
    clear();
    CLogEntry::duplicate(on);

    playerAddress = on.playerAddress;
    playerName = on.playerName;
    ethOut = on.ethOut;
    compressedData = on.compressedData;
    compressedIDs = on.compressedIDs;
    winnerAddr = on.winnerAddr;
    winnerName = on.winnerName;
    amountWon = on.amountWon;
    newPot = on.newPot;
    P3DAmount = on.P3DAmount;
    genAmount = on.genAmount;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline COnWithdrawAndDistributeEvent& COnWithdrawAndDistributeEvent::operator=(const COnWithdrawAndDistributeEvent& on) {
    duplicate(on);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool COnWithdrawAndDistributeEvent::operator==(const COnWithdrawAndDistributeEvent& item) const {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default equal operator in class definition, assume none are equal (so find fails)
    return false;
}

//-------------------------------------------------------------------------
inline bool operator<(const COnWithdrawAndDistributeEvent& v1, const COnWithdrawAndDistributeEvent& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted, preserve ordering
    return true;
}

//---------------------------------------------------------------------------
typedef vector<COnWithdrawAndDistributeEvent> COnWithdrawAndDistributeEventArray;
extern CArchive& operator>>(CArchive& archive, COnWithdrawAndDistributeEventArray& array);
extern CArchive& operator<<(CArchive& archive, const COnWithdrawAndDistributeEventArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE


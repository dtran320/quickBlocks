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
class COwnerRemovalEvent : public CLogEntry {
public:
    address_t owner;

public:
    COwnerRemovalEvent(void);
    COwnerRemovalEvent(const COwnerRemovalEvent& ow);
    virtual ~COwnerRemovalEvent(void);
    COwnerRemovalEvent& operator=(const COwnerRemovalEvent& ow);

    DECLARE_NODE(COwnerRemovalEvent);

    // EXISTING_CODE
    // EXISTING_CODE
    bool operator==(const COwnerRemovalEvent& item) const;
    bool operator!=(const COwnerRemovalEvent& item) const { return !operator==(item); }
    friend bool operator<(const COwnerRemovalEvent& v1, const COwnerRemovalEvent& v2);
    friend ostream& operator<<(ostream& os, const COwnerRemovalEvent& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const COwnerRemovalEvent& ow);
    bool readBackLevel(CArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline COwnerRemovalEvent::COwnerRemovalEvent(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline COwnerRemovalEvent::COwnerRemovalEvent(const COwnerRemovalEvent& ow) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(ow);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline COwnerRemovalEvent::~COwnerRemovalEvent(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void COwnerRemovalEvent::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void COwnerRemovalEvent::initialize(void) {
    CLogEntry::initialize();

    owner = "";

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void COwnerRemovalEvent::duplicate(const COwnerRemovalEvent& ow) {
    clear();
    CLogEntry::duplicate(ow);

    owner = ow.owner;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline COwnerRemovalEvent& COwnerRemovalEvent::operator=(const COwnerRemovalEvent& ow) {
    duplicate(ow);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool COwnerRemovalEvent::operator==(const COwnerRemovalEvent& item) const {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default equal operator in class definition, assume none are equal (so find fails)
    return false;
}

//-------------------------------------------------------------------------
inline bool operator<(const COwnerRemovalEvent& v1, const COwnerRemovalEvent& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted, preserve ordering
    return true;
}

//---------------------------------------------------------------------------
typedef vector<COwnerRemovalEvent> COwnerRemovalEventArray;
extern CArchive& operator>>(CArchive& archive, COwnerRemovalEventArray& array);
extern CArchive& operator<<(CArchive& archive, const COwnerRemovalEventArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE


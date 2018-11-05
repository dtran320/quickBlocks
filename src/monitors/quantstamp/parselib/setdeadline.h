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
#include "transaction.h"

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
class CSetDeadline : public CTransaction {
public:
    biguint_t timestamp;

public:
    CSetDeadline(void);
    CSetDeadline(const CSetDeadline& se);
    virtual ~CSetDeadline(void);
    CSetDeadline& operator=(const CSetDeadline& se);

    DECLARE_NODE(CSetDeadline);

    // EXISTING_CODE
    // EXISTING_CODE
    bool operator==(const CSetDeadline& item) const;
    bool operator!=(const CSetDeadline& item) const { return !operator==(item); }
    friend bool operator<(const CSetDeadline& v1, const CSetDeadline& v2);
    friend ostream& operator<<(ostream& os, const CSetDeadline& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const CSetDeadline& se);
    bool readBackLevel(CArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline CSetDeadline::CSetDeadline(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline CSetDeadline::CSetDeadline(const CSetDeadline& se) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(se);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline CSetDeadline::~CSetDeadline(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CSetDeadline::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CSetDeadline::initialize(void) {
    CTransaction::initialize();

    timestamp = 0;

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CSetDeadline::duplicate(const CSetDeadline& se) {
    clear();
    CTransaction::duplicate(se);

    timestamp = se.timestamp;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline CSetDeadline& CSetDeadline::operator=(const CSetDeadline& se) {
    duplicate(se);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool CSetDeadline::operator==(const CSetDeadline& item) const {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default equal operator in class definition, assume none are equal (so find fails)
    return false;
}

//-------------------------------------------------------------------------
inline bool operator<(const CSetDeadline& v1, const CSetDeadline& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted, preserve ordering
    return true;
}

//---------------------------------------------------------------------------
typedef vector<CSetDeadline> CSetDeadlineArray;
extern CArchive& operator>>(CArchive& archive, CSetDeadlineArray& array);
extern CArchive& operator<<(CArchive& archive, const CSetDeadlineArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE


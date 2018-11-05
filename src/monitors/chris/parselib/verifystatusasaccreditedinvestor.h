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
class CVerifyStatusAsAccreditedInvestor : public CTransaction {
public:
    address_t _account;
    string_q _verifyMetaData;

public:
    CVerifyStatusAsAccreditedInvestor(void);
    CVerifyStatusAsAccreditedInvestor(const CVerifyStatusAsAccreditedInvestor& ve);
    virtual ~CVerifyStatusAsAccreditedInvestor(void);
    CVerifyStatusAsAccreditedInvestor& operator=(const CVerifyStatusAsAccreditedInvestor& ve);

    DECLARE_NODE(CVerifyStatusAsAccreditedInvestor);

    // EXISTING_CODE
    // EXISTING_CODE
    bool operator==(const CVerifyStatusAsAccreditedInvestor& item) const;
    bool operator!=(const CVerifyStatusAsAccreditedInvestor& item) const { return !operator==(item); }
    friend bool operator<(const CVerifyStatusAsAccreditedInvestor& v1, const CVerifyStatusAsAccreditedInvestor& v2);
    friend ostream& operator<<(ostream& os, const CVerifyStatusAsAccreditedInvestor& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const CVerifyStatusAsAccreditedInvestor& ve);
    bool readBackLevel(CArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline CVerifyStatusAsAccreditedInvestor::CVerifyStatusAsAccreditedInvestor(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline CVerifyStatusAsAccreditedInvestor::CVerifyStatusAsAccreditedInvestor(const CVerifyStatusAsAccreditedInvestor& ve) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(ve);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline CVerifyStatusAsAccreditedInvestor::~CVerifyStatusAsAccreditedInvestor(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CVerifyStatusAsAccreditedInvestor::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CVerifyStatusAsAccreditedInvestor::initialize(void) {
    CTransaction::initialize();

    _account = "";
    _verifyMetaData = "";

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CVerifyStatusAsAccreditedInvestor::duplicate(const CVerifyStatusAsAccreditedInvestor& ve) {
    clear();
    CTransaction::duplicate(ve);

    _account = ve._account;
    _verifyMetaData = ve._verifyMetaData;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline CVerifyStatusAsAccreditedInvestor& CVerifyStatusAsAccreditedInvestor::operator=(const CVerifyStatusAsAccreditedInvestor& ve) {
    duplicate(ve);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool CVerifyStatusAsAccreditedInvestor::operator==(const CVerifyStatusAsAccreditedInvestor& item) const {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default equal operator in class definition, assume none are equal (so find fails)
    return false;
}

//-------------------------------------------------------------------------
inline bool operator<(const CVerifyStatusAsAccreditedInvestor& v1, const CVerifyStatusAsAccreditedInvestor& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted, preserve ordering
    return true;
}

//---------------------------------------------------------------------------
typedef vector<CVerifyStatusAsAccreditedInvestor> CVerifyStatusAsAccreditedInvestorArray;
extern CArchive& operator>>(CArchive& archive, CVerifyStatusAsAccreditedInvestorArray& array);
extern CArchive& operator<<(CArchive& archive, const CVerifyStatusAsAccreditedInvestorArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE


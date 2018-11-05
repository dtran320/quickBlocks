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
class CSetFiatContractAddress : public CTransaction {
public:
    address_t _address;

public:
    CSetFiatContractAddress(void);
    CSetFiatContractAddress(const CSetFiatContractAddress& se);
    virtual ~CSetFiatContractAddress(void);
    CSetFiatContractAddress& operator=(const CSetFiatContractAddress& se);

    DECLARE_NODE(CSetFiatContractAddress);

    // EXISTING_CODE
    // EXISTING_CODE
    bool operator==(const CSetFiatContractAddress& item) const;
    bool operator!=(const CSetFiatContractAddress& item) const { return !operator==(item); }
    friend bool operator<(const CSetFiatContractAddress& v1, const CSetFiatContractAddress& v2);
    friend ostream& operator<<(ostream& os, const CSetFiatContractAddress& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const CSetFiatContractAddress& se);
    bool readBackLevel(CArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline CSetFiatContractAddress::CSetFiatContractAddress(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline CSetFiatContractAddress::CSetFiatContractAddress(const CSetFiatContractAddress& se) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(se);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline CSetFiatContractAddress::~CSetFiatContractAddress(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CSetFiatContractAddress::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CSetFiatContractAddress::initialize(void) {
    CTransaction::initialize();

    _address = "";

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void CSetFiatContractAddress::duplicate(const CSetFiatContractAddress& se) {
    clear();
    CTransaction::duplicate(se);

    _address = se._address;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline CSetFiatContractAddress& CSetFiatContractAddress::operator=(const CSetFiatContractAddress& se) {
    duplicate(se);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool CSetFiatContractAddress::operator==(const CSetFiatContractAddress& item) const {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default equal operator in class definition, assume none are equal (so find fails)
    return false;
}

//-------------------------------------------------------------------------
inline bool operator<(const CSetFiatContractAddress& v1, const CSetFiatContractAddress& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted, preserve ordering
    return true;
}

//---------------------------------------------------------------------------
typedef vector<CSetFiatContractAddress> CSetFiatContractAddressArray;
extern CArchive& operator>>(CArchive& archive, CSetFiatContractAddressArray& array);
extern CArchive& operator<<(CArchive& archive, const CSetFiatContractAddressArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE


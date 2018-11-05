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
#include <algorithm>
#include "start.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CStart, CTransaction);

//---------------------------------------------------------------------------
static string_q nextStartChunk(const string_q& fieldIn, const void *dataPtr);
static string_q nextStartChunk_custom(const string_q& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void CStart::Format(ostream& ctx, const string_q& fmtIn, void *dataPtr) const {
    if (!m_showing)
        return;

    if (fmtIn.empty()) {
        ctx << toJson();
        return;
    }

    string_q fmt = fmtIn;
    // EXISTING_CODE
    // EXISTING_CODE

    while (!fmt.empty())
        ctx << getNextChunk(fmt, nextStartChunk, this);
}

//---------------------------------------------------------------------------
string_q nextStartChunk(const string_q& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return reinterpret_cast<const CStart *>(dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool CStart::setValueByName(const string_q& fieldName, const string_q& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CTransaction::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CStart::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CStart::Serialize(CArchive& archive) {

    if (archive.isWriting())
        return SerializeC(archive);

    // Always read the base class (it will handle its own backLevels if any, then
    // read this object's back level (if any) or the current version.
    CTransaction::Serialize(archive);
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CStart::SerializeC(CArchive& archive) const {

    // Writing always write the latest version of the data
    CTransaction::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE

    return true;
}

//---------------------------------------------------------------------------
CArchive& operator>>(CArchive& archive, CStartArray& array) {
    uint64_t count;
    archive >> count;
    array.resize(count);
    for (size_t i = 0 ; i < count ; i++) {
        ASSERT(i < array.capacity());
        array.at(i).Serialize(archive);
    }
    return archive;
}

//---------------------------------------------------------------------------
CArchive& operator<<(CArchive& archive, const CStartArray& array) {
    uint64_t count = array.size();
    archive << count;
    for (size_t i = 0 ; i < array.size() ; i++)
        array[i].SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
void CStart::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CTransaction::registerClass();

    size_t fieldNum = 1000;
    ADD_FIELD(CStart, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(CStart, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(CStart, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(CStart, "cname", T_TEXT,  ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CStart, "schema");
    HIDE_FIELD(CStart, "deleted");
    HIDE_FIELD(CStart, "showing");
    HIDE_FIELD(CStart, "cname");

    builtIns.push_back(_biCStart);

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
string_q nextStartChunk_custom(const string_q& fieldIn, const void *dataPtr) {
    const CStart *sta = reinterpret_cast<const CStart *>(dataPtr);
    if (sta) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, sta);
                // EXISTING_CODE
                // EXISTING_CODE
                break;

            default:
                break;
        }
    }

    return "";
}

//---------------------------------------------------------------------------
bool CStart::readBackLevel(CArchive& archive) {

    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
string_q CStart::getValueByName(const string_q& fieldName) const {

    // Give customized code a chance to override first
    string_q ret = nextStartChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // No fields

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CTransaction::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const CStart& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    item.Format(os, "", nullptr);
    os << "\n";
    return os;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE


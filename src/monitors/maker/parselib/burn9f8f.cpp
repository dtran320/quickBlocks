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
#include "burn9f8f.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CBurn9f8f, CTransaction);

//---------------------------------------------------------------------------
static string_q nextBurn9f8fChunk(const string_q& fieldIn, const void *dataPtr);
static string_q nextBurn9f8fChunk_custom(const string_q& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void CBurn9f8f::Format(ostream& ctx, const string_q& fmtIn, void *dataPtr) const {
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
        ctx << getNextChunk(fmt, nextBurn9f8fChunk, this);
}

//---------------------------------------------------------------------------
string_q nextBurn9f8fChunk(const string_q& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return reinterpret_cast<const CBurn9f8f *>(dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool CBurn9f8f::setValueByName(const string_q& fieldName, const string_q& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CTransaction::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case 'g':
            if ( fieldName % "guy" ) { guy = str_2_Addr(fieldValue); return true; }
            break;
        case 'w':
            if ( fieldName % "wad" ) { wad = str_2_Wei(fieldValue); return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CBurn9f8f::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CBurn9f8f::Serialize(CArchive& archive) {

    if (archive.isWriting())
        return SerializeC(archive);

    // Always read the base class (it will handle its own backLevels if any, then
    // read this object's back level (if any) or the current version.
    CTransaction::Serialize(archive);
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    archive >> guy;
    archive >> wad;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CBurn9f8f::SerializeC(CArchive& archive) const {

    // Writing always write the latest version of the data
    CTransaction::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE
    archive << guy;
    archive << wad;

    return true;
}

//---------------------------------------------------------------------------
CArchive& operator>>(CArchive& archive, CBurn9f8fArray& array) {
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
CArchive& operator<<(CArchive& archive, const CBurn9f8fArray& array) {
    uint64_t count = array.size();
    archive << count;
    for (size_t i = 0 ; i < array.size() ; i++)
        array[i].SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
void CBurn9f8f::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CTransaction::registerClass();

    size_t fieldNum = 1000;
    ADD_FIELD(CBurn9f8f, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(CBurn9f8f, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(CBurn9f8f, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(CBurn9f8f, "cname", T_TEXT,  ++fieldNum);
    ADD_FIELD(CBurn9f8f, "guy", T_ADDRESS, ++fieldNum);
    ADD_FIELD(CBurn9f8f, "wad", T_NUMBER, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CBurn9f8f, "schema");
    HIDE_FIELD(CBurn9f8f, "deleted");
    HIDE_FIELD(CBurn9f8f, "showing");
    HIDE_FIELD(CBurn9f8f, "cname");

    builtIns.push_back(_biCBurn9f8f);

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
string_q nextBurn9f8fChunk_custom(const string_q& fieldIn, const void *dataPtr) {
    const CBurn9f8f *bur = reinterpret_cast<const CBurn9f8f *>(dataPtr);
    if (bur) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, bur);
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
bool CBurn9f8f::readBackLevel(CArchive& archive) {

    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
string_q CBurn9f8f::getValueByName(const string_q& fieldName) const {

    // Give customized code a chance to override first
    string_q ret = nextBurn9f8fChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // Return field values
    switch (tolower(fieldName[0])) {
        case 'g':
            if ( fieldName % "guy" ) return addr_2_Str(guy);
            break;
        case 'w':
            if ( fieldName % "wad" ) return bnu_2_Str(wad);
            break;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CTransaction::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const CBurn9f8f& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    item.Format(os, "", nullptr);
    os << "\n";
    return os;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE


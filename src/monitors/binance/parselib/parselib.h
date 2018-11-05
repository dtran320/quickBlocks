#pragma once
/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
 /*
  *
  * This code was generated automatically from grabABI and makeClass You may 
  * edit the file, but keep your edits inside the 'EXISTING_CODE' tags.
  *
  */
#include "etherlib.h"
#include "tokenlib.h"
#ifndef NOWALLETLIB
#include "walletlib.h"
#endif
#include "burnevent.h"
#include "freezeevent.h"
#include "unfreezeevent.h"
#include "burn.h"
#include "freeze.h"
#include "unfreeze.h"
#include "withdrawether.h"
#include "processing.h"

//------------------------------------------------------------------------
extern void parselib_init(QUITHANDLER qh=defaultQuitHandler);
extern const CTransaction *promoteToFunc(const CTransaction *p);
extern const CLogEntry *promoteToEvent(const CLogEntry *p);

//------------------------------------------------------------------------
extern const string_q func_burn;
extern const string_q func_freeze;
extern const string_q func_freezeOf;
extern const string_q func_owner;
extern const string_q func_unfreeze;
extern const string_q func_withdrawEther;

//------------------------------------------------------------------------
extern const string_q evt_Burn;
extern const string_q evt_Freeze;
extern const string_q evt_Unfreeze;

//-----------------------------------------------------------------------------
extern string_q sigs[];
extern string_q topics[];

extern size_t nSigs;
extern size_t nTopics;

// EXISTING_CODE
// EXISTING_CODE

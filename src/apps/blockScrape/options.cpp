/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *------------------------------------------------------------------------*/
#include "options.h"

//---------------------------------------------------------------------------------------------------
static COption params[] = {
    COption("-noWrite",         "do not write binary blocks to disc (default: write the blocks)"),
    COption("-start:<num>",     "first block to visit (default: last visited block + 1)"),
    COption("-end:<num>",       "last block to visit (required if --start supplied)"),
    COption("-maxBlocks:<num>", "maximum number of blocks to process (defaults to 5000)"),
    COption("@addrIndex",       "index addresses per block in addition to bloom filters"),
    COption("",                 "Decentralized blockchain scraper and block cache.\n"),
};
static size_t nParams = sizeof(params) / sizeof(COption);

//---------------------------------------------------------------------------------------------------
bool COptions::parseArguments(string_q& command) {

    if (!standardOptions(command))
        return false;

    // Make sure the user is not using the --file option
    if (!commandList.empty())
        return usage("You may not use the --file with this application. Quitting...");

    Init();
    while (!command.empty()) {
        string_q arg = nextTokenClear(command, ' ');
        if (arg == "-n" || arg == "--noWrite") {
            writeBlocks = false;

        } else if (arg == "-a" || arg == "--addrIndex") {
            keepAddrIdx = true;
            return usage("--addrIndex option is not implemented. Quiting...");

        } else if (startsWith(arg, "-s:") || startsWith(arg, "--start:")) {
            arg = substitute(substitute(arg, "-s:", ""), "--start:","");
            if (!isUnsigned(arg))
                return usage("--start must be a non-negative number. Quitting...");
            start = str_2_Uint(arg);

        } else if (startsWith(arg, "-e:") || startsWith(arg, "--end:")) {
            arg = substitute(substitute(arg, "-e:", ""), "--end:", "");
            if (!isUnsigned(arg))
                return usage("--end must be a non-negative number. Quitting...");
            end = str_2_Uint(arg);

        } else if (startsWith(arg, "-m:") || startsWith(arg, "--maxBlocks:")) {
            arg = substitute(substitute(arg, "-m:", ""), "--maxBlocks:", "");
            if (!isUnsigned(arg))
                return usage("--maxBlocks must be a non-negative number. Quitting...");
            maxBlocks = str_2_Uint(arg);

        } else if (startsWith(arg, '-')) {  // do not collapse
            if (!builtInCmd(arg)) {
                return usage("Invalid option: " + arg);
            }
        }
    }

    // The maximum number of blocks to process, only pick up from config if user has not told us the value
    if (maxBlocks == 5000)
        maxBlocks = getGlobalConfig("blockScrape")->getConfigInt("settings", "maxBlocks", 5000);

    // If writeBlocks is the default, check to see if set in config, use what user told us to use otherwise
    // Note: this setting is negated in acctScrape options. In this way we write block at one point or the
    // other, but the user can still choose not to write any blocks (by putting --writeBlocks on the
    // command line.
    if (writeBlocks)
        writeBlocks = getGlobalConfig("blockScrape")->getConfigBool("settings", "writeBlocks", true);

    // 'to' addresses (if any) to ignore (helps exclude dDos transactions)
    exclusions = toLower(getGlobalConfig("blockScrape")->getConfigStr ("exclusions", "list",      ""));

    // Make sure the full block index exists. If not, rebuild it
    establishFullBlockIndex();

    blknum_t cache, client;
    getLatestBlocks(cache, client);

    // Find out where to start and stop
    if (start == NOPOS && end != NOPOS) {

        // User tried to tell us where to stop, but didn't tell us where to start. Not okay.
        return usage("You may only specify an --end block if you've given a --start block. Quitting...");

    } else if (start != NOPOS && end != NOPOS) {

        // The user told us where to start and stop. This is okay, but check for bogus data...
        if (start >= end)
            return usage("--start must be before --end. Quitting...");

        if (start > cache)
            return usage("--start must be later than or equal to the last block already in the cache. Quitting...");

    } else if (start != NOPOS) {

        // The user told us where to start...
        start = max((uint64_t)47000, start);
        // ...we figure out where to end.
        end   = max(start + 1, client);

    } else {

        // The user didn't tell us anything
        start = max((uint64_t)47000, cache + 1);
        end   = max(start + 1, client);

    }

    // No more than maxBlocks after start
    end = min(end, start + maxBlocks);

    if (!isParity() || !nodeHasTraces())
        return usage("This tool will only run if it is running against a Parity node that has tracing enabled. Quitting...");

    return true;
}

//---------------------------------------------------------------------------------------------------
void COptions::Init(void) {

    start       = NOPOS;
    end         = NOPOS;
    maxBlocks   = 5000;
    writeBlocks = true;
    keepAddrIdx = false;
    minArgs     = 0;

    paramsPtr = params;
    nParamsRef = nParams;
}

//---------------------------------------------------------------------------------------------------
COptions::COptions(void) {
    // will sort the fields in these classes if --parity is given
    sorts[0] = GETRUNTIME_CLASS(CBlock);
    sorts[1] = GETRUNTIME_CLASS(CTransaction);
    sorts[2] = GETRUNTIME_CLASS(CReceipt);

    Init();
}

//--------------------------------------------------------------------------------
COptions::~COptions(void) {
}

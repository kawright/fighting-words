// =============================================================================
// dict.c - Dictionary management routines
// -----------------------------------------------------------------------------
// Fighting Words - The Tile-Dropping, Word-Spelling, Battle Game
// Copyright (C) 2023  Kristoffer A. Wright
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// =============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/func.h"
#include "include/const.h"
#include "include/macrofunc.h"

/* Destroy the dictionary. */
void DestroyDictionary(String* dictionary) {

    for (int i = 0; i < DICTIONARY_WORD_COUNT; i++) {
        MemoryDeallocate("Dictionary Entry", dictionary[i]);
    }
    MemoryDeallocate("Dictionary", dictionary);

}

/* Test whether a given query string is found in the dictionary. */
Boolean FindDictionaryMatch(String* dictionary, String query, int left, 
        int right) {

    CONSOLE_LOG("Finding dictionary match.");

    while (left <= right) {
        int center = left + (right-left) / 2;
        if (strcmp(query, dictionary[center]) == 0) {
            CONSOLE_LOG("Match found.");
            return TRUE;
        }
        if (strcmp(query, dictionary[center]) > 0) {
            left = center + 1;
        } else {
            right = center - 1;
        }
    }
    CONSOLE_LOG("Match not found.");
    return FALSE;
}

/* Load and return the contents of the dictionary file. */
String* LoadDictionaryFile() {
    String* returnData = MemoryAllocate("Dictionary", 
            (DICTIONARY_WORD_COUNT + 1) * sizeof(String*));
    FILE *fp = fopen(DICTIONARY_FILE_PATH, "r");
    ErrorCheck(fp != NULL, "Could not open dictionary file.");
    rewind(fp);
    int temporaryCharacter;
    char temporaryBuffer[32];
    int temporaryBufferCursor = 0;
    long returnDataCursor = 0;

    while (TRUE) {
        temporaryCharacter = fgetc(fp);
        if (temporaryCharacter == EOF) {
            break;
        }
        if (temporaryCharacter == '\n') {
            temporaryBuffer[temporaryBufferCursor] = '\0';
            returnData[returnDataCursor] = MemoryAllocate("Dictionary Entry", 
                    temporaryBufferCursor + 1);
            strcpy(returnData[returnDataCursor], temporaryBuffer);
            temporaryBufferCursor = 0;
            returnDataCursor++;
            continue;
        }
        temporaryBuffer[temporaryBufferCursor] = temporaryCharacter;
        temporaryBufferCursor++;
    }
    fclose(fp);
    return returnData;
}


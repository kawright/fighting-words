// =============================================================================
// mem.h - Memory management routines
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

#include "include/func.h"
#include "include/macrofunc.h"

/* Allocate heap memory. */
void* MemoryAllocate(String label, long size) {
    void* returnData = malloc(size);
    ErrorCheck(returnData != NULL, "Could not allocate heap memory.");
    MEMORY_ALLOCATION_LOG(size, returnData);
    return returnData;
}

/* Deallocate heap memory. */
void MemoryDeallocate(String label, void* block) {
    MEMORY_DEALLOCATION_LOG(block);
    free(block);
}

/* Reallocate heap memory. */
void* MemoryReallocate(String label, void* block, long size) {
    void* returnData = realloc(block, size);
    ErrorCheck(returnData != NULL, "Could not reallocate heap memory.");
    MEMORY_REALLOCATION_LOG(size, returnData);
    return returnData;
}


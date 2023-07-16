// =============================================================================
// err.h - Error management routines
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

#include "include/alias.h"
#include "include/func.h"

/** 
 * Assert the expression. If the expression is false, print the given error 
 * message and exit with code 1. 
 **/
void ErrorCheck(Boolean expression, String errorMessage) {
    if (!expression) {
        fprintf(stderr, "%s\n", errorMessage);
        exit(1);
    }
}



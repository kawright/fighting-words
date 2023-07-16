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
#include <string.h>
#include <time.h>

#include "include/enum.h"
#include "include/func.h"
#include "include/macrofunc.h"

/* Return the large tile texture code for a given letter. */
int GetLargeTextureCode(String letter) {
    if (strcmp(letter, "A") == 0) {
        return TEXTURE_MAP_TILE_LARGE_A;
    } else if (strcmp(letter, "B") == 0) {
        return TEXTURE_MAP_TILE_LARGE_B;
    } else if (strcmp(letter, "C") == 0) {
        return TEXTURE_MAP_TILE_LARGE_C;
    } else if (strcmp(letter, "D") == 0) {
        return TEXTURE_MAP_TILE_LARGE_D;
    } else if (strcmp(letter, "E") == 0) {
        return TEXTURE_MAP_TILE_LARGE_E;
    } else if (strcmp(letter, "F") == 0) {
        return TEXTURE_MAP_TILE_LARGE_F;
    } else if (strcmp(letter, "G") == 0) {
        return TEXTURE_MAP_TILE_LARGE_G;
    } else if (strcmp(letter, "H") == 0) {
        return TEXTURE_MAP_TILE_LARGE_H;
    } else if (strcmp(letter, "I") == 0) {
        return TEXTURE_MAP_TILE_LARGE_I;
    } else if (strcmp(letter, "J") == 0) {
        return TEXTURE_MAP_TILE_LARGE_J;
    } else if (strcmp(letter, "K") == 0) {
        return TEXTURE_MAP_TILE_LARGE_K;
    } else if (strcmp(letter, "L") == 0) {
        return TEXTURE_MAP_TILE_LARGE_L;
    } else if (strcmp(letter, "M") == 0) {
        return TEXTURE_MAP_TILE_LARGE_M;
    } else if (strcmp(letter, "N") == 0) {
        return TEXTURE_MAP_TILE_LARGE_N;
    } else if (strcmp(letter, "O") == 0) {
        return TEXTURE_MAP_TILE_LARGE_O;
    } else if (strcmp(letter, "P") == 0) {
        return TEXTURE_MAP_TILE_LARGE_P;
    } else if (strcmp(letter, "QU") == 0) {
        return TEXTURE_MAP_TILE_LARGE_QU;
    } else if (strcmp(letter, "R") == 0) {
        return TEXTURE_MAP_TILE_LARGE_R;
    } else if (strcmp(letter, "S") == 0) {
        return TEXTURE_MAP_TILE_LARGE_S;
    } else if (strcmp(letter, "T") == 0) {
        return TEXTURE_MAP_TILE_LARGE_T;
    } else if (strcmp(letter, "U") == 0) {
        return TEXTURE_MAP_TILE_LARGE_U;
    } else if (strcmp(letter, "V") == 0) {
        return TEXTURE_MAP_TILE_LARGE_V;
    } else if (strcmp(letter, "W") == 0) {
        return TEXTURE_MAP_TILE_LARGE_W;
    } else if (strcmp(letter, "X") == 0) {
        return TEXTURE_MAP_TILE_LARGE_X;
    } else if (strcmp(letter, "Y") == 0) {
        return TEXTURE_MAP_TILE_LARGE_Y;
    } else if (strcmp(letter, "Z") == 0) {
        return TEXTURE_MAP_TILE_LARGE_Z;
    } else if (strcmp(letter, "*") == 0) {
        return TEXTURE_MAP_TILE_LARGE_WILDCARD;
    } else if (strcmp(letter, "?") == 0) {
        return TEXTURE_MAP_TILE_LARGE_RANDOM;
    } else {
        return TEXTURE_MAP_TILE_LARGE_RANDOM;
    }
}



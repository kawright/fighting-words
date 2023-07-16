// =============================================================================
// rand.c - Random number generation
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
#include <time.h>

#include "include/enum.h"
#include "include/func.h"
#include "include/macrofunc.h"

/* Return a random blue letter. */
String GetRandomBlueLetter(){
    return "*";
}

/* Return a random green letter. */
String GetRandomGreenLetter() {
    switch (rand() % 11) {
        case (0):
            return "A";
        case (1):
            return "E";
        case (2):
            return "I";
        case (3):
            return "O";
        case (4):
            return "U";
        case (5):
            return "L";
        case (6):
            return "N";
        case (7):
            return "S";
        case (8):
            return "T";
        case (9):
            return "R";
        case (10):
            return "D";
        case (11):
            return "G";
        default:
            return "";
    }
}

/* Returns a random game letter, which includes "Qu", "*", and "?". */
String GetRandomLetter() {
    switch (rand() % 26) {
        case (0):
            return "A";
        case (1):
            return "B";
        case (2):
            return "C";
        case (3):
            return "D";
        case (4):
            return "E";
        case (5):
            return "F";
        case (6):
            return "G";
        case (7):
            return "H";
        case (8):
            return "I";
        case (9):
            return "J";
        case (10):
            return "K";
        case (11):
            return "L";
        case (12):
            return "M";
        case (13):
            return "N";
        case (14):
            return "O";
        case (15):
            return "P";
        case (16):
            return "QU";
        case (17):
            return "R";
        case (18):
            return "S";
        case (19):
            return "T";
        case (20):
            return "U";
        case (21):
            return "V";
        case (22):
            return "W";
        case (23):
            return "X";
        case (24):
            return "Y";
        case (25):
            return "Z";
        case (26):
            return "*";
        default:
            return "";

    }
}

/* Get a random red letter. */
String GetRandomRedLetter() {
    switch (rand() % 4) {
        case (0):
            return "K";
        case (1):
            return "J";
        case (2):
            return "X";
        case (3):
            return "QU";
        case (4):
            return "Z";
        default:
            return "";
    }
}

/* Get a random tile color. */
TileColor GetRandomTileColor() {
    int randomNumber = rand() % 99;
    if (randomNumber < 50) {
        return TILE_COLOR_GREEN;
    } else if (randomNumber < 80) {
        return TILE_COLOR_YELLOW;
    } else if (randomNumber < 95) {
        return TILE_COLOR_RED;
    } else {
        return TILE_COLOR_BLUE;
    }
}

/* Get a random yellow letter. */
String GetRandomYellowLetter() {
    switch (rand() % 8) {
        case (0):
            return "B";
        case (1):
            return "C";
        case (2):
            return "M";
        case (3):
            return "P";
        case (4):
            return "F";
        case (5):
            return "H";
        case (6):
            return "V";
        case (7):
            return "W";
        case (8):
            return "Y";
        default:
            return "";
    }
}


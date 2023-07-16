// =============================================================================
// entity.c - Entity management routines
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

/** 
 * Clear the next word from the Play Field. The value returned indicates the row 
 * where the match was found, or -1 for no match. 
 **/
int ClearNextWord(String* dictionary, PlayField* playfield) {
    for (int wordLength = 6; wordLength >= 3; wordLength--) {
        for (int row = 11; row >= 0; row--) {
            int start = 0;
            int end = start + wordLength;
            while (end <= 6) {
                Boolean proceed = TRUE;
                char currentWord[9];
                int currentWordCursor = 0;
                for (int column = start; column < end; column++) {

                    // Ignore empty spaces:
                    if (playfield->letters[column][row] == NULL) {
                        proceed = FALSE;
                        break;
                    }

                    // Concatenate:
                    for (int letterPosition = 0; letterPosition < 
                            strlen(playfield->letters[column][row]); 
                            letterPosition++) {
                        currentWord[currentWordCursor] = 
                            playfield->letters[column][row][letterPosition];
                        currentWordCursor++;
                    }
                }
                currentWord[currentWordCursor] = '\0';
                if (proceed && FindDictionaryMatch(dictionary, currentWord, 0, 
                            DICTIONARY_WORD_COUNT)) {
                    for (int column = start; column < end; column++) {
                        playfield->letters[column][row] = "!";
                    }
                    return row;
                }
                start++;
                end++;
            }
        }
    }
    return -1;
}

/* Create a new tile. */
Tile* CreateTile(SDL_Texture* texture, String letter, int x, int y) {
    Tile* returnData = MemoryAllocate("Tile", sizeof(Tile));
    returnData->texture = texture;
    returnData->letter = letter;
    returnData->x = x;
    returnData->y = y;
    int size;
    SDL_QueryTexture(texture, NULL, NULL, NULL, &size);
    returnData->size = size;
    return returnData;
}

/* Create a new tile group. */
TileGroup* CreateTileGroup(SDL_Texture* textureMap[TEXTURE_MAP_SIZE], int x, 
        int y) {
    TileGroup* returnData = MemoryAllocate("TileGroup", sizeof(TileGroup));
    switch (GetRandomTileColor()) {
        case (TILE_COLOR_GREEN):
            returnData->letterTop = GetRandomGreenLetter();
            break;
        case (TILE_COLOR_YELLOW):
            returnData->letterTop = GetRandomYellowLetter();
            break;
        case (TILE_COLOR_RED):
            returnData->letterTop = GetRandomRedLetter();
            break;
        case (TILE_COLOR_BLUE):
            returnData->letterTop = GetRandomBlueLetter();
            break;
        default:
            returnData->letterTop = "";
    }
    switch (GetRandomTileColor()) {
        case (TILE_COLOR_GREEN):
            returnData->letterMiddle = GetRandomGreenLetter();
            break;
        case (TILE_COLOR_YELLOW):
            returnData->letterMiddle = GetRandomYellowLetter();
            break;
        case (TILE_COLOR_RED):
            returnData->letterMiddle = GetRandomRedLetter();
            break;
        case (TILE_COLOR_BLUE):
            returnData->letterMiddle = GetRandomBlueLetter();
            break;
        default:
            returnData->letterMiddle = "";
    }
    switch (GetRandomTileColor()) {
        case (TILE_COLOR_GREEN):
            returnData->letterBottom = GetRandomGreenLetter();
            break;
        case (TILE_COLOR_YELLOW):
            returnData->letterBottom = GetRandomYellowLetter();
            break;
        case (TILE_COLOR_RED):
            returnData->letterBottom = GetRandomRedLetter();
            break;
        case (TILE_COLOR_BLUE):
            returnData->letterBottom = GetRandomBlueLetter();
            break;
        default:
            returnData->letterBottom = "";
    }

    returnData->textureTop = 
        textureMap[GetLargeTextureCode(returnData->letterTop)];
    returnData->textureMiddle = 
        textureMap[GetLargeTextureCode(returnData->letterMiddle)];
    returnData->textureBottom = 
        textureMap[GetLargeTextureCode(returnData->letterBottom)];
    returnData->tileSize = LARGE_TILE_SIZE;
    returnData->x = x;
    returnData->y = y;

    return returnData;
}

/* Add a newly dropped tile group to the play field. */
Boolean DropTileGroup(TileGroup* tileGroup, PlayField* playField, int column) {

    // Check for loss condition:
    if (playField->columnHeights[column] >= PLAY_FIELD_HEIGHT-3) {
        return FALSE;
    }

    playField->letters[column][PLAY_FIELD_HEIGHT - playField->
        columnHeights[column] - 1] = tileGroup->letterBottom;
    playField->letters[column][PLAY_FIELD_HEIGHT - playField->
        columnHeights[column] - 2] = tileGroup->letterMiddle;
    playField->letters[column][PLAY_FIELD_HEIGHT - playField->
        columnHeights[column] - 3] = tileGroup->letterTop;

    playField->columnHeights[column] += 3;
    return TRUE;
}

/* Initialize all slots in the play field to NULL. */
void InitializePlayField(PlayField* playField) {
    for (int x = 0; x < PLAY_FIELD_WIDTH; x++) {
        for (int y = 0; y < PLAY_FIELD_HEIGHT; y++) {
            playField->letters[x][y] = NULL;
        }
        playField->columnHeights[x] = 0;
    }
}

/* Rotate the letters in a tile group. */
void RotateTileGroup(TileGroup* tileGroup) {
    SDL_Texture* temporaryTexture = tileGroup->textureBottom;
    String temporaryLetter = tileGroup->letterBottom;
    tileGroup->textureBottom = tileGroup->textureMiddle;
    tileGroup->textureMiddle = tileGroup->textureTop;
    tileGroup->textureTop = temporaryTexture;
    tileGroup->letterBottom = tileGroup->letterMiddle;
    tileGroup->letterMiddle = tileGroup->letterTop;
    tileGroup->letterTop = temporaryLetter;
}

/**
 * Shift the columns of the playfield down on a given row for each empty cell. 
 * To be called after clearing a word. 
 **/
void ShiftPlayFieldDown(PlayField* playfield, int row) {

    // Degenerate case:
    if (row == 0) {
        return;
    }

    for (int column = 0; column < PLAY_FIELD_WIDTH; column++) {

        if (playfield->letters[column][row] == NULL || 
                strcmp(playfield->letters[column][row], "!") != 0){
            continue;
        }
        playfield->columnHeights[column]--;
        for (int currentRow = row; currentRow >= 0; currentRow--) {
            if (currentRow == 0) {
                playfield->letters[column][currentRow] = NULL;
            } else {
                playfield->letters[column][currentRow] = 
                    playfield->letters[column][currentRow-1];
            }
        }
    }
}

/** 
 * Translate a tile group along the x-axis. The position will be limited 
 * between the given bounds. Returns TRUE if the bounds were crossed. 
 **/
Boolean TranslateTileGroupX(TileGroup* tileGroup, int offset, int lowerBound, 
        int upperBound) {
    ErrorCheck(lowerBound < upperBound, 
            "upperBound must be greater than lowerBound.");
    tileGroup->x += offset;
    if (tileGroup->x < lowerBound) {
        tileGroup->x = lowerBound;
        return TRUE;
    }
    if (tileGroup->x + tileGroup->tileSize > upperBound) {
        tileGroup->x = upperBound - tileGroup->tileSize;
        return TRUE;
    }
    return FALSE;
}

/** 
 * Translate a tile group along the y-axis. The position will be limited 
 * between the given bounds. Returns TRUE if the bounds were crossed. 
 **/
Boolean TranslateTileGroupY(TileGroup* tileGroup, int offset, int lowerBound, 
        int upperBound) {
    ErrorCheck(lowerBound < upperBound, 
            "upperBound must be greater than lowerBound.");
    tileGroup->y += offset;
    if (tileGroup->y < lowerBound) {
        tileGroup->y = lowerBound;
        return TRUE;
    }
    if (tileGroup->y + (tileGroup->tileSize * 3) > upperBound) {
        tileGroup->y = upperBound - (tileGroup->tileSize * 3);
        return TRUE;
    }
    return FALSE;
}


/** 
 * Translate a tile along the x-axis. The position will be limited between the 
 * given bounds. Returns TRUE if the bounds were crossed. 
 **/
Boolean TranslateTileX(Tile* tile, int offset, int lowerBound, int upperBound) {
    ErrorCheck(lowerBound < upperBound, 
            "upperBound must be greater than lowerBound.");
    tile->x += offset;
    if (tile->x < lowerBound) {
        tile->x = lowerBound;
        return TRUE;
    }
    if (tile->x + tile->size > upperBound) {
        tile->x = upperBound - tile->size;
        return TRUE;
    }
    return FALSE;
}

/** 
 * Translate a tile along the y-axis. The position will be limited between the 
 * given bounds. Returns TRUE if the bounds were crossed. 
 **/
Boolean TranslateTileY(Tile* tile, int offset, int lowerBound, int upperBound) {
    ErrorCheck(lowerBound < upperBound, 
            "upperBound must be greater than lowerBound.");
    tile->y += offset;
    if (tile->y < lowerBound) {
        tile->y = lowerBound;
        return TRUE;
    }
    if (tile->y + tile->size > upperBound) {
        tile->y = upperBound - tile->size;
        return TRUE;
    }
    return FALSE;
}


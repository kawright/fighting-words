// =============================================================================
// struct.h - Struct definitions
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

#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <SDL2/SDL.h>

#include "alias.h"
#include "const.h"

/* Stores all of the tiles that have already been placed. */
typedef struct {
    String              letters[PLAY_FIELD_WIDTH][PLAY_FIELD_HEIGHT];
    int                 columnHeights[PLAY_FIELD_WIDTH];
} PlayField;

/* Stores the data for a single tile. */
typedef struct {
    SDL_Texture*        texture;
    String              letter;
    int                 x;
    int                 y;
    int                 size;
} Tile;

/* Stores the data for a group of three tiles. */
typedef struct {
    SDL_Texture*        textureTop;
    SDL_Texture*        textureMiddle;
    SDL_Texture*        textureBottom;
    String              letterTop;
    String              letterMiddle;
    String              letterBottom;
    int                 x;
    int                 y;
    int                 tileSize;
} TileGroup;

#endif


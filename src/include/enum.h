// =============================================================================
// enum.h - Enum definitions
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

#ifndef __ENUMS_H__
#define __ENUMS_H__

/** 
 * Stores all names in the color map. 
 **/
typedef enum {


    COLOR_MAP_BACKGROUND_LOSE,          // TODO Obs
    COLOR_MAP_BACKGROUND_PRIMARY,       // TODO Obs
    COLOR_MAP_BACKGROUND_SECONDARY,     // TODO Obs
    COLOR_MAP_TILE_PRIMARY,             // TODO Obs
    COLOR_MAP_TILE_SECONDARY,           // TODO Obs
    COLOR_MAP_TEXT_LABEL,               // TODO Obs
    COLOR_MAP_TEXT_SCORE,               // TODO Obs

    COLOR_MAP_BLACK,
    COLOR_MAP_CRIMSON,
    COLOR_MAP_DARK_SLATE_BLUE,
    COLOR_MAP_DIM_GRAY,
    COLOR_MAP_DODGER_BLUE,
    COLOR_MAP_FIREBRICK,
    COLOR_MAP_FOREST_GREEN,
    COLOR_MAP_GAINSBORO,
    COLOR_MAP_GOLD,
    COLOR_MAP_LIGHT_CORAL,
    COLOR_MAP_LIGHT_GOLDENROD_YELLOW,
    COLOR_MAP_LIGHT_GREEN,
    COLOR_MAP_LIGHT_SKY_BLUE,
    COLOR_MAP_MEDIUM_SLATE_BLUE,
    COLOR_MAP_RED,
    COLOR_MAP_WHITE,
    COLOR_MAP_YELLOW

} ColorMapEntry;

/** 
 * Stores all names in the font map. 
 **/
typedef enum {

    FONT_MAP_EXTRA_LARGE_EXTRA_BOLD,
    FONT_MAP_MEDIUM_BOLD,
    FONT_MAP_TILE_LARGE,                // TODO Obs
    FONT_MAP_TILE_SMALL,                // TODO Obs
    FONT_MAP_TEXT_LABEL,                // TODO Obs
    FONT_MAP_TEXT_SCORE,                // TODO Obs

} FontMapEntry;

/**
 * Stores all names in the texture map. 
 **/
typedef enum {

    TEXTURE_MAP_COUNTDOWN_ONE,
    TEXTURE_MAP_COUNTDOWN_THREE,
    TEXTURE_MAP_COUNTDOWN_TWO,
    TEXTURE_MAP_PLAY_FIELD_FRAME,
    TEXTURE_MAP_PREVIEW_LABEL,
    TEXTURE_MAP_SCORE_LABEL,
    TEXTURE_MAP_START_TEXT,
    TEXTURE_MAP_TILE_DIM_A,
    TEXTURE_MAP_TILE_DIM_B,
    TEXTURE_MAP_TILE_DIM_C,
    TEXTURE_MAP_TILE_DIM_D,
    TEXTURE_MAP_TILE_DIM_E,
    TEXTURE_MAP_TILE_DIM_F,
    TEXTURE_MAP_TILE_DIM_G,
    TEXTURE_MAP_TILE_DIM_H,
    TEXTURE_MAP_TILE_DIM_I,
    TEXTURE_MAP_TILE_DIM_J,
    TEXTURE_MAP_TILE_DIM_K,
    TEXTURE_MAP_TILE_DIM_L,
    TEXTURE_MAP_TILE_DIM_M,
    TEXTURE_MAP_TILE_DIM_N,
    TEXTURE_MAP_TILE_DIM_O,
    TEXTURE_MAP_TILE_DIM_P,
    TEXTURE_MAP_TILE_DIM_QU,
    TEXTURE_MAP_TILE_DIM_R,
    TEXTURE_MAP_TILE_DIM_S,
    TEXTURE_MAP_TILE_DIM_T,
    TEXTURE_MAP_TILE_DIM_U,
    TEXTURE_MAP_TILE_DIM_V,
    TEXTURE_MAP_TILE_DIM_W,
    TEXTURE_MAP_TILE_DIM_X,
    TEXTURE_MAP_TILE_DIM_Y,
    TEXTURE_MAP_TILE_DIM_Z,
    TEXTURE_MAP_TILE_LARGE_A,
    TEXTURE_MAP_TILE_LARGE_B,
    TEXTURE_MAP_TILE_LARGE_BLANK_BLACK,
    TEXTURE_MAP_TILE_LARGE_BLANK_WHITE,
    TEXTURE_MAP_TILE_LARGE_C,
    TEXTURE_MAP_TILE_LARGE_D,
    TEXTURE_MAP_TILE_LARGE_E,
    TEXTURE_MAP_TILE_LARGE_F,
    TEXTURE_MAP_TILE_LARGE_G,
    TEXTURE_MAP_TILE_LARGE_H,
    TEXTURE_MAP_TILE_LARGE_I,
    TEXTURE_MAP_TILE_LARGE_J,
    TEXTURE_MAP_TILE_LARGE_K,
    TEXTURE_MAP_TILE_LARGE_L,
    TEXTURE_MAP_TILE_LARGE_M,
    TEXTURE_MAP_TILE_LARGE_N,
    TEXTURE_MAP_TILE_LARGE_O,
    TEXTURE_MAP_TILE_LARGE_P,
    TEXTURE_MAP_TILE_LARGE_QU,
    TEXTURE_MAP_TILE_LARGE_R,
    TEXTURE_MAP_TILE_LARGE_RANDOM,
    TEXTURE_MAP_TILE_LARGE_S,
    TEXTURE_MAP_TILE_LARGE_T,
    TEXTURE_MAP_TILE_LARGE_U,
    TEXTURE_MAP_TILE_LARGE_V,
    TEXTURE_MAP_TILE_LARGE_W,
    TEXTURE_MAP_TILE_LARGE_WILDCARD,
    TEXTURE_MAP_TILE_LARGE_X,
    TEXTURE_MAP_TILE_LARGE_Y,
    TEXTURE_MAP_TILE_LARGE_Z,
    TEXTURE_MAP_TILE_SMALL_A,
    TEXTURE_MAP_TILE_SMALL_B,
    TEXTURE_MAP_TILE_SMALL_C,
    TEXTURE_MAP_TILE_SMALL_D,
    TEXTURE_MAP_TILE_SMALL_E,
    TEXTURE_MAP_TILE_SMALL_F,
    TEXTURE_MAP_TILE_SMALL_G,
    TEXTURE_MAP_TILE_SMALL_H,
    TEXTURE_MAP_TILE_SMALL_I,
    TEXTURE_MAP_TILE_SMALL_J,
    TEXTURE_MAP_TILE_SMALL_K,
    TEXTURE_MAP_TILE_SMALL_L,
    TEXTURE_MAP_TILE_SMALL_M,
    TEXTURE_MAP_TILE_SMALL_N,
    TEXTURE_MAP_TILE_SMALL_O,
    TEXTURE_MAP_TILE_SMALL_P,
    TEXTURE_MAP_TILE_SMALL_QU,
    TEXTURE_MAP_TILE_SMALL_R,
    TEXTURE_MAP_TILE_SMALL_RANDOM,
    TEXTURE_MAP_TILE_SMALL_S,
    TEXTURE_MAP_TILE_SMALL_T,
    TEXTURE_MAP_TILE_SMALL_U,
    TEXTURE_MAP_TILE_SMALL_V,
    TEXTURE_MAP_TILE_SMALL_W,
    TEXTURE_MAP_TILE_SMALL_WILDCARD,
    TEXTURE_MAP_TILE_SMALL_X,
    TEXTURE_MAP_TILE_SMALL_Y,
    TEXTURE_MAP_TILE_SMALL_Z

} TextureMapEntry;

/** 
 * Stores all tile color types. 
 **/
typedef enum {
    TILE_COLOR_BLUE,
    TILE_COLOR_GREEN,
    TILE_COLOR_RED,
    TILE_COLOR_YELLOW

} TileColor;

#endif


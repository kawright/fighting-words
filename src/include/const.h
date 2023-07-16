// =============================================================================
// const.h - Macro constants
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

#ifndef __MACRO_CONSTANTS_H__
#define __MACRO_CONSTANTS_H__

#include "enum.h"

#define BACKGROUND_COLOR COLOR_MAP_DARK_SLATE_BLUE
#define COLOR_MAP_SIZE 64
#define DEFAULT_WINDOW_HEIGHT 64*12 + 200
#define DEFAULT_WINDOW_TITLE "Fighting Words"
#define DEFAULT_WINDOW_WIDTH 64*6 + 430
#define DICTIONARY_FILE_PATH "/home/kawright/eclipse_projects/" \
                             "fighting-words-linux/asset/dictionary.txt"
#define DICTIONARY_FILE_SIZE 1763166
#define DICTIONARY_MAX_WORD_SIZE 15
#define DICTIONARY_WORD_COUNT 178691
#define FALSE 0
#define FONT_MAP_SIZE 64
#define LARGE_TILE_BORDER_WIDTH 6
#define LARGE_TILE_FONT_PATH "/home/kawright/eclipse_projects/" \
                             "fighting-words-linux/asset/font/black.ttf"
#define LARGE_TILE_FONT_SIZE 36
#define LARGE_TILE_SIZE 64
#define LOGGING_ENABLED 0
#define MOVE_SPEED_FAST 400
#define MOVE_SPEED_REGULAR 300
#define MOVE_SPEED_SLOW 200
#define MOVE_SPEED_VERY_FAST 500
#define MOVE_SPEED_VERY_SLOW 100
#define PLAY_FIELD_FRAME_COLOR COLOR_MAP_MEDIUM_SLATE_BLUE
#define PLAY_FIELD_HEIGHT 12
#define PLAY_FIELD_MARGIN_LEFT 100
#define PLAY_FIELD_MARGIN_TOP 100
#define PLAY_FIELD_WIDTH 6
#define PREVIEW_FRAME_COLOR COLOR_MAP_MEDIUM_SLATE_BLUE
#define PREVIEW_FRAME_HEIGHT (64 * 3) + 32
#define PREVIEW_FRAME_MARGIN_LEFT 100 + (64*6) + 50
#define PREVIEW_FRAME_MARGIN_TOP (100 + (64*12)) - ((64*3) + 32)
#define PREVIEW_FRAME_WIDTH 64 + 32
#define PREVIEW_LABEL_COLOR COLOR_MAP_WHITE
#define PREVIEW_LABEL_MARGIN_LEFT 100 + (64*6) + 50 + 8
#define PREVIEW_LABEL_MARGIN_TOP (100 + (64*12)) - ((64*3) + 32) - 24
#define SCORE_FRAME_COLOR COLOR_MAP_MEDIUM_SLATE_BLUE
#define SCORE_FRAME_MARGIN_LEFT 100 + (64*6) + 50
#define SCORE_FRAME_MARGIN_TOP 100 + 24
#define SCORE_FRAME_HEIGHT 64
#define SCORE_FRAME_WIDTH (64 * 3)
#define SCORE_LABEL_COLOR COLOR_MAP_WHITE
#define SCORE_LABEL_MARGIN_LEFT 100 + (64*6) + 50 + 8
#define SCORE_LABEL_MARGIN_TOP 100
#define SMALL_TILE_BORDER_WIDTH 3
#define SMALL_TILE_FONT_PATH "/home/kawright/eclipse_projects/" \
                             "fighting-words-linux/asset/font/black.ttf"
#define SMALL_TILE_FONT_SIZE 24
#define SMALL_TILE_SIZE 32
#define TEXTURE_MAP_SIZE 128
#define TILE_POOL_SIZE 6 * 12
#define TRUE 1

#endif



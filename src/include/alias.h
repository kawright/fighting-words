// =============================================================================
// alias.h - Common aliases
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

#ifndef __ALIAS_H__
#define __ALIAS_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "const.h"

typedef char Boolean;       // TODO Obs
typedef char *String;       // TODO Obs

/**
 * Stores all named colors used in the game.
 */
typedef SDL_Color ColorMap[COLOR_MAP_SIZE];

/**
 * Stores all named textures used in the game.
 */
typedef SDL_Texture* TexMap[TEXTURE_MAP_SIZE];

/**
 * Stores all named fonts used in the game.
 */
typedef TTF_Font* FontMap[FONT_MAP_SIZE];

#endif

// =============================================================================
// macrofunc.h - Macro functions
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

#ifndef __MACRO_FUNCTIONS_H__
#define __MACRO_FUNCTIONS_H__

#include "const.h"

#include <stdio.h>

#include <SDL2/SDL.h>

#if LOGGING_ENABLED
#define CONSOLE_LOG(message) printf("[%ld] %s\n", SDL_GetTicks64(), message);
#define MEMORY_ALLOCATION_LOG(siize, block) printf("[%ld] Allocated %ld " \
        "bytes at address %p.\n", SDL_GetTicks64(), size, block);
#define MEMORY_DEALLOCATION_LOG(block) printf("[%ld] Deallocated memory at "\
        "address %p.\n", SDL_GetTicks64(), block);
#define MEMORY_REALLOCATION_LOG(size, block) printf("[%ld] Reallocated %ld "\
        "bytes at address %p.\n", SDL_GetTicks64(), size, block);
#else
#define CONSOLE_LOG(message) ;
#define MEMORY_ALLOCATION_LOG(size, block) ;
#define MEMORY_DEALLOCATION_LOG(block) ;
#define MEMORY_REALLOCATION_LOG(size, block) ;
#endif


#endif


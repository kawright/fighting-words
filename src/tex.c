// =============================================================================
// tex.c - Texture rendering routines
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

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "include/func.h"
#include "include/macrofunc.h"

/* Create a text label texture. */
SDL_Texture* CreateTextureLabel(SDL_Renderer* renderer, TTF_Font* font, 
        SDL_Color color, String contents) {
    SDL_Surface* temporarySurface = TTF_RenderText_Blended(font, contents, 
            color);
    ErrorCheck(temporarySurface != NULL, "Could not create label surface.");
    SDL_Texture* returnData = SDL_CreateTextureFromSurface(renderer, 
            temporarySurface);
    ErrorCheck(returnData != NULL, "Could not create label texture.");
    return returnData;
}

/* Create the Play Field frame texture. */
SDL_Texture* CreateTexturePlayFieldFrame(SDL_Renderer* renderer, 
        SDL_Color colorMap[COLOR_MAP_SIZE]) {

    // Initialize an empty texture:
    SDL_Texture* returnData = SDL_CreateTexture(renderer, 
            SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 
            PLAY_FIELD_WIDTH * LARGE_TILE_SIZE,
            PLAY_FIELD_HEIGHT * LARGE_TILE_SIZE);

    SDL_SetRenderTarget(renderer, returnData);
    SDL_SetRenderDrawColor(renderer, colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE].r, 
            colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE].g, 
            colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE].b,
            colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE].a);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_SetRenderTarget(renderer, NULL);
    return returnData;
}

/* Create a tile texture. */
SDL_Texture* CreateTextureTile(SDL_Renderer* renderer, TTF_Font* font, 
        SDL_Color primaryColor, SDL_Color secondaryColor, int size, 
        int borderThickness, String letter) {

    SDL_Rect borderRectangle = { 0, 0, size, size };
    SDL_Rect backgroundRectangle = { borderThickness, borderThickness, 
        size-(2*borderThickness), size-(2*borderThickness) };
    SDL_Texture* letterTexture = CreateTextureLabel(renderer, font, 
            secondaryColor, letter);

    // Find the size of the letter Texture; use it to center the lettering:
    int letterTextureWidth;
    int letterTextureHeight;
    SDL_QueryTexture(letterTexture, NULL, NULL, &letterTextureWidth, 
            &letterTextureHeight);
    SDL_Rect letterRectangle = { size/2 - letterTextureWidth/2, 
        size/2 - letterTextureHeight/2, letterTextureWidth, 
        letterTextureHeight };

    // Initialize an empty texture:
    SDL_Texture* returnData = SDL_CreateTexture(renderer, 
            SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size, size);
    SDL_SetRenderTarget(renderer, returnData);

    // Draw the border, then the background, then the lettering:
    SDL_SetRenderDrawColor(renderer, secondaryColor.r, secondaryColor.g, 
            secondaryColor.b, secondaryColor.a);
    SDL_RenderFillRect(renderer, &borderRectangle);
    SDL_SetRenderDrawColor(renderer, primaryColor.r, primaryColor.g, 
            primaryColor.b, primaryColor.a);
    SDL_RenderFillRect(renderer, &backgroundRectangle);
    SDL_SetRenderDrawColor(renderer, secondaryColor.r, secondaryColor.g, 
            secondaryColor.b, secondaryColor.a);
    SDL_RenderCopy(renderer, letterTexture, NULL, &letterRectangle);

    SDL_RenderPresent(renderer);

    // Cleanup:
    SDL_SetRenderTarget(renderer, NULL);
    SDL_DestroyTexture(letterTexture);

    return returnData;
}

/* Get the height of a texture. */
int GetTextureHeight(SDL_Texture* texture) {
    int returnData;
    SDL_QueryTexture(texture, NULL, NULL, NULL, &returnData);
    return returnData;
}

/* Get the width of a texture. */
int GetTextureWidth(SDL_Texture* texture) {
    int returnData;
    SDL_QueryTexture(texture, NULL, NULL, &returnData, NULL);
    return returnData;
}


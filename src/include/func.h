// =============================================================================
// func.h - Function declarations
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

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "alias.h"
#include "enum.h"
#include "struct.h"
#include "const.h"

void BlankPlayFieldFrame(SDL_Renderer *renderer, 
        SDL_Texture *textureMap[TEXTURE_MAP_SIZE], SDL_Color color);

void BlankScreen(SDL_Renderer* renderer, SDL_Color color);

int ClearNextWord(String* dictionary, PlayField* playfield);

SDL_Texture* CreateTextureLabel(SDL_Renderer* renderer, TTF_Font* font, 
        SDL_Color color, String contents);

SDL_Texture* CreateTexturePlayFieldFrame(SDL_Renderer* renderer, 
        SDL_Color colorMap[COLOR_MAP_SIZE]);

SDL_Texture* CreateTextureTile(SDL_Renderer* renderer, TTF_Font* font, 
        SDL_Color primaryColor, SDL_Color secondaryColor, int size, 
        int borderThickness, String letter);

Tile* CreateTile(SDL_Texture* texture, String letter, int x, int y);

void DestroyDictionary(String* dictionary);

TileGroup* CreateTileGroup(SDL_Texture* textureMap[TEXTURE_MAP_SIZE], int x, 
        int y);

Boolean DropTileGroup(TileGroup* tileGroup, PlayField* playField, int column);

void ErrorCheck(Boolean expression, String errorMessage);

Boolean FindDictionaryMatch(String* dictionary, String query, int left, 
        int right);

int GetLargeTextureCode(String letter);

String GetRandomBlueLetter();

String GetRandomGreenLetter();

String GetRandomLetter();

String GetRandomRedLetter();

TileColor GetRandomTileColor();

String GetRandomYellowLetter();

int GetTextureHeight(SDL_Texture* texture);

int GetTextureWidth(SDL_Texture* texture);

void InitializeColorMap(SDL_Color colorMap[COLOR_MAP_SIZE]);

void InitializeFontMap(TTF_Font* fontMap[FONT_MAP_SIZE]);

void InitializePlayField(PlayField* playField);

void InitializeTextureMap(SDL_Texture* textureMap[TEXTURE_MAP_SIZE], 
        SDL_Color colorMap[COLOR_MAP_SIZE], TTF_Font* fontMap[FONT_MAP_SIZE],
        SDL_Renderer* renderer);

String* LoadDictionaryFile();

void* MemoryAllocate(String label, long size);

void MemoryDeallocate(String label, void* block);

void* MemoryReallocate(String label, void* block, long size);

void RedrawPlayFieldFrame(SDL_Renderer* renderer, SDL_Texture* 
        textureMap[TEXTURE_MAP_SIZE]);

void RedrawWindow(SDL_Renderer* renderer);

void RenderBackground(SDL_Renderer* renderer, SDL_Color color); // TODO Impl


void RenderCountdownOne(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE]);

void RenderCountdownThree(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE]);

void RenderCountdownTwo(SDL_Renderer* renderer, SDL_Texture* 
        textureMap[TEXTURE_MAP_SIZE]);

void RenderFlashTiles(SDL_Renderer* renderer, SDL_Texture* 
        textureMap[TEXTURE_MAP_SIZE], PlayField* playField, 
        Boolean colorFlag);                                     // TODO Impl

void RenderPlayField(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE], PlayField* playField);

void RenderPlayFieldFrame(SDL_Renderer* renderer, SDL_Color color, int x, 
        int y);

void RenderPreview(SDL_Renderer* renderer, TileGroup* tileGroup, int x, 
        int y);                                                 // TODO Impl
                                                                //
void RenderPreviewFrame(SDL_Renderer* renderer, 
        SDL_Color colorMap[COLOR_MAP_SIZE]);

void RenderScoreFrame(SDL_Renderer* renderer, 
        SDL_Color colorMap[COLOR_MAP_SIZE]);

void RenderStartText(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE]);

void RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y);

void RenderTileGroup(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE], TileGroup* tileGroup);

void RotateTileGroup(TileGroup* tileGroup);

void ShiftPlayFieldDown(PlayField* playfield, int row);

void TearDownFontMap(TTF_Font* fontMap[FONT_MAP_SIZE]);

void TearDownTextureMap(SDL_Texture* textureMap[TEXTURE_MAP_SIZE]);

Boolean TranslateTileGroupX(TileGroup* tileGroup, int offset, int lowerBound, 
        int upperBound);

Boolean TranslateTileGroupY(TileGroup* tileGroup, int offset, int lowerBound, 
        int upperBound);

Boolean TranslateTileX(Tile* tile, int offset, int lowerBound, int upperBound);

Boolean TranslateTileY(Tile* tile, int offset, int lowerBound, int upperBound);

void UpdatePlayFieldFrameColor(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE], SDL_Color color);

#endif


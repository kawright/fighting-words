// =============================================================================
// main.c - Main entry point
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

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "include/enum.h"
#include "include/func.h"
#include "include/const.h"
#include "include/macrofunc.h"
#include "include/struct.h"

/* Entry point for Fighting Words. */
int main(int argumentCount, char *argumentVector[]) {

    CONSOLE_LOG("Entry point function 'main' entered.");

    SDL_Color colorMap [COLOR_MAP_SIZE];
    int currentColumn = 0;
    int currentVelocity = MOVE_SPEED_VERY_SLOW;
    String *dictionary;
    TTF_Font *fontMap [FONT_MAP_SIZE];
    SDL_Event latestEvent;
    SDL_Renderer *mainRenderer = NULL;
    SDL_Window *mainWindow = NULL;
    PlayField playField;
    SDL_Texture *textureMap [TEXTURE_MAP_SIZE];
    TileGroup *currentTileGroup;

    // Perform initialization:
    {
        // RNG:
        srand(time(NULL));
        CONSOLE_LOG("Random number generator initialized.");

        // SDL Subsystem:
        ErrorCheck(SDL_Init(SDL_INIT_VIDEO) >= 0, \
                "Could not initialize SDL subsystem.");
        CONSOLE_LOG("SDL subsystem initialized.");

        // SDL TTF Subsystem:
        ErrorCheck(TTF_Init() >= 0, 
                "Could not initialize SDL TTF subsystem.");
        CONSOLE_LOG("SDL TTF subsystem initialized.");

        // Color map:
        InitializeColorMap(colorMap);
        CONSOLE_LOG("Color map initialized.");

        // Font map:
        InitializeFontMap(fontMap);
        CONSOLE_LOG("Font map initialized.");

        // Main Window and Renderer:
        ErrorCheck(SDL_CreateWindowAndRenderer(DEFAULT_WINDOW_WIDTH, 
                    DEFAULT_WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &mainWindow, 
                    &mainRenderer) == 0,
                "Could not initialize main window and renderer.");
        CONSOLE_LOG("Main window and renderer initialized.");

        // Texture map:
        InitializeTextureMap(textureMap, colorMap, fontMap, mainRenderer);
        CONSOLE_LOG("Texture map initialized.");

        // Playfield
        InitializePlayField(&playField);
        CONSOLE_LOG("Play field initialized.");

        // Dictionary
        dictionary = LoadDictionaryFile();
        CONSOLE_LOG("Dictioary loaded.");
    }

    // Configure the main window:
    {
        SDL_SetWindowTitle(mainWindow, DEFAULT_WINDOW_TITLE);
    }

    // Entity creation:
    {
        currentTileGroup = CreateTileGroup(textureMap, 0, 
                (LARGE_TILE_SIZE*3) * -1);
    }



    // Pre-game loop:
    {
        CONSOLE_LOG("Starting pre-game loop.");

        BlankScreen(mainRenderer, colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
        BlankPlayFieldFrame(mainRenderer, textureMap, 
                colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE]);

        RenderTileGroup(mainRenderer, textureMap, currentTileGroup);
        RenderStartText(mainRenderer, textureMap);

        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
        RenderPreviewFrame(mainRenderer, colorMap);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                PREVIEW_LABEL_MARGIN_LEFT, PREVIEW_LABEL_MARGIN_TOP);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_SCORE_LABEL], 
                SCORE_LABEL_MARGIN_LEFT, SCORE_LABEL_MARGIN_TOP);
        RenderScoreFrame(mainRenderer, colorMap);

        RedrawWindow(mainRenderer);

        Boolean isRunning = TRUE;
        while (isRunning) {

            // Process events:
            SDL_PollEvent(&latestEvent);
            switch (latestEvent.type) {
                case (SDL_QUIT):
                    isRunning = FALSE;
                    break;
                case (SDL_KEYDOWN):
                    switch (latestEvent.key.keysym.scancode) {
                        case (SDL_SCANCODE_SPACE):
                            isRunning = FALSE;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    // Countdown:
    {
        CONSOLE_LOG("Starting countdown.");

        BlankScreen(mainRenderer, colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
        BlankPlayFieldFrame(mainRenderer, textureMap, 
                colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE]);
        RenderCountdownThree(mainRenderer, textureMap);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
        RenderPreviewFrame(mainRenderer, colorMap);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                PREVIEW_LABEL_MARGIN_LEFT, PREVIEW_LABEL_MARGIN_TOP);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_SCORE_LABEL], 
                SCORE_LABEL_MARGIN_LEFT, SCORE_LABEL_MARGIN_TOP);
        RenderScoreFrame(mainRenderer, colorMap);
        RedrawWindow(mainRenderer);
        SDL_Delay(1000);

        BlankScreen(mainRenderer, colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
        BlankPlayFieldFrame(mainRenderer, textureMap, 
                colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE]);
        RenderCountdownTwo(mainRenderer, textureMap);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
        RenderPreviewFrame(mainRenderer, colorMap);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                PREVIEW_LABEL_MARGIN_LEFT, PREVIEW_LABEL_MARGIN_TOP);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_SCORE_LABEL], 
                SCORE_LABEL_MARGIN_LEFT, SCORE_LABEL_MARGIN_TOP);
        RenderScoreFrame(mainRenderer, colorMap);
        RedrawWindow(mainRenderer);
        SDL_Delay(1000);

        BlankScreen(mainRenderer, colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
        BlankPlayFieldFrame(mainRenderer, textureMap, 
                colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE]);
        RenderCountdownOne(mainRenderer, textureMap);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
        RenderPreviewFrame(mainRenderer, colorMap);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                PREVIEW_LABEL_MARGIN_LEFT, PREVIEW_LABEL_MARGIN_TOP);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_SCORE_LABEL], 
                SCORE_LABEL_MARGIN_LEFT, SCORE_LABEL_MARGIN_TOP);
        RenderScoreFrame(mainRenderer, colorMap);
        RedrawWindow(mainRenderer);
        SDL_Delay(1000);

    }

    // Pre-main-loop rendering:
    {
        BlankScreen(mainRenderer, colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
        BlankPlayFieldFrame(mainRenderer, textureMap, 
                colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE]);

        RenderTileGroup(mainRenderer, textureMap, currentTileGroup);
        //RedrawPlayFieldFrame(mainRenderer, textureMap);

        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
        RenderPreviewFrame(mainRenderer, colorMap);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                PREVIEW_LABEL_MARGIN_LEFT, PREVIEW_LABEL_MARGIN_TOP);
        RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_SCORE_LABEL], 
                SCORE_LABEL_MARGIN_LEFT, SCORE_LABEL_MARGIN_TOP);
        RenderScoreFrame(mainRenderer, colorMap);

        RedrawWindow(mainRenderer);
    }

    // Main loop:
    {
        Boolean isCurrentTileGroupCollision;
        Boolean isCurrentColumnOverflow;
        Boolean isDone = FALSE;
        Boolean isRunning = TRUE;
        long oldTicks = SDL_GetTicks64();
        long currentTicks;
        long deltaTicks;
        CONSOLE_LOG("Entering main loop.");

        while (isRunning) {

            // Process events:
            SDL_PollEvent(&latestEvent);
            switch (latestEvent.type) {
                case (SDL_QUIT):
                    isRunning = FALSE;
                    break;
                case (SDL_KEYDOWN):
                    switch (latestEvent.key.keysym.scancode) {
                        case (SDL_SCANCODE_LEFT):
                            if (currentColumn > 0 && ((currentTileGroup->y + 
                                    (LARGE_TILE_SIZE * 3)) < (
                                        DEFAULT_WINDOW_HEIGHT 
                                        - playField.columnHeights[
                                        currentColumn - 1] 
                                        * LARGE_TILE_SIZE))) {
                                currentColumn--;
                                currentTileGroup->x -= LARGE_TILE_SIZE;
                            }
                            break;
                        case (SDL_SCANCODE_UP):
                            RotateTileGroup(currentTileGroup);
                            break;
                        case (SDL_SCANCODE_DOWN):
                            currentVelocity = MOVE_SPEED_VERY_FAST;
                            break;
                        case (SDL_SCANCODE_RIGHT):
                            if (currentColumn < PLAY_FIELD_WIDTH-1 
                                    && ((currentTileGroup->y 
                                            + (LARGE_TILE_SIZE * 3))
                                    < (DEFAULT_WINDOW_HEIGHT 
                                        - playField.columnHeights[
                                        currentColumn + 1] 
                                        * LARGE_TILE_SIZE))) {
                                currentColumn++;
                                currentTileGroup->x += LARGE_TILE_SIZE;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case (SDL_KEYUP):
                    switch (latestEvent.key.keysym.scancode) {
                        case (SDL_SCANCODE_LEFT):
                            break;
                        case (SDL_SCANCODE_UP):
                            break;
                        case (SDL_SCANCODE_DOWN):
                            currentVelocity = MOVE_SPEED_VERY_SLOW;
                            break;
                        case (SDL_SCANCODE_RIGHT):
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }

            if (isDone) {
                continue;
            }

            // Calculate time delta since last cycle:
            currentTicks = SDL_GetTicks64();
            deltaTicks = currentTicks - oldTicks;
            oldTicks = currentTicks;

            // Apply movement:
            isCurrentTileGroupCollision = TranslateTileGroupY(currentTileGroup, 
                    (currentVelocity*deltaTicks)/1000,
                    0 - (currentTileGroup->tileSize*3),
                    (PLAY_FIELD_HEIGHT * LARGE_TILE_SIZE) 
                    - (playField.columnHeights[currentColumn] 
                        * LARGE_TILE_SIZE));
            if (isCurrentTileGroupCollision) {
                isCurrentColumnOverflow = DropTileGroup(currentTileGroup, 
                        &playField, currentColumn);

                // Check for words:
                int clearedRow = ClearNextWord(dictionary, &playField);
                while (clearedRow > 0) {


                    // Play flashing animation:
                    for (int frame = 0; frame < 12; frame++) {
                        BlankScreen(mainRenderer, 
                                colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
                        BlankPlayFieldFrame(mainRenderer, textureMap, 
                                colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE]);

                        RenderPlayField(mainRenderer, textureMap, &playField);
                        RenderFlashTiles(mainRenderer, textureMap, &playField, 
                                frame%2);

                        RenderTexture(mainRenderer, 
                                textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                                PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
                        RenderPreviewFrame(mainRenderer, colorMap);
                        RenderTexture(mainRenderer, 
                                textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                                PREVIEW_LABEL_MARGIN_LEFT, 
                                PREVIEW_LABEL_MARGIN_TOP);
                        RenderTexture(mainRenderer, 
                                textureMap[TEXTURE_MAP_SCORE_LABEL], 
                                SCORE_LABEL_MARGIN_LEFT, 
                                SCORE_LABEL_MARGIN_TOP);
                        RenderScoreFrame(mainRenderer, colorMap);

                        RedrawPlayFieldFrame(mainRenderer, textureMap);

                        SDL_Delay(100);
                    }

                    ShiftPlayFieldDown(&playField, clearedRow);


                    oldTicks = SDL_GetTicks64();

                    BlankScreen(mainRenderer, 
                            colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
                    BlankPlayFieldFrame(mainRenderer, textureMap, 
                            colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE]);

                    RenderPlayField(mainRenderer, textureMap, &playField);
                    RenderTileGroup(mainRenderer, textureMap, currentTileGroup);

                    RenderTexture(mainRenderer, 
                            textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                            PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
                    RenderPreviewFrame(mainRenderer, colorMap);
                    RenderTexture(mainRenderer, 
                            textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                            PREVIEW_LABEL_MARGIN_LEFT, 
                            PREVIEW_LABEL_MARGIN_TOP);
                    RenderTexture(mainRenderer, 
                            textureMap[TEXTURE_MAP_SCORE_LABEL], 
                            SCORE_LABEL_MARGIN_LEFT, SCORE_LABEL_MARGIN_TOP);
                    RenderScoreFrame(mainRenderer, colorMap);

                    RedrawPlayFieldFrame(mainRenderer, textureMap);

                    clearedRow = ClearNextWord(dictionary, &playField);
                    SDL_Delay(20);

                }


                // Handle loss condition
                if (!isCurrentColumnOverflow) {
                    BlankScreen(mainRenderer, 
                            colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
                    BlankPlayFieldFrame(mainRenderer, textureMap, 
                            colorMap[COLOR_MAP_CRIMSON]);

                    RenderPlayField(mainRenderer, textureMap, &playField);
                    RenderTileGroup(mainRenderer, textureMap, currentTileGroup);

                    RenderTexture(mainRenderer, 
                            textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                            PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
                    RenderPreviewFrame(mainRenderer, colorMap);
                    RenderTexture(mainRenderer, 
                            textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                            PREVIEW_LABEL_MARGIN_LEFT, 
                            PREVIEW_LABEL_MARGIN_TOP);
                    RenderTexture(mainRenderer, 
                            textureMap[TEXTURE_MAP_SCORE_LABEL], 
                            SCORE_LABEL_MARGIN_LEFT, SCORE_LABEL_MARGIN_TOP);
                    RenderScoreFrame(mainRenderer, colorMap);

                    RedrawWindow(mainRenderer);
                    isDone = TRUE;
                    continue;

                }
                MemoryDeallocate("TileGroup", currentTileGroup);
                currentTileGroup = CreateTileGroup(textureMap, 0, 
                        (LARGE_TILE_SIZE*3) * -1);
                currentColumn = 0;

            }

            // Redraw the scene:
            BlankScreen(mainRenderer, colorMap[COLOR_MAP_DARK_SLATE_BLUE]);
            BlankPlayFieldFrame(mainRenderer, textureMap, 
                    colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE]);

            RenderPlayField(mainRenderer, textureMap, &playField);
            RenderTileGroup(mainRenderer, textureMap, currentTileGroup);



            RenderTexture(mainRenderer, 
                    textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME], 
                    PLAY_FIELD_MARGIN_LEFT, PLAY_FIELD_MARGIN_TOP);
            RenderPreviewFrame(mainRenderer, colorMap);
            RenderTexture(mainRenderer, 
                    textureMap[TEXTURE_MAP_PREVIEW_LABEL], 
                    PREVIEW_LABEL_MARGIN_LEFT, PREVIEW_LABEL_MARGIN_TOP);
            RenderTexture(mainRenderer, textureMap[TEXTURE_MAP_SCORE_LABEL], 
                    SCORE_LABEL_MARGIN_LEFT, SCORE_LABEL_MARGIN_TOP);
            RenderScoreFrame(mainRenderer, colorMap);


            //RedrawWindow(mainRenderer);
            RedrawPlayFieldFrame(mainRenderer, textureMap);

            SDL_Delay(20);

        }

    }

    // Perform teardown:
    {
        DestroyDictionary(dictionary);
        CONSOLE_LOG("Dictionary destroyed.");

        MemoryDeallocate("TileGroup", currentTileGroup);
        CONSOLE_LOG("Tile Group destroyed.");

        TearDownTextureMap(textureMap);
        CONSOLE_LOG("All textures destroyed.");

        TearDownFontMap(fontMap);
        CONSOLE_LOG("All colors and fonts cleaned.");

        SDL_DestroyRenderer(mainRenderer);
        CONSOLE_LOG("Main renderer destroyed.");

        SDL_DestroyWindow(mainWindow);
        CONSOLE_LOG("Main window destroyed.");

        CONSOLE_LOG("Shutting down SDL subsystems and exiting with code 0.");
        SDL_Quit();

    }

    return 0;

}



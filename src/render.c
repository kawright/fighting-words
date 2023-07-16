// =============================================================================
// Fighting Words! - The Tile-Dropping, Word-Spelling, Battle Game
// 
// Written By: KRISTOFFER A. WRIGHT (kris.al.wright@gmail.com)
//
// render.c - Graphics rendering routines.
// =============================================================================

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "include/func.h"
#include "include/macrofunc.h"
#include "include/struct.h"

/* Blank the Play Field frame using a given color. */
void BlankPlayFieldFrame(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE], SDL_Color color) {
    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);

    SDL_SetRenderTarget(renderer, NULL);
}

/* Blank the screen using a given color. */
void BlankScreen(SDL_Renderer* renderer, SDL_Color color) {
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

/* Redraw changes to the Play Field frame. */
void RedrawPlayFieldFrame(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE]) {
    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_RenderPresent(renderer);

    SDL_SetRenderTarget(renderer, NULL);
}

/* Redraw changes to the window. */
void RedrawWindow(SDL_Renderer* renderer) {
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderPresent(renderer);
}

/* Render the countdown text for number one. */
void RenderCountdownOne(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE]) {
    int playFieldHalfWidth = (PLAY_FIELD_WIDTH * LARGE_TILE_SIZE) / 2;
    int playFieldHalfHeight = (PLAY_FIELD_HEIGHT * LARGE_TILE_SIZE) / 2;
    int textureWidth;
    int textureHeight;
    SDL_QueryTexture(textureMap[TEXTURE_MAP_COUNTDOWN_ONE], NULL, NULL, 
            &textureWidth, &textureHeight);

    SDL_Rect boundingRectangle = { playFieldHalfWidth - (textureWidth / 2), 
        playFieldHalfHeight, textureWidth, textureHeight };
    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_RenderCopy(renderer, textureMap[TEXTURE_MAP_COUNTDOWN_ONE], NULL, 
            &boundingRectangle);
    SDL_SetRenderTarget(renderer, NULL);
}

/* Render the countdown text for number three. */
void RenderCountdownThree(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE]) {
    int playFieldHalfWidth = (PLAY_FIELD_WIDTH * LARGE_TILE_SIZE) / 2;
    int playFieldHalfHeight = (PLAY_FIELD_HEIGHT * LARGE_TILE_SIZE) / 2;
    int textureWidth;
    int textureHeight;
    SDL_QueryTexture(textureMap[TEXTURE_MAP_COUNTDOWN_THREE], NULL, NULL, 
            &textureWidth, &textureHeight);

    SDL_Rect boundingRectangle = { playFieldHalfWidth - (textureWidth / 2), 
        playFieldHalfHeight, textureWidth, textureHeight };
    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_RenderCopy(renderer, textureMap[TEXTURE_MAP_COUNTDOWN_THREE], NULL, 
            &boundingRectangle);
    SDL_SetRenderTarget(renderer, NULL);
}

/* Render the countdown text for number two. */
void RenderCountdownTwo(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE]) {
    int playFieldHalfWidth = (PLAY_FIELD_WIDTH * LARGE_TILE_SIZE) / 2;
    int playFieldHalfHeight = (PLAY_FIELD_HEIGHT * LARGE_TILE_SIZE) / 2;
    int textureWidth;
    int textureHeight;
    SDL_QueryTexture(textureMap[TEXTURE_MAP_COUNTDOWN_TWO], NULL, NULL, 
            &textureWidth, &textureHeight);

    SDL_Rect boundingRectangle = { playFieldHalfWidth - (textureWidth / 2), 
        playFieldHalfHeight, textureWidth, textureHeight };
    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_RenderCopy(renderer, textureMap[TEXTURE_MAP_COUNTDOWN_TWO], NULL, 
            &boundingRectangle);
    SDL_SetRenderTarget(renderer, NULL);
}

/**
 * Render the flashing tiles for matched words. When colorFlag is TRUE, the 
 * tiles will be light, otherwise they will be dark. 
 **/
void RenderFlashTiles(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE], PlayField* playField, 
        Boolean colorFlag) {
    CONSOLE_LOG("Rendering flash tiles.");
    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_Rect boundingRectangle;
    boundingRectangle.w = LARGE_TILE_SIZE;
    boundingRectangle.h = LARGE_TILE_SIZE;
    for (int x = 0; x < PLAY_FIELD_WIDTH; x++) {
        for (int y = 0; y < PLAY_FIELD_HEIGHT; y++) {
            if (playField->letters[x][y] != NULL 
                    && strcmp(playField->letters[x][y], "!") == 0) {
                boundingRectangle.x = x * LARGE_TILE_SIZE;
                boundingRectangle.y = y * LARGE_TILE_SIZE;
                if (colorFlag) {
                    SDL_RenderCopy(renderer, 
                            textureMap[TEXTURE_MAP_TILE_LARGE_BLANK_WHITE], 
                            NULL, &boundingRectangle);
                } else {
                    SDL_RenderCopy(renderer, 
                            textureMap[TEXTURE_MAP_TILE_LARGE_BLANK_BLACK], 
                            NULL, &boundingRectangle);
                }
            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);

}

/* Render the play field. */
void RenderPlayField(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE], PlayField* playField) {
    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_Rect boundingRectangle;
    boundingRectangle.w = LARGE_TILE_SIZE;
    boundingRectangle.h = LARGE_TILE_SIZE;
    for (int x = 0; x < PLAY_FIELD_WIDTH; x++) {
        for (int y = 0; y < PLAY_FIELD_HEIGHT; y++) {
            if (playField->letters[x][y] != NULL 
                    && strcmp(playField->letters[x][y], "!") != 0) {
                boundingRectangle.x = x * LARGE_TILE_SIZE;
                boundingRectangle.y = y * LARGE_TILE_SIZE;
                SDL_RenderCopy(renderer, 
                        textureMap[GetLargeTextureCode(
                            playField->letters[x][y])], NULL, 
                        &boundingRectangle);
            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
}

/* Render the background of the playfield. */
void RenderPlayFieldFrame(SDL_Renderer* renderer, SDL_Color color, int x, 
        int y) {
    SDL_Rect boundingRectangle = { x, y, PLAY_FIELD_WIDTH * LARGE_TILE_SIZE, 
        PLAY_FIELD_HEIGHT * LARGE_TILE_SIZE };
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &boundingRectangle);
}

/* Render the background of the preview area. */
void RenderPreviewFrame(SDL_Renderer* renderer, 
        SDL_Color colorMap[COLOR_MAP_SIZE]) {
    SDL_Rect boundingRectangle = { PREVIEW_FRAME_MARGIN_LEFT, 
        PREVIEW_FRAME_MARGIN_TOP, PREVIEW_FRAME_WIDTH, PREVIEW_FRAME_HEIGHT };
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, colorMap[PREVIEW_FRAME_COLOR].r, 
            colorMap[PREVIEW_FRAME_COLOR].g, colorMap[PREVIEW_FRAME_COLOR].b,
            colorMap[PREVIEW_FRAME_COLOR].a);
    SDL_RenderFillRect(renderer, &boundingRectangle);
}

/* Render the background of the score area. */
void RenderScoreFrame(SDL_Renderer* renderer, 
        SDL_Color colorMap[COLOR_MAP_SIZE]) {
    SDL_Rect boundingRectangle = { SCORE_FRAME_MARGIN_LEFT, 
        SCORE_FRAME_MARGIN_TOP, SCORE_FRAME_WIDTH, SCORE_FRAME_HEIGHT };
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, colorMap[SCORE_FRAME_COLOR].r, 
            colorMap[SCORE_FRAME_COLOR].g, colorMap[SCORE_FRAME_COLOR].b,
            colorMap[SCORE_FRAME_COLOR].a);
    SDL_RenderFillRect(renderer, &boundingRectangle);
}

/* Render the start text onto the Play Field frame. */
void RenderStartText(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE]) {

    int playFieldHalfWidth = (PLAY_FIELD_WIDTH * LARGE_TILE_SIZE) / 2;
    int playFieldQuarterHeight = (PLAY_FIELD_HEIGHT * LARGE_TILE_SIZE) / 4;
    int textWidth;
    int textHeight;
    SDL_QueryTexture(textureMap[TEXTURE_MAP_START_TEXT], NULL, NULL, 
            &textWidth, &textHeight);

    SDL_Rect boundingRectangle = { playFieldHalfWidth - (textWidth / 2), 
        playFieldQuarterHeight, textWidth, textHeight };
    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_RenderCopy(renderer, textureMap[TEXTURE_MAP_START_TEXT], NULL,
            &boundingRectangle);

    SDL_SetRenderTarget(renderer, NULL);

}

/**
 * Render a texture to the window. x and y refer to the top-left corner of the 
 * texture. 
 **/
void RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {

    // Find the texture dimensions and build the bounding rectangle:
    int textureWidth;
    int textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect boundingRectangle = { x, y, textureWidth, textureHeight };
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, texture, NULL, &boundingRectangle);
}

void RenderTileGroup(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE], TileGroup* tileGroup) {

    // Build the bounding rectangles for each tile texture
    SDL_Rect boundingRectangleTop = { tileGroup->x, tileGroup->y, 
        tileGroup->tileSize, tileGroup->tileSize };
    SDL_Rect boundingRectangleMiddle = { tileGroup->x, 
        tileGroup->y + tileGroup->tileSize, tileGroup->tileSize,
            tileGroup->tileSize };
    SDL_Rect boundingRectangleBottom = { tileGroup->x, 
        tileGroup->y + (2 * tileGroup->tileSize),
            tileGroup->tileSize, tileGroup->tileSize };

    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_RenderCopy(renderer, tileGroup->textureTop, NULL, 
            &boundingRectangleTop);
    SDL_RenderCopy(renderer, tileGroup->textureMiddle, NULL, 
            &boundingRectangleMiddle);
    SDL_RenderCopy(renderer, tileGroup->textureBottom, NULL, 
            &boundingRectangleBottom);

    SDL_SetRenderTarget(renderer, NULL);
}

/* Update the color of the Play Field frame. */
void UpdatePlayFieldFrameColor(SDL_Renderer* renderer, 
        SDL_Texture* textureMap[TEXTURE_MAP_SIZE], SDL_Color color) {

    SDL_SetRenderTarget(renderer, textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);

    SDL_SetRenderTarget(renderer, NULL);
}

#endif


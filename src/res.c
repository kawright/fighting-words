// =============================================================================
// Fighting Words! - The Tile-Dropping, Word-Spelling, Battle Game
// 
// Written By: KRISTOFFER A. WRIGHT (kris.al.wright@gmail.com)
//
// res.c - Resource management routines
// =============================================================================

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "include/enum.h"
#include "include/func.h"
#include "include/macrofunc.h"

/* Initialize all colors. Mutates the passed in color map. */
void InitializeColorMap(SDL_Color colorMap[COLOR_MAP_SIZE]) {

    colorMap[COLOR_MAP_BACKGROUND_LOSE].r = 0xb0;
    colorMap[COLOR_MAP_BACKGROUND_LOSE].g = 0x00;
    colorMap[COLOR_MAP_BACKGROUND_LOSE].b = 0x00;
    colorMap[COLOR_MAP_BACKGROUND_LOSE].a = 0xff;

    colorMap[COLOR_MAP_BACKGROUND_PRIMARY].r = 0x00;
    colorMap[COLOR_MAP_BACKGROUND_PRIMARY].g = 0x00;
    colorMap[COLOR_MAP_BACKGROUND_PRIMARY].b = 0x40;
    colorMap[COLOR_MAP_BACKGROUND_PRIMARY].a = 0xff;

    colorMap[COLOR_MAP_BACKGROUND_SECONDARY].r = 0x00;
    colorMap[COLOR_MAP_BACKGROUND_SECONDARY].g = 0x00;
    colorMap[COLOR_MAP_BACKGROUND_SECONDARY].b = 0x80;
    colorMap[COLOR_MAP_BACKGROUND_SECONDARY].a = 0xff;

    colorMap[COLOR_MAP_TILE_PRIMARY].r = 0xf5;
    colorMap[COLOR_MAP_TILE_PRIMARY].g = 0xde;
    colorMap[COLOR_MAP_TILE_PRIMARY].b = 0xb3;
    colorMap[COLOR_MAP_TILE_PRIMARY].a = 0xff;

    colorMap[COLOR_MAP_TILE_SECONDARY].r = 0x8b;
    colorMap[COLOR_MAP_TILE_SECONDARY].g = 0x45;
    colorMap[COLOR_MAP_TILE_SECONDARY].b = 0x13;
    colorMap[COLOR_MAP_TILE_SECONDARY].a = 0xff;

    colorMap[COLOR_MAP_TEXT_LABEL].r = 0xff;
    colorMap[COLOR_MAP_TEXT_LABEL].g = 0xff;
    colorMap[COLOR_MAP_TEXT_LABEL].b = 0xff;
    colorMap[COLOR_MAP_TEXT_LABEL].a = 0xff;

    colorMap[COLOR_MAP_TEXT_SCORE].r = 0xff;
    colorMap[COLOR_MAP_TEXT_SCORE].g = 0xff;
    colorMap[COLOR_MAP_TEXT_SCORE].b = 0xff;
    colorMap[COLOR_MAP_TEXT_SCORE].a = 0xff;


    colorMap[COLOR_MAP_BLACK].r = 0x00;
    colorMap[COLOR_MAP_BLACK].g = 0x00;
    colorMap[COLOR_MAP_BLACK].b = 0x00;
    colorMap[COLOR_MAP_BLACK].a = 0xff;

    colorMap[COLOR_MAP_CRIMSON].r = 0xdc;
    colorMap[COLOR_MAP_CRIMSON].g = 0x14;
    colorMap[COLOR_MAP_CRIMSON].b = 0x3c;
    colorMap[COLOR_MAP_CRIMSON].a = 0xff;

    colorMap[COLOR_MAP_DARK_SLATE_BLUE].r = 0x48;
    colorMap[COLOR_MAP_DARK_SLATE_BLUE].g = 0x3d;
    colorMap[COLOR_MAP_DARK_SLATE_BLUE].b = 0x8b;
    colorMap[COLOR_MAP_DARK_SLATE_BLUE].a = 0xff;

    colorMap[COLOR_MAP_DIM_GRAY].r = 0x69;
    colorMap[COLOR_MAP_DIM_GRAY].g = 0x69;
    colorMap[COLOR_MAP_DIM_GRAY].b = 0x69;
    colorMap[COLOR_MAP_DIM_GRAY].a = 0xff;

    colorMap[COLOR_MAP_DODGER_BLUE].r = 0x1e;
    colorMap[COLOR_MAP_DODGER_BLUE].g = 0x90;
    colorMap[COLOR_MAP_DODGER_BLUE].b = 0xff;
    colorMap[COLOR_MAP_DODGER_BLUE].a = 0xff;

    colorMap[COLOR_MAP_FIREBRICK].r = 0xb2;
    colorMap[COLOR_MAP_FIREBRICK].g = 0x22;
    colorMap[COLOR_MAP_FIREBRICK].b = 0x22;
    colorMap[COLOR_MAP_FIREBRICK].a = 0xff;

    colorMap[COLOR_MAP_FOREST_GREEN].r = 0x22;
    colorMap[COLOR_MAP_FOREST_GREEN].g = 0x8b;
    colorMap[COLOR_MAP_FOREST_GREEN].b = 0x22;
    colorMap[COLOR_MAP_FOREST_GREEN].a = 0xff;

    colorMap[COLOR_MAP_GAINSBORO].r = 0xdc;
    colorMap[COLOR_MAP_GAINSBORO].g = 0xdc;
    colorMap[COLOR_MAP_GAINSBORO].b = 0xdc;
    colorMap[COLOR_MAP_GAINSBORO].a = 0xff;

    colorMap[COLOR_MAP_GOLD].r = 0xdf;
    colorMap[COLOR_MAP_GOLD].g = 0xb7;
    colorMap[COLOR_MAP_GOLD].b = 0x00;
    colorMap[COLOR_MAP_GOLD].a = 0xff;

    colorMap[COLOR_MAP_LIGHT_CORAL].r = 0xf0;
    colorMap[COLOR_MAP_LIGHT_CORAL].g = 0x80;
    colorMap[COLOR_MAP_LIGHT_CORAL].b = 0x80;
    colorMap[COLOR_MAP_LIGHT_CORAL].a = 0xff;

    colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW].r = 0xfa;
    colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW].g = 0xfa;
    colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW].b = 0xb2;
    colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW].a = 0xff;

    colorMap[COLOR_MAP_LIGHT_GREEN].r = 0x90;
    colorMap[COLOR_MAP_LIGHT_GREEN].g = 0xee;
    colorMap[COLOR_MAP_LIGHT_GREEN].b = 0x90;
    colorMap[COLOR_MAP_LIGHT_GREEN].a = 0xff;

    colorMap[COLOR_MAP_LIGHT_SKY_BLUE].r = 0x87;
    colorMap[COLOR_MAP_LIGHT_SKY_BLUE].g = 0xce;
    colorMap[COLOR_MAP_LIGHT_SKY_BLUE].b = 0xfa;
    colorMap[COLOR_MAP_LIGHT_SKY_BLUE].a = 0xff;

    colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE].r = 0x7b;
    colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE].g = 0x68;
    colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE].b = 0xee;
    colorMap[COLOR_MAP_MEDIUM_SLATE_BLUE].a = 0xff;

    colorMap[COLOR_MAP_RED].r = 0xff;
    colorMap[COLOR_MAP_RED].g = 0x00;
    colorMap[COLOR_MAP_RED].b = 0x00;
    colorMap[COLOR_MAP_RED].a = 0xff;

    colorMap[COLOR_MAP_WHITE].r = 0xff;
    colorMap[COLOR_MAP_WHITE].g = 0xff;
    colorMap[COLOR_MAP_WHITE].b = 0xff;
    colorMap[COLOR_MAP_WHITE].a = 0xff;

    colorMap[COLOR_MAP_YELLOW].r = 0xff;
    colorMap[COLOR_MAP_YELLOW].g = 0xff;
    colorMap[COLOR_MAP_YELLOW].b = 0x00;
    colorMap[COLOR_MAP_YELLOW].a = 0xff;

}

/* Initialize all fonts. Mutates the passed in font map. */
void InitializeFontMap(TTF_Font* fontMap[FONT_MAP_SIZE]) {

    fontMap[FONT_MAP_EXTRA_LARGE_EXTRA_BOLD] = TTF_OpenFont("/home/kawright/"
            "eclipse_projects/fighting-words-linux/asset/font/extra_bold.ttf", 
            64);
    fontMap[FONT_MAP_MEDIUM_BOLD] = TTF_OpenFont("/home/kawright/"
            "eclipse_projects/fighting-words-linux/asset/font/bold.ttf", 24);

    fontMap[FONT_MAP_TEXT_LABEL] = TTF_OpenFont("/home/kawright/"
            "eclipse_projects/fighting-words-linux/asset/font/semi_bold.ttf", 
            16);
    fontMap[FONT_MAP_TEXT_SCORE] = TTF_OpenFont("/home/kawright/"
            "eclipse_projects/fighting-words-linux/asset/font/bold.ttf", 36);
    fontMap[FONT_MAP_TILE_LARGE] = TTF_OpenFont(LARGE_TILE_FONT_PATH, 
            LARGE_TILE_FONT_SIZE);
    fontMap[FONT_MAP_TILE_SMALL] = TTF_OpenFont(SMALL_TILE_FONT_PATH, 
            SMALL_TILE_FONT_SIZE);
}

/* Initialize all static textures. Mutates the passed in texture map. */
void InitializeTextureMap(SDL_Texture* textureMap[TEXTURE_MAP_SIZE], 
        SDL_Color colorMap[COLOR_MAP_SIZE], TTF_Font* fontMap[FONT_MAP_SIZE],
        SDL_Renderer* renderer) {

    // TODO Update tile textures to use new colors.
    textureMap[TEXTURE_MAP_COUNTDOWN_ONE] = CreateTextureLabel(renderer, 
            fontMap[FONT_MAP_EXTRA_LARGE_EXTRA_BOLD], colorMap[COLOR_MAP_RED], 
            "1");
    textureMap[TEXTURE_MAP_COUNTDOWN_THREE] = CreateTextureLabel(renderer, 
            fontMap[FONT_MAP_EXTRA_LARGE_EXTRA_BOLD], colorMap[COLOR_MAP_WHITE], 
            "3");
    textureMap[TEXTURE_MAP_COUNTDOWN_TWO] = CreateTextureLabel(renderer, 
            fontMap[FONT_MAP_EXTRA_LARGE_EXTRA_BOLD], 
            colorMap[COLOR_MAP_YELLOW], "2");
    textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME] = CreateTexturePlayFieldFrame(
            renderer, colorMap);
    textureMap[TEXTURE_MAP_PREVIEW_LABEL] = CreateTextureLabel(renderer, 
            fontMap[FONT_MAP_TEXT_LABEL], colorMap[PREVIEW_LABEL_COLOR], 
            "NEXT");
    textureMap[TEXTURE_MAP_SCORE_LABEL] = CreateTextureLabel(renderer, 
            fontMap[FONT_MAP_TEXT_LABEL], colorMap[SCORE_LABEL_COLOR], "SCORE");
    textureMap[TEXTURE_MAP_START_TEXT] = CreateTextureLabel(renderer, 
            fontMap[FONT_MAP_MEDIUM_BOLD], colorMap[COLOR_MAP_WHITE], 
            "Press SPACE to Play");
    textureMap[TEXTURE_MAP_TILE_LARGE_A] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "A");
    textureMap[TEXTURE_MAP_TILE_LARGE_B] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, LARGE_TILE_BORDER_WIDTH, 
            "B");
    textureMap[TEXTURE_MAP_TILE_LARGE_BLANK_BLACK] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_DIM_GRAY],
                colorMap[COLOR_MAP_BLACK], LARGE_TILE_SIZE, 
                LARGE_TILE_BORDER_WIDTH, " ");
    textureMap[TEXTURE_MAP_TILE_LARGE_BLANK_WHITE] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_WHITE],
                colorMap[COLOR_MAP_GAINSBORO], LARGE_TILE_SIZE, 
                LARGE_TILE_BORDER_WIDTH, " ");
    textureMap[TEXTURE_MAP_TILE_LARGE_C] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, LARGE_TILE_BORDER_WIDTH, 
            "C");
    textureMap[TEXTURE_MAP_TILE_LARGE_D] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "D");
    textureMap[TEXTURE_MAP_TILE_LARGE_E] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "E");
    textureMap[TEXTURE_MAP_TILE_LARGE_F] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, LARGE_TILE_BORDER_WIDTH, 
            "F");
    textureMap[TEXTURE_MAP_TILE_LARGE_G] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "G");
    textureMap[TEXTURE_MAP_TILE_LARGE_H] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "H");
    textureMap[TEXTURE_MAP_TILE_LARGE_I] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "I");
    textureMap[TEXTURE_MAP_TILE_LARGE_J] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_CORAL],
            colorMap[COLOR_MAP_FIREBRICK], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "J");
    textureMap[TEXTURE_MAP_TILE_LARGE_K] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_CORAL],
            colorMap[COLOR_MAP_FIREBRICK], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "K");
    textureMap[TEXTURE_MAP_TILE_LARGE_L] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "L");
    textureMap[TEXTURE_MAP_TILE_LARGE_M] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, LARGE_TILE_BORDER_WIDTH, 
            "M");
    textureMap[TEXTURE_MAP_TILE_LARGE_N] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "N");
    textureMap[TEXTURE_MAP_TILE_LARGE_O] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "O");
    textureMap[TEXTURE_MAP_TILE_LARGE_P] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, LARGE_TILE_BORDER_WIDTH, 
            "P");
    textureMap[TEXTURE_MAP_TILE_LARGE_QU] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_CORAL],
            colorMap[COLOR_MAP_FIREBRICK], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "Qu");
    textureMap[TEXTURE_MAP_TILE_LARGE_R] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "R");
    textureMap[TEXTURE_MAP_TILE_LARGE_RANDOM] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_SKY_BLUE],
            colorMap[COLOR_MAP_DODGER_BLUE], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "?");
    textureMap[TEXTURE_MAP_TILE_LARGE_S] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "S");
    textureMap[TEXTURE_MAP_TILE_LARGE_T] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "T");
    textureMap[TEXTURE_MAP_TILE_LARGE_U] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_GREEN],
            colorMap[COLOR_MAP_FOREST_GREEN], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "U");
    textureMap[TEXTURE_MAP_TILE_LARGE_V] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "V");
    textureMap[TEXTURE_MAP_TILE_LARGE_W] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, LARGE_TILE_BORDER_WIDTH, 
            "W");
    textureMap[TEXTURE_MAP_TILE_LARGE_WILDCARD] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_SKY_BLUE],
            colorMap[COLOR_MAP_DODGER_BLUE], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "*");
    textureMap[TEXTURE_MAP_TILE_LARGE_X] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_CORAL],
            colorMap[COLOR_MAP_FIREBRICK], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "X");
    textureMap[TEXTURE_MAP_TILE_LARGE_Y] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], 
            colorMap[COLOR_MAP_LIGHT_GOLDENROD_YELLOW],
            colorMap[COLOR_MAP_GOLD], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "Y");
    textureMap[TEXTURE_MAP_TILE_LARGE_Z] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_LARGE], colorMap[COLOR_MAP_LIGHT_CORAL],
            colorMap[COLOR_MAP_FIREBRICK], LARGE_TILE_SIZE, 
            LARGE_TILE_BORDER_WIDTH, "Z");
    textureMap[TEXTURE_MAP_TILE_SMALL_A] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "A");
    textureMap[TEXTURE_MAP_TILE_SMALL_B] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "B");
    textureMap[TEXTURE_MAP_TILE_SMALL_C] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "C");
    textureMap[TEXTURE_MAP_TILE_SMALL_D] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "D");
    textureMap[TEXTURE_MAP_TILE_SMALL_E] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "E");
    textureMap[TEXTURE_MAP_TILE_SMALL_F] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "F");
    textureMap[TEXTURE_MAP_TILE_SMALL_G] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "G");
    textureMap[TEXTURE_MAP_TILE_SMALL_H] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "H");
    textureMap[TEXTURE_MAP_TILE_SMALL_I] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "I");
    textureMap[TEXTURE_MAP_TILE_SMALL_J] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "J");
    textureMap[TEXTURE_MAP_TILE_SMALL_K] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "K");
    textureMap[TEXTURE_MAP_TILE_SMALL_L] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "L");
    textureMap[TEXTURE_MAP_TILE_SMALL_M] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "M");
    textureMap[TEXTURE_MAP_TILE_SMALL_N] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "N");
    textureMap[TEXTURE_MAP_TILE_SMALL_O] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "O");
    textureMap[TEXTURE_MAP_TILE_SMALL_P] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "P");
    textureMap[TEXTURE_MAP_TILE_SMALL_QU] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "Qu");
    textureMap[TEXTURE_MAP_TILE_SMALL_R] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "R");
    textureMap[TEXTURE_MAP_TILE_SMALL_RANDOM] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "?");
    textureMap[TEXTURE_MAP_TILE_SMALL_S] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "S");
    textureMap[TEXTURE_MAP_TILE_SMALL_T] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "T");
    textureMap[TEXTURE_MAP_TILE_SMALL_U] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "U");
    textureMap[TEXTURE_MAP_TILE_SMALL_V] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "V");
    textureMap[TEXTURE_MAP_TILE_SMALL_W] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "W");
    textureMap[TEXTURE_MAP_TILE_SMALL_WILDCARD] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "*");
    textureMap[TEXTURE_MAP_TILE_SMALL_X] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "X");
    textureMap[TEXTURE_MAP_TILE_SMALL_Y] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "Y");
    textureMap[TEXTURE_MAP_TILE_SMALL_Z] = CreateTextureTile(renderer, 
            fontMap[FONT_MAP_TILE_SMALL], colorMap[COLOR_MAP_TILE_PRIMARY],
            colorMap[COLOR_MAP_TILE_SECONDARY], SMALL_TILE_SIZE, 
            SMALL_TILE_BORDER_WIDTH, "Z");

}

/* Close all fonts. */
void TearDownFontMap(TTF_Font* fontMap[FONT_MAP_SIZE]) {

    TTF_CloseFont(fontMap[FONT_MAP_EXTRA_LARGE_EXTRA_BOLD]);
    TTF_CloseFont(fontMap[FONT_MAP_MEDIUM_BOLD]);

    TTF_CloseFont(fontMap[FONT_MAP_TEXT_LABEL]);
    TTF_CloseFont(fontMap[FONT_MAP_TEXT_SCORE]);
    TTF_CloseFont(fontMap[FONT_MAP_TILE_LARGE]);
    TTF_CloseFont(fontMap[FONT_MAP_TILE_SMALL]);
}

/* Destroy all static textures. */
void TearDownTextureMap(SDL_Texture* textureMap[TEXTURE_MAP_SIZE]) {

    SDL_DestroyTexture(textureMap[TEXTURE_MAP_COUNTDOWN_ONE]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_COUNTDOWN_THREE]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_COUNTDOWN_TWO]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_PLAY_FIELD_FRAME]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_PREVIEW_LABEL]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_SCORE_LABEL]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_START_TEXT]);

    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_A]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_B]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_BLANK_BLACK]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_BLANK_WHITE]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_C]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_D]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_E]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_F]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_G]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_H]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_I]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_J]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_K]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_L]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_M]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_N]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_O]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_P]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_QU]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_R]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_S]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_T]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_U]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_V]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_W]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_WILDCARD]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_X]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_Y]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_LARGE_Z]);

    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_A]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_B]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_C]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_D]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_E]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_F]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_G]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_H]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_I]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_J]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_K]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_L]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_M]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_N]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_O]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_P]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_QU]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_R]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_S]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_T]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_U]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_V]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_W]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_WILDCARD]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_X]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_Y]);
    SDL_DestroyTexture(textureMap[TEXTURE_MAP_TILE_SMALL_Z]);


}


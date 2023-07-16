# ==============================================================================
# Makefile - Project build configuration
# ------------------------------------------------------------------------------
# Fighting Words - The Tile-Dropping, Word-Spelling, Battle Game
# Copyright (C) 2023  Kristoffer A. Wright
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
# ==============================================================================

OBJS = src/main.c \
	   build/obj/dict.o \
	   build/obj/entity.o \
	   build/obj/err.o \
	   build/obj/letter.o \
	   build/obj/mem.o \
	   build/obj/rand.o \
	   build/obj/render.o \
	   build/obj/res.o \
	   build/obj/tex.o

CC = gcc

COMPILE_FLAGS = -Wall \
				-Werror \
				-g

LINK_FLAGS = -lSDL2 \
			 -lSDL2_ttf

EX_NAME = build/fw

clean:
	rm -Rf build; mkdir build; mkdir build/obj

build/obj/%.o: src/%.c
	$(CC) -c -o $@ $< $(COMPILE_FLAGS) $(LINK_FLAGS)

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILE_FLAGS) $(LINK_FLAGS) -o $(EX_NAME)

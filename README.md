# Fighting Words
The Tile-Dropping, Word-Spelling, Battle Game

## Introduction

*Fighting Words* is an open-source tile-dropping game where the goal is not to 
make lines or match colors, but rather to spell words. As the game progresses, 
the player can earn powerups which can be used to help clear their own board, 
or--in multiplayer mode--ruin their opponent's.

Currently, *Fighting Words* is in a very early stage of development. The most
recent build, `v0.1-alpha`, exhibits rudimentary and incomplete single player
game mechanics.

As *Fighting Words* is an open-source project, contributions are always
encouraged. If you have a feature you would like to suggest or a bug you would
like to address, please feel free to fork this repo, make your changes, and 
submit a pull request. If you have any questions about the codebase, please send
me an email, and I will do my best to respond promptly.

## Quickstart

> **NOTE:** All build instructions are relative to my development machine, which
> happens to be running Ubuntu. Instructions may differ for your particular
> distro of choice. This code has not been tested on a Windows machine.

First, in order to build *Fighting Words*, you will need to install the `SDL`
and `SDL_ttf` libraries:

```bash
$ sudo apt-get install libsdl2-dev 
```

```bash
$ sudo apt-get install libsdl2-ttf-dev
```

Then, all you need to do is run the `Makefile`, and *Fighting Words* will
be compiled. 

```bash
$ make all
```

The output executable can be found in the newly created `build` folder.

```bash
$ build/fw
```

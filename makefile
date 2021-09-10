CC=gcc

CFLAGS=-Wall

SDL_I=/usr/local/Cellar/sdl2/2.0.16/include/
SDL_L=/usr/local/Cellar/sdl2/2.0.16/lib/

IMG_I=/usr/local/Cellar/sdl2_image/2.0.5/include/
IMG_L=/usr/local/Cellar/sdl2_image/2.0.5/lib/

LIBS=libSDL2-2.0.0 libSDL2_image-2.0.0
LIBS_PARAMS=$(LIBS:%=-l%)

HTS_I=./huskyTech1/

HTS_S=$(wildcard huskyTech1/*.cpp)

HTS_O := $(patsubst %.cpp,%.o,$(HTS_S))

INC=$(SDL_I) $(IMG_I) $(HTS_I)
INC_PARAMS=$(INC:%=-I%)

LDIR=$(SDL_L) $(IMG_L)
LDIR_PARAMS=$(LDIR:%=-L%)

all:
	$(CC) -o huskytch $(HTS_O) $(INC_PARAMS) $(LDIR_PARAMS) $(LIBS_PARAMS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
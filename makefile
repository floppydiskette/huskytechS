CC=g++

CFLAGS=-Wall

SDL_I=/usr/local/Cellar/sdl2/2.0.16/include/SDL2/
SDL_L=/usr/local/Cellar/sdl2/2.0.16/lib/

IMG_I=/usr/local/Cellar/sdl2_image/2.0.5/include/SDL2/
IMG_L=/usr/local/Cellar/sdl2_image/2.0.5/lib/

LIBS=SDL2-2.0.0 SDL2_image-2.0.0
LIBS_PARAMS=$(LIBS:%=-l%)

HTS_I=huskyTech1/

HTS_S=$(wildcard huskyTech1/*.cpp)

HTS_O := $(patsubst %.cpp,%.o,$(HTS_S))

INC=$(SDL_I) $(IMG_I) $(HTS_I)
INC_PARAMS=$(INC:%=-I%)

LDIR=$(SDL_L) $(IMG_L)
LDIR_PARAMS=$(LDIR:%=-L%)

huskytch: $(HTS_O)
	$(CC) -std=c++17 -o $@ $^ $(INC_PARAMS) $(LDIR_PARAMS) $(LIBS_PARAMS)

%.o: %.cpp
	$(CC) -std=c++17 -c $^ -o $@ $(INC_PARAMS) $(LDIR_PARAMS) $(LIBS_PARAMS)

clean:
	rm -rf $(TARGET) huskyTech1/*.o
PROGRAM=tower

#SYSTEM FILES
OBJS=src/main.o src/Game/game.o src/Graphic/sprite.o src/UI/button.o src/Game/level.o src/Graphic/map.o src/Graphic/drawAsset.o src/Graphic/renderer.o src/Graphic/sound.o src/Graphic/resource.o src/MapEditor/mapEditor.o 

#ENEMY FILES
OBJS+= src/Entity/Enemy/enemy.o src/Entity/Enemy/enemySpawn.o src/Entity/Enemy/enemyPlane.o src/Entity/Enemy/enemyLeader.o src/Entity/Enemy/enemyTank.o src/Entity/Enemy/enemyMedic.o src/Entity/Enemy/enemyRunner.o src/Entity/Enemy/enemyBrute.o

#TOWER FILES
OBJS+= src/Entity/Tower/tower.o src/Entity/Tower/freezingTower.o src/Entity/Tower/explosiveTower.o src/Entity/Tower/poisonTower.o src/Entity/Tower/comboTower.o src/Entity/Tower/shotgunTower.o

#EFFECT FILES
OBJS+= src/Entity/Effect/effect.o src/Entity/Effect/freezeEffect.o src/Entity/Effect/explosionEffect.o src/Entity/Effect/poisonEffect.o src/Entity/Effect/leadEffect.o src/Entity/Effect/healEffect.o

#OTHER ENTITIES FILES
OBJS+=src/Entity/entity.o src/Entity/Player/player.o 

CXX?=g++
TARGET?=$(shell $(CXX) -dumpmachine)

CXXFLAGS=-std=c++17 -O0 -g -Wall -Wextra -Wno-unused-parameter
CPPFLAGS=-Iinclude -Ithird_party/include -MMD
LDFLAGS=-Lthird_party/libs-$(TARGET)
LDLIBS=-lraylib

ifeq ($(TARGET),x86_64-linux-gnu)
LDLIBS+=-ldl -lpthread -lm -lstdc++fs
else ifeq ($(TARGET),x86_64-pc-cygwin)
LDLIBS+=-lgdi32
else ifeq ($(TARGET),wasm32-unknown-emscripten)
OPTIM_FLAGS=-Os
LDFLAGS+=-s ASYNCIFY
LDFLAGS+=-s USE_GLFW=3
LDFLAGS+=--preload-file assets
LDFLAGS+=-s ALLOW_MEMORY_GROWTH=1
EXT=.html
else ifeq ($(TARGET),x86_64-w64-mingw32)
LDLIBS+=-lgdi32 -lwinmm -lstdc++fs
CXXFLAGS+=-static
endif

DEPS=$(OBJS:.o=.d)

.PHONY: all clean

all: $(PROGRAM)$(EXT)

-include $(DEPS)

%.o: %.c
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

$(PROGRAM)$(EXT): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

build.tar.gz: $(PROGRAM) $(wildcard assets/*)
	tar czf build.tar.gz $(PROGRAM) assets

host: $(PROGRAM)$(EXT)
	python3 -m http.server 8000

clean:
	rm -f $(OBJS) $(DEPS) $(PROGRAM) build.tar.gz
	rm -f $(PROGRAM).html $(PROGRAM).js $(PROGRAM).data $(PROGRAM).wasm

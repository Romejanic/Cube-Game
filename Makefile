CXX?=clang
CXXFLAGS?=-Wall

LIBS=
BINARY_NAME=cubegame

# Detect OS
OS=$(shell uname)
ifeq ($(OS), Darwin)
	# Mac Library flags
	LIBS += -L/usr/local/lib -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif
ifeq ($(OS), Linux)
	# Linux library flags
	LIBS += -lglfw -lGL
endif

all: main

# TODO: Fewer subdirs.
SRCS := \
src/Utils.cpp \
src/camera/Camera.cpp \
src/gl/Shader.cpp \
src/Keys.cpp \
src/main.cpp \
src/renderer/Chunk.cpp \
src/renderer/Renderer.cpp \
src/renderer/Window.cpp \
src/renderer/WorldRenderer.cpp \
src/world/Block.cpp \
src/world/World.cpp

OBJS := $(SRCS:%.cpp=%.o)

main: $(OBJS)
	$(CXX) -o $(BINARY_NAME) $(OBJS) $(LIBS)

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINARY_NAME)

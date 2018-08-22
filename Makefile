CXX?=clang
CXXFLAGS?=-Wall

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
	$(CXX) -o $@ $(OBJS) -lGL -lglfw

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS) main

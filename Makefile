CXX = g++
CXXFLAGS = -std=c++17 -Wall `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

SRCS = main.cpp
OUT = sorting_visualizer

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OUT) $(LDFLAGS)

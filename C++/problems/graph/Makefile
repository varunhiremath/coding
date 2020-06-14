IFLAGS = -I../../data_structures/graph/

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%.x)

all: $(BINS)

%.x: %.cpp
	g++ $< -o $@ $(IFLAGS)

clean:
	rm $(BINS) a.out

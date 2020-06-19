IFLAGS = -I../../data_structures/tree/

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%.x)

all: $(BINS)

%.x: %.cpp
	g++ $< -o $@ $(IFLAGS)

clean:
	rm -f $(BINS)

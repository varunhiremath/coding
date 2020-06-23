IFLAGS = -I../../data_structures/tree/

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%.x)
OUTS := $(SRCS:%.cpp=%.out)

all: $(BINS)
run: $(OUTS)

%.x: %.cpp
	g++ $< -o $@ $(IFLAGS)

%.out: %.x
	./$< > $@ 2>&1

clean:
	rm -f $(BINS) $(OUTS)

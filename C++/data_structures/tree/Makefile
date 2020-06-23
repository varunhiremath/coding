SRCS := $(wildcard test*.cpp)
BINS := $(SRCS:%.cpp=%.x)
OUTS := $(SRCS:%.cpp=%.out)

all: $(BINS)
run: $(OUTS)

%.x: %.cpp
	g++ $< -o $@

%.out: %.x
	./$< > $@ 2>&1

clean:
	rm -f $(BINS) $(OUTS)

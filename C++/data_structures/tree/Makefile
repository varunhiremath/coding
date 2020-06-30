SRCS := $(wildcard test*.cpp)
HDRS := $(wildcard *.h)
BINS := $(SRCS:%.cpp=%.x)
OUTS := $(SRCS:%.cpp=%.out)

all: $(BINS)
run: $(OUTS)

%.x: %.cpp $(HDRS)
	g++ $< -o $@

%.out: %.x
	./$< > $@ 2>&1

clean:
	rm -f $(BINS) $(OUTS)

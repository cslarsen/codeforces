CXXFLAGS := -W -Wall -O3 -fomit-frame-pointer
TARGETS := 1b

test: all
	@echo Result on left, expected value on right
	@time -p ./1b < in | diff -y -W 72 --suppress-common-lines - expected

all: $(TARGETS)

show:
	@cat $(TARGETS).cpp

clean:
	rm -f $(TARGETS)

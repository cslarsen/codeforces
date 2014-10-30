CXXFLAGS := -W -Wall -O3 -march=native -mtune=native -fomit-frame-pointer
TARGET := 1c

test: all
	@time -p ./$(TARGET) < in | \
		diff -y -W 72 --suppress-common-lines - expected

all: $(TARGET)

show:
	@cat $(TARGET).cpp

clean:
	rm -f $(TARGET)

TARGET = find-duplicates

DEBUG = 1

ifeq ($(DEBUG), 1)
    CFLAGS += -g3 -O0
else
    CFLAGS += -O3
endif

SOURCES = find-duplicates.c	
SAMPLE_INPUT = sample-input.txt
SAMPLE_OUTPUT = sample-output.txt

OBJECTS = $(SOURCES:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

clean:
	-rm -f $(OBJECTS) $(TARGET)

test: $(TARGET)
	./$(TARGET) $(SAMPLE_INPUT) | sort | cmp $(SAMPLE_OUTPUT)

help:
	@echo "TODO"

all: $(TARGET)

.DEFAULT_GOAL := all

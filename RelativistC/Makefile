CC = gcc
CFLAGS = -O3 -std=c11 -Wall -Wextra -fopenmp -Iinclude
LDFLAGS = -fopenmp
SRCDIR = src
BINDIR = bin
TARGET = $(BINDIR)/relativistc

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(SRCDIR)/%.o,$(SOURCES))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

run: all
	$(TARGET) -n 100000 -t 4

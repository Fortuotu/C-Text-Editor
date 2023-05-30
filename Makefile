
CC = gcc
CFLAGS = -Wall -Werror -Iinclude
LDFLAGS = -lncurses

SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

TARGET = $(BINDIR)/main.out

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(wildcard $(BUILDDIR)/*) $(TARGET)

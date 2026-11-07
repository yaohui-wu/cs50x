# CS50 C compiler and linker settings.
CC := clang
CFLAGS := -ferror-limit=1 -gdwarf-4 -ggdb3 -O0 -std=c11 \
          -Wall -Werror -Wextra \
          -Wno-gnu-folding-constant -Wno-sign-compare \
          -Wno-unused-parameter -Wno-unused-variable \
          -Wno-unused-but-set-variable -Wshadow
LDLIBS := -lcrypt -lcs50 -lm

# Program name, source files, and output excutable.
PROGRAM := readability
SRCS := readability.c
HEADERS := $(wildcard *.h)
EXE := build/$(PROGRAM)

.PHONY: all clean $(PROGRAM)
all: $(EXE)

# Allow building the executable by its program name.
$(PROGRAM): $(EXE)

# Build the executable without printing the compiler command.
$(EXE): $(SRCS) $(HEADERS) | build
	@$(CC) $(CFLAGS) -o $@ $(SRCS) $(LDLIBS)

build:
	@mkdir -p $@

clean:
	@rm -f $(EXE)

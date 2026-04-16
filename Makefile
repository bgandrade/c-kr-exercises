CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -Werror -pedantic
LDFLAGS ?=
SRC_DIR := src
BIN_DIR := bin

EXERCISES := $(sort $(basename $(notdir $(shell find $(SRC_DIR) -type f -name '*.c'))))

.PHONY: all list run clean $(EXERCISES)

all: list

list:
	@printf '%s\n' $(EXERCISES)

$(EXERCISES): %: $(BIN_DIR)/%

$(BIN_DIR)/%:
	@mkdir -p $(BIN_DIR)
	@src=$$(find $(SRC_DIR) -type f -name '$*.c' -print -quit); \
	if [ -z "$$src" ]; then \
		printf 'error: exercise %s not found\n' '$*' >&2; \
		exit 1; \
	fi; \
	printf 'Compiling %s -> %s\n' "$$src" "$@"; \
	$(CC) $(CFLAGS) $$src -o $@ $(LDFLAGS)

run:
	@if [ -z "$(EX)" ]; then \
		printf 'usage: make run EX=ex-1-01\n' >&2; \
		exit 1; \
	fi
	@$(MAKE) --no-print-directory $(EX)
	@./$(BIN_DIR)/$(EX)

clean:
	@rm -rf $(BIN_DIR)
	@mkdir -p $(BIN_DIR)
	@: > $(BIN_DIR)/.gitkeep

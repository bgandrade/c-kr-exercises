CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -Werror -pedantic
LDFLAGS ?=
SRC_DIR := src
BIN_DIR := bin

SRC_FILES := $(sort $(shell find $(SRC_DIR) -type f -name '*.c'))
EXERCISES := $(basename $(notdir $(SRC_FILES)))

.PHONY: all list run clean $(EXERCISES)

all: list

list:
	@printf '%s\n' $(EXERCISES)

$(EXERCISES): %: $(BIN_DIR)/%

define BUILD_EXERCISE
$(BIN_DIR)/$(1): $(2)
	@mkdir -p $(BIN_DIR)
	@printf 'Compiling %s -> %s\n' "$$<" "$$@"
	@$(CC) $(CFLAGS) $$< -o $$@ $(LDFLAGS)
endef

$(foreach src,$(SRC_FILES),$(eval $(call BUILD_EXERCISE,$(basename $(notdir $(src))),$(src))))

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

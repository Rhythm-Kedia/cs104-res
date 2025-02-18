SRC = $(shell find src/ -name "*.c")
OBJ = $(addprefix obj/, $(notdir $(SRC:.c=.o)))

$(info SRC_FILES = $(SRC))
$(info OBJ = $(OBJ))

all: udp-test

# Compiler flags
CFLAGS = -Wall -Wextra

# The object files rule
obj/%.o: src/%.c
	@mkdir -p obj   # Create obj directory if it doesn't exist
	cc $(CFLAGS) -c $< -o $@

# The udp-test target rule
udp-test: $(OBJ)
	cc $(OBJ) -o udp-test -lm

# Clean up the object files and executable
clean:
	rm -rf obj udp-test


# an MWE Makefile

# Use bash as the shell interpreter
SHELL := /bin/bash

# Phony targets are not actual files but labels for commands
.PHONY: all clean build install test help

# Default target
all: build

# Build target
build:
	@echo "Building the project..."
	for f in main?.txt; do \
		echo $$f $${f%.txt}.svg; \
	done


# Clean target to remove build artifacts
clean:
	@echo "Cleaning the project..."
	# Add your clean commands here

# Install target to install the project
install:
	@echo "Installing the project..."
	# Add your install commands here

# Test target to run tests
test:
	@echo "Running tests..."
	# Add your test commands here

# Help target to display the help message
help:
	@echo "Makefile targets:"
	@echo "  all      - Default target, builds the project"
	@echo "  build    - Build the project"
	@echo "  clean    - Clean the project"
	@echo "  install  - Install the project"
	@echo "  test     - Run tests"
	@echo "  help     - Display this help message"
# Main Makefile - delegates to src/build/Makefile
# This provides a convenient entry point for the project

.PHONY: all clean test test_check gcov_report install clean_all test_clean check_clean install_clean

# Default target
all:
	@echo "Building s21_decimal library..."
	@cd src/build && $(MAKE) all

# Build library
s21_decimal.a:
	@cd src/build && $(MAKE) s21_decimal.a

# Run tests
test:
	@cd src/build && $(MAKE) test

test_check:
	@cd src/build && $(MAKE) test_check

# Coverage report
gcov_report:
	@cd src/build && $(MAKE) gcov_report

# Install library
install:
	@cd src/build && $(MAKE) install

# Cleanup
clean:
	@cd src/build && $(MAKE) clean

clean_all:
	@cd src/build && $(MAKE) clean_all

# Combined targets
test_clean:
	@cd src/build && $(MAKE) test_clean

check_clean:
	@cd src/build && $(MAKE) check_clean

install_clean:
	@cd src/build && $(MAKE) install_clean

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build library and run tests"
	@echo "  s21_decimal.a - Build library only"
	@echo "  test         - Run basic tests"
	@echo "  test_check   - Run Check library tests"
	@echo "  gcov_report  - Generate coverage report"
	@echo "  install      - Install library to system"
	@echo "  clean        - Clean temporary files"
	@echo "  clean_all    - Clean all files including gcov"
	@echo "  test_clean   - Run tests and clean up"
	@echo "  check_clean  - Run Check tests and clean up"
	@echo "  install_clean - Install and clean up"
	@echo "  help         - Show this help"
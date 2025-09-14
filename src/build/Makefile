CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
TEST_FLAGS = -lcheck -lm -lpthread

# Directories
SRC_DIR = ..
BUILD_DIR = .
TMP_DIR = ../tmp
DOCS_DIR = ../docs
TESTS_DIR = ../tests

# Source files
SRC_FILES = $(SRC_DIR)/s21_helpers.c \
            $(SRC_DIR)/s21_is_less.c \
            $(SRC_DIR)/s21_is_greater.c \
            $(SRC_DIR)/s21_is_less_or_equal.c \
            $(SRC_DIR)/s21_is_greater_or_equal.c \
            $(SRC_DIR)/s21_from_int_to_decimal.c \
            $(SRC_DIR)/s21_from_decimal_to_int.c

# Object files (in tmp directory)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(TMP_DIR)/%.o)

# Library
LIBRARY = $(BUILD_DIR)/s21_decimal.a

# Test files
TEST_FILE = $(TESTS_DIR)/test_simple.c
CHECK_TEST_FILE = $(TESTS_DIR)/test_comparison.c

# Coverage files
GCOV_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(TMP_DIR)/%.gcno) $(SRC_FILES:$(SRC_DIR)/%.c=$(TMP_DIR)/%.gcda) $(SRC_FILES:$(SRC_DIR)/%.c=$(TMP_DIR)/%.gcov)
COVERAGE_DIR = $(TMP_DIR)/coverage

.PHONY: all clean test test_check s21_decimal.a gcov_report install clean_all

all: $(LIBRARY) test

$(LIBRARY): $(OBJ_FILES)
	ar rcs $(LIBRARY) $(OBJ_FILES)

$(TMP_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(TMP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIBRARY)
	@mkdir -p $(TMP_DIR)
	$(CC) $(CFLAGS) $(TEST_FILE) $(LIBRARY) -o $(TMP_DIR)/test_comparison
	$(TMP_DIR)/test_comparison
	@echo "✓ Basic tests completed successfully"

test_check: $(LIBRARY)
	@mkdir -p $(TMP_DIR)
	$(CC) $(CFLAGS) $(CHECK_TEST_FILE) $(LIBRARY) $(TEST_FLAGS) -o $(TMP_DIR)/test_check_comparison
	$(TMP_DIR)/test_check_comparison
	@echo "✓ Check tests completed successfully"

gcov_report: clean
	@echo "Building with coverage flags..."
	@mkdir -p $(TMP_DIR)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $(SRC_FILES)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(CHECK_TEST_FILE) $(SRC_FILES) $(TEST_FLAGS) -o $(TMP_DIR)/test_gcov
	$(TMP_DIR)/test_gcov
	@echo "Generating coverage report..."
	@mkdir -p $(COVERAGE_DIR)
	gcov $(SRC_FILES)
	lcov --capture --directory $(TMP_DIR) --output-file $(COVERAGE_DIR)/coverage.info
	genhtml $(COVERAGE_DIR)/coverage.info --output-directory $(COVERAGE_DIR)/html
	@echo "Coverage report generated in $(COVERAGE_DIR)/html/index.html"
	@echo "✓ Coverage report completed"

install: $(LIBRARY)
	@echo "Installing library..."
	@mkdir -p /usr/local/lib
	@mkdir -p /usr/local/include
	cp $(LIBRARY) /usr/local/lib/
	cp $(SRC_DIR)/s21_decimal.h /usr/local/include/
	@echo "✓ Library installed successfully"

clean:
	rm -f $(OBJ_FILES) $(LIBRARY) $(TMP_DIR)/test_comparison $(TMP_DIR)/test_check_comparison $(TMP_DIR)/test_gcov
	rm -f $(GCOV_FILES)
	rm -rf $(COVERAGE_DIR)

clean_all: clean
	rm -f $(TMP_DIR)/*.gcno $(TMP_DIR)/*.gcda $(TMP_DIR)/*.gcov
	rm -rf $(TMP_DIR)/coverage/
	@echo "✓ All files cleaned"

# Auto-clean after successful build and test
install_clean: install clean_all
	@echo "✓ Installation and cleanup completed"

test_clean: test clean_all
	@echo "✓ Testing and cleanup completed"

check_clean: test_check clean_all
	@echo "✓ Check testing and cleanup completed"

# Individual function compilation for testing
test_helpers: $(SRC_DIR)/s21_helpers.o
	@echo "Helpers compiled successfully"

test_comparison: $(SRC_DIR)/s21_is_less.o $(SRC_DIR)/s21_is_greater.o $(SRC_DIR)/s21_is_less_or_equal.o $(SRC_DIR)/s21_is_greater_or_equal.o $(SRC_DIR)/s21_helpers.o
	@echo "Comparison functions compiled successfully"

test_conversion: $(SRC_DIR)/s21_from_int_to_decimal.o $(SRC_DIR)/s21_from_decimal_to_int.o $(SRC_DIR)/s21_helpers.o
	@echo "Conversion functions compiled successfully"

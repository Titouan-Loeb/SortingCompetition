# Compiler and flags
CXX := g++
# Flags for the compiler
CXXFLAGS := -std=c++11 -Wall -Wextra
CXXFLAGS_RELEASE := -O3
CXXFLAGS_DEBUG := -g

# Directories
SRC_DIR := src
INC_DIR := include
BASE_BUILD_DIR := build
BUILD_DIR := $(BASE_BUILD_DIR)/obj
BUILD_RELEASE_DIR := $(BASE_BUILD_DIR)/release
BUILD_DEBUG_DIR := $(BASE_BUILD_DIR)/debug
BIN_DIR := bin
TESTDIR := test

# Target executable names
BIN_NAME := SortingCompetion
TARGET := $(BIN_DIR)/$(BIN_NAME)
TARGET_RELEASE := $(BIN_DIR)/$(BIN_NAME)-release
TARGET_DEBUG := $(BIN_DIR)/$(BIN_NAME)-debug
TARGET_TEST := $(BIN_DIR)/$(BIN_NAME)-test

# Find all source files in the src directory and its subdirectories
SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp")

# Find all source files in the src directory and its subdirectories
TESTS := $(shell find $(TESTDIR) -type f -name "*.cpp")

# Derive object file names from source file names and place them in the build directory
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.cpp=.o))
OBJECTS_RELEASE := $(patsubst $(SRC_DIR)/%,$(BUILD_RELEASE_DIR)/%,$(SOURCES:.cpp=.o))
OBJECTS_DEBUG := $(patsubst $(SRC_DIR)/%,$(BUILD_DEBUG_DIR)/%,$(SOURCES:.cpp=.o))

# Include directories for header files (including subdirectories)
INCLUDES := -I$(INC_DIR) $(shell find $(INC_DIR) -type d | sed 's/^/-I/')

# Colors for terminal output
GREEN := \033[1;32m
CYAN := \033[1;36m
RESET := \033[0m

build: clean $(TARGET)

# Rule to build the target
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo "$(CYAN)Linking$(RESET) $(GREEN)$@$(RESET)"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(CYAN)Compiling$(RESET) $(GREEN)$<$(RESET)"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# release: CXXFLAGS += $(CXXFLAGS_RELEASE)
release: $(TARGET_RELEASE)

# Rule to build the target in release mode
$(TARGET_RELEASE): $(OBJECTS_RELEASE)
	@mkdir -p $(BIN_DIR)
	@echo "$(CYAN)Linking$(RESET) $(GREEN)$@$(RESET)"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# Rule to build object files in release mode
$(BUILD_RELEASE_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(CYAN)Compiling$(RESET) $(GREEN)$<$(RESET)"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

debug: $(TARGET_DEBUG)

# Rule to build the target in release mode
$(TARGET_DEBUG): $(OBJECTS_DEBUG)
	@mkdir -p $(BIN_DIR)
	@echo "$(CYAN)Linking$(RESET) $(GREEN)$@$(RESET)"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# Rule to build object files
$(BUILD_DEBUG_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(CYAN)Compiling$(RESET) $(GREEN)$<$(RESET)"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

all: build release debug

clean:
	@echo "$(CYAN)Cleaning$(RESET) $(GREEN)build$(RESET) directory"
	@rm -rf $(BASE_BUILD_DIR)

fclean: clean
	@echo "$(CYAN)Cleaning$(RESET) $(GREEN)bin$(RESET) directory"
	@rm -rf $(TARGET) $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re release debug
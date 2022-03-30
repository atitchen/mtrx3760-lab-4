CC = g++
CFLAGS = -g -Iinclude -Wall
LIBS =

TARGET = output

# Use a Source and Object Directory
# Compile all sources in the source directory
SRC_DIR = src
OBJ_DIR = obj


# Grab paths of all sources and objects
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(subst .cpp,.o,$(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS)))

# Build Targets
all: $(OBJ_DIR) $(TARGET)

# Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Object Directory
$(OBJ_DIR):
	mkdir $@

# Main Target Output
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean bear generate
# Clean
clean:
	$(RM) $(TARGET)
	$(RM) -r $(OBJ_DIR)
	$(RM) output.txt

# Run Bear to generate compile_commands.json for clangd
bear:
	$(MAKE) clean
	bear -- $(MAKE)

# Make and generate output text files
generate:
	$(MAKE)
	./$(TARGET) > output.txt

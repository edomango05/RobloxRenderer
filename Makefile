CC := g++
CFLAGS := -Wall -g
TARGET := rbxrender
BUILDDIR := bin
SRCDIR := src
LIBS += -lpugixml

SRCS := $(wildcard $(SRCDIR)/**/*.cpp $(SRCDIR)/main.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

all: dist $(BUILDDIR)/$(TARGET)

dist: 
	mkdir -p bin/libs
	
$(BUILDDIR)/$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CC) $(CFLAGS) -c $< -o $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$<)

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
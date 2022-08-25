NAME := rbxlxrender
IDIR := src/include/
LDIR := src/lib/

all: build/rbxlxrender

build/rbxlxrender: main.o rbxlx_parser.o
	g++ -o build/rbxlxrender main.o rbxlx_parser.o

rbxlx_parser.o: $(LDIR)rbxlx_parser.cpp $(IDIR)rbxlx_parser.h
	g++ -I$(IDIR) /usr/include/libxml -c $(LDIR)rbxlx_parser.cpp -lxml2

main.o: src/main.cpp $(IDIR)/rbxlx_parser.h
	g++ -I$(IDIR) -c src/main.cpp -lxml2

clean:
	rm -f *.o
	rm -f build/rbxlxrender
	rm -f *~

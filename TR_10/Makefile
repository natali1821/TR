ANTLR = antlr4
CPP = g++
CPPFLAGS = -std=c++17
ANTLRFLAGS = -Dlanguage=Cpp -o src
INCLUDE = -I . -I /usr/include/antlr4-runtime
LIBS = -lantlr4-runtime

all: build

build: generate compile

generate:
	$(ANTLR) $(ANTLRFLAGS) -visitor -listener gram.g4

compile:
	$(CPP) $(CPPFLAGS) -o gram main.cpp src/gramLexer.cpp src/gramParser.cpp  src/gramBaseListener.cpp src/gramListener.cpp src/gramBaseVisitor.cpp  src/gramVisitor.cpp $(LIBS) $(INCLUDE)

clean:
	rm -rf src/*.cpp src/*.h gram

.PHONY: all build generate compile clean

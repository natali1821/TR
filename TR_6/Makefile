CXX = g++
CXXFLAGS = -std=c++17      

all: Translator

Translator: Translator.o Parser.o 
	$(CXX) Translator.o Parser.o -o Translator

Translator.o: Translator.cpp
	$(CXX) $(CXXFLAGS) -c Translator.cpp   

Parser.o: Parser.cpp
	$(CXX) $(CXXFLAGS) -c Parser.cpp   

clean:
	rm -rf *.o Translator

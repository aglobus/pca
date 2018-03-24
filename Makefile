CXX=g++
CXXFLAGS= -IEigen -std=c++11 -pedantic -Wno-c++11-extensions
LDFLAGS=

.PHONY: all debug clean

all:
	@$(CXX) $(CXXFLAGS) *.cpp $(LDFLAGS) -o assignment3

debug:
	@$(CXX) $(CXXFLAGS) -ggdb *.cpp $(LDFLAGS) -o assignment3

clean:
	@rm assignment3

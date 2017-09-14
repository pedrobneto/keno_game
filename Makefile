# commands
CXX = g++
DEL = rm

# options
DEBUG = -g
WARNING = -Wall
STD = -std=c++11
OPTIONSCXX = $(STD) $(WARNING)

# directories
DECLRDIR = -I . -I ./include
SRCDIR = ./src/
BINDIR = ./bin/


### executable
keno: main.o funcoesaux.o kenobet.o
	$(CXX) $(BINDIR)main.o $(BINDIR)funcoesaux.o $(BINDIR)kenobet.o -o keno $(OPTIONSCXX)

### obj main
main.o: $(SRCDIR)main.cpp
	$(CXX) $(SRCDIR)main.cpp -c -o $(BINDIR)main.o $(OPTIONSCXX) $(DECLRDIR)
	
### obj funcoesaux
funcoesaux.o: $(SRCDIR)funcoesaux.cpp
	$(CXX) $(SRCDIR)funcoesaux.cpp -c -o $(BINDIR)funcoesaux.o $(OPTIONSCXX) $(DECLRDIR)

### obj kenobet
kenobet.o: $(SRCDIR)kenobet.cpp
	$(CXX) $(SRCDIR)kenobet.cpp -c -o $(BINDIR)kenobet.o $(OPTIONSCXX) $(DECLRDIR)


### clear objects
clean:
	$(DEL) ./keno
	$(DEL) $(BINDIR)*.o
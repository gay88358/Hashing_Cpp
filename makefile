INC_DIR = include
SRC = src
TARGET = hash

all: $(TARGET)

$(TARGET): mainHash.o hash.o
ifeq (${OS}, Windows_NT) 
	g++ -o $(TARGET) mainHash.o hash.o   -lgtest
else
	g++ -o $(TARGET) mainHash.o hash.o -lgtest -lpthread
endif

mainHash.o: mainHash.cpp
	g++ -std=gnu++0x -c mainHash.cpp

main.o: main.cpp 
	g++ -std=gnu++0x -c main.cpp

hash.o: $(INC_DIR)/hash.h $(SRC)/hash.cpp
	g++ -std=gnu++0x -c $(SRC)/hash.cpp

clean:	
ifeq (${OS}, Windows_NT) 
	del *.o *.exe
else
	rm -f *.o $(TARGET)
endif
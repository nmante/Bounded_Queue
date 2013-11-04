CC=g++
DEBUG=-g
EXE=NiiQueueKPCB
INC=inc
SRC=src
BIN=bin


all: Queue.o TestSuite.o $(SRC)/main.cpp
	$(CC) $(DEBUG) -I$(INC) $(SRC)/main.cpp $(BIN)/Queue.o $(BIN)/TestSuite.o -o $(EXE)

TestSuite.o: $(SRC)/TestSuite.cpp
	$(CC) $(DEBUG) -I$(INC) -c $(SRC)/TestSuite.cpp
	mv *.o $(BIN)

Queue.o: $(SRC)/Queue.cpp
	$(CC) $(DEBUG) -I$(INC) -c $(SRC)/Queue.cpp
	mv *.o $(BIN)

clean:
	rm -rf $(BIN)/*.o $(EXE) *.dSYM


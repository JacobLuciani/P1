CC=g++
CFLAGS=-g
EX=scanner
DEPS=inputProcessing.h Scanner.h token.h
OBJ=inputProcessing.o Scanner.o token.o

all: $(EX)

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(EX): testScanner.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : clean 
clean :
	rm -rf *.o $(EX)
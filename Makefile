OBJS =  main.o helperFunctions.o statistics.o reorderBuffer.o instruction.o memory.o pipeline.o IQueue.o execute.o fetchUnit.o registerFile.o exception.o
OUT = run
CC = g++
FLAGS = -g -c
LFLAGS = -lstdc++

output: $(OBJS) 
			#$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
			$(CC) -o $(OUT) $(OBJS) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

helperFunctions.o: helperFunctions.cpp
	$(CC) $(FLAGS) helperFunctions.cpp

statistics.o: statistics.cpp
	$(CC) $(FLAGS) statistics.cpp

reorderBufffer.o: reorderBuffer.cpp
	$(CC) $(FLAGS) reorderBuffer.cpp

instruction.o: instruction.cpp
	$(CC) $(FLAGS) instruction.cpp

memory.o: memory.cpp
	$(CC) $(FLAGS) memory.cpp

pipeline.o: pipeline.cpp
	$(CC) $(FLAGS) pipeline.cpp

IQueue.o: IQueue.cpp
	$(CC) $(FLAGS) IQueue.cpp

execute.o: execute.cpp
	$(CC) $(FLAGS) execute.cpp

fetchUnit.o: fetchUnit.cpp
	$(CC) $(FLAGS) fetchUnit.cpp

registerFile.o: registerFile.cpp
	$(CC) $(FLAGS) registerFile.cpp
	
exception.o: exception.cpp
	$(CC) $(FLAGS) exception.cpp
	
clean: 
	rm -f $(OBJS) $(OUT)



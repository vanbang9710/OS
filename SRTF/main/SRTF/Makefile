CPPFLAGS=
CFLAGS=
CC=g++
sjf: main.o srtf.o
	$(CC) -o srtf main.o srtf.o
%.o : %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@	
clean:
	rm -rf *.o *~ sjf
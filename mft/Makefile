CPPFLAGS=
CFLAGS=
CC=g++
mft: main.o mft.o
	$(CC) -o mft main.o mft.o
%.o : %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@	
clean:
	rm -rf *.o *~ mft
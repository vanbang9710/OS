CPPFLAGS=
CFLAGS=
CC=g++
fifo: main.o fifo.o
	$(CC) -o fifo main.o fifo.o
%.o : %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@	
clean:
	rm -rf *.o *~ fifo
CPPFLAGS=
CFLAGS=
CC=g++
sjf: main.o resourcerequest.o
	$(CC) -o resourcerequest main.o resourcerequest.o
%.o : %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@	
clean:
	rm -rf *.o *~ resourcerequest
CPPFLAGS=
CFLAGS=
CC=g++
extenta : main.o ExtentA.o
	$(CC) -m64 -o extenta main.o ExtentA.o
%.o : %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@	
clean:
	rm -rf *.o *~ extenta
	

CPPFLAGS=
CFLAGS=
CC=g++
all: producer consumer

producer: producer.o sem_util.o
	$(CC) -o producer producer.o sem_util.o
consumer: consumer.o sem_util.o
	$(CC) -o consumer consumer.o sem_util.o
%.o : %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@	
clean:
	rm -rf *.o *~ consumer producer 

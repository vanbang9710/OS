//Nguyen Van Bang 20020002
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "common.h"

int main(int	argc, char* argv[])
{
	int	shmid, semid, sendval = 0;
	buf_t* buf = NULL;
	struct	sembuf	sem;
	union	semun {
		int              val;    /* Value for SETVAL */
		struct semid_ds* buf;    /* Buffer for IPC_STAT, IPC_SET */
		unsigned short* array;  /* Array for GETALL, SETALL */
		struct seminfo* __buf;  /* Buffer for IPC_INFO
										   (Linux-specific) */
	} arg;

	shmid = shmget(SHMKEY, sizeof(buf_t), IPC_CREAT | 0600);
	if (shmid < 0) {
		perror("Cannot create shared memory");
		return(1);
	}
	buf = (buf_t*)shmat(shmid, NULL, 0600 & ~SHM_RDONLY);
	if (buf == NULL) {
		perror("Cannot attach shared memory");
		return(2);
	}
	// Get semaphore
	semid = semget(SEMKEY, 1, IPC_CREAT | 0600);
	if (semid < 0) {
		perror("Cannot create semaphore");
		return(2);
	}

	// Init semaphore value	
	arg.val = 1;
	if (semctl(semid, 0, SETVAL, arg) < 0) {
		perror("semwriter: Cannot initialize semaphore value");
		return(3);
	}

	/* Init the buffer */
	buf->done = 0;
	buf->in = 0;
	buf->out = 0;
	buf->count = 0;

	FILE* fin = fopen("input.dat", "rb");
	while (1) {		// Both parent and child process run

		while (buf->count >= MAXSIZE);
		//usleep(50000);
		sem_wait(semid, &sem, ~IPC_NOWAIT);

		// Critical section
		char c;
		size_t readbyte = fread(&c, 1, 1, fin);
		if (readbyte == 1) {
			buf->buffer[buf->in] = c;
			printf("count %d position %d value %c\n", buf->count, buf->in, buf->buffer[buf->in]);
			buf->in = (buf->in + 1) % MAXSIZE;
			buf->count++;
		}
		else {
			buf->done = 1;
			printf("Done Done Done Done Done Done Done Done Done Done Done Done Done Done Done Done\n");
		}

		sem_signal(semid, &sem, ~IPC_NOWAIT);
		if (buf->done) {
			break;
		}
	}
}

/* -- EOF --- */


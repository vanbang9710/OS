//Nguyen Van Bang 20020002
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "common.h"

int main(int argc, char* argv[])
{
	int	semid, shmid, i = 0, j;
	buf_t* buf = NULL;
	struct	sembuf	sem;

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
	FILE* fout = fopen("output.dat", "wb+");
	while (1) {
		while (buf->count == 0) {
			if (buf->done) {
				break;
			}
		}
		if (buf->done && buf->count == 0) {
			fclose(fout);
			break;
		}
		//usleep(50000);
		sem_wait(semid, &sem, ~IPC_NOWAIT);
		char c = buf->buffer[buf->out];
		printf("%c\n", c);
		fwrite(&c, 1, 1, fout);
		buf->out = (buf->out + 1) % MAXSIZE;
		buf->count--;
		sem_signal(semid, &sem, ~IPC_NOWAIT);
	}
}

/* -- EOF --- */

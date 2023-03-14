#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
//////////////////////////////////
int	sem_signal(int semid, struct sembuf *sem, int flag)
{
	// Unlock resource
	sem->sem_num = 0;
	sem->sem_op = 1;
	sem->sem_flg = flag;
	if (semop(semid, sem, 1) < 0) {
		perror("semreader: Cannot increase sem value");
		return(-1);
	}
	else return(0);
}
//////////////////////////////////
int	sem_wait(int semid, struct sembuf *sem, int flag)
{
	// Lock resource
	sem->sem_num = 0;
	sem->sem_op = -1;
	sem->sem_flg = flag;
	if (semop(semid, sem, 1) < 0) {
		perror("semwriter: Cannot decrease sem value");
		return(-1);
	}
	else return(0);
}
//////////////////////////////////

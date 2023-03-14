#ifndef COMMON_H
#define COMMON_H
#include <unistd.h>

#define	SHMKEY	4
#define	SEMKEY	4
#define	MAXSIZE	8
#define	ASLEEP	300000
typedef struct {
	int done;        //Sent all file content
	int	in, out;	// Vi tri doc, ghi trong buffer
	int	count;		// So luong phan tu trong buffer
	char	buffer[MAXSIZE];// Buffer
} buf_t;
int	sem_signal(int semid, struct sembuf*, int flag);
int	sem_wait(int semid, struct sembuf*, int flag);
#endif

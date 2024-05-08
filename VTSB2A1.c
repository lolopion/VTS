#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int semId;
int semId2;
int init_sem();
void P(int semNum, int semNum2);
void V(int semNum, int senNum2);
void Essen(int g);

int init_sem(){
 int sem_key, sem_id;
 if ((sem_key =ftok("/home/lars",'1'))<0){
   perror("Error in ftok");
   exit(1);
 }

 if ((sem_id = semget(sem_key, 1 , IPC_CREAT|0666))<0){
   perror("Error in semget");
   exit(1);
 }

 if ((semctl(sem_id, 0, SETVAL, 1)<0){
     perror("Error in semctl");
     exit(1);
 }
 return sem_id;
}  

void P(int semNum, int semNum2){
  struct sembuf semaphore, semaphore2;
  semaphore.sem_num = semNum;
  semaphore.sem_op = -1;
  semaphore.sem_flg =~(IPC_NOWAIT|SEM_UNDO);
  semaphore2.sem_num = semNum2;
  semaphore2.sem_op = -1;
  semaphore2.sem_flg =~(IPC_NOWAIT|SEM_UNDO);

    if(semop(semId, semId2, &semaphore, &semaphore2, -1)){
      perror("error in semop P()");
      exit(1);
    }
}

void V(int semNum, int semNum2){
  struct sembuf semaphore, semaphore2;
  semaphore.sem_num = semNum;
  semaphore.sem_op = 1;
  semaphore.sem_flg =~(IPC_NOWAIT|SEM_UNDO);
  semaphore2.sem_num = semNum2;
  semaphore2.sem_op = -1;
  semaphore2.sem_flg =~(IPC_NOWAIT|SEM_UNDO);

    if(semop(semId, semId2, &semaphore, &semaphore2, 1)){
      perror("error in semop V()");
      exit(1);
    }
}

void Essen(int g){
  printf("Sohnprozess %d beginnt zu Essen", g);
  sleep(rand());
  printf("Sohnprozess %d ist fertig mit Essen", g); 
}

int main(){
  for(int process=0; process<5;process++){
  P_id=fork();
  if(P_id==-1){
    perror("Fork failed");
    exit(1);
  } else if (P_id == 0){
    printf("child process %d (%d) started\n", process, getpid());
    P(S1,S2);
    Essen(process);
    V(S1,S2);
    exit(0);
}


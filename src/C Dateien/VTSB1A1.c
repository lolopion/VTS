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
int init_sem();
void P(int semNum);
void V(int semNum);

void un_kritischerBereich(int g){
  for(int i=0; i<3; i++){
    P(0);
    printf("Prozess %d betritt kritischen Bereich\n", g);
    sleep(1);
    printf("Prozess %d verlässt kritischen Bereich\n", g);
    V(0);
    printf("Prozess %d betritt unkritischen Bereich\n", g);
    sleep(1);
    printf("Prozess %d verlässt unkritischen Bereich\n",g);
  }
}

int init_sem(){
 int sem_key, sem_id;
 if ((sem_key = ftok("/home/lars",'1'))<0){
 perror("Error in ftok");
 exit(1);
 }

 if ((sem_id = semget(sem_key, 1, IPC_CREAT|0666))<0){
 perror("Error in semget");
 exit(1);
 }

 if(semctl(sem_id, 0, SETVAL, 1)<0){
 perror("Error in semctl");
 exit(1);
 }
  return sem_id;
}

void P(int semNum){
 struct sembuf semaphore;
 semaphore.sem_num = semNum; 
 semaphore.sem_op = -1;
 semaphore.sem_flg =~(IPC_NOWAIT|SEM_UNDO);
  if(semop(semId, &semaphore , 1)){
  perror("error in semopP()");
  exit(1);
 }
}
void V(int semNum){
 struct sembuf semaphore;
 semaphore.sem_num = semNum;
 semaphore.sem_op = 1;
 semaphore.sem_flg =~(IPC_NOWAIT|SEM_UNDO);
  if(semop(semId,&semaphore,1)){
  perror("error in semop V()");
  exit(1);
 }  
}

int main(){
  semId=init_sem();
  for(int process; process<3; process++){
    switch(fork()){
      case -1:
        perror("Fork failed");
        exit(1);
        break;
      case 0:
        printf("child process %d (%d) started \n", process, getpid());
        un_kritischerBereich(process);
        exit(0);
    }
  }
  sleep(3);
  printf("Vaterprozess gestoppt\n");
}


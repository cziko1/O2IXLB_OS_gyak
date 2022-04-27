/*
 * semset.c
 *
 *  Created on: 2022. ápr. 27.
 *      Author: Tivadar Cziko, O2IXLB
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>	//Uzenetek, szemaforok es megosztott memoria
#include <sys/sem.h>	//Strukturakat hataroz meg
#include <stdlib.h>

#define KEY 123456L

union semun {
    int val;                 // Value for SETVAL 
    struct semid_ds *buf;    // Buffer for IPC_STAT, IPC_SET 
    unsigned short *array;   // Array for GETALL, SETALL 
    struct seminfo *__buf;   // Buffer for IPC_INFO Linux-specific
};

void main() {
    
    int semID = semget(KEY, 0, 0);
    int n = 10;
    if (semID == -1) {
        perror("Szemaforokat lekerdezese sikertelen!\n");
        exit(-1);
    }

    union semun arg;

    printf("Szemaforok: \n");
    arg.array = (short *)calloc(n, sizeof(int));

    semctl(semID, 0, GETALL, arg);

    for (int i = 0; i < n; i++) 
        printf("%d ", arg.array[i]);   
}
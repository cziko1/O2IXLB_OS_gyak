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
    union semun atr;

    int m = 10;
    int sem = semget(KEY, m, IPC_CREAT | 0666);

    if (sem == -1) {
        	perror("Letrehozasa sikertelen!");
        exit(-1);
    }

    atr.array = (short *)calloc(m, sizeof(int));


    if (semctl(sem, 0, SETALL, atr)) {
        	perror("Ertek beallitasa sikertelen!\n");
        exit(-1);
    }
}

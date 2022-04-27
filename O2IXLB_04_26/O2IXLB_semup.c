/*
 * semup.c
 *
 *  Created on: 2022. ápr. 27.
 *      Author: Tivadar Cziko, O2IXLB
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#define KEY 123456L

void main() {
    int semID = semget(KEY, 0, 0);
    if (semID == -1) {
        perror("Szemaforok lekerdezese sikertelen!\n");
        exit(-1);
    }

    struct sembuf buffer;

    buffer.sem_num = 4;
    buffer.sem_op = 1;     
    buffer.sem_flg = 0666;  

    if (semop(semID, &buffer, 1)) {
        perror("Sikertelen\n");
        exit(-1);
	}
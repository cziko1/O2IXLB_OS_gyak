/*
 * semkill.c
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
    int n = 5;
    int semID = semget(KEY, 0, 0);
    if (semID == -1) {
        perror("Szemaforokat lekerdezese sikertelen!\n");
        exit(-1);
    }

    for (int i = 0; i < n; i++)
     
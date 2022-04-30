#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "queue.h"

void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1); /* Hiba eseten killep */
}

int main() {
	int value;
  key_t key = ftok(PathName, ProjectId); /* kulcs generalasa*/
  if (key < 0) report_and_exit("Nem kaphato kulcsot!");

  int qid = msgget(key, 0666 | IPC_CREAT); /* generalt kulcs hasznalata queue id kereshez*/
  if (qid < 0) report_and_exit("Nem kaphato queue id!");
	value = qid;
  int i;
  for (i = 0; i < MsgCount; i++) {
    /* uzenetsor generalasa, queuedMessage a queue.h fileban definialt struktura */
    queuedMessage msg;
    msg.value = value;
	msg.id = i;

    /* uzenet kuldese */
    msgsnd(qid, &msg, sizeof(msg), IPC_NOWAIT); /* ha az uzenetsor tele, nem ir uzenetet, hanem visszater a processz elejere */
    printf("%i Uzenet elkuldve! Ertek: %i\n",(int) msg.id, (int) msg.value);
	value = value + 2;
	sleep(1);
  }
  return 0;
}
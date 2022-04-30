#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include "queue.h"

void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1); /* hiba eseten kilep */
}

int main() {
  key_t key= ftok(PathName, ProjectId); /* kulcs az uzenetsor azonositasara */
  if (key < 0) report_and_exit("Nem kaphato kulcs!");

  int qid = msgget(key, 0666 | IPC_CREAT); /* eleri a qid-t, ha mar elkeszitve */
  if (qid < 0) report_and_exit("Nincs hozzaferes a sorhoz!");

  int i;
  for (i = 0; i < MsgCount; i++) {
    queuedMessage msg;
    if (msgrcv(qid, &msg, sizeof(msg),0, MSG_NOERROR | IPC_NOWAIT) < 0)
      puts("Msgreceive problema!");
    printf("%i Uzenet megkapva! Ertek: %i\n",(int) msg.id, (int) msg.value);
    sleep(1);
  }

  /** uzenetsor eltavolitasa **/
  if (msgctl(qid, IPC_RMID, NULL) < 0)  /* NULL = 'no flags' */
    report_and_exit("Problema az uzenetsor eltavolitasaval!");

  return 0;
}
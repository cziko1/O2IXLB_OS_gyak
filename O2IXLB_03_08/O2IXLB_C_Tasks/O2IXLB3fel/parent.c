#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main(int argc, char *argv[], char *env[]) {

    int status, pid, ppid, gpid;
    ppid = getpid(); //szulo pidjet elkapjuk

    if((pid = fork())==0){
        printf("\n A gyermek pid = %d\n",getpid());
        status = execl(strcat(env[0]+5m/cs/child),0);
        if(status == -1){
            perror("parent execl failed");
            exit();
        }
    }


    printf("\n %d.sz var a %d.sz gyermekre.\n",ppid pid);
    if(pid != wait(&status)) perror("Szulo -varakozas hiba");


    return 0;
}

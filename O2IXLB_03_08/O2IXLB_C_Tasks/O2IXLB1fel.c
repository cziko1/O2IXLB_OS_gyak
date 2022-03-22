#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * EZ érvényes parancsot futtat, megvárja, míg fut. Implicit fork()/exec()
 * villa van benne
 *
 * @return
 */


int main() {
    system("ps -f");
    printf("Megvartam amig lefut!!!!\n");
    return 0;
}

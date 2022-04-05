#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <unistd.h>

int main()
{

    int file = open("O2IXLB.txt",O_RDWR);  //open txt file

    if (file > 0){
        printf("Succesfull scanning\n\n");  
    }else{                                 // How to scanning txt file
        printf("ERROR SCANNING\n");
    }

    char txt[54];
    ssize_t x = read(file,&txt,54);        // How to reading txt file

    if (x < 0) 
        printf("ERROR READING\n");
    else 
        printf("%s\nRead byte: %ld\n",txt,x);

    lseek(file,0,SEEK_SET);
    read(file,&txt,54);                    // txt file's size

    ssize_t w = write(1,&txt,54);
    
    if(w < 0){ 
        printf("ERROR PRINTING\n");
    }else{ 
        printf("\nPrinted byte: %ld",w);    // txt file printing
    }
    return 0;
}
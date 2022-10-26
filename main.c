#include<fcntl.h> 
#include <stdio.h>
#include<unistd.h> 
#include <string.h>

int main()
{
    int fd1 = open("file.txt", O_RDWR); 
    char c[bufs+1];
    int red =1;
    while(red>0 && )
    {
        red =read(fd1, c  , bufs);
        bzero(c+red,bufs-red);
        printf("%s",c);
    }
    
    
    return 0;
}
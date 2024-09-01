/*

============================================================================
Name : 10.c
Author : Shane Gomes
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
    a. check the return value of lseek
    b. open the file with od and check the empty spaces in between the data.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv) {
    if(argc == 2) {
        char* filename = argv[1];

        int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644)   ;

        if(fd < 0) {
            perror("Error opening the file");
            return -1;
        }

        char buf1[] = "shaneshane"; // 10 bytes
        char buf2[] = "gomesgomes\n"; // 10 bytes
        if(write(fd, buf1, 10) != 10) {
            perror("Error writing to file");
            close(fd);
            return -1;
        }

        int offset = lseek(fd, 10, SEEK_CUR);

        if(offset == -1) {
            perror("Error seeking");
            close(fd);
            return -1;
        }

        if(write(fd, buf2, 10) != 10) {
            perror("Error writing to file");
            close(fd);
            return -1;
        }
        
        close(fd);
    } else {
        printf("Usage: [executable] [filename]\n");
    }
}

/*

shane-laptop@shane-laptop:~/SoftSys/10$ gcc 10.c -o 10.o

shane-laptop@shane-laptop:~/SoftSys/10$ cat file1
shaneshanegomesgomes

shane-laptop@shane-laptop:~/SoftSys/10$ od -x file1
0000000 6873 6e61 7365 6168 656e 0000 0000 0000
0000020 0000 0000 6f67 656d 6773 6d6f 7365
0000036

*/
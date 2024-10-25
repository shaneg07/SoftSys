/*
============================================================================
Name : 2.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to print the system resource limits. Use getrlimit system call.
============================================================================
*/

#include <stdio.h>     
#include <sys/resource.h> 
#include <stdlib.h>    


void print_limit(int resource, const char* name) {
    struct rlimit limit; 


    if (getrlimit(resource, &limit) == 0) {
       
        printf("%s:\n", name);
        
       
        printf("  Soft limit: %ld\n", (long) limit.rlim_cur);
        
     
        printf("  Hard limit: %ld\n", (long) limit.rlim_max);
    } else {
      
        perror("getrlimit");
        exit(EXIT_FAILURE); 
    }
}

int main() {
  
    print_limit(RLIMIT_CPU, "CPU Time (seconds)");


    print_limit(RLIMIT_FSIZE, "File Size (bytes)");

 
    print_limit(RLIMIT_DATA, "Data Segment Size (bytes)");


    print_limit(RLIMIT_STACK, "Stack Size (bytes)");


    print_limit(RLIMIT_CORE, "Core File Size (bytes)");


    print_limit(RLIMIT_RSS, "Resident Set Size (bytes)");

    print_limit(RLIMIT_NOFILE, "Max Number of File Descriptors");

    print_limit(RLIMIT_MEMLOCK, "Locked Memory (bytes)");

    print_limit(RLIMIT_NPROC, "Max Number of Processes");

    print_limit(RLIMIT_AS, "Address Space (bytes)");

    return 0;  
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ ./2.o
CPU Time (seconds):
  Soft limit: -1
  Hard limit: -1
File Size (bytes):
  Soft limit: -1
  Hard limit: -1
Data Segment Size (bytes):
  Soft limit: -1
  Hard limit: -1
Stack Size (bytes):
  Soft limit: 8388608
  Hard limit: -1
Core File Size (bytes):
  Soft limit: 0
  Hard limit: -1
Resident Set Size (bytes):
  Soft limit: -1
  Hard limit: -1
Max Number of File Descriptors:
  Soft limit: 1024
  Hard limit: 1048576
Locked Memory (bytes):
  Soft limit: 67108864
  Hard limit: 67108864
Max Number of Processes:
  Soft limit: 31414
  Hard limit: 31414
Address Space (bytes):
  Soft limit: -1
  Hard limit: -1
============================================================================
*/
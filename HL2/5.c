/*
============================================================================
Name : 5.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to print the system limitation of
                a. maximum length of the arguments to the exec family of functions.
                b. maximum number of simultaneous process per user id.
                c. number of clock ticks (jiffy) per second.
                d. maximum number of open files
                e. size of a page
                f. total number of pages in the physical memory
                g. number of currently available pages in the physical memory.
============================================================================
*/

#include <stdio.h>      
#include <unistd.h>    

int main() {
 
    long arg_max;  
    arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions: %ld\n", arg_max);

    long max_procs; 
    max_procs = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user id: %ld\n", max_procs);

    long clk_tck;  
    clk_tck = sysconf(_SC_CLK_TCK); 
    printf("Number of clock ticks (jiffy) per second: %ld\n", clk_tck);

    long open_max;
    open_max = sysconf(_SC_OPEN_MAX); 
    printf("Maximum number of open files: %ld\n", open_max);

 
    long page_size; 
    page_size = sysconf(_SC_PAGESIZE); 
    printf("Size of a memory page: %ld bytes\n", page_size);

    long total_pages; 
    total_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in physical memory: %ld\n", total_pages);

    
    long avail_pages;  
    avail_pages = sysconf(_SC_AVPHYS_PAGES);  
    printf("Number of currently available pages in physical memory: %ld\n", avail_pages);

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 5.c -o 5.o && ./5.o
Maximum length of the arguments to the exec family of functions: 2097152
Maximum number of simultaneous processes per user id: 31414
Number of clock ticks (jiffy) per second: 100
Maximum number of open files: 1024
Size of a memory page: 4096 bytes
Total number of pages in physical memory: 2012248
Number of currently available pages in physical memory: 1811545
============================================================================
*/
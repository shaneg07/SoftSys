/*
============================================================================
Name : 2.c
Author : Shane Gomes
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {                    
    int pid = getpid();

    printf("PID - %d\n", pid);
    
    while(1);

    return 0;
}

/*

#terminal 1
shane-laptop@shane-laptop:~/SoftSys/2$ ./2.o 
PID - 19523

#terminal 2
shane-laptop@shane-laptop:/proc/19523$ cat status
Name:   2.o
Umask:  0022
State:  R (running)
Tgid:   19523
Ngid:   0
Pid:    19523
PPid:   479
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 20 24 25 27 29 30 44 46 116 1000
NStgid: 19523
NSpid:  19523
NSpgid: 19523
NSsid:  479
VmPeak:     2776 kB
VmSize:     2776 kB
VmLck:         0 kB
VmPin:         0 kB
VmHWM:       964 kB
VmRSS:       964 kB
RssAnon:              92 kB
RssFile:             872 kB
RssShmem:              0 kB
VmData:      224 kB
VmStk:       132 kB
VmExe:         4 kB
VmLib:      1796 kB
VmPTE:        36 kB
VmSwap:        0 kB
HugetlbPages:          0 kB
CoreDumping:    0
THP_enabled:    1
Threads:        1
SigQ:   1/31415
SigPnd: 0000000000000000
ShdPnd: 0000000000000000
SigBlk: 0000000000000000
SigIgn: 0000000000000000
SigCgt: 0000000000000000
CapInh: 0000000000000000
CapPrm: 0000000000000000
CapEff: 0000000000000000
CapBnd: 000001ffffffffff
CapAmb: 0000000000000000
NoNewPrivs:     0
Seccomp:        0
Seccomp_filters:        0
Speculation_Store_Bypass:       thread vulnerable
SpeculationIndirectBranch:      conditional enabled
Cpus_allowed:   ffff
Cpus_allowed_list:      0-15
Mems_allowed:   1
Mems_allowed_list:      0
voluntary_ctxt_switches:        0
nonvoluntary_ctxt_switches:     5

*/

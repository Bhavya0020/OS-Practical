// Q1. Write a program to create 5 child processes of a parent process using fork. Print the pids and ppids of all the processes.
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define rep(i,n) for(int i = 0; i < n; i++)

int main()
{
	int i;
    rep(i,5)
    {
        if(fork() == 0)
        {
            printf("pid of Process %d is %d and it's ppid is %d\n",i+1,getpid(),getppid());
            exit(0);
        }
    }
    rep(i,5)
    wait(NULL);
}
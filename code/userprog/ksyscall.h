/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"
#include "iostream"
#include "synchconsole.h"

void SysHalt()
{
  kernel->interrupt->Halt();
}

void SysPrintInt(int num)  
{ 
    //kernel->interrupt->PrintInt(num);
    int i=0,intArray[20]={0};	
    
    while(num!=0){
        intArray[i]=num%10;
	num=num/10;
	i++;
    }
    for(i=19;i>=0;i--){
	if(intArray[i]!=0) break;
    }
    if(i<0) i=0;
    for(;i>=0;i--){
	kernel->synchConsoleOut->PutChar(intArray[i]+'0');
    }  
    kernel->synchConsoleOut->PutChar('\n');
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

#ifdef FILESYS_STUB
int SysCreate(char *filename)
{
	 return value
 	// 1: success
 	 // 0: failed
	return kernel->interrupt->CreateFile(filename);
}
	#endif

int SysCreate(char *filename, int size)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename, size);
}


int SysOpen(char *name)
{
	return kernel->interrupt->OpenFile(name);
}


int SysWrite(char *buffer, int size, int id)
{
	return kernel ->interrupt ->WriteFile( buffer, size, id );
}

int SysRead(char *buffer, int size, int id)
{
	return kernel ->interrupt ->ReadFile( buffer, size, id );
}

int SysClose(int id)
{
	return kernel ->interrupt ->CloseFile( id );
}






#endif /* ! __USERPROG_KSYSCALL_H__ */

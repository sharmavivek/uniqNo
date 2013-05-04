#include <sys/time.h>
#include <stdio.h>
#include <string.h>

/* 
 - To get a unique no per machine, and this is not universally unique generator.
 - It can generate the size upto 16 digits
 - It can modified to for mode digits easily, strcat the buffers.
 - Universally Unique Generator we shall use MAC address of the machine.
*/

/*
struct timeval {
    time_t      tv_sec;     // seconds 
    suseconds_t tv_usec;    // microseconds
};
*/


char* unique_no(int size)
{
    struct timeval tv;
    static char buffer[32];

    gettimeofday(&tv, NULL);
    // Find the time in microseconds.
    unsigned long long u_sec = (unsigned long long)(tv.tv_sec) \
		    * 1000000 + (unsigned long long)(tv.tv_usec);
	
	// Store it a string buffer for size manipulation.	    
    sprintf(buffer,"%lld", u_sec);
    
    // To get the MSB calculate the index in the buffer.
    size = strlen(buffer) - size;
    
    // overwrite size to the maximum limit
    if (size < 0)
        size = 0;
    
    return (&buffer[size]);
}


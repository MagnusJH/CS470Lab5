#ifndef MAGNUS_LIBFS_H
#define MAGNUS_LIBFS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

void fileCreate();
FILE* fileOpen();
void fileWrite(char* intro);
void fileRead();
void fileClose(FILE **fp);
void fileDelete();

#endif
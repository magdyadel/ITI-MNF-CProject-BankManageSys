//repo.h

#ifndef REPO_H_
#define REPO_H_


#include "stdio.h"
#include <string.h>
#include "stdlib.h"
#include <time.h> 
#include <limits.h>

#include "STD_TYPES.h"
#include "account.h"

#define PASSLENGTH 7
#define MIN14Digit 10000000000000
#define MAX14Digit 99999999999999
#define MIN10Digit 1000000000
#define MAX10Digit 9999999999

#define element_type sAccBuffer_t

#define DPRINTF(...)	{fflush(stdout); \
						fflush(stdin); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}

//APIs
int words(const char *sent);
void generateRandomPass(char* pass);
char checkPass(char* pass);
void changePass(char* oldPass);
long long read14Digit();



						
						
#endif /* REPO_H_ */
//account.h

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "repo.h"

/* User Configuration */
enum accountStatus{
	Active=1,
	Restricted,
	Closed
};

//Account info
typedef struct {
	char needGuardian;
	char isAdmin;
	char status;
	int balance;
	int age;
	char pass[12];
	char bankAccountID[11];
	char nationalID[15];
	char guardNationalID[15];
	char fullName[50];
	char fullAddress[50];
}sAcount_t;

//list contain acounts
sAcount_t accountLST[50];

//FIFO Data Types.....queue
typedef struct{
	unsigned int len;
	unsigned int count;
	sAcount_t* base;
	sAcount_t* head;
	sAcount_t* tail;
}sAccBuffer_t;

typedef enum{
	LIST_NO_ERROR,
	LIST_FULL,
	LIST_EMPTY,
	LIST_NULL
}listStatus_t;


//APIs
listStatus_t AccountList_init(sAccBuffer_t * accList , sAcount_t * account, u32 length);
void readAccountFile(sAccBuffer_t * accList);
void writeToFile(sAcount_t * curr);
listStatus_t List_isFull(sAccBuffer_t * accList );
sAcount_t * getByAccountID(sAccBuffer_t * accList);
char checkByNationalID(sAccBuffer_t * accList , char* id);
sAcount_t * login(sAccBuffer_t * accList);
void ShowAll(sAccBuffer_t * fifo);
void printAccount(sAcount_t *current);

			
#endif /* ACCOUNT_H_ */

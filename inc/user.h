//user.h


#ifndef USER_H_
#define USER_H_


#include "repo.h"


void makeTransaction(sAccBuffer_t * accList, sAcount_t * curr);//user
void getCash(sAcount_t * curr);//user
void deposit(sAcount_t * curr);//user
void changeAccountPassword(sAcount_t * curr);//user
void getPass(sAcount_t * curr);//user


	
#endif /* USER_H_ */
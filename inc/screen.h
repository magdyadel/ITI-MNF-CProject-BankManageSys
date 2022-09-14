//screen.h

#ifndef SCREEN_H_
#define SCREEN_H_


#include "repo.h"
#include "admin.h"
#include "user.h"

void mainScreen(sAccBuffer_t * accList);
void userScreen(sAccBuffer_t * accList, sAcount_t * curr);
void AdminScreen(sAccBuffer_t * accList, sAcount_t * curr);



	
#endif /* SCREEN_H_ */
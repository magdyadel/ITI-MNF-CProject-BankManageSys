//admin.h


#ifndef ADMIN_H_
#define ADMIN_H_


#include "repo.h"


listStatus_t CreateAccount(sAccBuffer_t * accList); //admin
void getTotalNum(sAccBuffer_t * accList );//admin
void changeAccStatus(sAccBuffer_t * accList);//admin
void makeAdmin(sAccBuffer_t * accList, sAcount_t * curr);//admin

	
#endif /* ADMIN_H_ */
// user.c

#include "../inc/repo.h"


// - make Transaction //user
void makeTransaction(sAccBuffer_t * accList, sAcount_t * curr)
{
	sAcount_t * tmp = NULL;
	char money[10];

	
	DPRINTF("\n----- MAKE TRANSACTION -----\n ");
	DPRINTF("\n mybalance = %d \n ",curr->balance);
	tmp = getByAccountID(accList);
	DPRINTF("\n enter amount of money to transfer it to %s account : ",tmp->fullName);
	gets(money);
    fflush(stdout);
	fflush(stdin);
	if(atoi(money)<=curr->balance){
		curr->balance -= atoi(money);
		tmp->balance += atoi(money);
		DPRINTF("\n mybalance = %d \n ",curr->balance);
		DPRINTF("\n accbalance = %d \n ",tmp->balance);
	}
	else{
		system("cls");
		DPRINTF("\nSorry!! Your balance isn't enough to complete this process\n ");
		return;
	}
	system("cls");
	DPRINTF("Successfully Transaction");
	return ;
}


 // - Get Cash ///user
void getCash(sAcount_t * curr)
{
	sAcount_t * tmp =curr;
	char money[10];

	
	DPRINTF("\n----- Get Cash -----\n ");
	DPRINTF("\nenter amount of money you want :\n ");
	gets(money);
    fflush(stdout);
	fflush(stdin);
	if( atoi(money)<=tmp->balance)
		tmp->balance -= atoi(money);
	else{
		system("cls");
		DPRINTF("\nSorry!! Your balance isn't enough to complete this process\n ");
		return;
	}
	system("cls");
	DPRINTF("Successfully process");
	return ;
}

// - Deposit in Account  //user
void deposit(sAcount_t * curr)
{
	sAcount_t * tmp =curr;
	char money[10];

	
	DPRINTF("\n----- Deposit in Account -----\n ");
	DPRINTF("\nenter amount of money you want :\n ");
	gets(money);
	tmp->balance += atoi(money);

	system("cls");
	DPRINTF("Successfully Deposit");
	return ;
}


// - Change Password  //user
void changeAccountPassword(sAcount_t * curr)
{
	sAcount_t * tmp = curr;

	
	DPRINTF("\n----- Change Password -----\n ");
	if( checkPass(tmp->pass) == 0 )
		changePass(tmp->pass);
	else{
		system("cls");
		DPRINTF("\nSorry!! You entered wrong password.\n ");
		return;
	}
	system("cls");
	DPRINTF("Password Change Successfully.");
	return ;
}

// - get Password  //user
void getPass(sAcount_t * curr)
{
	sAcount_t * tmp =curr;
	
	DPRINTF("\n----- Your Password : %s -----\n ",tmp->pass);
	
	return ;
}



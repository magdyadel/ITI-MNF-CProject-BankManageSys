#include "../inc/screen.h"


void AdminScreen(sAccBuffer_t * accList, sAcount_t * curr)
{
	
	int Choice;
	sAccBuffer_t accountBuffer;
	sAcount_t * temp=NULL;

	//DPRINTF("-------- Admin Screen ------------\n");
	DPRINTF("--------Welcome %s ------------\n", curr->fullName );
	while(1)
	{
		system("color 1");
		DPRINTF("-------- Admin Screen ------------\n");
		DPRINTF("\n-- Choose The Task that you want to perform\n");
		DPRINTF("--- 1. Create New Account .\n");
		DPRINTF("--- 2. Open Existing Account .\n");
		DPRINTF("--- 3. Make New Admin .\n");
		DPRINTF("--- 4. Change Account Status .\n");
		DPRINTF("--- 5. Show all account.\n");
		DPRINTF("--- 6. To Exit\n");
		DPRINTF("--- Enter your choice to perform the task: ");

		scanf("%d",&Choice);
		switch(Choice)
		{
		case 1:
			system("cls");
			DPRINTF("========================================\n");
			CreateAccount(accList);
			break;
		case 2:
			system("cls");
			DPRINTF("========================================\n");
			userScreen(accList, curr);
			break;
		case 3:
			system("cls");
			DPRINTF("========================================\n");
			makeAdmin(accList, curr);
			break;
		case 4:
			system("cls");
			DPRINTF("========================================\n");
			changeAccStatus(accList);
			break;
		case 5:
			system("cls");
			DPRINTF("========================================\n");
			ShowAll(accList);
		break;
		case 6:
			exit(1);
		}
	}
}


void userScreen(sAccBuffer_t * accList, sAcount_t * curr)
{
	system("color 3");
	system("cls");
	int Choice;
	sAccBuffer_t accountBuffer;
	sAcount_t * temp=NULL;
	
	DPRINTF("--------Welcome %s ------------\n", curr->fullName );
	while(1)
	{
		DPRINTF("---------- User Screen --------------\n");
		DPRINTF("\n--- Choose The Task that you want to perform\n");
		DPRINTF("--- 1. Make Transaction.\n");
		DPRINTF("--- 2. Change Account Password .\n");
		DPRINTF("--- 3. Get Cash .\n");
		DPRINTF("--- 4. Deposit in Account .\n");
		DPRINTF("--- 5. Back to previous Menu .\n");
		DPRINTF("--- 6. To Exit\n");
		DPRINTF("--- Enter your choice to perform the task: ");

		scanf("%d",&Choice);
		switch(Choice)
		{
		case 1:
			system("cls");
			DPRINTF("========================================\n");
			makeTransaction(accList, curr);
				
			break;
		case 2:
			system("cls");
			DPRINTF("========================================\n");
			changeAccountPassword(curr);
			break;
		case 3:
			system("cls");
			DPRINTF("========================================\n");
			getCash( curr);//user
			break;
		case 4:
			system("cls");
			DPRINTF("========================================\n");
			deposit( curr);
			break;
		case 5:
			return;
		case 6:
			exit(1);
		}
		system("cls");
	}
}

void mainScreen(sAccBuffer_t * accList)
{
	system("color 0");
	int Choice;
	sAcount_t * temp=NULL;
	
	DPRINTF("--------------- Main Screen --------------\n");
	DPRINTF("\n--- Choose The Task that you want to perform..\n");
	DPRINTF("--- n01. Login to your Account.\n");
	DPRINTF("--- n02. First time.\n");
	DPRINTF("--- n03. To Exit\n");
	DPRINTF("--- Enter your choice to perform the task: ");

	scanf("%d",&Choice);
	DPRINTF("\n##########################################################################\n");
	switch(Choice)
	{
	case 1:
		DPRINTF("========================================\n");
		temp = login(accList);
		if( temp !=NULL)
		{
			temp->isAdmin?AdminScreen( accList ,temp):userScreen(accList, temp);
		}
		break;
	case 2:
		system("cls");
		DPRINTF("========================================\n");
		CreateAccount(accList);
		break;
	case 3:
		exit(1);
	}
	system("cls");
}

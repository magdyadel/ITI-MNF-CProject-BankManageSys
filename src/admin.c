//admin.c

#include "../inc/repo.h"


//get numbers of all of Accounts ----- ADMIN
void getTotalNum(sAccBuffer_t * accList ){
	//check FIFO list is valid
	if(!accList->base || !accList->head || !accList->tail)
		return;
	DPRINTF("[INFO] The total number of Accounts is %d\n",accList->count);
	DPRINTF("[INFO] You can add up to %d Accounts\n",accList->len);
	DPRINTF("[INFO] You can add %d more Accounts\n",50-accList->count);
}



//Add Student ----- ADMIN
listStatus_t CreateAccount(sAccBuffer_t * accList)
{
//	sAcount_t* current= accList->head++;
	sAcount_t tmp;
	int counter=0;

	char data[40];
	//long long ID;
	static long long accID=MIN10Digit;
	//char isValid=0;

	//check accList is valid
	if(!accList->base || !accList->head || !accList->tail)
		return LIST_NULL;
	//check accList is full
	if(List_isFull(accList) == LIST_FULL)
		return LIST_FULL;


	DPRINTF("-------------Add Account Details--------------- \n");
	//full name
	do{
		counter++;
		DPRINTF("please, Enter Full Name (at least first four names ): \n");
		gets(tmp.fullName);
	//	scanf("%[^\n]%*c",c);
	}while( words(tmp.fullName)!=4 && counter<=3);

	if(counter==4)
	{
		DPRINTF("\nSorry!! Try agian Later.\n ");
		return LIST_NO_ERROR;
	}
	counter=0;
	
	//full address
	DPRINTF("please, Enter Full Address (ex.6 Hussien Wassef, From El-Dokki st, Giza.): \n");
	gets(tmp.fullAddress);

	//national id
	do{
		counter++;
		DPRINTF("please, Enter National ID consist 14 digit (ex: 29805070100179): \n");
		gets(tmp.nationalID);
	//	scanf("%[^\n]%*c",c);
	}while( !(atoll(tmp.nationalID)<=MAX14Digit && atoll(tmp.nationalID)>=MIN14Digit)&& counter<=3);
	if(counter==4)
	{
		DPRINTF("\nSorry!! Try agian Later.\n ");
		return LIST_NO_ERROR;
	}
	counter=0;
	
	if(!checkByNationalID(accList, tmp.nationalID))
	{
		system("cls");
		DPRINTF("\n\"National ID is already exist..\" \n");
		return LIST_NO_ERROR;
	}


	//age
	DPRINTF("please, Enter %s Age : \n",tmp.fullName);
	gets(data);
	tmp.age=atoi(data);

	//guardian id
	if(21>tmp.age)
	{
		tmp.needGuardian=1;
		do{
			counter++;
			DPRINTF("please, Enter Guardian National ID consist 14 digit (ex: 29805070100179): \n");
			gets(tmp.guardNationalID);
			//	scanf("%[^\n]%*c",c);
		}while( !(atoll(tmp.guardNationalID)<=MAX14Digit && atoll(tmp.guardNationalID)>=MIN14Digit) && counter<=3);
		if(counter==4)
		{
			DPRINTF("\nSorry!! Try agian Later.\n ");
			return LIST_NO_ERROR;
		}
		counter=0;
		
	}else
		tmp.needGuardian=0;

	//Account Balance
	DPRINTF("please,Enter Account Balance.\n");
	gets(data);
	tmp.balance=atoi(data);
	//scanf("%d",accountLST->balance);
	fflush(stdout);
	fflush(stdin);
	tmp.status=Active;
	generateRandomPass(tmp.pass);
	lltoa (accID++,tmp.bankAccountID,10);
	
	// writeToFile(accountLST);
//--------------------------------------------------------------------------------------
	//*(accountLST+accList->count++) =tmp;
	//Enqueue Value
	//accList->head++;
	//accList->count++;
		//Enqueue Value
	*(accList->head)=tmp;
	accList->count++;

	/* Circular FIFO */

	// if( accList->head == ( accList->base + (accList->len * sizeof() ))) //to know head is MAX (0x0 + 5*1)=5
		// accList->head ==accList->base;
	// else
		accList->head++;
	//accList=NULL;
	//readAccountFile(accList);
	system("cls");
	printAccount(accList->head);
	DPRINTF("Account Added Successfully.\n");
	getTotalNum(accList);
	return LIST_NO_ERROR;
}


// - Change Account Status ----- ADMIN
void changeAccStatus(sAccBuffer_t * accList)
{
	sAcount_t * tmp = NULL;
	char choice[2],flag=1;
	
	
	DPRINTF("\n----- Change Account Status -----\n ");
	tmp = getByAccountID(accList);
	DPRINTF("\nenter new Account Status for %s account\n ",tmp->fullName);
	DPRINTF("\nActive press -> 1 \nRestricted press -> 2 \nClosed press -> 3 \n ",tmp->fullName);
	gets(choice);
	do switch(atoi(choice)) {
        case 1: tmp->status = Active; flag=0; break;
        case 2: tmp->status = Restricted; flag=0; break;
		case 3: tmp->status = Closed; flag=0; break;
		case '\r':  break;
        default: 
			DPRINTF("\nActive press -> 1 \nRestricted press -> 2 \nClosed press -> 3 \n ",tmp->fullName);
			scanf("%c",choice);
    } while(flag);
	DPRINTF("Account Status changed successfully");
	return ;
}



// - Make Admin ---ADMIN
void makeAdmin(sAccBuffer_t * accList, sAcount_t * curr)
{
	sAcount_t * tmp = NULL;
	//char choise;

	
	DPRINTF("\n----- MAKE ADMIN -----\n ");
	tmp = getByAccountID(accList);;
	if(tmp!=NULL){
		tmp->isAdmin = 1;
	}
	else{
		system("cls");
		DPRINTF("\nSorry!! Your entered wrong account id.\n ");
		return;
	}
	system("cls");
	DPRINTF("make admin Successfully.");
	return ;
}


//account.c

#include "../inc/repo.h"



//init list 
listStatus_t AccountList_init(sAccBuffer_t * accList , sAcount_t * buf, u32 length)
{
	if(!buf)
		return LIST_NULL;

	accList->base =buf;
	accList->head =buf;
	accList->tail =buf;
	accList->len=length;
	accList->count=0;
	
	return LIST_NO_ERROR;
}


//check if list is fill
listStatus_t List_isFull(sAccBuffer_t * accList )
{
	//check FIFO is valid
	if(!accList->base || !accList->head || !accList->tail)
		return LIST_NULL;
	else if(accList->count == accList->len)
		return LIST_FULL;
	else
		return LIST_NO_ERROR;
}


//get by Account id
sAcount_t * getByAccountID(sAccBuffer_t * accList)
{
	sAcount_t * current=accList->base;
	char tmpID[15];

	//check accList list is valid
	if(!accList->base || !accList->head || !accList->tail)
		return NULL;

	//check accList is empty
	if(accList->count == 0)
	{
		DPRINTF("\n List is already empty \n ");
		return NULL ;
	}
	int i = 0;
	
	do{
		DPRINTF("please, Enter bank Account ID : ");
		gets(tmpID);
	//	scanf("%[^\n]%*c",c);
		i++;
	}while( !(atoll(tmpID)<=MAX10Digit && atoll(tmpID)>=MIN10Digit) && i<=3 );
	if(i==4)
		return NULL;
	for(int i=0;i<accList->count;i++)
	{
		if( (strcmp(current->bankAccountID,tmpID)+1)==1 )
		{
			return current;
		}
		current++;
	}
	return NULL;
}

//check if NationalID is exist
char checkByNationalID(sAccBuffer_t * accList , char* id)
{
	sAcount_t* ptr= accList->base;
	int flag = 1;

	for(int i=0; i<accList->count; i++){

		if(strcmp(ptr->nationalID , id)==0){
			flag = 0;
			return flag;
		}
		ptr++;
	}
	return flag;
}



// - Login
sAcount_t * login(sAccBuffer_t * accList)
{
	sAcount_t * tmp=NULL;
	char flag=1;
	tmp = getByAccountID(accList);
	if(tmp==NULL)
	{
		DPRINTF("\nSorry!! Try Later.\n ");
		return NULL;
	}
	flag = checkPass(tmp->pass);
	if( flag != 0 ){
		DPRINTF("\nSorry!! You entered wrong password.\n ");
		return NULL;
	}
	if( tmp->status != Active ){
		DPRINTF("\nSorry!! You Account not Active\n ");
		return NULL;
	}
	
	return tmp;
}



void readAccountFile(sAccBuffer_t * accList)
{
	//system("color 5");
	FILE* fp = fopen("addAccounts.txt","r");

	int Rec_no = 0 , Field_no = 0;// , Acount_Count = 0;
	char Line[200];
	const char* Taken;


	while(fgets(Line,sizeof Line,fp) != NULL)
	{
		Rec_no++;
		Taken = strtok(Line,",");
		Field_no = 0;
		if(Taken != NULL)
			DPRINTF("\n###### NEW Account ###### \n");
		while(Taken != NULL)
		{
			
			Field_no++;
			if(Field_no == 1){
				//accList->head->bankAccountID = atoll(Taken);
				strcpy(accList->head->bankAccountID , Taken);
				DPRINTF("[INFO] account ID : %s\n",accList->head->bankAccountID);
			}
			else if(Field_no == 2){
				strcpy(accList->head->fullName , Taken);
				DPRINTF("[INFO] name : %s\n",accList->head->fullName);
			}
			else if(Field_no == 3){
				strcpy(accList->head->fullAddress , Taken);
				DPRINTF("[INFO] address : %s \n",accList->head->fullAddress);
			}
			else if(Field_no == 4){
				strcpy(accList->head->nationalID , Taken);
				DPRINTF("[INFO] national id : %s\n",accList->head->nationalID);				
			}
			else if(Field_no == 5){
				strcpy(accList->head->pass , Taken);
				DPRINTF("[INFO] pass : %s\n",accList->head->pass);
			}
			else if(Field_no == 6){
				accList->head->age = atoi(Taken);
				DPRINTF("[INFO] age : %d years\n",accList->head->age);	
			}
			else if(Field_no == 7){
				accList->head->balance = atoi(Taken);
				DPRINTF("[INFO] balance : %d $\n",accList->head->balance);	
			}
			else if(Field_no == 8){
				accList->head->status = atoi(Taken);
			}
			else if(Field_no == 9){
				accList->head->needGuardian = atoi(Taken);
			}
			else if(Field_no == 10){
				accList->head->isAdmin = atoi(Taken);
				(accList->head->isAdmin==1)?printf("[INFO] is Admin \n"):printf("[INFO] is User \n");	
			}
				
			Taken = strtok(NULL,",\n");
		}
	//	if(Check_RollNum(fifo, atoi(Taken)) == 0)
	//		continue;

		accList->count++;
		accList->head++;
	}
	fclose(fp);

}

void ShowAll(sAccBuffer_t * fifo){
	sAcount_t * Ptr;

	//check FIFO list is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return ;

	//check FIFO is empty
	if(fifo->count == 0)
	{
		DPRINTF("\n List is already empty \n ");
		return ;
	}
	Ptr=fifo->tail;
	DPRINTF("---------Student Details are-----------\n");
	for(int i=0; i<fifo->count; ++i)
		printAccount(Ptr++);
	//getTotalNum(fifo );
}

void printAccount(sAcount_t *current)
{
	DPRINTF("Account ID  : %s\n",current->bankAccountID);
	DPRINTF("Name        : %s\n",current->fullName);
	DPRINTF("Address     : %s \n",current->fullAddress);
	DPRINTF("National ID : %s\n",current->nationalID);				
	DPRINTF("Pass        : %s\n",current->pass);
	DPRINTF("Age         : %d years\n",current->age);	
	(current->needGuardian==1)?printf("Guard National ID : %s\n",current->guardNationalID):printf("Above the age of 21.\n");
	DPRINTF("Balance     : %d $\n",current->balance);	
	(current->isAdmin==1)?printf("--- Admin ---\n"):printf("--- User ---\n");	
	DPRINTF("---------------------------------------\n");
}

void writeToFile(sAcount_t * curr)
{
   char *filename = "test.txt";

    // open the file for writing
    FILE *fp = fopen("addAccounts.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
        return ;
    }
    // write to the text file
    fprintf(fp, "\n%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,",curr->bankAccountID,curr->fullName,curr->fullAddress,curr->nationalID,curr->pass,curr->age ,curr->balance,curr->status,curr->needGuardian,curr->isAdmin );

    // close the file
    fclose(fp);
}



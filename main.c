//main.c

#include "inc/repo.h"
#include "inc/screen.h"


void main(void)
{
	sAccBuffer_t accountBuffer;
	AccountList_init(&accountBuffer ,accountLST , 50);
	
	DPRINTF("************* Read from FILE **************\n");
	readAccountFile(&accountBuffer);
	DPRINTF("*******************************************\n");
	
	DPRINTF("\n##########################################################################\n");
	DPRINTF("--------Welcome to Bank System------------\n");
	while(1)
	{
		//system("color 8");
		mainScreen(&accountBuffer);
	}
}




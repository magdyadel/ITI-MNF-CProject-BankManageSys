//repo.c

#include "../inc/repo.h"


int words(const char *sent)//magdy adel from aswan
{
	int count = 0;
	const char* str = sent;
    char isWord = 0;

    do switch(*str) {
        case '\0': 
        case ' ' : 
		case '\t':
		case '\n':
		case '\r': 
            if (isWord) 
			{ 
				isWord = 0; 
				count++; 
			}
            break;
        default: isWord = 1;
    } while(*str++);

    return count;
}


void generateRandomPass(char* pass) {
    char *c=pass;
    int i=0;
    char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$\%^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM[]{};':\"<>,.?/|";

    srand(time(NULL));
    for( i = 0; i < (PASSLENGTH-1); i++) {
        *c++ = list[rand() % (sizeof (list) - 1)];
    }
    c[i] = '\0';
}

void changePass(char* oldPass)
{
	char * newPass;
	printf("please, Enter your new Password : \n");
	gets(oldPass);
}

char checkPass(char* pass)
{
	char check[7];
	printf("please, Enter your Password : ");
	gets(check);
	return strcmp(pass,check);
}


long long read14Digit()
{
	long long ID;
	scanf("%lld",&ID);
	while( !(ID<=MAX14Digit && ID>=MIN14Digit) )
	{
		DPRINTF("please, Enter VALID ID consist 14 digit : \n");
		scanf("%lld",&ID);
	}
	return ID;
}




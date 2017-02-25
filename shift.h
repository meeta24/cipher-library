#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* shiftencrypt(char arr[], int len,int key)
{
	static char st[150];
    int i;
    int ascii=0;
    
for(i=0;i<len;)
{
while(arr[i]!='\0')
{
	ascii=arr[i];
	ascii=ascii+key;
    st[i]=ascii;
i++;
}
}
return st;
}

char* shiftdecrypt(char g[], int len, int key)
{
    int i;
    int aval=0;
    	static char kk[150];
for(i=0;i<len;)
{
while(g[i]!='\0')
{
	aval=g[i];
	aval=aval-key;
    kk[i]=aval;
i++;
}
}
return kk;
}

int shift()
{
	char arr[150];
printf("Enter the string: \n");
scanf("%s", &arr);	
	int count=0;
	int len=strlen(arr);
  printf("\n");
  time_t t;
	srand((unsigned) time(&t));
	int key=rand() % (25 + 1 - 1) + 1;
  char* g;
  int i;
  g=shiftencrypt(arr, len, key);
    printf("the encypted text is\n");
	for( i=0;i<len;i++)
    {
    	printf("%c", g[i]);
	}

printf("\n");
char* h;
h=shiftdecrypt(g, len, key);
	printf("the decrypted text is\n");
for(i=0;i<len;i++)
{
printf("%c", h[i]);
} 

return 0;
}

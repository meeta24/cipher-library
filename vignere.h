#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* vigencrypt(char arr[], char key[],int len)
{
static char en[150];
int ascii, i=0, keyshift, r;
char key_buff[255];

 while(strlen(key) < strlen(arr))
{ 
   strcpy(key_buff, key);
   strcat(key, key_buff);
 }
for(i=0;i<len;)
{
while(arr[i]!='\0')
{ 

  ascii= arr[i];
  
    keyshift = key[i]; 
      
	    r = (ascii + keyshift)-97;
	    if(r>122)
	    r=r-26;
        
        en[i]=r;
       i++;
   
}
}
return en;
}
 

char* vigdecrypt(char ct[], char key[],int len)
{
    
   int pos, i=0, keys, s;
   char key_buff1[255];
    static char dec[150];

while(strlen(key) < strlen(ct))
{ 
   strcpy(key_buff1, key);
   strcat(key, key_buff1);
 }
for(i=0;i<len;)
{
while(ct[i]!='\0')
{ 
   pos= ct[i];
    keys = key[i] ; 
    
        s = (pos - keys)+97;
        if(s>122)
        s=s-26;
        else if(s<97)
        s=s+26;
        dec[i]=s;

    i++;
}
}
return dec;
}

int vignere()
{
	char arr[150];
printf("Enter string:");
//    gets(arr);
scanf("%s", arr);
	//puts(arr);
	int len=strlen(arr);
	int i;
	
	time_t t;
	srand((unsigned) time(&t));
	char key[20];
	for(i=0;i<20;i++)
	{
		key[i]=rand() % (122 + 1 - 97) + 97;
	//printf ("%c", key);
    }
    int ascii=0;

    for(i=0;i<5;i++)
    {
	  ascii=key[i];
	//printf("%c=%d\t", ascii, ascii);
	}

       //RANDOM KEY GENERATE

    
  char* a;
  a=vigencrypt(arr, key,len);
    printf("\nThe encrypted text is\n");
	for( i=0;i<len;i++)
    {
    	printf("%c", a[i]);
	}

char* k;
k=vigdecrypt(a, key,len);
printf("\nThe decrypted text is\n");
for(i=0;i<len;i++)
{
printf("%c", k[i]);
} 
return 0;
}



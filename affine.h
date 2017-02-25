#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char alph[62] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

int hcf(int a, int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int affine()
{
	srand(time(NULL));
    int i,j,len,v,a,b,a_inv,z;
    char out[50];
    char output[50];
    char input[50];
    char outer[50];
printf("Enter the text to be encrypted: ");
    scanf("%s",&input);
    len = strlen(input);
    
    do {
    a = rand() % 62;
    } while (hcf(62, a) != 1);
    
    b = rand() % 62;
        
for(i=0;i<len;i++)
   {
   	for(j=0;j<62;j++)
   	{
   	if(input[i]==alph[j])
	   {
	   v=((a*j)+b)%62;	
       }
	}
	out[i]=alph[v];   	
   }    


printf("\nEncrypted Text: ");   
for(i=0;i<len;i++)   
    printf("%c",out[i]);

	do {
        a_inv = rand() % 62;
    } while (((a_inv * a) % 62) != 1);

    
for(i=0;i<len;i++)
   {
   	for(j=0;j<62;j++)
   	{
   	if(out[i]==alph[j])
	   {
	   z=j-b;
	   if(z<0)
	   {
	   z=z+62;	
	   }	
       v=(a_inv*z)%62;
	   }  
	}
	output[i]=alph[v];   	
   }

printf("\nDecrypted Text:");
for(i=0;i<len;i++)
    printf("%c",output[i]);
      
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
char letters[62] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

long int gcd(long int a, long int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

long int isprime(long int a)
{
    int i;
    for(i = 2; i < a; i++){
        if((a % i) == 0)
            return 0;
    }
    return 1;
}

long int encrypt(int ch, long int n, long int e)
{
    int i;
    long int temp = ch;
    for(i = 1; i < e; i++)
        temp = (temp * ch) % n;    
	return temp;
}

long int decrypt(long int ch, long int n, long int d)
{
    int i;
    long int temp = ch;
    for(i = 1; i < d; i++)
        temp =(temp * ch) % n;
    return temp;
}

int rsaenc()
{
    srand(time(NULL));
    long int i,j, len;
    long int p, q, n, phi, e=3, d, cipher[50],v;
    char text[50];
    int text1[50];
    printf("Enter the text to be encrypted: ");
    scanf("%s",&text);
    len = strlen(text);
    
for(i=0;i<len;i++)
    {
	       for(j=0;j<62;j++) 
	   {
       	if(text[i]==letters[j])
       	    text1[i]=j;
	   }
    }

 
   do {
        p = rand() % 30 + 2;
    } while (!isprime(p));


    do {
        q = rand() % 30 + 2;
    } while (!isprime(q));



    n = p * q;
    phi = (p - 1) * (q - 1);

    do {
        e = rand() % phi;
   } while (gcd(phi, e) != 1);
 


   do {
        d = rand() % phi + 1;
    } while (((d * e) % phi) != 1);
   

    for (i = 0; i < len; i++)
        cipher[i] = encrypt(text1[i], n, e);
    
    printf("Encrypted message: ");
    
    for (i = 0; i < len; i++)
        printf("%d",cipher[i]);
    
    for (i = 0; i < len; i++)
        text1[i] = decrypt(cipher[i], n, d);
    
    printf("\n");
    printf("Decrypted message: ");
    
    for (i = 0; i < len; i++)
      {
      	v=text1[i];
		printf("%c",letters[v]);
	  }
	printf("\n");
    return 0;
}

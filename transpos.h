#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* transencrypt(char pl_text[], int len)
{
	static char st[600];
	int rows=0;
	rows=len/5;
	int remainder;
	remainder=len%5;
	int i, j;
	if(remainder==0)
	{
	 	char mat[rows][5];
        int k=0;
        int x=0;
        int i, j;
        for(i=0;i<rows;i++)
        {
        	for(j=0;j<5;j++)
        	{
        		mat[i][j]=pl_text[k];
        		k++;
			}
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<5;j++)
			{
			}
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<rows;j++)
			{
				st[x]=mat[j][i];
				x++;
			}
		}
    }
	 else
	{
	 	rows=rows+1;
	 	char mat[rows][5];
	    int k=0;
        int x=0;
        int i, j;
        int p=0;
        for(i=0;i<rows;i++)
        {
        	for(j=0;j<5;j++)
        	{
        		if (pl_text[k]=='\0')
        	{
			mat[i][j]='-';
    		}
			else	
        	{
			mat[i][j]=pl_text[k++];
            }
			}
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<5;j++)
			{
			}
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<rows;j++)
			{
				st[x]=mat[j][i];
				x++;
			}
		}
		
	}
return st;
}

char* transdecrypt(char g[], int l)
{
	 static char t[600];
	 int rows=0;
	 rows=l/5;
	 int remainder;
	 remainder=l%5;
	 int i, j;
	 if(remainder==0)
	 {
	 	char mat[rows][5];
        int k=0;
        int x=0;
        int i, j;
        for(i=0;i<5;i++)
        {
        	for(j=0;j<rows;j++)
        	{
        		mat[j][i]=g[k];
        		k++;
			}
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<5;j++)
			{
			}
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<5;j++)
			{
				t[x]=mat[i][j];
				x++;
			}
		}
	 }
	 else
	 {
	 	rows=rows+1;
	 	char mat[rows][5];
	 	
		 int k=0;
        int x=0;
        int i, j;
        for(i=0;i<5;i++)
        {
        	for(j=0;j<rows;j++)
        	{
				mat[j][i]=g[k++];
        	}
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<5;j++)
			{
			}
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<5;j++)
			{
				t[x]=mat[i][j];
				x++;
			}
		}
	 }
return t;
}


int transpos() 
{
     char pl_text[600];
printf("Enter the string: ");
printf("\n");
	 scanf("%s", &pl_text);
	 printf("\n");
	 
	 int len=strlen(pl_text);
	 char* g;
	  g=transencrypt(pl_text, len);
	 int i;
	 printf("\n");
	printf("the encrypted text is\n");
	 
	 for(i=0;g[i]!='\0';i++)
	 {
	 	printf("%c", g[i]);
	 
	 }
	 printf("\n");
	 	int l=strlen(g);
	 
	 char* h;
	 h=transdecrypt(g, l);
	 printf("the decrypted text is\n");
	 
	 for(i=0;h[i]!='-';i++)
	 {
	 	printf("%c", h[i]);
	 }
	 printf("\n");
	 int length=strlen(h);
	 return 0;
}

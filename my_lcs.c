#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i,j,x,y,c[20][20];
char str1[20],str2[20],b[20][20];

void lcs()
{
	x = strlen(str1);
	y = strlen(str2);

	for(i=0;i<=x;i++)
		c[i][0]=0;
	for(i=0;i<=y;i++)
		c[0][i]=0;

	for(i=1;i<=x;i++)
	{
		printf("\n");
		for(j=1;j<=y;j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				c[i][j] = c[i-1][j-1]+1;
				b[i][j]='c';
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j]='u';
			}

			else
			{
				c[i][j] = c[i][j-1];
				b[i][j]='l';
			}		
			printf(" %d ",c[i][j]);
		}
	}
}

void print(int i,int j)
{
	if(i==0 || j==0)
		return;

	else if(b[i][j]=='c')
	{
		print(i-1,j-1);
		printf("%c",str1[i-1]);
	}
	else if(b[i][j]=='u')
		print(i-1,j);
	
	else
		print(i,j-1);
}
int main()
{
	printf("Enter 1st sequence\n");
	scanf("%s",str1);
	printf("Enter 2nd sequence\n");
	scanf("%s",str2);

	lcs();
	printf("\nlongest sequence is:");
	print(x,y);
	printf("\n");
	return 0;
}

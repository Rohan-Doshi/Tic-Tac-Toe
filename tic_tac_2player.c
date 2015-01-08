#include <stdio.h>
#include <stdlib.h>
int check(int[][3]);
void print(int[][3]);
int main()
{
	int i,j,match[3][3]={0},posx,posy,comp_posx,comp_posy,slot,fill=0,n=0,user_1=0,user_2=0;
 	char ch;
	print(match);
	do
 	{
	  	while(fill<9)
	  	{
	   		printf("\nPlayer %d : Enter the slot you want to fill.\n",(n+1));
	   		scanf("%d",&slot);
	   		if (slot > 9)
	   		{
	    			printf("Error!\nSlot value cannot exceed 9.\n");
	    			continue;
	   		}
	   		else if(slot >= 1 && slot <= 3)
	   		{
	    			posx=0;
	    			posy=slot-1;
	   		}
	   		else if (slot >= 4 && slot <= 6)
	   		{
	    			posx=1;
	    			posy=slot-4;
	   		}
	   		else
	   		{
	    			posx=2;
	    			posy=slot-7;
	   		}
	   		if (match[posx][posy] == 0)
	   		{
				if(n==0)
	    				match[posx][posy]=1;
				else 
					match[posx][posy]=-1;
	    			fill++;
	    			check(match);
				n=(n+1)%2;
	    			if(check(match)==1)
	    			{
	     				printf("The user 1 wins!\n");
	     				user_1++;
	     				print(match);
	     				break;
	    			}
				else if(check(match)==-1)
	    			{
	     				printf("The user 2 wins!\n");
	     				user_2++;
	     				print(match);
	     				break;
	    			}	
	   		}		
	   		else
	   		{	
	    			printf("Sorry! This slot is already filled.\nPlease pick another slot.\n");
	    			continue;
	   		}
	   		
	   		print(match);
	  	}
  		for(i=0;i<3;i++)
  		{	
   			for(j=0;j<3;j++)
   			{
    				match[i][j]=0;
   			}
  		}
  		printf("Continue? Y/N\n");
  		scanf("%c ",&ch);
 	}while(ch=='y'||ch=='Y');
 	printf("FINAL SCORES>>\nUser1=%d\nUser2=%d\n",user_1,user_2);
 	return 0;
}
int check(int match[][3])
{
 	int i,j;
 	if(match[2][0]==match[1][1] && match[1][1]==match[0][2] )
 	{
  		if (match[0][2]==1)
  			return 1;
  		else if (match[0][2]==-1)
  			return -1;
 	}
 	for(i=0;i<3;i++)
 	{
  		if (match[i][0]==match[i][1]&&match[i][1]==match[i][2])
  		{
   			if(match[i][1]==1)
   				return 1;
   			else if(match[i][1]==-1)
   				return -1;
   			else
   				continue;
  		}
 	}
 	for(j=0;j<3;j++)
 	{
  		if(match[0][j]==match[1][j]&&match[0][j]==match[2][j])
  		{
   			if (match[0][j]==1)
   				return 1;
   			else if(match[0][j]==-1)
   	 				return -1;	
   			else
   				continue;
  		}
 	}
 	for (i=0;i<1;i++)
 	{
  		if(match[i][i]==match[i+1][i+1]&&match[i][i]==match[i+2][i+2])
  		{
   			if (match[i][i]==1)
   				return 1;
   			else if (match[i][i]==-1)
				return -1;
			else 
				continue;
		}
 	}
	return 0;
}
void print(int match[][3])
{
	int i,j;
	for(i=0;i<3;i++)
  	{
   		printf("\n");
   		for(j=0;j<3;j++)
   		{
			if(match[i][j]==1)
    				printf("X\t");
			else if(match[i][j]==-1)
    				printf("O\t");
			else
				printf("-\t");
   		}
  	}
}

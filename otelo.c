#include<stdio.h>
int main(int argc,char **argv[])
{
	int i,j,board[8][8],player;
	for(i=0;i<9;i++)
		for(j=0;j<8;j++)
			board[i][j]=argv[1+i][j];
	player=argv[9][0];
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			printf("%d",board[i][j]);
	return 0;
}

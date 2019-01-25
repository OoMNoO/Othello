#include <stdio.h>

void score(int scorepoint[8][8]);
void Rowchecker(char board[8][8],int scorepoint[8][8],char player);
void nearcornerpoint(int scorepoint[8][8]);
void cornerpoint(int scorepoint[8][8]);
int check(int i,int j,char board[8][8],char player);
int upcheck(int i,int j,char board[8][8],char player);
int downcheck(int i,int j,char board[8][8],char player);
int leftcheck(int i,int j,char board[8][8],char player);
int rightcheck(int i,int j,char board[8][8],char player);
int rightupcheck(int i,int j,char board[8][8],char player);
int rightdowncheck(int i,int j,char board[8][8],char player);
int leftupcheck(int i,int j,char board[8][8],char player);
int leftdowncheck(int i,int j,char board[8][8],char player);
void choice(int scorepoint[8][8],int a[]);
int main(int argc,char* argv[])
{

    int i,j,scorepoint[8][8],a[2]={0};
	char board[8][8],player;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			board[i][j]=argv[1+i][j];

	score(scorepoint);
    player=argv[9][0];

    if(player=='1')
        player='2';
    else
        player='1';

    Rowchecker(board,scorepoint,player);
    /*for(i=0;i<8;i++){
        for(j=0;j<8;j++)
            printf("%d ",scorepoint[i][j]);
        printf("\n");
    }*/
    choice(scorepoint,a);
    printf("%d %d",a[1],a[0]);
    return 0;
}

int upcheck(int i,int j,char board[8][8],char player){
    int counter,point_of_check=0;    
    i--;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i--;
            point_of_check++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return point_of_check;
        }
        if(i<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int downcheck(int i,int j,char board[8][8],char player){
    int counter,point_of_check=0;    
    i++;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i++;
            point_of_check++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return point_of_check;
        }
        if(i>7||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}

int leftcheck(int i,int j,char board[8][8],char player){
    int counter,point_of_check=0;    
    j--;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            j--;
            point_of_check++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return point_of_check;
        }
        if(j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int rightcheck(int i,int j,char board[8][8],char player){
int counter,point_of_check=0;    
    j++;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            j++;
            point_of_check++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return point_of_check;
        }
        if(j>7||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int rightupcheck(int i,int j,char board[8][8],char player){
    int counter,point_of_check=0;    
    i--;
    j++;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i--;
            j++;
            point_of_check++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return point_of_check;
        }
        if(j>7||i<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int rightdowncheck(int i,int j,char board[8][8],char player){
    int counter,point_of_check=0;    
    i++;
    j++;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i++;
            j++;
            point_of_check++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return point_of_check;
        }
        if(i>7||j>7||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int leftupcheck(int i,int j,char board[8][8],char player){

    int counter,point_of_check=0;    
    i--;
    j--;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i--;
            j--;
            point_of_check++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return point_of_check;
        }
        if(i<0||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int leftdowncheck(int i,int j,char board[8][8],char player){

    int counter,point_of_check=0;    
    i++;
    j--;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i++;
            j--;
            point_of_check++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return point_of_check;
        }
        if(i>7||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}

int check(int i,int j,char board[8][8],char player){
    int a,b,c,d,e,f,g,h;
    a=upcheck(i,j,board,player);
    b=downcheck(i,j,board,player);
    c=leftcheck(i,j,board,player);
    d=rightcheck(i,j,board,player);
    e=rightupcheck(i,j,board,player);
    f=rightdowncheck(i,j,board,player);
    g=leftupcheck(i,j,board,player);
    h=leftdowncheck(i,j,board,player);
    return a+b+c+d+e+f+g+h;
}
void Rowchecker(char board[8][8],int scorepoint[8][8],char player){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if (board[i][j]=='0'){
                scorepoint[i][j]=check(i,j,board,player);
            }
        }
    }
	cornerpoint(scorepoint);
	nearcornerpoint(scorepoint);
}
void score(int scorepoint[8][8]){
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            scorepoint[i][j]=0;
}
void cornerpoint(int scorepoint[8][8]){
	if(scorepoint[0][0]>0)
        scorepoint[0][0]=100;
    if(scorepoint[7][0]>0)
    	scorepoint[7][0]=100;
    if(scorepoint[0][7]>0)
    	scorepoint[0][7]=100;
    if(scorepoint[7][7]>0)
    	scorepoint[7][7]=100;
}
void nearcornerpoint(int scorepoint[8][8]){
	if(scorepoint[0][1]>0)
        scorepoint[0][1]=1;
    if(scorepoint[1][0]>0)
    	scorepoint[1][0]=1;
    if(scorepoint[1][1]>0)
    	scorepoint[1][1]=1;
    //
    if(scorepoint[6][0]>0)
        scorepoint[6][0]=1;
    if(scorepoint[6][1]>0)
    	scorepoint[6][1]=1;
    if(scorepoint[7][1]>0)
    	scorepoint[7][1]=1;
    //
    if(scorepoint[0][6]>0)
        scorepoint[0][6]=1;
    if(scorepoint[1][6]>0)
    	scorepoint[1][6]=1;
    if(scorepoint[1][7]>0)
    	scorepoint[1][7]=1;
    //
    if(scorepoint[7][6]>0)
        scorepoint[7][6]=1;
    if(scorepoint[6][6]>0)
    	scorepoint[6][6]=1;
    if(scorepoint[6][7]>0)
    	scorepoint[6][7]=1;
}
void choice(int scorepoint[8][8],int a[]){
	int i,j,max=0;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
        	if(scorepoint[i][j]>=max){
        		max=scorepoint[i][j];
        		a[0]=i;
				a[1]=j;
        	}
}

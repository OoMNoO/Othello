#include <stdio.h>

void score(int scoreboard[8][8],int scorepoint[8][8]);
void Rowchecker(char board[8][8],int scorepoint[8][8],char player);
void pointmixer(int pointboard[8][8],int scoreboard[8][8],int scorepoint[8][8]);
int check(int i,int j,char board[8][8],char player);
int upcheck(int i,int j,char board[8][8],char player);
int downcheck(int i,int j,char board[8][8],char player);
int leftcheck(int i,int j,char board[8][8],char player);
int rightcheck(int i,int j,char board[8][8],char player);
int rightupcheck(int i,int j,char board[8][8],char player);
int rightdowncheck(int i,int j,char board[8][8],char player);
int leftupcheck(int i,int j,char board[8][8],char player);
int leftdowncheck(int i,int j,char board[8][8],char player);


int main(int argc,char* argv[])
{
    
    int i,j,scoreboard[8][8],scorepoint[8][8],pointboard[8][8];
	char board[8][8],player;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			board[i][j]=argv[1+i][j];
    
	score(scoreboard,scorepoint);
    player=argv[9][0];
    
    if(player=='1')
        player='2';
    else
        player='1';

    Rowchecker(board,scorepoint,player);
    pointmixer(pointboard,scoreboard,scorepoint);
    /*
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
            printf("%d ",pointboard[i][j]);
        printf("\n");
    }
    */
}

int upcheck(int i,int j,char board[8][8],char player){
    int counter,w=0;    
    i--;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i--;
            w++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return w;
        }
        if(i>7||j>7||i<0||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int downcheck(int i,int j,char board[8][8],char player){
    int counter,w=0;    
    i++;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i++;
            w++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return w;
        }
        if(i>7||j>7||i<0||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}

int leftcheck(int i,int j,char board[8][8],char player){
    int counter,w=0;    
    j--;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            j--;
            w++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return w;
        }
        if(i>7||j>7||i<0||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int rightcheck(int i,int j,char board[8][8],char player){
int counter,w=0;    
    j++;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            j++;
            w++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return w;
        }
        if(i>7||j>7||i<0||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int rightupcheck(int i,int j,char board[8][8],char player){
    int counter,w=0;    
    i--;
    j++;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i--;
            j++;
            w++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return w;
        }
        if(i>7||j>7||i<0||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int rightdowncheck(int i,int j,char board[8][8],char player){
    int counter,w=0;    
    i++;
    j++;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i++;
            j++;
            w++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return w;
        }
        if(i>7||j>7||i<0||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int leftupcheck(int i,int j,char board[8][8],char player){
    
    int counter,w=0;    
    i--;
    j--;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i--;
            j--;
            w++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return w;
        }
        if(i>7||j>7||i<0||j<0||board[i][j]=='0'){
            return 0;
        }
    }
    return 0;
}
int leftdowncheck(int i,int j,char board[8][8],char player){
    
    int counter,w=0;    
    i++;
    j--;
    for(counter=0;counter<8;counter++){
        if(board[i][j]==player){
            i++;
            j--;
            w++;
        }
        if(board[i][j]!=player&&board[i][j]!='0'){
            return w;
        }
        if(i>7||j>7||i<0||j<0||board[i][j]=='0'){
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
}

void score(int scoreboard[8][8],int scorepoint[8][8]){
    int i,j,k,g,h,m;
    for(m=0,h=7,g=8,k=100;m<4,g>4;m++,h-=2,g--,k-=20){
        for(i=m;i<g;i+=h){
            for(j=m;j<g;j++){
            scoreboard[i][j]=k;
            scoreboard[j][i]=k;
            }
        }
    }
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            scorepoint[i][j]=0;
}

void pointmixer(int pointboard[8][8],int scoreboard[8][8],int scorepoint[8][8]){
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            pointboard[i][j]=scoreboard[i][j]+scorepoint[i][j];
}

#include <stdio.h>

void Rowchecker(char board[8][8]);
int check(int i,int j);
int upcheck(int i,int j);
int downcheck(int i,int j);
int leftcheck(int i,int j);
int rightcheck(int i,int j);
int rightupcheck(int i,int j);
int rightdowncheck(int i,int j);
int leftupcheck(int i,int j);
int leftdowncheck(int i,int j);


int main(int argc,char* argv[])
{
    int i,j;
    char board[8][8];
    for(i=1;i<argc;i++){
        char *string=argv[i];
        for(j=0;j<8;j++)
            board[i][j]=(*(string + j));
    }
    /*
    for(i=1;i<argc;i++){
        for(j=0;j<8;j++)
            printf("%c ",board[i][j]);
        printf("\n");
    }
    */
    Rowchecker(board);
    return 0;
}

int upcheck(int i,int j){

}
int downcheck(int i,int j){
    
}
int leftcheck(int i,int j){
    
}
int rightcheck(int i,int j){
    
}
int rightupcheck(int i,int j){
    
}
int rightdowncheck(int i,int j){
    
}
int leftupcheck(int i,int j){
    
}
int leftdowncheck(int i,int j){
    
}

int check(int i,int j){
    upcheck(i,j);
    downcheck(i,j);
    leftcheck(i,j);
    rightcheck(i,j);
    rightupcheck(i,j);
    rightdowncheck(i,j);
    leftupcheck(i,j);
    leftdowncheck(i,j);
}
void Rowchecker(char board[8][8]){
    int i,j;
    for(int i=1;i<8;i++){
        for(j=0;j<8;j++){
            if (board[i][j]=='0'){
                check(i,j);
            }
        }
    }
}

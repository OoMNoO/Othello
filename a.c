#include <stdio.h>

void Rowchecker(char *string);
void check(char *string);
void upcheck(string);
void downcheck(string);
void leftcheck(string);
void rightcheck(string);
void rightupcheck(string);
void rightdowncheck(string);
void leftupcheck(string);
void leftdowncheck(string);

int main(int argc,char* argv[])
{
    int counter;
    printf("Program Name Is: %s",argv[0]);
    if(argc==1)
    printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
    if(argc>=2){
        for(counter=0;counter<argc;counter++){
            Rowchecker(argv[counter]);
        }
    }
    return 0;
}

void upcheck(string){

}
void downcheck(string){
    
}
void leftcheck(string){
    
}
void rightcheck(string){
    
}
void rightupcheck(string){
    
}
void rightdowncheck(string){
    
}
void leftupcheck(string){
    
}
void leftdowncheck(string){
    
}

void check(char *string){
    upcheck(string);
    downcheck(string);
    leftcheck(string);
    rightcheck(string);
    rightupcheck(string);
    rightdowncheck(string);
    leftupcheck(string);
    leftdowncheck(string);
}
void Rowchecker(char *string){
    for(int i=0;i<8;i++){
        if (*(string + i) == '0'){
            check((string + i));
        }
    }
}

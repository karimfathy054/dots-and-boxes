#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxsize 200
int checkedboxes =0;
void printarray(int rows ,int columns ,char arr[10][10]){
     for(int i=0;i<5;i++){
        for(int j=0; j<5 ; j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}
void checksquare (int size , int grid[20][20]){

    for(int i=0;i<size-2;i+=2){
        for(int j=0;j<size-1;j++){
            if((i%2==0 && j%2==0)/*||(i==j)*/){
                continue;
            }
            if(grid[i][j]!=' '&&grid[i+2][j]!=' '&&grid[i+1][j-1]!=' '&&grid[i+1][j+1]!=' '){
                checkedboxes++;
            }
        }
        //return checkedboxes;
    }
}
int main()
{
    int boardsize = 3;
    int boarddim = boardsize*2-1;
    char arr[boarddim][boarddim];

    for(int i=0;i<boarddim;i++){
        for(int j=0;j<boarddim;j++){
            if(i%2==0){
                if(j%2==0){
                    arr[i][j]='o';
                }
                else{
                    arr[i][j]=' ';
                }
            }
            else{
                arr[i][j]=' ';
            }
        }
    }
    for(int i=0;i<boarddim;i++){
        printf("    ");
        printf("%d",i);
    }
    printf("\n");
    for(int i=0;i<boarddim;i++){
            printf("%d | ",i);
        for(int j=0; j<boarddim ; j++){
            printf("%c    ",arr[i][j]);
        }
        printf("\n");
    }
    int availableboxes = (boarddim-boardsize)*(boarddim-boardsize);
    int checkedboxes = 0;

    int flag =1;


    //game loop;
    while(flag){
    int x , y ;
    printf("enter coordinates of line in the format (row number,column number) \n");
    scanf("%d %d",&x,&y);
    while(x==y || x>boarddim-1 || y>boarddim-1 || (x%2==0&&y%2==0)){
        printf("Enter valid coordinates\n");
        scanf("%d %d",&x,&y);
    }
    if (x%2==0){
        arr[x][y]='_';
    }
    else{
        arr[x][y]='|';
    }
    //printarray(x,y,arr);

    for(int i=0;i<boarddim;i++){
        printf("    ");
        printf("%d",i);
    }
    printf("\n");
    for(int i=0;i<boarddim;i++){
            printf("%d | ",i);
        for(int j=0; j<boarddim ; j++){
            printf("%c    ",arr[i][j]);
        }
        printf("\n");
    }
    checksquare(boarddim,arr);
    }
    availableboxes-= checkedboxes;
    if(availableboxes==0){
        flag=0;
    }
    printf("game over");
    return 0;
}

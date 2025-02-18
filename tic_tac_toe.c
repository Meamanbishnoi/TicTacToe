#include <stdio.h>
#include <stdbool.h>
#define true 1
#define false 0

int boxNo,player;
char arr[9]={'0','1','2','3','4','5','6','7','8'};
bool checkWin();
void showBoard();

int main(){
    int i=1;
    showBoard();
    printf("Game instruction: Type the no of box in which you want to type X or O\n");
    for(int i=1; i<=9; i++){
        if(i%2!=0){
            player=1; 
            printf("Player %dst Turn:\n",player);
            printf("Type Box No:");
            scanf("%d",&boxNo);
            if(boxNo<0 || boxNo>8){ //To check if user types something Invalid
                puts("Invalid Value...Type again!!");
                i--; 
                continue;;
            }
            if(arr[boxNo]=='X' || arr[boxNo]=='O'){
                puts("Place already filled...choose another space");
                i--;
                continue;
            } else arr[boxNo]='X';
            // arr[boxNo]='X';
            showBoard();
            checkWin();
            // printf("i = %d\n",i);
            if(checkWin()){ //Win Condition
                printf("Player %d has won!!",player);
                return 0;
            }
        } else {
            player=2;
            printf("Player %dnd Turn:\n",player);
            printf("Type Box No:");
            scanf("%d",&boxNo);
            if(boxNo<0 || boxNo>8){ //To check if user types something Invalid
                puts("Invalid Value...Type again!!");
                i--; 
                continue;
            }
            if(arr[boxNo]=='X' || arr[boxNo]=='O'){
                puts("Place already filled...choose another space");
                i--;
                continue;
            } else arr[boxNo]='O';
            // arr[boxNo]='O';
            showBoard();
            checkWin();
            // printf("i = %d\n",i);
            if(checkWin()){
                printf("Player %d has won!!",player);
                return 0;
            }
        }
    }
    printf(">>>>> Game Draw <<<<<");

    return 0;
}

bool checkWin(){
    //column win check
    if(arr[0]==arr[3] && arr[3]==arr[6]) return true;
    else if(arr[1]==arr[4] && arr[4]==arr[7]) return true;
    else if(arr[2]==arr[5] && arr[5]==arr[8]) return true;
    //rows win check
    else if(arr[0]==arr[1] && arr[1]==arr[2]) return true;
    else if(arr[3]==arr[4] && arr[4]==arr[5]) return true;
    else if(arr[6]==arr[7] && arr[7]==arr[8]) return true;
    //diagonal win check
    else if(arr[0]==arr[4] && arr[4]==arr[8]) return true;
    else if(arr[2]==arr[4] && arr[4]==arr[6]) return true;

    else return false;
}
void showBoard(){
    printf("            |           |           \n");
    printf("      %c     |     %c     |     %c     \n",arr[0],arr[1],arr[2]);
    printf("            |           |           \n");
    printf("------------|-----------|-----------\n");
    printf("            |           |           \n");
    printf("      %c     |     %c     |     %c     \n",arr[3],arr[4],arr[5]);
    printf("            |           |           \n");
    printf("------------|-----------|-----------\n");
    printf("            |           |           \n");
    printf("      %c     |     %c     |     %c     \n",arr[6],arr[7],arr[8]);
    printf("            |           |           \n");
}
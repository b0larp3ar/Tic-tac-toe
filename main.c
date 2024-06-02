#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char board[3][3]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '};
int es=0;
char winner=' ';
char player='X';
char computer='O';
char ch='y';


//print board------------
void printBoard(char b[3][3]){
  
  system("clear");
  
  printf("  %c  |  %c  |  %c  \n", b[0][0], b[0][1], b[0][2]);
  printf("_____|_____|______\n");
  printf("  %c  |  %c  |  %c  \n", b[1][0], b[1][1], b[1][2]);
  printf("_____|_____|______\n");
  printf("  %c  |  %c  |  %c  \n", b[2][0], b[2][1], b[2][2]);
  printf("     |     |      \n");
}




//empty spaces----------
int emptySpaces(char b[3][3]){
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      if (b[i][j]==' '){
        es++;
      }
    }
  }
  return es;
}





//player move------------
void playerMove(char b[3][3]){
  int x;
  int y;
  char pluh='y';
  
  while(pluh=='y'){
    printf("enter row(0/1/2):");
    scanf("%d", &x);
  
    printf("enter column(0/1/2)");
    scanf("%d", &y);
  
    if (b[x][y]!=' '){
      printf("Invalid move!");
    }
    
    else {
      b[x][y]=player;
      break;
    }
  }
  
  
}


//computer move-------------
void computerMove(char b[3][3]){
  char pluh='y';
  while (pluh=='y'){
    int x=rand() %3;
    int y=rand() %3;
    
    if(b[x][y]==' '){
      b[x][y]=computer;
      break;
    }
  }
  
  
}



//check winner-------
char checkWinner(char b[3][3]){
  //check rows
  for (int i=0; i<3; i++){
    if (b[i][0]==b[i][1] && b[i][0]==b[i][2]){
      if (b[i][0]==player){
        winner=player;
      }
      else if(b[i][0]==computer){
        winner=computer;
      }
    }
  }
  //check columns
  for (int j=0; j<3; j++){
    if(b[0][j]==b[1][j] && b[0][j]==b[2][j]){
      if (b[0][j]==player){
        winner=player;
      }
      
      else if (b[0][j]==computer){
        winner=computer;
      }
    }
  }
  //check diagonals
  if (b[0][0]==b[1][1] && b[0][0]==b[2][2]){
    if (b[0][0]==player){
      winner=player;
    }
    else if (b[0][0]==computer){
      winner=computer;
    }
  }
  if(b[0][2]==b[1][1] && b[0][2]==b[2][0]){
    if (b[0][2]==player){
      winner=player;
    }
    else if (b[0][2]==computer){
      winner=computer;
    }
  }
  
  return winner;
}




//print winner--------
void printWinner(char w){
  if (w==player){
    printf("You win!");
  }
  else if (w==computer){
    printf("You lose!");
  }
  else {
    printf("Tie!");
  }
}








//------------MAIN------------------
int main()
{
  while(ch=='y'){
    printBoard(board);
    
    es=emptySpaces(board);
    winner=checkWinner(board);
    
    if (es!=0){
        playerMove(board);
        
        es=emptySpaces(board);
        winner=checkWinner(board);
        
        if (es==0 || winner!=' '){
          printWinner(winner);
          
          printf("Play again?(y/n)");
          scanf("%s",&ch);
        }
        
        else if (es!=0){
          computerMove(board);
          
          es=emptySpaces(board);
          winner=checkWinner(board);
        }
        
    }
    
    else if (es==0 || winner!=' '){
      printWinner(winner);
          
      printf("Play again?(y/n)");
      scanf("%s",&ch);
    }
  }
    
   

  return 0;
}









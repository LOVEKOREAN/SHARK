#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h" 
//main.c에서 함수 호출가능? 
#define MAX_CHARNAME   200
#define N_PLAYER    3
#define MAX_DIE     6

#define PLAYERSTATUS_LIVE  0
#define PLAYERSTATUS_DIE   1
#define PLAYERSTATUS_END   2
 
int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0,1,2중에 하나를 가지는데 플레이어별로 가짐?? 
char player_statusString[3][MAX_CHARNAME]={"LIVE", "DIE", "END"}; 

 

void opening(void)
{
  printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  printf("<                                                  >\n");
  printf("<                   game start                     >\n");
  printf("<                                                  >\n");
  printf(" vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
}

int rolldie(void)
{
  return rand()%MAX_DIE+1;
}
 
void printPlayerPosition (int player)
{
     int i;
     for(i=0;i<N_BOARD;i++)
     {
           printf("|");
           if (i==player_position[player])
             printf("%c",player_name[player][0]); 
           else
           {
               if(board_getBoardStatus(i)==BOARDSTATUS_NOK)
                printf("X");
               else
                printf(" ");
            }
      }
      printf("|\n");
}

void printPlayerStatus(void)
{
  int i;
  for(i=0;i<N_PLAYER;i++)
   printf("%s :pos %i, coin %i, staus %s\n"
     ,player_name[i],player_position[i],player_coin[i],player_statusString[player_status[i]]);
  printf("----------------------------------------\n");
}  

void checkDie(void)
{
     int i;
     for(i=0;i<N_PLAYER;i++)
       if(board_getBoardStatus(player_position[i])==BOARDSTATUS_NOK)
         player_status[i]=PLAYERSTATUS_DIE;
}
int main(int argc, char *argv[])
{
  int pos=0;
  int i;
  int turn=0; 
  srand((unsigned)time(NULL));
  //0.opening 
  opening();
  
  //1.초기화 & 플레이어 이름 결정
  board_initBoard();
  //1-2.
  for(i=0;i<N_PLAYER;i++)
   {
        player_position[i]=0;
        player_coin[i]=0;
        player_status[i]=PLAYERSTATUS_LIVE;
        //player name
        
        printf("Player %i's name:", i);
        scanf("%s", player_name[i]);
    }
  //2.반복문(플레이어 턴)
  do {
      int step = rolldie();
      int coinResult;
      char c;
      
      if(player_status[turn]!=PLAYERSTATUS_LIVE)
      {
          turn=(turn+1)%N_PLAYER;
          continue;
       }
       
      //2-1.플레이어의 상태 출력
      board_printBoardStatus();
      for(i=0;i<N_PLAYER;i++)
         printPlayerPosition(i);
      printPlayerStatus();
      
      
     // pos+=step;
      //printf("차례를 시작하세요\n");
      //coinResult = board_getBoardCoin(pos);
          
     // printf("아무키나 눌러서 진행:");
      //scanf("%d", &c);
      //fflush(stdin) ;
      
     

   //2-2.주사위 던지기
   printf("%s turn!", player_name[turn]);
   printf("아무키나 눌러서 진행:");
   scanf("%d", &c);
   fflush(stdin) ; //버퍼에 있는거 제거하는 용도-scanf에서 입력받은거 제거 
   step=rolldie();
   
   //2-3.이동
   player_position[turn]+=step;
    if(player_position[turn]>=N_BOARD)
    {
      player_position[turn] = N_BOARD-1;
     }
    if (player_position[turn]==N_BOARD-1)
      player_status[turn]=PLAYERSTATUS_END;
   
   printf("주사위 결과 : %i, %s는 %i칸을 움직였습니다.\n",step,player_name[turn],step);
   //2-4.동전 줍기
   coinResult = board_getBoardCoin(pos);
   player_coin[turn] +=coinResult;
   printf("축하합니다! %s는 코인 %i개를 주웠습니다.\n",player_name[turn], coinResult);
   
   //2-5.다음턴
   turn= (turn+1)%N_PLAYER; //wrap around
   //2-6.if (조건: 모든 플레이어가 한 번씩 턴을 돈다) ->상어의 동작
   if (turn==0)
   {
             int shark_pos = board_stepShark();
             printf("상어가 움직였습니다!");
             checkDie();  
   }
 } while(1); //while 안에 조건 함수 이용해서 써넣기 
   //3.정리 (승자 계산, 출력 등)  
 int game_end(void)
 {
     int i;
     int flag_end = 1;
     
     for (i=0;i<N_PLAYER;i++)
     {
         if (player_status[i]==PLAYERSTATUS_LIVE)
         {
           flag_end=0;
           break;
           }
      }
      return flag_end;
 }     
 
 int getAlivePlayer(void)
 {
     int i;
     int cnt=0;
     for (i=0;i<N_PLAYER;i++)
     {
         if(player_status[i]==PLAYERSTATUS_END)
            cnt++;
      }
     return cnt;
}

int getWinner(void)
{
    int i;
    int winner;
    int max_coin=-1;
    
    for(i=0;i<N_PLAYER;i++)
    {
         if (player_coin[i]>max_coin)
         winner = i;
    }
  
  return winner;
}  
 
  system("PAUSE");	
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h" 
//main.c���� �Լ� ȣ�Ⱑ��? 
#define MAX_DIE     6
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
 
int main(int argc, char *argv[])
{
  int pos=0;
  srand((unsigned)time(NULL));
  //0.opening 
  opening();
  
  //1.�ʱ�ȭ & �÷��̾� �̸� ����
  int board_initBoard(void);
  //2.�ݺ���(�÷��̾� ��)
  do {
      int step = rolldie();
      int coinResult;
      char c;
      
      board_printBoardStatus();
      pos+=step;
      printf(" ");
      coinResult = board_getBoardCoin(pos);
          
      printf("�ƹ�Ű�� ������ ����:");
      scanf("%d", &c);
      fflush(stdin) ;
      
   //2-1.�÷��̾��� ���� ���
   //2-2.�ֻ��� ������
   //2-3.�̵�
   //2-4.���� �ݱ�
   //2-5.������
   //2-6.if (����: ��� �÷��̾ �� ���� ���� ����) ->����� ����
   
     } while(1);
   //3.���� (���� ���, ��� ��)  
 
  system("PAUSE");	
  return 0;
}
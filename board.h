//프로토타이핑해보기
#define N_BOARD         15
#define BOARDSTATUS_OK   1
#define BOARDSTATUS_NOK  0

 
int board_initBoard(void);
int board_printBoardStatus(void);

int board_getBoardCoin(int pos); //괄호 안에가 입력이 있는지?
int board_getSharkPosition(void);
int board_stepShark(void);
int board_getBoardStatus(int pos);

 

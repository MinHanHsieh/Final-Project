#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//72,80,75,77是方向鍵對應的鍵值
#define Space 32
#define Air 0
#define Dinosaur 1     //恐龍的座標標識
#define Obstacle 2      //障礙的座標標識
#define BAR 3       //牆的座標標識
void print_game(void);
//初始化地圖 130*25
char map[25][80];
int game, Dx,Dy,Ox,Ox2,Ox3,jump_temp,jump,DS;
game = 0;
jump = 0;
DS = 1;
int main()
{
	int x, y;
	Dx = 3; Ox = 48; Dy = 23;
	//初始化恐龍座標
	map[Dy][Dx] = Dinosaur;
	//初始化障礙座標
	map[23][Ox] = Obstacle;
	//邊界
	for ( x = 0; x < 25; x++)
	{
		for ( y = 0; y < 50; y++)
		{
			if (x==24)
				map[x][y] = BAR;
		}
	}
	while (1)
	{
		print_game();
		map[23][Ox] =Air;
		Ox--;
		map[23][Ox] = Obstacle;
		if (kbhit()!=0)
		{
			jump_temp = getch();
			if ((jump_temp==Space)&&(jump==0))
			{
				jump = 1;
			}
			jump_temp == 0;
		}
		if (jump==1)
		{
			map[Dy][Dx] = Air;
			if((0<DS)&&(DS<3))
			{
				Dy--;
				DS++;
			}
			else if (DS == 3)
			{
				DS = -1;
			}
			else if ((-3<DS)&&(DS < 0))
			{
				Dy++;
				DS--;
			}
			else if (DS == -3)
			{
				DS = 1;
				jump = 0;
			}
			map[Dy][Dx] = Dinosaur;
		}
		
		

	}

}
void print_game(void) {
	int i, j;
	//根據地圖上每點的情況繪製遊戲（ i 表示 x 軸，j 表示 y 軸），按行列印
	for (i = 0; i < 25;i++) 
	{
		for (j = 0; j < 50; j++) {
			//空白地方
			if (map[i][j] == 0) {
				printf("  ");
			}
			//恐龍
			else if (map[i][j] == Dinosaur) {
				printf("龍");
			}
			//圍欄
			else if (map[i][j] == BAR) {
				printf("地");
			}
			//障礙
			else if (map[i][j] == Obstacle) {
				printf("石");
			}
		}
		putchar('\n');
	}
	Sleep(1);     //休眠函式  
	system("cls");  //清屏函式 配合下一次 print_game() 起到重新整理作用，包含在stdlib.h中
}
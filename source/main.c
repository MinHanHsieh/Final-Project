#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//72,80,75,77�O��V����������
#define Space 32
#define Air 0
#define Dinosaur 1     //���s���y�м���
#define Obstacle 2      //��ê���y�м���
#define BAR 3       //�𪺮y�м���
void print_game(void);
//��l�Ʀa�� 130*25
char map[25][80];
int game, Dx,Dy,Ox,Ox2,Ox3,jump_temp,jump,DS;
game = 0;
jump = 0;
DS = 1;
int main()
{
	int x, y;
	Dx = 3; Ox = 48; Dy = 23;
	//��l�Ʈ��s�y��
	map[Dy][Dx] = Dinosaur;
	//��l�ƻ�ê�y��
	map[23][Ox] = Obstacle;
	//���
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
	//�ھڦa�ϤW�C�I�����pø�s�C���] i ��� x �b�Aj ��� y �b�^�A����C�L
	for (i = 0; i < 25;i++) 
	{
		for (j = 0; j < 50; j++) {
			//�ťզa��
			if (map[i][j] == 0) {
				printf("  ");
			}
			//���s
			else if (map[i][j] == Dinosaur) {
				printf("�s");
			}
			//����
			else if (map[i][j] == BAR) {
				printf("�a");
			}
			//��ê
			else if (map[i][j] == Obstacle) {
				printf("��");
			}
		}
		putchar('\n');
	}
	Sleep(1);     //��v�禡  
	system("cls");  //�M�̨禡 �t�X�U�@�� print_game() �_�쭫�s��z�@�ΡA�]�t�bstdlib.h��
}
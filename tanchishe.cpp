#include <stdio.h>
#include <windows.h>		//Sleep(int ms)调用
#include <stdlib.h>			//可以用里面的很多system("string");
#include <conio.h>			//int kbhit(),usleep(int ms)(但在这里这个函数无法调用，不知为何.
#include <time.h>	//用时间来做随机数的种子，生成真正随机数
#define w 10		//宽度
#define h 10		//高度

char bx=4, by=4, mx=4, my=4, ox=4, oy=4, key=1, foodx, foody,k[h][w];	//定义显示坐标位置，蛇头，首尾之间最后一个坐标，蛇尾，键值，食物,显示的10*10数组
char leng=1;	//定义长度，初始长度是1；
char body[64][2];			//记录蛇身，如果蛇头相加之后与蛇身之一相等则游戏结束，显示由长度计算出的相关分数
bool state, game_over=0;   //退出标志位

void disp(char k[h][w]);	//显示函数
void sfood();		//放置食物
void countb();		//计算身体的坐标
void tem();			//一时不知道怎么命名了，自己看着办
void Init();		//对整个显示矩阵的初始化
void over();		//程序结束
void turn(char d);	//走的方向，d用来传递方位，u,d,l,r，上下左右
void run();			//用int kbhit()判断是否有输入值，如果有则使用int getch()读出一个输入值

int main()
{
	while(!state)
    {
        Init();
        run();
    }
}

void Init()
{
    system("cls");
    bx=4, by=4, mx=4, my=4, ox=4, oy=4, key=1, leng=1, state=0, game_over=0;
	srand(time(NULL));	//设置种子，使用则是int rand();
	char m,n;
	for(m=0;m<h;m++)
	{
		for(n=0;n<w;n++)		//初始化边框，把内容全部弄成没有
		{
			if(m==0||m==(h-1)||n==0||n==(w-1))
				k[m][n]=4;
			else
				k[m][n]=0;
		}
	}
	k[bx][by]=2;	//3是桃心作为食物，2是笑脸做蛇身
	sfood();	//初始化一个食物、
	body[0][0]=bx;
	body[0][1]=by;
	disp(k);
}

void sfood()		//这里也可以修改用来加随机的墙
{
loop:foodx=rand()%(w-2)+1;
	foody=rand()%(h-2)+1;
	if(k[foody][foodx]!=2)
		k[foody][foodx]=3;
	else
		goto loop;
}

void run()
{
	while(key!='e' && !game_over)		//改变运行模式，以便测试，注释以上内容为一般贪吃蛇的运行模式
	//while((key=getch())!='e')
	{
		if(kbhit())		//获取输入并对相应值进行处理
			key=getch();
        if(key == 'q')
            state = 1;  //退出程序
		turn(key);
		disp(k);
	}
}

void turn(char d)
{
	static char t;
	if(key=='8'||key=='4'||key=='6'||key=='2')
		t=key;
	if(t=='8')
	{
		by--;
		tem();
	}
	else if(t=='6')
	{
		bx++;
		tem();
	}
	else if(t=='4')
	{
		bx--;
		tem();
	}
	else if(t=='2')
	{
		by++;
		tem();
	}
	countb();
}

void disp(char k[h][w])
{
	system("cls");
	char m,n;
	printf("	");
	for(m=0;m<h;m++)
	{
		for(n=0;n<w;n++)
			printf("%c ",k[m][n]);
		printf("\n	");
	}
	Sleep(300);	//显示完，停止半秒,相当于游戏难度，这里可以随机修改
}

void countb()	//身体数组计算
{
	char len;
	len=leng;
	while(--len){
		body[len][0]=body[len-1][0];
		body[len][1]=body[len-1][1];
	}
	body[0][0]=bx;body[0][1]=by;
	ox=body[leng-1][0];oy=body[leng-1][1];
}

void tem()
{
	if(k[by][bx]==2||k[by][bx]==4)		//如果蛇头遇到本来就是身体的或者边框则撞上了
		over();
	else if(k[by][bx]==3)	//如果蛇头遇到食物则加上
	{
		k[by][bx]=2;
		leng++;
		sfood();
	}
	else		//不是上面两种情况就只是移动
	{
		k[by][bx]=2;
		k[oy][ox]=0;
	}
}

void over()
{
    game_over = 1;
	char most;
	FILE* fp;
	if((fp=fopen("record.d","r+"))==NULL)
	{
		fp=fopen("record.d","w");
		fputc(leng,fp);
	}
	most=fgetc(fp);
	if(most<leng)
	{
		fp=fopen("record.d","w");
		fputc(leng,fp);
		most=leng;
	}
	fclose(fp);

	if(leng == (w * h -2))
        printf("    哥哥，你已经超神了好吗，地球人已经无法满足你了，还是去火星玩吧!!!!\n");
	printf("游戏结束，长度是%d,分数：%d\n	历史最高长度%d\n是否退出\ny/任意键:",leng,leng*leng+leng,most);
//	Sleep(10000);
//	system("pause");
    if('y' == getchar())
        state = 1;
}
//本来打算自己写一个贪吃蛇，弄好之后再弄到单片机8*8LED点阵上的，但是暂时不想了。革命尚未成功，同志仍需努力，虽然垃圾。不过你们还是可以参考弄到点阵上玩玩

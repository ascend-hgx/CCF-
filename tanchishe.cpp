#include <stdio.h>
#include <windows.h>		//Sleep(int ms)����
#include <stdlib.h>			//����������ĺܶ�system("string");
#include <conio.h>			//int kbhit(),usleep(int ms)(����������������޷����ã���֪Ϊ��.
#include <time.h>	//��ʱ����������������ӣ��������������
#define w 10		//���
#define h 10		//�߶�

char bx=4, by=4, mx=4, my=4, ox=4, oy=4, key=1, foodx, foody,k[h][w];	//������ʾ����λ�ã���ͷ����β֮�����һ�����꣬��β����ֵ��ʳ��,��ʾ��10*10����
char leng=1;	//���峤�ȣ���ʼ������1��
char body[64][2];			//��¼���������ͷ���֮��������֮һ�������Ϸ��������ʾ�ɳ��ȼ��������ط���
bool state, game_over=0;   //�˳���־λ

void disp(char k[h][w]);	//��ʾ����
void sfood();		//����ʳ��
void countb();		//�������������
void tem();			//һʱ��֪����ô�����ˣ��Լ����Ű�
void Init();		//��������ʾ����ĳ�ʼ��
void over();		//�������
void turn(char d);	//�ߵķ���d�������ݷ�λ��u,d,l,r����������
void run();			//��int kbhit()�ж��Ƿ�������ֵ���������ʹ��int getch()����һ������ֵ

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
	srand(time(NULL));	//�������ӣ�ʹ������int rand();
	char m,n;
	for(m=0;m<h;m++)
	{
		for(n=0;n<w;n++)		//��ʼ���߿򣬰�����ȫ��Ū��û��
		{
			if(m==0||m==(h-1)||n==0||n==(w-1))
				k[m][n]=4;
			else
				k[m][n]=0;
		}
	}
	k[bx][by]=2;	//3��������Ϊʳ�2��Ц��������
	sfood();	//��ʼ��һ��ʳ�
	body[0][0]=bx;
	body[0][1]=by;
	disp(k);
}

void sfood()		//����Ҳ�����޸������������ǽ
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
	while(key!='e' && !game_over)		//�ı�����ģʽ���Ա���ԣ�ע����������Ϊһ��̰���ߵ�����ģʽ
	//while((key=getch())!='e')
	{
		if(kbhit())		//��ȡ���벢����Ӧֵ���д���
			key=getch();
        if(key == 'q')
            state = 1;  //�˳�����
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
	Sleep(300);	//��ʾ�ֹ꣬ͣ����,�൱����Ϸ�Ѷȣ������������޸�
}

void countb()	//�����������
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
	if(k[by][bx]==2||k[by][bx]==4)		//�����ͷ����������������Ļ��߱߿���ײ����
		over();
	else if(k[by][bx]==3)	//�����ͷ����ʳ�������
	{
		k[by][bx]=2;
		leng++;
		sfood();
	}
	else		//�����������������ֻ���ƶ�
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
        printf("    ��磬���Ѿ������˺��𣬵������Ѿ��޷��������ˣ�����ȥ�������!!!!\n");
	printf("��Ϸ������������%d,������%d\n	��ʷ��߳���%d\n�Ƿ��˳�\ny/�����:",leng,leng*leng+leng,most);
//	Sleep(10000);
//	system("pause");
    if('y' == getchar())
        state = 1;
}
//���������Լ�дһ��̰���ߣ�Ū��֮����Ū����Ƭ��8*8LED�����ϵģ�������ʱ�����ˡ�������δ�ɹ���ͬ־����Ŭ������Ȼ�������������ǻ��ǿ��Բο�Ū������������

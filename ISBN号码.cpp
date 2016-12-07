#include <stdio.h>

void disp(char n[13]);
int main()
{
	char num[13];
	int sum;
	int i;

	for(i = 0; i < 12; i++)
    {
		num[i] = getchar();
		num[i] -= 48;
//        printf("%d\n", num[i]);
    }
    num[12] = getchar();
    if(num[12] == 'X')
        num[12] == 10;
    else
        num[12] -= 48;

	sum = num[0]*1;
	sum += num[2]*2 + num[3]*3 + num[4]*4;
	sum += num[6]*5 + num[7]*6 + num[8]*7 + num[9]*8 + num[10]*9;

	sum %= 11;
	if(sum == num[12])
		printf("Right");
	else if(sum == 10)
    {
		num[12] = 'X';
		disp(num);
    }
	else
    {
        num[12] = sum + 48;
        disp(num);
    }

	return 0;
}

void disp(char n[13])
{
    int i;
    for(i = 0; i < 12; i++)
    {
        n[i] += 48;
        putchar(n[i]);
    }
    putchar(n[12]);
}

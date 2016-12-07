#include <iostream>
#include <cmath>

using namespace std;

int maxday(int year,int month);
int isLeap(int year);

int main()
{
	int year;
	int num;
	cin >> year >> num;

	int last;
	int i;
	for(i = 1; i <= 12; i++)
	{
		last = num;
		num -= maxday(year, i);

		if(num <= 0)
		{
			num = last;
			break;
		}

	}

    cout << i << endl;
    cout << num << endl;
	return 0;
}

int maxday(int year,int month)
{
	int leap;
	leap = isLeap(year);

	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		return 31;
	else if(month != 2)
		return 30;

	if(isLeap(year))
		return 29;
	else
		return 28;
}

int isLeap(int year)
{
	int leap;
	if(year%4==0)
	{
		if(year%100==0)
		{
			if(year%400==0)
                leap=1;
			else
                leap=0;
		}
		else
            leap=1;
	}
	else
        leap=0;
	return leap;
}

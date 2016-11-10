#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n,num[1000];
	int max=0;
	cin >> n;
	for(int i=0; i < n; i++)
	{
		cin >> num[i];
	}
	
	int temp;
	for(int i=1; i < n; i++)
	{
		temp = abs(num[i] - num[i-1]);
		if(temp > max)
		{
			max = temp;
		}
	}
	cout << max;
	
	return 0;
}

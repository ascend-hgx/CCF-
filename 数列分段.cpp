#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n,num[1000];
	int max=0;
	cin >> n;
	for(int i=0; i < n; i++)
	{
		cin >> num[i];
		if(num[i] != num[i-1])
			max++;
	}

	cout << max;
	return 0;
}

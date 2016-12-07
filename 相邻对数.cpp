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
	}

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
		{
			if(num[i] == num[j] + 1 ||
			   num[i] == num[j] - 1)
				max++;
//            cout << "num" << num[i] << " " << num[j] << " " << max << endl;
		}
	cout << max;

	return 0;
}

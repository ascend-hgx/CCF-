#include <iostream>
#include <math.h>
using namespace std;

int cnt[1000];

int main()
{
	int n,num[1000];
	int max=0, ans;

	cin >> n;
	for(int i=0; i < n; i++)
	{
		cin >> num[i];
	}

	int temp;
	for(int i=0; i < n; i++)
		cnt[num[i]]++;
	for(int i=1; i < 1000; i++)
	{
//	    cout << cnt[i] << endl;
		if(cnt[i] > max)
		{
			max = cnt[i];
			ans = i;
		}
	}
	cout << ans;

	return 0;
}

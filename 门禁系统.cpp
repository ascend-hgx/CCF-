#include <iostream>
#include <cmath>
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
		cout << ++cnt[num[i]] << " ";
	}

	return 0;
}

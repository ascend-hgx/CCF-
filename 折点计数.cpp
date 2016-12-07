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

	for(int i=1; i < n -1; i++)
    {
        if(num[i-1] < num[i] &&
           num[i+1] < num[i])
            max++;
        if(num[i-1] > num[i] &&
           num[i+1] > num[i])
            max++;
//        cout << num[i] << " " << max << endl;
    }
	cout << max;
	return 0;
}

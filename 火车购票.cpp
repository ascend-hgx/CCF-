#include <iostream>
using namespace std;

int main()
{
	int n,num[100];
	int chg[20];
	cin >> n;
	for(int i=0; i < n; i++)
		cin >> num[i];
	for(int i=0; i < 20;i++)
		chg[i] = 5;

	for(int i=0; i < n; i++)
	{
		int temp = 0;
		int start;
		while(chg[temp] < num[i])
		{
            temp++;
		}
        start = (temp+1)*5 - chg[temp] + 1;
        chg[temp] -= num[i];

        for(int j = 0; j < num[i]; j++)
            cout << start++ << "	";
        cout << endl;
	}
}

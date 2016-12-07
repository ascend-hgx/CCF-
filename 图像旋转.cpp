#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,m;
	int num[1000][1000];
	int ans[1000][1000];

	cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> num[i][j];
            ans[m - j - 1][i] = num[i][j];
        }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}

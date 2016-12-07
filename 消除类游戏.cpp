#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    int i, j;
    int num[100][100];
    int flag[100][100];

    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> num[i][j];

    for(i = 0; i < n-2; i++)
        for(j = 0; j < m-2; j++)
        {
            if(num[i+1][j] == num[i][j] &&
               num[i+2][j] == num[i][j])
               flag[i][j] = 1, flag[i+1][j] = 1, flag[i+2][j] = 1;
            if(num[i][j+1] == num[i][j] &&
               num[i][j+2] == num[i][j])
               flag[i][j] = 1, flag[i][j+1] = 1, flag[i][j+2] = 1;
        }

    for(i = n-2; i < n; i++)
        for(j = 0; j < m-2; j++)
        {
            if(num[i][j+1] == num[i][j] &&
               num[i][j+2] == num[i][j])
               flag[i][j] = 1, flag[i][j+1] = 1, flag[i][j+2] = 1;
        }

    for(i = 0; i < n-2; i++)
        for(j = m-2; j < m; j++)
        {
            if(num[i+1][j] == num[i][j] &&
               num[i+2][j] == num[i][j])
               flag[i][j] = 1, flag[i+1][j] = 1, flag[i+2][j] = 1;
        }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(flag[i][j])
                num[i][j] = 0;

            cout << num[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}

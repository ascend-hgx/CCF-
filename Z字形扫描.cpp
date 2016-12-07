#include <iostream>
#include <cmath>

using namespace std;

int n, i, j;

void forward(int num[500][500], int n);
void backward(int num[500][500],int n);

void rforward(int num[500][500], int n, int m);
void rbackward(int num[500][500],int n, int m);

int main()
{
	int num[500][500];
	int flag;

	cin >> n;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			cin >> num[i][j];

    flag = 0;
	for(i = 0; i < n; i++)
	{
		if(flag)
		{
			flag = 0;
			forward(num, i);
		}
		else
		{
			flag = 1;
			backward(num,i);
		}
	}

//	flag = 0;
	for(i = 1; i < n; i++)
    {
//        cout << i << endl;
        if(flag)
		{
			flag = 0;
			rbackward(num,i, n);
		}
		else
		{
			flag = 1;
			rforward(num, i, n);
		}
    }

	return 0;
}

void forward(int num[500][500], int n)
{
    int i, j;
	for(i = 0, j = n; i <= n; i++, j--)
		cout << num[i][j] << " ";
}

void backward(int num[500][500],int n)
{
    int i, j;
	for(i = n, j = 0; j <= n; i--, j++)
		cout << num[i][j] << " ";
}

void rforward(int num[500][500], int n, int m)
{
    int i, j;
	for(i = m-1, j = n; j < m; i--, j++)
		cout << num[i][j] << " ";
}

void rbackward(int num[500][500],int n, int m)
{
    int i, j;
	for(j = m-1, i = n; i < m; j--, i++)
		cout << num[i][j] << " ";
}


#include <iostream>
#include <math.h>
using namespace std;

typedef struct route{
	int a;
    int b;
	int c;
}ROUTE; 

typedef struct node{
//	int  src;
    int *dst;
	int *length;
	int conNum=0;
}NODE; 

int main()
{
	int n,m;
	ROUTE rt[100];
	NODE  nd[100];

	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> rt[i].a >> rt[i].b >> rt[i].c;
		nd[rt[i].a].dst    = rt[i].b;
		nd[rt[i].a].length = rt[i].c;
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			
		}
	}

	return 0;
}

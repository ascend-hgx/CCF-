#include <iostream>
#include <cmath>

using namespace std;

typedef struct rect{
	int x1, y1;
	int x2, y2;
}Rect;

class window
{
	int num;
	Rect r;

public:
	void getRect(){cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;}
	void setIndex(int num){this->num = num;}

	int inWindow(int x, int y){
		if(r.x1 <= x && x <= r.x2 &&
		   r.y1 <= y && y <= r.y2)
		   return num;

		return 0;
	}
};

int main()
{
    int n, m;
	int x, y;
	int list[10];
	int ans[10];
	window w[10];

	cin >> n >> m;
	int temp = n;
	for(int i = 0; i < n; i++)
	{
	    list[i] = temp--;
		w[i].getRect();
		w[i].setIndex(i + 1);
	}

	int curr;
	int j;
	int cnt = 0;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;

		for(j = 0; j < n; j++)
		{
			curr = list[j];
			if(w[--curr].inWindow(x, y))
			{
                ans[cnt++] = ++curr;
				for(int z = j; z; z--)
					list[z] = list[z-1];
				list[0] = curr;

				break;
			}
		}

		if(j == n)
			ans[cnt++] = 0;
	}

	for(int i = 0; i < m; i++)
    {
        if(!ans[i])
            cout << "IGNORED" << endl;
        else
            cout << ans[i] << endl;
    }
	return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i, j, temp;
	char Exit = 0;
    int cow;
	int panel[16][10];
	int rect[4][4];
//	int cow = 3;
//	int panel[16][10] = {
//	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
//        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
//        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
//        1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
//        0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
//	int rect[4][4] = {
//        0, 0, 0, 0,
//        0, 1, 1, 1,
//        0, 0, 0, 1,
//        0, 0, 0, 0};

	for(i = 0; i < 15; i++)
		for(j = 0; j < 10; j++)
			cin >> panel[i][j];
	for(i = 0; i < 10; i++)
		panel[15][i] = 1;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			cin >> rect[i][j];
	cin >> cow;

    cow--;
	for(temp = 0; temp < 15; temp++)
	{
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
			{
				if(panel[temp + i][cow + j] && rect[i][j])
				{
					Exit = 1;
				}
			}

		if(Exit)
		{
			temp--;
			for(i = 0; i < 4; i++)
				for(j = 0; j < 4; j++)
				{
					panel[temp + i][cow + j] += rect[i][j];
				}
//            cout << temp << endl;
			break;
		}
	}

    for(i = 0; i < 15; i++)
    {
		for(j = 0; j < 10; j++)
			cout << panel[i][j] << " ";
        cout << endl;
    }

	return 0;
}

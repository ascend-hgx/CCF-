#include <iostream>
#include <cmath>
#include <map>

using namespace std;

void maxValue(map<int, int> &cnt);

int main()
{
	int n, i;
	int key;
	int num = 0;
	map<int, int> cnt;
	map<int, int>::iterator iter;

	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> key;
		iter = cnt.find(key);
		if(iter == cnt.end())
		{
			cnt.insert(map<int, int>::value_type(key, 1));
			num++;
		}
		else
		{
			iter->second++;		//equal cnt[key]++;
		}
	}

    for(i = 0; i < num; i++)
        maxValue(cnt);
	return 0;
}

void maxValue(map<int, int> &cnt)
{
	int maxValue = 0;
	int maxKey;
	map<int, int>::iterator iter;

	for(iter = cnt.begin(); iter != cnt.end(); iter++)
	{
//	    cout << iter->first << " " << iter->second <<endl;
        if(maxValue < iter->second)
        {
            maxValue = iter->second;
            maxKey   = iter->first;
        }
	}
    cnt.erase(maxKey);

	cout << maxKey << " " << maxValue <<endl;
}

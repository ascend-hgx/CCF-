#include <iostream>
#include <math.h>
using namespace std;

int cnt[1000];

bool have7(int num) {
    while (num > 10) {
        if (num % 10 == 7) {
            return true;
        }
        num /= 10;
    }
    if (num == 7) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int s;
    int user[4] = { 0, 0, 0, 0 };
    int i = 1, j = 0;
    int n = 1;

    cin >> s;
    while (i <= s) {
        if ((n % 7 == 0) | have7(n)) {
            user[j]++;
        }
        else {
            i++;
        }

        j++;
        n++;
        if (j >= 4)
            j = 0;
    }

    for (int i = 0; i < 4; i++) {
        cout << user[i] << endl;
    }

    return 0;
}


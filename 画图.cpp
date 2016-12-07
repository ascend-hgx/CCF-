#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Rect;

class Point{
public:
    int x;
    int y;

    Point(){}
    Point(int _x, int _y): x(_x), y(_y){}
    bool inRect(Rect rect);
};

class Rect{
public:
    Point start;
    Point over;

    Rect(){}
    Rect(int num)
    {
        start.x = start.y = num;
        over.x = over.y = num;
    }
};


int main()
{
    int n;
    int num = 0;
    cin >> n;
    vector<Rect> rects;
    Rect range(0);
    for(int i =0; i < n; i++)
    {
        Rect tempRect;
        cin >> tempRect.start.x >> tempRect.start.y >> tempRect.over.x >> tempRect.over.y;
        rects.push_back(tempRect);
    }

    range.start.x = rects.back().start.x;
    range.start.y = rects.back().start.y;
    for(int i =0; i < rects.size(); i++)
    {
        Rect rect = rects[i];
        if(rect.start.x < range.start.x)
            range.start.x = rect.start.x;
        if(rect.start.y < range.start.y)
            range.start.y = rect.start.y;
        if(rect.over.x > range.over.x)
            range.over.x = rect.over.x;
        if(rect.over.y > range.over.y)
            range.over.y = rect.over.y;
    }

    Point point;
    for(int i = range.start.x; i < range.over.x; i++)
    {
        for(int j = range.start.y; j < range.over.y; j++)
        {
            point = Point(i, j);
            for(int m = 0; m < n; m++)
            {
                if(point.inRect(rects[m]))
                {
//                    cout << point.x << "  " << point.y << " " << m << endl;
                    num++;
                    break;
                }
            }
        }
    }

    cout << num << endl;
    return 0;
}

bool Point::inRect(Rect rect)
{
    if(x >= rect.start.x &&
       y >= rect.start.y &&
       x < rect.over.x &&
       y < rect.over.y)
        return true;
    else
        return false;
}

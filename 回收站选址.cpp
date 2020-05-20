/* */
#include <iostream>
#include <list>
#include <vector>

//#define test

using namespace std;

typedef struct Point{
    int x;
    int y;
}Point;


int main(){
    vector <Point> pointList;
    Point point;
    int result[5] = {0, 0, 0, 0, 0};

    int totalNum;
    cin >> totalNum;

    if(totalNum > 0){
        for(int i = 0; i < totalNum; i++){
            cin >> point.x;
            cin >> point.y;
            pointList.push_back(point);             // push_back在链表的末端添加元素
        }

        #ifdef test
        //point = pointList.back();   // front得到起始变量，back得到末尾变量
        for(int i = 0; i < totalNum; i++){
            point = pointList[i];
            cout << point.x << " " << point.y << endl;
        }
        #endif // test


        //对每一个位置进行检测是否上下左右都有点，并且邻近的斜边是否也有
        for(int i = 0; i < totalNum; i++){
            int mustNum = 0;        // 上下左右
            int slope = 0;          // 斜边个数
            point = pointList[i];

            for(int j = 0; j < totalNum; j++ ){
                Point p = pointList[j];

                // 确定点的上下左右一个位置都有
                if((p.x - 1 == point.x && p.y == point.y) ||
                   (p.x + 1 == point.x && p.y == point.y) ||
                   (p.x == point.x && p.y + 1 == point.y) ||
                   (p.x == point.x && p.y - 1 == point.y))
                {
                    mustNum++;
                }
                // 确定斜边有
                if((p.x - 1 == point.x && p.y - 1 == point.y) ||
                   (p.x + 1 == point.x && p.y - 1 == point.y) ||
                   (p.x - 1 == point.x && p.y + 1 == point.y) ||
                   (p.x + 1 == point.x && p.y + 1 == point.y))
                {
                    slope++;
                }
            }

            if(mustNum == 4)
                result[slope]++;
        }

        for(int i = 0; i < 5; i++){
            cout << result[i] << endl;
        }
    }

    return 0;
}
/**/

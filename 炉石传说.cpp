#include <iostream>
#include <string>
using namespace std;

typedef struct obd{
//    int pos;
    int atk;
    int health;
}ODB;           //随从的位置，攻击力，生命值

class player
{
	int health;	//生命值
	int atk;	//攻击力
	ODB obd[7];	//随从

public:
	int win;    //胜负

	player():atk(0),health(30),win(1)
	{
		for(int i = 0; i < 7; i++)
		{
		    obd[i].atk = 0;
		    obd[i].health = 0;
		}
	}
	~player(){}
	void addObd(int pos, int atk, int health);
	void delObd(int pos);
	void hurt(int attackValue, int attackObj);
	void dispAtk(){cout << atk << endl;}
	void dispHealth(){cout << health << endl;}
	void dispOdb(int n)
	{
	    n--;
	    cout << "obd:" << n+1 << " atk:" << obd[n].atk << " health:" << obd[n].health << endl;
        }
    
        int getAtk(int pos){return obd[--pos].atk;}
        int getHealth(){return health;}
        int liveOdbNum();
};

int main()
{
    player p1, p2;
    string str;
    int n;
    int pos, atk, health;
    int atk1, atk2;
    int attacker, defender;
    bool state = 1;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
//        cout << p1.getHealth()  << endl;
//        cout << p1.liveOdbNum() << endl;
//        cout << p2.getHealth()  << endl;
//        cout << p2.liveOdbNum() << endl;
//        p1.dispOdb(1);p1.dispOdb(2);p1.dispOdb(3);
//        p2.dispOdb(1);p2.dispOdb(2);p2.dispOdb(3);

        if(state)
		{
			cin >> str;
			if(str == "end")
			{
				state = 0;
			}
			else{
				if(str == "summon")
				{
				    cin >> pos >> atk >> health;
				    p1.addObd(pos, atk, health);
				}
				else{
					cin >> attacker >> defender;
					atk1 = p1.getAtk(attacker);
					atk2 = p2.getAtk(defender);
					p2.hurt(atk1, defender);
					p1.hurt(atk2, attacker);
				}
			}
		}
		else
		{
			cin >> str;
			if(str == "end")
			{
				state = 1;
			}
			else{
				if(str == "summon")
				{
				    cin >> pos >> atk >> health;
				    p2.addObd(pos, atk, health);
				}
				else{
					cin >> attacker >> defender;
					atk2 = p2.getAtk(attacker);
					atk1 = p1.getAtk(defender);
					p1.hurt(atk2, defender);
					p2.hurt(atk1, attacker);
				}
			}
		}
    }

    if(p1.win && p1.win)
        cout << "0" << endl;
    else if(p1.win)
        cout << "1" << endl;
    else
        cout << "-1"<< endl;

    cout << p1.getHealth()  << endl;
    p1.liveOdbNum();
    cout << p2.getHealth()  << endl;
    p2.liveOdbNum();

	return 0;
}


void player::addObd(int pos, int atk, int health)
{
    pos--;
    for(int i = 6; i > pos; i--)
    {
        obd[i] = obd[i-1];
    }
    obd[pos].atk = atk;
    obd[pos].health = health;
}

void player::hurt(int attackValue, int attackObj)
{
    if(!attackObj)
    {
        health -= attackValue;
        if(health <= 0)
        {
            win = 0;
        }
    }
    else{
        attackObj--;
        obd[attackObj].health -= attackValue;

        if(obd[attackObj].health <= 0)
            delObd(++attackObj);
    }
}

void player::delObd(int pos)
{
    pos--;
    for(int i = pos; i < 6; i++)
    {
        obd[i] = obd[i+1];
    }
}

int player::liveOdbNum()
{
    int cnt = 0;
    for(int i = 0; i < 7; i++)
    {
        if(obd[i].health > 0)
            cnt++;
    }

    cout << cnt << " " ;
    for(int i = 0; i < 7; i++)
    {
        if(obd[i].health > 0)
            cout << obd[i].health << " " ;
    }
    cout << endl;

    return cnt;
}

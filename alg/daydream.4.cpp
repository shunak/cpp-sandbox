#include <string>
#include <iostream>

using namespace std;

void erase(string *s, int n)
{
    (*s).erase((*s).begin() + 0, (*s).begin() + n);
}

int main()
{
    string strs, strt;

    cin >> strs;

    bool answer = true; //最後の判定に使う
    while (strs.size() != 0)
    {

        //---最初の5文字がdreamでもeraseでもない場合---//
        if ((strs.substr(0, 5) != "erase") && (strs.substr(0, 5) != "dream"))
        {
            answer = false;
            break;
        }

        //---最初の5文字がdreamの場合---//
        if (strs.substr(0, 5) == "dream")
        {
            //---dreamの次にerが続く場合---//
            if (strs.substr(5, 2) == "er")
            {
                if (strs.substr(5, 5) == "erase")
                    erase(&strs, 5); //eraseが続く場合はdreamのみ消去
                else                 //if (strs.substr(5, 5) != "erase")
                    erase(&strs, 7); //erが続くがeraseではなかった場合はdreamerを消去
            }
            else
            {
                erase(&strs, 5); //dreamを消去
            }
        }

        //---最初の5文字がeraseの場合---//
        if (strs.substr(0, 5) == "erase")
        {
            //---eraseの次にrが続く場合---//
            if (strs[5] == 'r')
            {
                erase(&strs, 6); //eraserを消去
            }
            //---rが続かない場合---//
            else
                erase(&strs, 5); //eraseを消去
        }
    }

    if (answer)
        cout << "YES\n";
    else
        cout << "NO\n";
}
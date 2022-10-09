#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> stri{0};
void stringcq(string str0)
{
    for (int i = 0; i < int(str0.length()); i += 2)
    {
        if (str0[i + 1] == '1')
        {
            if (str0[i] == 'a')
                stri.push_back(1);
            else if (str0[i] == 'b')
                stri.push_back(2);
            else if (str0[i] == 'c')
                stri.push_back(3);
            else if (str0[i] == 'd')
                stri.push_back(4);
        }
        else if (str0[i + 1] == '2')
        {
            if (str0[i] == 'a')
                stri.push_back(5);
            else if (str0[i] == 'b')
                stri.push_back(6);
            else if (str0[i] == 'c')
                stri.push_back(7);
            else if (str0[i] == 'd')
                stri.push_back(8);
        }
        else
        {
            stri.push_back(0);
        }
    }
}

int main()
{

    stringcq("a1a2b1c2d1");
    vector<int> stri0{0, 2, 1, 5, 7};
    stri.assign(stri0.begin(), stri0.end());

    sort(stri.begin() + 1, stri.end());
    for (int i = 1; i < int(stri.size()); ++i)
    {
        switch (stri[i])
        {
        case 1:
            cout << "a1";
            break;
        case 2:
            cout << "b1";
            break;
        case 3:
            cout << "c1";
            break;
        case 4:
            cout << "d1";
            break;
        case 5:
            cout << "a2";
            break;
        case 6:
            cout << "b2";
            break;
        case 7:
            cout << "c2";
            break;
        case 8:
            cout << "d2";
            break;
        }
    }
}

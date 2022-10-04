#include "..//include//test1.hpp"
int G1 = 1;

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class terms
{
  private:
    int aandb[8];
    int a;
    int b;
    int c;
    int d;

  public:
    string term;
    void matrixmpy(bool);
    terms();
    terms(string, int[8]);
    terms(const terms &);
    void printmat();
    bool operator==(const terms &);
    bool operator<(const terms &);
};

void terms::matrixmpy(bool t)
{
    if (t == true)
    {
        this->a = max(this->a + aandb[1], this->b + aandb[3]);
        this->b = max(this->a + aandb[2], this->b + aandb[4]);
        this->c = max(this->c + aandb[1], this->d + aandb[3]);
        this->d = max(this->c + aandb[2], this->d + aandb[4]);
    }
    else
    {
        this->a = max(this->a + aandb[5], this->b + aandb[7]);
        this->b = max(this->a + aandb[6], this->b + aandb[8]);
        this->c = max(this->c + aandb[5], this->d + aandb[7]);
        this->d = max(this->c + aandb[6], this->d + aandb[8]);
    }
}
terms::terms(){};
terms::terms(string x0, int aandb[8]) : term(x0)
{
    a = 0;
    b = -2000000000;
    c = -2000000000;
    d = 0;
    int n = x0.length();
    bool t = true;
    for (int i = 0; i < n; ++i)
    {
        t = x0[i] == 'a';
        this->matrixmpy(t);
    }
}
terms::terms(const terms &term0)
{
    this->a = term0.a;
    this->b = term0.b;
    this->c = term0.c;
    this->d = term0.d;
    this->term = term0.term;
}
void terms::printmat()
{
    cout << a << "," << b << "," << c << "," << d << endl;
}
bool terms::operator==(const terms &x)
{
    if (this->b != x.b)
        return false;
    else if (this->c != x.c)
        return false;
    else if (this->d != x.d)
        return false;
    return true;
}
bool terms::operator<(const terms &x)
{
    if (this->a < x.a)
        return true;
    else if (this->a == x.a)
    {
        if (this->b < x.b)
            return true;
        else if (this->b == x.b)
        {
            if (this->c < x.c)
                return true;
            else if (this->c == x.c)
            {
                if (this->d < x.d)
                    return true;
            }
        }
    }
    return false;
}

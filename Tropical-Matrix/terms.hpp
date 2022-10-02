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
    int a;
    int b;
    int c;
    int d;

  public:
    string term;
    void matrixmpy(bool);
    terms();
    terms(string);
    terms(const terms &);
    void printmat();
    bool operator==(const terms &);
    bool operator<(const terms &);
};

void terms::matrixmpy(bool t)
{
    if (t == true)
    {
        this->a = max(this->a + A1, this->b + C1);
        this->b = max(this->a + B1, this->b + D1);
        this->c = max(this->c + A1, this->d + C1);
        this->d = max(this->c + B1, this->d + D1);
    }
    else
    {
        this->a = max(this->a + A2, this->b + C2);
        this->b = max(this->a + B2, this->b + D2);
        this->c = max(this->c + A2, this->d + C2);
        this->d = max(this->c + B2, this->d + D2);
    }
}
terms::terms(){};
terms::terms(string x0) : term(x0)
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
    return false;
}

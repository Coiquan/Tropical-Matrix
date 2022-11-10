
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace cq
{
class stringcq
{
  private:
    vector<int> stri{0};

  public:
    stringcq();
    stringcq(vector<int> stri0);
    stringcq(const stringcq &stri0);
    stringcq(string str0);
    stringcq operator+(stringcq stei0);
    bool operator<(const stringcq stri0) const;
    friend bool operator==(stringcq str1, stringcq str2);
    friend ostream &operator<<(ostream &coutao, stringcq stri);
};
class atom
{
  private:
    stringcq str0;

  public:
    atom();
    atom(stringcq str1);
    atom(const char *a);
    atom operator+(atom atom0);
    friend ostream &operator<<(ostream &coutao, atom &ao0);
};
class quarter
{
  private:
    vector<atom> quarter0{""};

  public:
    quarter();
    quarter(string str0);
    quarter(vector<atom> qtr);
    quarter(const quarter &qtr0);
    void print(ostream &cout0);
    quarter operator+(quarter qtr0);
    quarter &operator=(quarter qtr0);
    friend quarter mutqtr(quarter &a1, quarter &a2);
};
class matrix
{
  private:
    quarter qtr[4];

  public:
    void print(ostream &cout0);
    void printqtr(int i, ostream &cout0);
    void mut(matrix &mat0);
    matrix(string a, string b, string c, string d);
    matrix(const matrix &mat0);
    matrix(){};
};
class word
{
  private:
    string word0;
    matrix consq;

  public:
    void print(ostream &cout0);
    void printqtr(int i, ostream &cout0);
    word(string word1);
    word(){};
};
quarter mutqtr(quarter &a1, quarter &a2);
ostream &operator<<(ostream &coutao, atom &ao0);
ostream &operator<<(ostream &coutao, stringcq stri);
bool operator==(stringcq str1, stringcq str2);
} // namespace cq

void cq::word::print(ostream &cout0)
{
    consq.print(cout0);
}
void cq::word::printqtr(int i, ostream &cout0)
{
    if (i < 1 || i > 4)
        throw domain_error("1~4!");
    consq.printqtr(i, cout0);
}
cq::word::word(string word1) : word0(word1)
{
    bool t = true;
    matrix mata("a1", "b1", "c1", "d1");
    matrix matb("a2", "b2", "c2", "d2");
    if (word1[0] == 'a')
        consq = mata;
    else
        consq = matb;
    for (int i = 1; i < int(word1.length()); ++i) // test!!
    {
        t = word1[i] == 'a';
        if (t)
            consq.mut(mata);
        else
            consq.mut(matb);
    }
}

void cq::matrix::print(ostream &cout0)
{
    for (int i = 0; i < 4; ++i)
    {
        qtr[i].print(cout0);
        cout0 << endl;
    }
}
void cq::matrix::printqtr(int i, ostream &cout0)
{
    qtr[i].print(cout0);
}
void cq::matrix::mut(matrix &mat0)
{
    quarter ntr[4];
    for (int i = 0; i < 4; ++i)
    {
        ntr[i] = qtr[i];
    }
    qtr[0] = mutqtr(ntr[0], mat0.qtr[0]) + mutqtr(ntr[1], mat0.qtr[2]);
    qtr[1] = mutqtr(ntr[0], mat0.qtr[1]) + mutqtr(ntr[1], mat0.qtr[3]);
    qtr[2] = mutqtr(ntr[2], mat0.qtr[0]) + mutqtr(ntr[3], mat0.qtr[2]);
    qtr[3] = mutqtr(ntr[2], mat0.qtr[1]) + mutqtr(ntr[3], mat0.qtr[3]);
}
cq::matrix::matrix(string a, string b, string c, string d)
{
    quarter a_(a);
    qtr[0] = a_;
    quarter b_(b);
    qtr[1] = b_;
    quarter c_(c);
    qtr[2] = c_;
    quarter d_(d);
    qtr[3] = d_;
}
cq::matrix::matrix(const matrix &mat0)
{
    qtr[0] = mat0.qtr[0];
    qtr[1] = mat0.qtr[1];
    qtr[2] = mat0.qtr[2];
    qtr[3] = mat0.qtr[3];
}

cq::quarter::quarter(string str0)
{
    cq::atom ao0{str0};
    quarter0.push_back(ao0);
}
cq::quarter::quarter()
{
}
cq::quarter::quarter(const quarter &qtr0)
{
    quarter0.assign(qtr0.quarter0.begin(), qtr0.quarter0.end());
}
cq::quarter::quarter(vector<atom> qtr)
{
    quarter0.assign(qtr.begin(), qtr.end());
}
void cq::quarter::print(ostream &cout0)
{
    for (int i = 1; i < int(quarter0.size()); ++i)
    {
        cout0 << quarter0[i] << endl;
    }
}
cq::quarter cq::quarter::operator+(cq::quarter qtr0)
{
    vector<atom> qtrconsqs;
    qtrconsqs.assign(this->quarter0.begin(), this->quarter0.end());
    for (int i = 1; i < int(qtr0.quarter0.size()); ++i)
        qtrconsqs.push_back(qtr0.quarter0[i]);
    return qtrconsqs;
}
cq::quarter &cq::quarter::operator=(cq::quarter qtr0)
{
    quarter0.assign(qtr0.quarter0.begin(), qtr0.quarter0.end());
    return *this;
}
cq::quarter cq::mutqtr(cq::quarter &a1, cq::quarter &a2)
{
    vector<atom> qtrconsqs{""};
    for (int i = 1; i < int(a1.quarter0.size()); ++i)
        for (int j = 1; j < int(a2.quarter0.size()); ++j)
        {
            qtrconsqs.push_back(a1.quarter0[i] + a2.quarter0[j]);
        }
    return qtrconsqs;
}

cq::atom::atom()
{
    str0 = vector<int>{0};
}
cq::atom::atom(stringcq str1)
{
    str0 = str1;
}
cq::atom::atom(const char *a)
{
    str0 = string(a);
}
cq::atom cq::atom::operator+(cq::atom atom0)
{
    return str0 + atom0.str0;
}
ostream &cq::operator<<(ostream &coutao, cq::atom &ao0)
{
    coutao << ao0.str0;
    return coutao;
}

cq::stringcq::stringcq()
{
}
cq ::stringcq::stringcq(vector<int> stri0)
{
    stri.assign(stri0.begin(), stri0.end());
}
cq::stringcq::stringcq(const stringcq &stri0)
{
    stri.assign(stri0.stri.begin(), stri0.stri.end());
}
cq::stringcq::stringcq(string str0)
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
cq::stringcq cq::stringcq::operator+(stringcq stei0)
{
    vector<int> qtrconsqs;
    qtrconsqs.assign(this->stri.begin(), this->stri.end());
    for (int i = 1; i < int(stei0.stri.size()); ++i)
        qtrconsqs.push_back(stei0.stri[i]);
    return qtrconsqs;
}
bool cq::stringcq::operator<(const stringcq stri0) const
{
    int t1 = 0;
    int t2 = 0;
    for (auto i : stri)
    {
        t1 += i;
    }
    for (auto i : stri0.stri)
    {
        t2 += i;
    }
    if (t1 < t2)
        return true;
    else
        return false;
}
ostream &cq::operator<<(ostream &coutao, stringcq stri)
{
    sort(stri.stri.begin() + 1, stri.stri.end());
    for (int i = 1; i < int(stri.stri.size()); ++i)
    {
        switch (stri.stri[i])
        {
        case 1:
            coutao << "a1";
            break;
        case 2:
            coutao << "b1";
            break;
        case 3:
            coutao << "c1";
            break;
        case 4:
            coutao << "d1";
            break;
        case 5:
            coutao << "a2";
            break;
        case 6:
            coutao << "b2";
            break;
        case 7:
            coutao << "c2";
            break;
        case 8:
            coutao << "d2";
            break;
        }
    }
    return coutao;
}
bool cq::operator==(cq::stringcq str1, cq::stringcq str2)
{
    int len0 = int(str1.stri.size());
    if (int(str2.stri.size()) != len0)
        return false;
    for (int i = 1; i < len0; ++i)
    {
        if (str1.stri[i] != str2.stri[i])
            return false;
    }
    return true;
}
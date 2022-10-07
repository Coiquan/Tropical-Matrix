#include "./terms.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <random>
#include <vector>

namespace cq
{
int generator();
void countergnrt(int *);
int read(int, int, vector<terms> &, int *);
void print(int, bool &, int &, vector<terms> &, int *, int);
void remove(int);
int next(const int &);
int next(int &&);
void printctr(int *, int);
void init();
} // namespace cq
void gnrt(int, int, char[], int, fstream &);

int cq::generator()
{
    int N;
    cin >> N;
    if (N < 1 || N > 41)
    {
        cout << "?";
        exit(721);
    }
    char *term = new char[N];
    for (int A = 1, n1 = 0; A < N / 2 + 1; ++A, ++n1)
    {
        int B = N - A;
        fstream *file0 = new fstream;
        string name = "./output1/" + to_string(n1) + ".txt";
        file0->open(name, ios::out);
        gnrt(A, B, term, N, *file0);
        file0->close();
        delete file0;
    }
    delete[] term;
    return N;
}
void gnrt(int a, int b, char term[], int N, fstream &cout2f)
{
    if (a != 0)
    {
        term[N - a - b] = 'a';
        gnrt(a - 1, b, term, N, cout2f);
    }
    if (b != 0)
    {
        term[N - a - b] = 'b';
        gnrt(a, b - 1, term, N, cout2f);
    }
    if (a == 0 && b == 0)
    {
        for (int i = 0; i < N; ++i)
        {
            cout2f << term[i];
        }
        cout2f << endl;
    }
}
void cq::countergnrt(int *cou)
{
    int Max = 50000000;
    int Min = -50000000;
    random_device seed1;
    mt19937 gen1(seed1());
    uniform_int_distribution mm(Min, Max);
    for (int i = 0; i < 8; ++i)
    {
        cou[i] = mm(gen1);
    }
}
void cq::remove(int p0)
{
    string path;
    string strp = to_string(cq::next(cq::next(p0)));
    for (int i = 0;; ++i)
    {
        path = "./output" + strp + "/" + to_string(i) + ".txt";
        if (std::remove(path.c_str()) != 0)
            return;
    }
}
int cq::next(const int &p)
{
    int p0 = p;
    ++p0;
    if (p0 == 4)
        p0 = 1;
    return p0;
}
int cq::next(int &&p)
{
    int p0 = p;
    ++p0;
    if (p0 == 4)
        p0 = 1;
    return p0;
}
int cq::read(const int p0, const int n1, vector<terms> &termses, int *counter0)
{
    fstream *file0 = new fstream;
    string name = "./output" + to_string(p0) + "/" + to_string(n1) + ".txt";
    file0->open(name, ios::in);
    if (!(*file0))
    {
        file0->close();
        delete file0;
        return 1;
    }
    for (string str1; !file0->eof();)
    {
        str1 = "";
        *file0 >> str1;
        if (str1 == "")
            continue;
        terms *term0 = new terms(str1, counter0);
        termses.push_back(*term0);
        delete term0;
    }
    file0->close();
    delete file0;

    sort(termses.begin(), termses.end());
    return 0;
}
void cq::print(const int p0, bool &printb, int &n2, vector<terms> &termses, int *counters, int N)
{
    int szbu = 1;
    int sz = termses.size();

    int i = 1;
    fstream *file1;
    for (int p = 0; i < sz; ++i)
    {
        if (termses[i] == termses[i - 1])
        {
            if (p == 0)
            {
                p = 1;
                file1 = new fstream;
                string naabbme = "./output" + to_string(cq::next(p0)) + "/" + to_string(n2) + ".txt";
                file1->open(naabbme, ios::app);
            }
            *file1 << termses[i - 1].term << endl;
            ++szbu;
            if (i == sz - 1)
            {
                p = 0;
                *file1 << termses[i].term << endl;
                ++szbu;
                file1->close();
                delete file1;
                ++n2;
            }
        }
        else if (p == 1)
        {
            p = 0;
            *file1 << termses[i - 1].term << endl;
            ++szbu;
            file1->close();
            delete file1;
            ++n2;
        }
    }
    if (sz > szbu && printb)
    {
        cq::printctr(counters, N);
        printb = false;
    }
}
void cq::printctr(int *counters, const int N)
{
    fstream file0;
    file0.open("./counters" + to_string(N) + ".txt", ios::app);
    for (int i = 0; i < 8; ++i)
    {
        file0 << counters[i] << " ";
    }
    file0 << endl;
    file0.close();
}
void cq::init()
{
    cq::remove(1);
    cq::remove(2);
    cq::remove(3);
}
#include "terms.hpp"
#include <random>

void countergnrt(int *);
int read(int, vector<terms>);
int print();
void remove();

int main()
{
    int counter0[8];
    countergnrt(counter0);

    for (int p0 = 0;;)
    {
        vector<terms> termses; // terms...es?

        read(p0, termses);

        int n2 = 0;

        long long unsigned i = 1;
        fstream *file1;
        for (int p = 0; i < termses.size(); ++i)
        {
            if (termses[i] == termses[i - 1])
            {
                if (p == 0)
                {
                    p = 1;
                    file1 = new fstream;
                    string naabbme = to_string(G2) + "_" + to_string(n2) + ".txt";
                    file1->open(naabbme, ios::app);
                }
                *file1 << termses[i - 1].term << endl;
                if (i == termses.size() - 1)
                {
                    p = 0;
                    *file1 << termses[i].term << endl;
                    file1->close();
                    delete file1;
                    ++n2;
                }
            }
            else if (p == 1)
            {
                p = 0;
                *file1 << termses[i - 1].term << endl;
                file1->close();
                delete file1;
                ++n2;
            }
        }
    }
    if (p0 == 3)
        p0 = 1;
    else
        ++p0;
}

void countergnrt(int *cou)
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

int read(int p0, vector<terms> termses);
{
    for (int n1 = 0;; ++n1)
    {

        fstream *file0 = new fstream;
        string name = "../output" + to_string(p0) + "/" + to_string(n1) + ".txt";
        file0->open(name, ios::in);
        if (!file0)
        {
            file0->close();
            delete file0;
            break;
        }
        for (string str1; !file0->eof();)
        {
            str1 = "";
            *file0 >> str1;
            if (str1 == "")
                continue;
            terms *term0 = new terms(str1);
            termses.push_back(*term0);
            delete term0;
        }
        file0->close();
        delete file0;

        sort(termses.begin(), termses.end());
    }
}
#include "terms.hpp"

int main()
{
    int G2 = G1 + 1;
    int n2 = 0;
    for (int n1 = 0; n1 < 10; ++n1)
    {
        vector<terms> termses; // terms...es?
        fstream *file0 = new fstream;
        string name;
        if (G1 == 0)
            name = to_string(n1) + ".txt";
        else
            name = to_string(G1) + "_" + to_string(n1) + ".txt";
        name = "../output" + to_string(G1) + "/" + name;
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
        cout << n1;

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
}
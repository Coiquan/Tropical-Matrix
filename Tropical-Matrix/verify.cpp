#include "../include/verify.hpp"
#include <fstream>

string WORD1 = "abbaababba";
string WORD2 = "abbabaabba";
string DIGIT0 = "a"; // a or b or c or d;

class Ferror
{
  public:
    string what() const;
    Ferror(){};
};

void fprintword0(string, string);
void freadword(vector<cq::stringcq> &, string, string);
void freadword0(fstream &, vector<cq::stringcq> &);
void testfstream(fstream &f1);

int main()
{

    string word1 = WORD1;
    string word2 = WORD2;
    string Digit0 = DIGIT0;
    fprintword0(word1, Digit0);
    fprintword0(word2, Digit0);

    vector<cq::stringcq> st1;
    vector<cq::stringcq> st2;
    freadword(st1, word1, Digit0);
    freadword(st2, word2, Digit0);

    ofstream fc;
    fc.open(R"(E:\code\codes-I-write\cpp\project0\exe\)" + DIGIT0 + "intersctn" + ".txt");

    vector<cq::stringcq> c;
    /*for test*/ auto t = 0;
    for (auto i : st1)
    {
        /*for test*/ ++t;
        /*for test*/ cout << t << endl;
        int p = 0;
        for (auto j : st2)
            if (i == j)
                p = 1;
        if (p == 0)
            c.push_back(i);
    }
    for (auto i : c)
    {
        fc << i << endl;
    }
    fc.close();
}

string Ferror::what() const
{
    return ("file error");
}
void fprintword0(string word, string digit)
{
    int digit0 = char(digit[0]) - 'a' + 1;
    ofstream f11(word + "-" + digit + ".txt");
    cq::word a(word);
    a.printqtr(digit0, f11);
    f11.close();
}
void freadword(vector<cq::stringcq> &st1, string word, string digit)
{
    fstream f1(word + "-" + digit + ".txt");
    try
    {
        testfstream(f1);
    }
    catch (const Ferror &e)
    {
        std::cerr << e.what() << '\n';
    }
    freadword0(f1, st1);
    f1.close();
}
void freadword0(fstream &f1, vector<cq::stringcq> &st1)
{
    for (string str1; !f1.eof();)
    {
        str1 = "";
        f1 >> str1;
        if (str1 == "")
            continue;
        cq::stringcq cq1(str1);
        st1.push_back(cq1);
    }
}
void testfstream(fstream &f1)
{
    if (!f1)
    {
        f1.close();
        throw Ferror();
    }
}
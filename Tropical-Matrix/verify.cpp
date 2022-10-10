#include "../include/verify.hpp"
#include <fstream>
#include <set>

int main()
{
    ofstream f11;
    f11.open("abbaababb-b1.txt");
    cq::word a("abbaababb");
    a.printqtr(2, f11);
    f11.close();
    ofstream f12;
    f12.open("abbabaabb-b1.txt");
    cq::word b("abbabaabb");
    b.printqtr(2, f12);
    f12.close();

    set<cq::stringcq> st1;
    set<cq::stringcq> st2;
    fstream f1, f2;
    f1.open("abbaababb-b1.txt");
    f2.open("abbabaabb-b1.txt");
    if ((!f1) || (!f2))
    {
        f1.close();
        f2.close();
        return 0;
    }

    for (string str1; !f1.eof();)
    {
        str1 = "";
        f1 >> str1;
        if (str1 == "")
            continue;
        cq::stringcq cq1(str1);
        st1.insert(cq1);
    }

    for (string str1; !f2.eof();)
    {
        str1 = "";
        f2 >> str1;
        if (str1 == "")
            continue;
        cq::stringcq cq1(str1);
        st2.insert(cq1);
    }

    ofstream fc;
    fc.open("bintersectiontest.txt");
    if (!fc)
    {
        fc.close();
        cin.get();
        return 0;
    }
    set<cq::stringcq> c;
    set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(c, c.begin())); //?
    for (auto i : c)
    {
        fc << i << endl;
    }
    fc.close();
}
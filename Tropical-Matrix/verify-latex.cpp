#include "../include/verify-latex.hpp"
#include <fstream>

int main()
{
    ofstream f;
    f.open("abbaababba-latex.txt");
    cq::word a("abbaababba");
    a.print(f);
    f.close();
}
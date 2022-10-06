#include "../include/cq.hpp"

int main()
{
    cq::init();
    int counter0[8];
    int N = cq::generator();
    for (int p0 = 1;; p0 = cq::next(p0))
    {
        cq::countergnrt(counter0);
        bool printb = true;
        // ts
        cout << counter0[0] << endl;
        // st
        int n2 = 0;
        for (int n1 = 0;; ++n1)
        {
            vector<terms> termses; // terms...es?
            if (cq::read(p0, n1, termses, counter0) == 0)
            {
                cq::print(p0, printb, n2, termses, counter0, N);
                // test
                cout << termses.size() << endl;
                cin.get();
                // test
            }
            else if (n1 == 0)
                return 0;
            else
                break;
        }
        cq::remove(p0);
    }
}
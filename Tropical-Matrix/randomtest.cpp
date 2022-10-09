#include "../include/cq.hpp"

int main()
{
    int counter0[8];
    int N = 111111;
    for (int p0 = 1;; p0 = cq::next(p0))
    {
        cq::countergnrt(counter0);
        bool printb = true;
        int n2 = 0;
        for (int n1 = 0;; ++n1)
        {
            vector<terms> termses; // terms...es?
            if (cq::read(p0, n1, termses, counter0) == 0)
                cq::print(p0, printb, n2, termses, counter0, N);
            else if (n1 == 0)
                return 0;
            else
                break;
        }
        cq::remove(p0);
    }
}
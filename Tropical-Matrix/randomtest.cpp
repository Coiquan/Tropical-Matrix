#include "../include/cq.hpp"

int main()
{
    int p0 = 1;
    cout << cq::next(cq::next(p0));
    string path;
    string strp = to_string(cq::next(cq::next(p0)));
    for (int i = 0;; ++i)
    {
        path = "./output" + strp + "/" + to_string(i) + ".txt";
        if (std::remove(path.c_str()) != 0)
            cout << "cmn";
    }
}

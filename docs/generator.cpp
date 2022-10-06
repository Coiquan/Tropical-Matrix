#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void gnrt(int, int, char[], int, fstream &);
int main()
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
        string name = to_string(n1) + ".txt";
        file0->open(name, ios::out);
        gnrt(A, B, term, N, *file0);
        file0->close();
        delete file0;
    }
    delete[] term;
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
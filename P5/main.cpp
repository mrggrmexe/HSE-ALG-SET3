#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <cstdlib>
using namespace std;

const int MAXN = 4000;

void readMatrix(vector< bitset<MAXN> > &M, int n, int L) {
    for (int i = 0; i < n; ++i) {
        string tok;
        cin >> tok;
        bitset<MAXN> row;
        int col = 0;

        for (char ch : tok) {
            int val;
            if (ch >= '0' && ch <= '9') val = ch - '0';
            else if (ch >= 'A' && ch <= 'F') val = 10 + (ch - 'A');
            else if (ch >= 'a' && ch <= 'f') val = 10 + (ch - 'a');
            else val = 0;

            for (int bit = 3; bit >= 0 && col < n; --bit) {
                row[col] = (val >> bit) & 1;
                ++col;
            }
        }

        M[i] = row;
    }
}

inline void multiply(const vector< bitset<MAXN> > &M,
                     const bitset<MAXN> &x,
                     bitset<MAXN> &y,
                     int n) {
    for (int i = 0; i < n; ++i) {
        bitset<MAXN> tmp = M[i] & x;
        y[i] = (tmp.count() & 1u);
    }
    for (int i = n; i < MAXN; ++i) y[i] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    int L = (n + 3) / 4;

    vector<bitset<MAXN>> A(n), B(n), C(n);

    readMatrix(A, n, L);
    readMatrix(B, n, L);
    readMatrix(C, n, L);
  
    const int ITER = 25;

    srand(123456);

    bitset<MAXN> r, t, u, v;

    for (int it = 0; it < ITER; ++it) {
        do {
            for (int i = 0; i < n; ++i) {
                r[i] = rand() & 1;
            }
        } while (r.none());

        multiply(B, r, t, n);
        multiply(A, t, u, n);
        multiply(C, r, v, n);

        if (u != v) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

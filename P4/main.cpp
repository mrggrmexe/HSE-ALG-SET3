#include <iostream>
#include <vector>
using namespace std;

struct Fraction {
    int num;
    int den;
};

bool fractionLess(const Fraction &a, const Fraction &b) {
    long long left  = 1LL * a.num * b.den;
    long long right = 1LL * b.num * a.den;
    return left < right;
}

void mergeSort(std::vector<Fraction> &a,
               std::vector<Fraction> &temp,
               int l, int r)
{
    if (r - l <= 1) {
        return;
    }

    int m = (l + r) / 2;
    mergeSort(a, temp, l, m);
    mergeSort(a, temp, m, r);

    int i = l;
    int j = m;
    int k = l;

    while (i < m && j < r) {
        if (fractionLess(a[j], a[i])) {
            temp[k++] = a[j++];
        } else {
            temp[k++] = a[i++];
        }
    }

    while (i < m) {
        temp[k++] = a[i++];
    }
    while (j < r) {
        temp[k++] = a[j++];
    }

    for (int t = l; t < r; ++t) {
        a[t] = temp[t];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) {
        return 0;
    }

    vector<Fraction> fractions;
    fractions.reserve(N);

    for (int i = 0; i < N; ++i) {
        Fraction f;
        char slash;
        cin >> f.num >> slash >> f.den;
        fractions.push_back(f);
    }

    vector<Fraction> temp(N);
    mergeSort(fractions, temp, 0, N);

    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << fractions[i].num << '/' << fractions[i].den;
    }
    cout << '\n';

    return 0;
}

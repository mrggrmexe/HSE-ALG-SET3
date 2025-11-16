#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    std::vector<int32_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n <= 1) {
        if (n == 1) {
            cout << a[0];
        }
        return 0;
    }

    vector<int32_t> b(n);
    const int RADIX = 256;
    const uint32_t MASK = RADIX - 1;
    int cnt[RADIX];

    for (int pass = 0; pass < 4; ++pass) {
        fill(cnt, cnt + RADIX, 0);

        int shift = pass * 8;

        for (int i = 0; i < n; ++i) {
            uint32_t x = static_cast<uint32_t>(a[i]);
            uint32_t byte = (x >> shift) & MASK;
            if (pass == 3) {
                byte ^= 0x80u;
            }
            ++cnt[byte];
        }

        int sum = 0;
        for (int i = 0; i < RADIX; ++i) {
            int c = cnt[i];
            cnt[i] = sum;
            sum += c;
        }

        for (int i = 0; i < n; ++i) {
            uint32_t x = static_cast<uint32_t>(a[i]);
            uint32_t byte = (x >> shift) & MASK;
            if (pass == 3) {
                byte ^= 0x80u;
            }
            int pos = cnt[byte]++;
            b[pos] = a[i];
        }

        a.swap(b);
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }

    return 0;
}

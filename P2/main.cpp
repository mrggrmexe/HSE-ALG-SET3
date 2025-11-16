#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    const int MINV = -1000000;
    const int MAXV =  1000000;
    const int OFFSET = -MINV;
    const int RANGE  = MAXV - MINV + 1;

    vector<int> count(RANGE, 0);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        count[x + OFFSET]++;
    }

    string buffer;
    buffer.reserve(1 << 20);
    int remaining = n;

    for (int idx = 0; idx < RANGE; ++idx) {
        int cnt = count[idx];
        if (cnt == 0) continue;

        int value = idx + MINV;
        string s = to_string(value);

        while (cnt--) {
            buffer += s;
            --remaining;
            if (remaining > 0) {
                buffer.push_back(' ');
            }

            if (buffer.size() >= (1 << 20)) {
                cout << buffer;
                buffer.clear();
            }
        }
    }

    if (!buffer.empty()) {
        cout << buffer;
    }

    return 0;
}

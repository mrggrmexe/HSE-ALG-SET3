#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;

static inline uint64_t xorshift64(uint64_t &state) {
    state ^= state << 7;
    state ^= state >> 9;
    return state;
}

static inline double rand01(uint64_t &state) {
    const double inv = 1.0 / (1ULL << 53);
    return (xorshift64(state) >> 11) * inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x[3], y[3], r[3];
    for (int i = 0; i < 3; ++i) {
        if (!(cin >> x[i] >> y[i] >> r[i])) return 0;
    }

    double xmin = x[0] - r[0], xmax = x[0] + r[0];
    double ymin = y[0] - r[0], ymax = y[0] + r[0];
    for (int i = 1; i < 3; ++i) {
        xmin = min(xmin, x[i] - r[i]);
        xmax = max(xmax, x[i] + r[i]);
        ymin = min(ymin, y[i] - r[i]);
        ymax = max(ymax, y[i] + r[i]);
    }

    double width  = xmax - xmin;
    double height = ymax - ymin;
    double rectArea = width * height;

    double r2[3];
    for (int i = 0; i < 3; ++i) {
        r2[i] = r[i] * r[i];
    }

    const int N = 2000000;

    uint64_t state = 88172645463393265ULL;
    int hits = 0;

    for (int i = 0; i < N; ++i) {
        double rx = xmin + width  * rand01(state);
        double ry = ymin + height * rand01(state);

        bool inside = true;
        for (int k = 0; k < 3; ++k) {
            double dx = rx - x[k];
            double dy = ry - y[k];
            if (dx * dx + dy * dy > r2[k]) {
                inside = false;
                break;
            }
        }
        if (inside) ++hits;
    }

    double estimate = rectArea * (double)hits / (double)N;

    cout.setf(ios::fixed);
    cout << setprecision(12) << estimate << "\n";

    return 0;
}

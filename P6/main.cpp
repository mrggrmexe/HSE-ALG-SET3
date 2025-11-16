#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) {
        return 0;
    }

    if (N <= 3) {
        return 0;
    }

    vector<int> answer; answer.reserve(N);
  
    if (N % 6 != 2 && N % 6 != 3) {
        for (int i = 2; i <= N; i += 2) {
            answer.push_back(i);
        }
        for (int i = 1; i <= N; i += 2) {
            answer.push_back(i);
        }
    } else {
        vector<int> even; even.reserve(N);
        vector<int> odd; odd.reserve(N);

        for (int i = 2; i <= N; i += 2) {
            even.push_back(i);
        }
        for (int i = 1; i <= N; i += 2) {
            odd.push_back(i);
        }

        if (N % 6 == 2) {
            if (odd.size() >= 2) {
                swap(odd[0], odd[1]);
            }

            for (size_t i = 0; i < odd.size(); ++i) {
                if (odd[i] == 5) {
                    int v = odd[i];
                    odd.erase(odd.begin() + static_cast<long>(i));
                    odd.push_back(v);
                    break;
                }
            }
        } else {
            for (size_t i = 0; i < even.size(); ++i) {
                if (even[i] == 2) {
                    int v = even[i];
                    even.erase(even.begin() + static_cast<long>(i));
                    even.push_back(v);
                    break;
                }
            }
            vector<int> newOdd;
            newOdd.reserve(odd.size());
            for (int v : odd) {
                if (v != 1 && v != 3) {
                    newOdd.push_back(v);
                }
            }
            for (int x : {1, 3}) {
                for (int v : odd) {
                    if (v == x) {
                        newOdd.push_back(x);
                        break;
                    }
                }
            }
            odd.swap(newOdd);
        }
        answer.insert(answer.end(), even.begin(), even.end());
        answer.insert(answer.end(), odd.begin(), odd.end());
    }

    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';

    return 0;
}

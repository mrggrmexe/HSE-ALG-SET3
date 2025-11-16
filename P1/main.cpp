#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heapSize = 0;

void heapify(vector<long long> &A, int i) {
    while (true) {
        int largest = i;
        int left   = 2 * i + 1;
        int right  = 2 * i + 2;

        if (left < heapSize && A[left] > A[largest])
            largest = left;
        if (right < heapSize && A[right] > A[largest])
            largest = right;

        if (largest == i) {
            break;
        }

        swap(A[i], A[largest]);
        i = largest;
    }
}

void buildMaxHeap(vector<long long> &A) {
    heapSize = (int)A.size();
    for (int i = heapSize / 2 - 1; i >= 0; --i) {
        heapify(A, i);
    }
}

void heapSort(vector<long long> &A) {
    buildMaxHeap(A);
    for (int i = (int)A.size() - 1; i >= 1; --i) {
        swap(A[0], A[i]);
        --heapSize;
        heapify(A, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    heapSort(A);

    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ' ';
        cout << A[i];
    }
    cout << '\n';

    return 0;
}

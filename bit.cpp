#include <bits/stdc++.h>
using namespace std;

vector<long long> get_divisors(long long num) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            divisors.push_back(i);
            if (i != num / i) divisors.push_back(num / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    long long w, h, d, n;
    cin >> w >> h >> d >> n;
    auto divisors = get_divisors(n);
    for (auto x : divisors) {
        if (w % x != 0) continue;
        for (auto y : divisors) {
            if (h % y != 0) continue;
            long long prod = x * y;
            if (prod > n || n % prod != 0) continue;
            long long z = n / prod;
            if (d % z == 0) {
                cout << (x - 1) << " " << (y - 1) << " " << (z - 1) << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
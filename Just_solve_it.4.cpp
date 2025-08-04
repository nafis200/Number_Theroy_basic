#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

int main() {
   
    long long n, m, l, r;
    cin >> n >> m >> l >> r;

    long long lc = lcm(n, m);

    long long count = r / lc - (l - 1) / lc;
    cout << count << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 50007;
const int MOD = 1e9 + 7;
bool is_not_prime[N];
vector<int> primes;

void sieve() {
    is_not_prime[0] = is_not_prime[1] = true;
    for (int i = 2; i * i < N; i++) {
        if (!is_not_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_not_prime[j] = true;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (!is_not_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    sieve();
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 1;

        for (int i = 0; i < (int)primes.size() && primes[i] <= n; i++) {
            int p = primes[i];
            int exponent = 0;
            int temp = n;

            while (temp) {
                exponent += temp / p;
                temp /= p;
            }

            ans = (1LL * ans * (exponent + 1)) % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}

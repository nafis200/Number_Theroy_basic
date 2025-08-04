#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 20000000;
vector<bool> is_prime(LIMIT + 1, true);
vector<pair<int, int>> twin_primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 3; i + 2 <= LIMIT && twin_primes.size() < 100000; i++) {
        if (is_prime[i] && is_prime[i + 2]) {
            twin_primes.emplace_back(i, i + 2);
        }
    }
}

int main() {
    sieve();
    int s;
    while (cin >> s) {
        cout << "(" << twin_primes[s - 1].first << ", " << twin_primes[s - 1].second << ")\n";
    }
    return 0;
}

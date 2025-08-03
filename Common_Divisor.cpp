#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    long long g = 0;
    for(int i = 0; i < n; i++){
        g = __gcd(g, v[i]);
    }

    int ans = 0;
    for(long long i = 1; i * i <= g; i++){
        if(g % i == 0){
            ans++;
            if(i != g / i) ans++; 
        }
    }

    cout << ans << "\n";
}

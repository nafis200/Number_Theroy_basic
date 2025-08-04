#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
         int count = 0;
         vector<long long>v;
         long long n,a,b,c;
         cin >> n >> a >> b >> c;
         for(int i = 1; i * i <= n; i++){
             if(n % i == 0){
                v.push_back(i);
                if(n / i != i){
                    v.push_back(n / i);
                }
             }
         }
         for(auto it : v){
             for(auto it1 : v){
                int it2 = n / (it * it1);
                if(it <= a && it1 <= b && it2 <= c){
                        if(1LL * it * it1 * it2 == n){
                            count++;
                        }
                    }
             }
         }
         cout << count << "\n";
         count = 0;
    }
}
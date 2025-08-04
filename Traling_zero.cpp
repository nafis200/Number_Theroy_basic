#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 9;
bool vis[N];
#define faster ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
vector<int>v;
void sieve(){
   for(int i = 2; i * i <= N; i++){
      if(vis[i] == false){
         for(int j = i * i; j <= N; j+=i){
            vis[j] = true;
         }
      }
   }
   for(int i = 2; i <= N; i++){
      if(vis[i] == false){
         v.push_back(i);
      }
   }
}
int divisor(long long x){
    int ans = 1;
    for(int i = 0; 1LL * v[i] * v[i] <= x; i++){
       int count = 0;
       while(x % v[i] == 0){
           count++;
           x = x / v[i];
       }
       ans = ans * (count + 1);
    }
    if(x > 1){
      ans = ans * 2;
    }
    return ans;
}
int main()
{
    faster;
    sieve();
    int t; cin >> t;
    int cs = 0;
    while(t--){
       long long x; 
       cin >> x;
       cout << "Case " << ++cs << ": " << divisor(x) - 1 << "\n";
    }   
}

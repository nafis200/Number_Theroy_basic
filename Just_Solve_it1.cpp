#include<bits/stdc++.h>
using namespace std;
int binary_expoential(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1){
            ans = ans * a;
        }
        b = b / 2;
        a = a * a;
    }
    return ans;
}
int main(){
     int n; cin >> n;
     vector<int>v(n);
     for(int i = 0; i < n; i++){
        cin >> v[i];
     }
     for(int i = 0; i < n; i++){
         vector<int>v1;
         int lpf = 1e9;
         int gpf = 0;
         int dpf = 0;
         int tpf = 0;
         int nod = 1;
         int sod = 1;
         map<int,int>mp;

         int x = v[i];
         int ans = 1;
         for(int i = 2; i * i <= x; i++){
             if(v[i] % i == 0){
                while(x % i == 0){
                    mp[i]++;
                    x = x / i;
                }
             }
         }

         if(x > 1){
             mp[x]++;
         }
         for(auto it: mp){
            lpf = min(lpf,it.first);
         }
         for(auto it: mp){
            gpf = max(gpf,it.first);
         }
         dpf = mp.size();
         for(auto it: mp){
            tpf +=it.second;
         }

         for(auto it: mp){
            nod = nod * (it.second + 1);
         }

         for(auto it: mp){
            sod = sod * (binary_expoential(it.first,(it.second + 1)) - 1) / (it.first - 1);
         }

         cout << lpf << " " << gpf << " " << dpf << " " << tpf << " " << nod << " " << sod << "\n";

     }
}
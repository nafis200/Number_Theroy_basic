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
         int least_prime_factor = 1e9;
         int greatest_prime_factor = 0;
         int distnict_prime_factor = 0;
         int total_prime_factor = 0;
         int number_of_divisor = 1;
         int sum_of_divisor = 1;
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
            least_prime_factor = min(least_prime_factor,it.first);
         }
         for(auto it: mp){
            greatest_prime_factor = max(greatest_prime_factor,it.first);
         }
         distnict_prime_factor = mp.size();
         for(auto it: mp){
            total_prime_factor +=it.second;
         }

         for(auto it: mp){
            number_of_divisor = number_of_divisor * (it.second + 1);
         }

         for(auto it: mp){
            sum_of_divisor = sum_of_divisor * (binary_expoential(it.first,(it.second + 1)) - 1) / (it.first - 1);
         }

         cout << least_prime_factor << " " << greatest_prime_factor << " " << distnict_prime_factor << " " << total_prime_factor << " " << number_of_divisor << " " << sum_of_divisor << "\n";

     }
}
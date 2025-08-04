// both are accepted
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
bool prime[N];

void sieve()
{
    memset(prime, false, sizeof(prime));
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; 1LL * i * i < N; i++)
    {
        if (prime[i] == false)
        {

            for (int j = i * i; j < N; j += i)
            {
                prime[j] = true;
            }
        }
    }
}
void not_zero()
{
    for (int i = 2; i < N; i++)
    {
        if (prime[i] == false)
        {
            bool ok = false;
            int x = i;
            while (x > 0)
            {
                int digit = x % 10;
                x = x / 10;
                if (digit == 0)
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
            {
                prime[i] = true;
            }
        }
    }
}


void all_primes()
{
  
    for (int i = 2; i < N; i++)
    {
       
        if (prime[i] == false) 
        {
            string num = to_string(i);
            int len = num.size();
            for (int j = 0; j < len; j++)
            {
                string num1 = num.substr(j);
                int num2 = stoi(num1);
                if (prime[num2])
                {
                    prime[i] = true; 
                    break;
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    not_zero();
    all_primes();

    vector<int> v(N);
    for (int i = 2; i < N; i++)
    {
        v[i] = v[i - 1] + !prime[i];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[n] << "\n";
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 9;
// bool valid[N];
// bool is_prime[N];
// void sieve(){
//      for(int i = 2; i < N; i++){
//         is_prime[i] = true;
//      }
//      for(int i = 2; i < N; i++){
//          if(is_prime[i]){
//            for(int j = i + i; j < N; j += i){
//               is_prime[j] = false;
//            }
//          }
//      }
// }

// bool has_digit_zero(int x){
//     while(x){
//         if(x % 10 == 0){
//             return true;
//         }
//         x = x / 10;
//     }
//     return false;
// }

// bool is_valid(int x){
//     if(!is_prime[x]){
//         return false;
//     }
//     if(has_digit_zero(x)){
//         return false;
//     }
//     string s = to_string(x);
//     int len = s.size();
//     for(int i = 0; i < len; i++){
//         string suffix = s.substr(i);
//         int num = stoi(suffix);
//         if(!is_prime[num]){
//             return false;
//         }
//     }
//     return true;
// }
// int pref[N];
//  bool valid_[N];
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     memset(pref,0,sizeof(pref));
//     sieve();
//     for(int i = 1; i < N; i++){
//         valid_[i] = is_valid(i);
//     }
//     for(int i = 2; i < N; i++){
//          pref[i] = pref[i - 1] + valid_[i];
//     }
//  int t; cin >> t;
//     while(t--){
//         int x; cin >> x;
//         cout << pref[x] << "\n";
//     }
// }
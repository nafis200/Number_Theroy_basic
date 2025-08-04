#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int l, r;
    cin >> l >> r;
    if((r - l + 1) % 2 ){
       cout << "NO\n";
       return 0;
    }
    long long int ans = (r - l + 1) / 2;
    cout << "YES\n";
    while(ans--){
        cout << l << " " << l + 1 << "\n";
       l+=2;
    }
    return 0;
}
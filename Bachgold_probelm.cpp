#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int ans = 0;
    bool ok = false;
    if(n % 2 == 0){
     ok = true;
     ans = n / 2;
    }
    else{
        ans = n / 2;
        ans--;
    }
    cout << n / 2 << "\n"; 
    while(ans){
        cout << 2 << " ";
        ans--;
    }
    if(!ok){
        cout << 3;
    }
}
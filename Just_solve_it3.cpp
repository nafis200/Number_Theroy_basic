#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[1000] = {0};
    for(int i = 1; i <= 500; i++){
       for(int j = i; j <= 500; j+= i){
          a[j]++;
       }
    }

    for(int i = 1; i < 20; i++){
        cout << a[i] << " ";
    }
}
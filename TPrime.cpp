#include<bits/stdc++.h>
using namespace std;
bool vis[10000000];
void prime(){
     for(int i = 2; 1LL * i * i <= 1000002; i++){
        if(vis[i] == false){
          for(int j =1LL * i * i; j <= 1000002; j+= i){
             vis[j] = true;
          }
        }
     }
}
int main(){
   int n; cin >> n;
   memset(vis,false,sizeof(vis));
   prime();
   vis[1] = true;
   vis[0] = true;
   for(int i = 0; i < n; i++){
      long long x; cin >> x;
      int ans = sqrt(x);

      if(1LL * ans * ans == x && vis[ans] == false){
        cout << "YES\n";
      }
      else{
        cout << "NO\n";
      }
   }
   
}
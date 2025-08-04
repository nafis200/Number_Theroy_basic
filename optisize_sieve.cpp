#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
bool prime[N];

void sieve()
{
    memset(prime, false, sizeof(prime));
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

int main()
{
    sieve();
    int count = 0;
    for(int i = 2; i < 100000; i++){
        if(prime[i] == false){
            if(count % 100 == 0){
                cout << i << "\n";
            }
            count++;
        }
    }
}

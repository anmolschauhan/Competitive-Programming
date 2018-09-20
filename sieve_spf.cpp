#include <bits/stdc++.h>
#define MAXN 500050

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() 
{
    vector<int> spf(1000001, 0), prime;
    for(int i = 2; i <= 1000; i++)
        if(spf[i] == 0)
            for(int j = 2; i*j <= 1000000; j++)
                if(spf[i*j] == 0)
                    spf[i*j] = i;
    for(int i = 2; i <= 1000000; i++)
        if(spf[i] == 0)
            prime.push_back(i), spf[i] = i;
  // prime contains list of primes and spf[i] contains smallest prime factor of i for 2 <= i <= 1000000       
	return 0;
}

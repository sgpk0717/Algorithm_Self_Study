#include <iostream>  
#include <algorithm>
#include<cstdio>
#include<cmath>
#define N 200010
using namespace std;  

__int64 a[N];
__int64 pref[N];
__int64 suff[N];

int n, k, x;

int main(){
    scanf("%d%d%d", &n, &k, &x);
    long long maxN = 0;
    for(int i=1; i<=n; ++i)
        scanf("%I64d", &a[i]);
    long long xk = (long long)(pow((double)x, (double)k) + 0.5);
    for(int i=1; i<=n; ++i){
        pref[i] = pref[i-1] | a[i];
        suff[n-i+1] = suff[n-i+2] | a[n-i+1];
    }
    
    for(int i=1; i<=n; ++i){
        long long num = a[i]*xk | pref[i-1] | suff[i+1];
        if(maxN < num)
            maxN = num;
    }
    printf("%I64d\n", maxN);
    return 0;
}

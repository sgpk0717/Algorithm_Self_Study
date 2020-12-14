#include <iostream>
 
using namespace std;
 
int main(void)
{
    long long n;
    int cnt = 1;      
    long long range =1; 
    long long tmp =1;  
 
    cin >> n;
    while(true) {
        if(range >= n) break;
        tmp = 6*(cnt++);
        range += tmp;
    }
 
    cout << cnt << endl;
    
    return 0;
}

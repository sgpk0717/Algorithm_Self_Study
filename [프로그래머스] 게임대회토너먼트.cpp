#include <iostream>

using namespace std;

int exp(int n) {
    int exp=0;
    
    while(n>1) {
        n/=2;
        ++exp;
    }
    return exp;
}

int solution(int n, int a, int b)
{
    int answer;
    while(true) {
        int mid = n/2;
        if( (a>mid && b<=mid) || (a<=mid && b>mid) ) {
            answer = exp(n);
            break;
        }
        else {
            if(a>mid && b>mid) {
                a-=mid;
                b-=mid;
            }
            n/=2;
        }
    }
    

    return answer;
}

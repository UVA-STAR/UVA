#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;

int main() {
    int k,cunt=0,x,y;
    while(scanf("%d",&k)==1) {
        cunt=0;
        for(int y=k+1; y<=2*k; y++) {
            x=floor((double)1.0*(k*y)/(y-k)+0.5);
            if(x*(y-k)==k*y) cunt++;
        }
        //cout<<cunt<<endl;
        printf("%d\n",cunt);
        for(int y=k+1; y<=2*k; y++) {
            x=floor((double)1.0*(k*y)/(y-k)+0.5);
            if(x*(y-k)==k*y) {
                printf("1/%d = 1/%d + 1/%d\n",k,x,y);
            }
        }
    }
    return 0;
}

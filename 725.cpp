#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int used[10];

int solve(int a,int b) {
    int ans=0;
    memset(used,0,sizeof(used));
    for(int i=0; i<5; i++) {
        used[a%10]++;
        a/=10;
        used[b%10]++;
        b/=10;
    }
    for(int i=0; i<=9; i++)
        if(used[i]!=1) {
            ans=1;
            break;
        }
    return ans;
}

int main() {
    int n,flag=0;
    while(scanf("%d",&n)==1&&n) {
        if(flag==0) flag=1;
        else printf("\n");
        int flag2=0;
        for(int i=1234; i<=98765; i++) {
            int b=i*n;
            if(b<=98765&&b>=1234&&solve(b,i)==0) {
                flag2=1;
                printf("%05d / %05d = %d\n",b,i,n);
            }
        }
        if(flag2==0) printf("There are no solutions for %d.\n",n);
    }
    return 0;
}

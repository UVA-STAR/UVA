#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL a[20];
int main() {
    int n,cunt=0,k;
    while(scanf("%d",&n)==1) {
        for(int i=1; i<=n; i++) {
            scanf("%d",&k);
            a[i]=(long long)k;
        }
        LL ans=0LL;
        a[0]=1LL;
        /*for(int i=2; i<=n; i++) {
            a[i]=a[i-1]*a[i];
            //cout<<"debug"<<a[i]<<endl;
        }*/
        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j++) {
                LL nowans=1LL;
                for(int k=i; k<=j; k++)
                    nowans*=a[k];
                if(nowans>ans) ans=nowans;
            }
        printf("Case #%d: The maximum product is %lld.\n\n",++cunt,ans);
    }
    return 0;
}

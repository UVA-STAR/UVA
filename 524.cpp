#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int n;
int isp[40];
int A[40],vis[20];
int is_prime(int n) {
    int sqr=floor(sqrt(n));
    int ans=1;
    if(n==1) return ans=0;
    for(int i=2; i<=sqr; i++)//有等于号
        if(n%i==0) return ans=0;
    return ans;
}

void dfs(int cur) {
    if(cur==n&&isp[A[0]+A[n-1]]) {
        //cout<<"hehe"<<endl;
        for(int i=0; i<n; i++) {
            if(i!=0) printf(" ");//空格问题
            printf("%d",A[i]);
        }
        printf("\n");
    } else for(int i=2; i<=n; i++)//有等于号
            if(!vis[i]&&isp[i+A[cur-1]]) {
                A[cur]=i;
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;
            }
}

int main() {
    memset(isp,0,sizeof(isp));
    for(int i=2; i<=16*2; i++) {
        isp[i]=is_prime(i);
        //cout<<"hehe "<<i<<" "<<isp[i]<<endl;
    }
    int nCase=0;
    while(scanf("%d",&n)==1) {
        memset(vis,0,sizeof(vis));
        //vis[1]=1;
        if(nCase!=0) printf("\n");//空行
        printf("Case %d:\n",++nCase);
        A[0]=1;
        dfs(1);
        //printf("\n");
    }
    return 0;
}

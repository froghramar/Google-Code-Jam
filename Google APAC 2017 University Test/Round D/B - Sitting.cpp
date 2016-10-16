#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

int val(int x){
    return x / 3 * 2 + x % 3;
}

int calc(int x, int y){
    int cnt1 = val(y);
    int cnt2 = val(y - 1);
    int cnt3 = 1 + val(y - 2);
    int v1 = (x + 2) / 3;
    int v2 = (x + 1) / 3;
    int v3 = x / 3;
    int res = v1 * cnt1 + v3 * cnt2 + v2 * cnt3;
    if(x == 2) res = cnt1 * 2;
    return res;
}

void init(){
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("Case #%d: %d\n",t,max(calc(x,y), calc(y,x)));
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    init();
    return 0;
}
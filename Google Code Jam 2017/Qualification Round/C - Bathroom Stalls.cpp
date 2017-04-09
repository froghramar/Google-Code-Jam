#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

long long n, k;
map <long long,long long> cnt;

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%lld%lld",&n,&k);
		cnt.clear();
		cnt[n] = 1;
		while(1){
			long long key = cnt.rbegin()->first;
			long long val = cnt.rbegin()->second;
			if(val >= k){
				break;
			}
			k -= val;
			cnt.erase(--cnt.end());
			if(cnt[(key - 1) >> 1] < (long long)1e18) cnt[(key - 1) >> 1] += val;
			if(cnt[key >> 1] < (long long)1e18) cnt[key >> 1] += val;
		}
		long long x = cnt.rbegin()->first;
		printf("Case #%d: %lld %lld\n", t, x >> 1, (x - 1) >> 1);
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
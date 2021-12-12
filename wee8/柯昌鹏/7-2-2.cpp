#include<bits/stdc++.h>
using namespace std;
const int Max = 1e6+10;
int a[Max];
int find(int n, int m){
	int res = n+1;
	for(int i = n; i <= m; i ++){
		if(a[n] < a[i]){
			a[n] = a[i];
			res = i;
		}
	}
	return res;
}
int link(int n, int m){
	int res = n;
	for(int i = res; i <= m; i ++){
		if(a[n] < a[i]+(i-n)){
			n = i;
		}
	}
	return n;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	int k = 0, ress = 1; // 最少跳一次
	while(k+a[k] < n-1){
        int p = a[k]; // 防丢失
		int m = find(k,a[k]+k); // 寻找k到a[k]+k之内最大值所在的位置
		k = link(m,p+k); // 寻找要跳入的位置上
		ress ++;
	}
	cout << ress << endl;
    return 0;
}

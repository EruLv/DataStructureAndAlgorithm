#include<iostream>
using namespace std;

const int N = 100000;

int h[N];	//模拟堆 
int n, m;	//n:元素个数，m:前m小的数 
 
void down(int u){
	//自上而下调整节点
	int t = u;	//最小下标 
	//左孩子 
	if (u * 2 <= n && h[u * 2] < h[t]) t = u * 2;
	//右孩子 
	if(u * 2 + 1 <=n && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	if(u != t){
		swap(h[u], h[t]);
		down(t);
	} 
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++ ) cin >> h[i];
	
	//初始化堆O(n)
	for(int i = n / 2; i >= 1; i--) down(i);
	
	while(m--){
		cout << h[1] <<" ";
		h[1] = h[n];
		n--;
		down(1);
	}
	cout << endl;
	return 0;
} 

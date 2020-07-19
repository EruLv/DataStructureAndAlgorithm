#include<iostream>
using namespace std;

const int N = 100000;

int h[N];	//ģ��� 
int n, m;	//n:Ԫ�ظ�����m:ǰmС���� 
 
void down(int u){
	//���϶��µ����ڵ�
	int t = u;	//��С�±� 
	//���� 
	if (u * 2 <= n && h[u * 2] < h[t]) t = u * 2;
	//�Һ��� 
	if(u * 2 + 1 <=n && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	if(u != t){
		swap(h[u], h[t]);
		down(t);
	} 
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++ ) cin >> h[i];
	
	//��ʼ����O(n)
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

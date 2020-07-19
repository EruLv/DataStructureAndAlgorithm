#include<iostream>
using namespace std;

const int N = 100000, INF = 0x3f3f3f3f;

int a[N];
int n;

//ð������һ�αȽ��������ڵ�����O(n^2) 
void BubbleSort(){
	for(int i = 0; i < n; i++){
		for(int j = 0;j < n-1; j++){
			if(a[j] > a[j+1]) swap(a[j],a[j+1]);
		}
	}
}

//ѡ������ 
void SelectSort(){
	for(int i = 0; i < n; i++){
		int idx = -1, m = INF;
		//����СԪ�� 
		for(int j = i; j <n ;j++){
			if(a[j] < m){
				m = a[j];
				idx = j;
			}
		}
		//�ŵ�ǰ���Ѿ��ź����ĩβ 
		swap(a[i],a[idx]); 
	} 
} 

//�������� 
void InsertSort(){
	for(int i = 1; i < n; i++){
		//����i�������뵽ǰ�泤��Ϊi - 1������������
		//�Ӻ���ǰ�����ȽϷ��棬����ֱ�ӽ��� 
		for(int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--)
			swap(a[j],a[j+1]);
	}
} 


void Print(){
	for(int i = 0; i < n; i++) cout << a[i] <<" ";
	cout << endl;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i] = x;
	}
	BubbleSort();
	SelectSort();
	InsertSort();
	Print();
	return 0;
}

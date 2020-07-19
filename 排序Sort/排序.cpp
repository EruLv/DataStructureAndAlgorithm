#include<iostream>
using namespace std;

const int N = 100000, INF = 0x3f3f3f3f;

int a[N];
int n;

//冒泡排序，一次比较两个相邻的数，O(n^2) 
void BubbleSort(){
	for(int i = 0; i < n; i++){
		for(int j = 0;j < n-1; j++){
			if(a[j] > a[j+1]) swap(a[j],a[j+1]);
		}
	}
}

//选择排序 
void SelectSort(){
	for(int i = 0; i < n; i++){
		int idx = -1, m = INF;
		//找最小元素 
		for(int j = i; j <n ;j++){
			if(a[j] < m){
				m = a[j];
				idx = j;
			}
		}
		//放到前端已经排好序的末尾 
		swap(a[i],a[idx]); 
	} 
} 

//插入排序 
void InsertSort(){
	for(int i = 1; i < n; i++){
		//将第i个数插入到前面长度为i - 1的有序数组中
		//从后向前遍历比较方面，可以直接交换 
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

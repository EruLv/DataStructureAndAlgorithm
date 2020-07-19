#include<iostream>
using namespace std;

const int N = 100000;

int n;
int a[N];
int tmp[N];	//�鲢������

 
//����
void quick_sort(int q[], int l, int r){
	if(l >= r) return;
	int i = l , j = r , x = q[l + r >> 1];
	while(i < j){
		while(q[i] < x) i++;
		while(q[j] > x) j--;
		if(i < j) swap(q[i],q[j]);
	}
	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}

//�鲢���� 
void merge_sort(int q[], int l, int r){
	if(l >= r) return;
	//�Ƚ�mid���������ź��� 
	int mid = l + r >> 1;
	merge_sort(q,l,mid);
    merge_sort(q, mid+1, r);
    //�����߹鲢���ִ���tmp������ 
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <q [j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    //��tmp����ź�������ݷŻ�ԭ���� 
    for(int i = l, j = 0; i <= r;  i++,j++) q[i] = tmp[j];
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
	quick_sort(a,0,n-1);
	merge_sort(a,0,n-1); 
	Print();
	return 0;
} 

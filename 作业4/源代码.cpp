#include<iostream>
using namespace std;

int Merge(int a[],int left,int mid,int right){
	int i,j,k,b[999];
	i=left;
	j=mid+1;
	k=left;
	while(i<=mid&&j<=right){
		if(a[i]<a[j])
		    b[k++]=a[i++];
		else
		    b[k++]=a[j++];
	}
	while(i<=mid){
		b[k++]=a[i++];
	}
	while(k<=right){
		b[k++]=a[j++];
	}
	for(k=left;k<=right;k++){
		a[k]=b[k];
	}
}
int MergeSort(int a[],int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);
		Merge(a,left,mid,right);
	}
}
int main(){
	int n;
	cout<<"请输入元素个数:";
	cin>>n;
	cout<<"请输入元素：";
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	MergeSort(a,0,n);
	for(int i=0;i<n-1;i++)
	cout<<a[i]<<',';
	cout<<a[n-1];
} 

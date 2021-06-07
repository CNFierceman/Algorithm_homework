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

int select(int a[],int left,int right,int k){
	int n=right-left;
	if(n<=5){
		MergeSort(a,left,right);
		return a[left+k];
	}
	int t=n/5;
	int m[t];
	for(int i=0;i<t;i++){
		MergeSort(a,left+i*5,left+i*5+5);
		m[i]=a[left+i*5+2];
	}
	MergeSort(m,0,t);
	int mid=m[t/2];
	int a1[n],a2[n],a3[n];
	int s1=0,s2=0,s3=0;
	for(int i=left;i<right;i++){
		if(a[i]<mid){
			a1[s1++]=a[i];
		}
		else if(a[i]==mid){
			a2[s2++]=a[i];
		}
		else{
			a3[s3++]=a[i];
		}
	}
	if(s1>=k){
		return select(a1,0,s1,k);
	}
	if(s1+s2>=k){
		return mid;
	}
	else
		return select(a3,0,s3,k-s1-s2);
}

int main(){
	int n;
	cout<<"请输入数组的元素个数n：";
	cin>>n;
	int a[n];
	cout<<"请输入数组元素："<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cout<<"请输入要找的第k小的元素"<<endl;
	cin>>k;
	cout<<select(a,0,n,k);
} 

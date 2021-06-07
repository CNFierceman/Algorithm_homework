#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node{
	float v;
	float w;
	float vw;
}node;

bool cmp(node x,node y)
{
	if(x.vw>y.vw)
		return true;
	else
		return false;
}
void knapsack(int n,float b,float w[],float v[]){
	Node node[n];
	float sum=0;
	for(int i=0;i<n;i++){
		node[i].v=v[i];
		node[i].w=w[i];
		node[i].vw=node[i].v/node[i].w;
	}
	sort(node,node+n,cmp);
	float t=b;
	for(int i=0;i<n;i++){
		if(t<node[i].w)
			continue;
		sum+=node[i].v;
		t-=node[i].w;
	}
	cout<<"����������ֵΪ��"<<sum;
}

int main(){
	int n;
	float b;
	cout<<"�����빲�м�����Ʒ�����������������Ƕ���:"; 
	cin>>n>>b;
	float w[n],v[n];
	cout<<"������������Ʒ��Ӧ�������ͼ�ֵ:"<<endl;
	for(int i=0;i<n;i++){
		cin>>w[i];
		cin>>v[i];
	}

	knapsack(n,b,w,v);
} 

#include<iostream>
#include<stdlib.h>
#define n 6
using namespace std;
struct Node{
	int a;//�ߵ���� 
	int b;//�ߵ��յ� 
	int l;//�ߵĳ��� 
};
Node node[n]; 
int cmp(const void *a, const void *b) {
    return (*(Node *)a).l - (*(Node*)b).l;
}

int father[n]={0};
int cap[n]={0};


int edge[n][3]=//�ߵ����ԣ���㣬�յ㣬Ȩֵ 
{
{0,1,3},
{0,2,4},
{1,2,6},
{1,3,7},
{2,3,2},
{2,4,1}
};

void make_set(){
	for(int i=0;i<n;i++){
		father[i]=i;
		cap[i]=1;
	}
}

int find(int x){
	if(x!=father[x])
	    father[x]=find(father[x]);
	return father[x];
}


void Union(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)
    	return ;
  	if(cap[x]<cap[y])
    	father[x]=find(y);
	else{
		if(cap[x]==cap[y])
    		cap[x]++;
	  	father[y]=find(x);
	}
}

int Kruskal(int x){
	int sum=0;
	make_set();
	for(int i=0;i<n;i++){
		if(find(node[i].a)!=find(node[i].b)){
			Union(node[i].a,node[i].b);
			sum+=node[i].l;
		}
	}
	return sum;
}

int main(){
	for(int i=0;i<n;i++){
		node[i].a=edge[i][0];
		node[i].b=edge[i][1];
		node[i].l=edge[i][2];
	}
	qsort(node,n,sizeof(node[0]),cmp);//������������С��������
	cout<<Kruskal(0)<<endl;
	 
}

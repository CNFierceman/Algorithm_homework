#include<iostream>
using namespace std;
const int n=5;
const int INF=99999; 
int graph[n][n]=
{
{INF,3,4,INF,INF},
{3,INF,6,7,INF},
{4,6,INF,2,1},
{INF,7,2,INF,INF},
{INF,INF,1,INF,INF}
};//��¼ÿ����֮��ľ��룬INF��������֮�䲻�ɴ� 

int dist[n]={0};

int Prim(int start){
	int index=start;
	int sum=0;
	int i,j;
	cout<<start;
	bool book[n];
	book[start]=true;//��ǳ�ʼ�� 
	for(i=0;i<n;i++)
	    dist[i]=graph[start][i];//��ÿ�����ʼ���ڽӵĵ�ľ������dist 
	for(i=1;i<n;i++){
		int min=INF;
		for(j=0;j<n;j++){
			if(!book[j]&&dist[j]<min){//�ҵ���index���ڵ�����ĵ� 
				min=dist[j];
				index=j;
			}
		}
		book[index]=true;//���Ѿ���¼��index���� 
		cout<<"->"<<index;
		sum+=min;//��¼��·��
		 
		for(j=0;j<n;j++){//���³�ʼ��dist���ҵ���index�ڽӵĵ� 
			if(!book[j]&&dist[j]>graph[index][j])
				dist[j]=graph[index][j];
		}
	}
	cout<<endl;
	return sum;
}
int main(){
	for(int i=0;i<n;i++)//����ÿ������Ϊ��ʼ������ 
	cout<<"���·��Ϊ��"<<Prim(i)<<endl;
	return 0;
} 

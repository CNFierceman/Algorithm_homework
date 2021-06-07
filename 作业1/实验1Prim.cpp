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
};//记录每个点之间的距离，INF代表两点之间不可达 

int dist[n]={0};

int Prim(int start){
	int index=start;
	int sum=0;
	int i,j;
	cout<<start;
	bool book[n];
	book[start]=true;//标记初始点 
	for(i=0;i<n;i++)
	    dist[i]=graph[start][i];//将每个与初始点邻接的点的距离存入dist 
	for(i=1;i<n;i++){
		int min=INF;
		for(j=0;j<n;j++){
			if(!book[j]&&dist[j]<min){//找到与index相邻的最近的点 
				min=dist[j];
				index=j;
			}
		}
		book[index]=true;//将已经记录的index点标记 
		cout<<"->"<<index;
		sum+=min;//记录总路径
		 
		for(j=0;j<n;j++){//重新初始化dist，找到与index邻接的点 
			if(!book[j]&&dist[j]>graph[index][j])
				dist[j]=graph[index][j];
		}
	}
	cout<<endl;
	return sum;
}
int main(){
	for(int i=0;i<n;i++)//遍历每个点作为初始点的情况 
	cout<<"最短路径为："<<Prim(i)<<endl;
	return 0;
} 

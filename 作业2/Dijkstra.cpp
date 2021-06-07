#include<iostream>
const int INF=9999999;
const int n=8;
using namespace std;
int map[n][n]={
{0,1,INF,INF,INF,INF,INF,INF},
{INF,0,2,INF,INF,INF,INF,INF},
{2,INF,0,INF,INF,INF,INF,INF},
{INF,INF,1,0,INF,8,INF,INF},
{INF,INF,INF,2,0,INF,2,INF},
{INF,INF,INF,INF,2,0,INF,INF},
{INF,INF,INF,INF,INF,3,0,3},
{INF,INF,INF,INF,INF,2,INF,0}
};

int Dijkstra(int start,int end){
	int min,book[n]={0},index,dist[n];
	for(int i=0;i<n;i++){
		dist[i]=map[start][i];
	} 
	book[start]=1;
	for(int i=0;i<n-1;i++){
		min=INF;
		for(int j=0;j<n;j++){
			if(book[j]==0&&dist[j]<min){
				min=dist[j];
				index=j;
			}
		}
		book[index]=1;
		for(int k=0;k<n;k++){
			if(map[index][k]<INF){
				if(dist[k]>dist[index]+map[index][k]);
				dist[k]=dist[index]+map[index][k];
			}
		}

	}
	return dist[end];
}

int main(){
	cout<<Dijkstra(0,7)<<endl;
}

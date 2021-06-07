#include<iostream> 
const int n=4;
const int INF=99999; 
using namespace std;

int map[n][n]={
	{0,2,6,4},
	{INF,0,3,INF},
	{7,INF,0,1},
	{5,INF,12,0}
};//INF代表两点之间不可达 

void Folyed(){
	for(int flag=0;flag<n;flag++){//flag为可经过的中转点 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j]=min(map[i][j],map[i][flag]+map[flag][j]);
			}
		}
	}
} 
int main(){
	Folyed();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
} 

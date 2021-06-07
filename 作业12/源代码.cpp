#include<iostream>
#include<string>
using namespace std;
#define MAX 150
int m,n,p;
int a[MAX][MAX];
int color[MAX]={0};
int count=0;

bool OK(int t){
	for(int i=0;i<n;i++){
		if(a[t][i]==1&&color[t]==color[i])
			return false;
	}
	return true;
}
void Trackback(int t){
	if(t>n){
		count++;
		for(int i=0;i<n;i++)
			cout<<color[i];
		cout<<endl;
	}
	else{
		for(int i=0;i<m;i++){
			color[t]=i;
			if(OK(t))
				Trackback(t+1);
			color[t]=0;
		}
	}
}
int main(){
	cin>>m;
	cin>>n>>p;
	for(int i=0;i<p;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	Trackback(1);
	if(count==0)
		cout<<"NO"<<endl;
	else
		cout<<count<<endl;
}

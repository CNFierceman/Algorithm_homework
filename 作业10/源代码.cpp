#include<iostream>
#include <algorithm>
using namespace std;
int c1,c2,n,all=0;
int now=0,Max=0;
bool cmp(int x,int y)
{
	return x > y;
}
void backtrack(int i,int w[]){
	if(i>n-1){
		if(now>Max)Max=now;
		return;
	}
	else{
		all-=w[i];
		if(now+w[i]<=c1){
			now+=w[i];
			backtrack(i+1,w);
			now-=w[i];
		}
		if(now+all>Max)
			backtrack(i+1,w);
		all+=w[i];
	}
}


int main(){
	cin>>c1>>c2>>n;
	int w[n];
	for(int i=0;i<n;i++){
		cin>>w[i];
		all+=w[i];
	}
	sort(w,w+n,cmp);
	backtrack(0,w);
	cout<<Max;
	if(all-Max<=c2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
} 

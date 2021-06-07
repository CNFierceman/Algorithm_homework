#include<iostream>
using namespace std;

void MartixChain(int p[],int n){
	int m[n+1][n+1],s[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			m[i][j]=0;
			s[i][j]=i;
		}
	}
	int j;
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n-r+1;i++){
			j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<=j-1;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
					cout<<m[i][j]<<' '<<s[i][j]<<endl;
				}
			}
		}
	}
}

int main(){
	int n;
	cout<<"ÇëÊäÈën:";
	cin>>n;
	int p[n+1];
	cout<<"ÇëÊäÈëP:"; 
	for(int i=0;i<=n;i++)
	cin>>p[i];
	
	MartixChain(p,n);
} 

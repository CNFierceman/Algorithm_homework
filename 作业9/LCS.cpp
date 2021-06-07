#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;
const int N=999;
int c[N][N];
char t;
void LCS(char a[N],char b[N]){
	int m,n;
	m=strlen(a);
	n=strlen(b);
	memset(c,0,sizeof(c));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i-1]==b[j-1])
				c[i][j]=c[i-1][j-1]+1;
			else 
				c[i][j]=max(c[i][j-1],c[i-1][j]);
		}
	}		
	int i=m,j=n;
	stack<char>s;
	while(c[i][j]){
		if(c[i][j]==c[i-1][j])
			i--;
		else if(c[i][j]==c[i][j-1])
			j--;
		else if(c[i][j]>c[i-1][j-1]){
			i--;
			j--;
			s.push(a[i]);
		}
	}
	while(!s.empty())
    {
        t=s.top();
        cout<<t;
        s.pop();
    }
}
int main(){
	char a[N],b[N];
	cin>>a>>b;
	LCS(a,b);
} 

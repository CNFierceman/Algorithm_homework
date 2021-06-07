#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct point{
	double x,y;
};

double distance(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp1(point a,point b){
	return a.x<b.x;
}

bool cmp2(point a,point b){
	return a.y<b.y;
}

double ClosePair(point p[],point q[],int n){
	if(n==2)
	return distance(p[0],p[1]);
	
	if(n==3){
		double d1,d2,d3;
		d1=distance(p[0],p[1]);
		d2=distance(p[1],p[2]);
		d3=distance(p[0],p[2]);
		return min(d1,min(d2,d3));
	}
	
	int mid=n/2;
	point pl[mid],ql[mid],pr[n-mid],qr[n-mid],s[n];
	for(int i=0;i<mid;i++){
		pl[i]=p[i];
		ql[i]=q[i];
	}
	for(int i=0;i<n-mid;i++){
		pr[i]=p[mid+i];
		qr[i]=q[mid+i];
	}
	double dl,dr,d,dminsq;
	dl=ClosePair(pl,ql,mid);
	dr=ClosePair(pr,qr,n-mid);
	d=min(dl,dr);
	double m=p[mid-1].x;
	
	int num=0;
	for(int i=0;i<n;i++){
		if(abs(q[i].x-m)<d){
			s[num]=q[i];
			num++;
		}
	}
	
	dminsq=d*d;
	for(int i=0;i<num-2;i++){
		for(int j=i+1;j<=num-1&&pow(s[j].y-s[i].y,2)<dminsq;j++){
			dminsq=min(pow(s[j].x-s[i].x,2)+pow(s[j].y-s[i].y,2),dminsq);
		}
	}
	return sqrt(dminsq);
}
int main(){
	int n;
	cout<<"请输入有几对点：";
	cin>>n;
	point p[n],q[n];
	cout<<"请输入点的x，y坐标（x,y）:"<<endl;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
		q[i].x=p[i].x;
		q[i].y=p[i].y;
	}
	
	sort(p,p+n,cmp1);
	sort(q,q+n,cmp2);
	double closepair;
	closepair=ClosePair(p,q,n);
	
	cout<<"最近点距离为："<<closepair;

	
}

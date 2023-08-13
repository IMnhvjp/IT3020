#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(){
	int n,m,h=0;		//n: so dinh; m: so canh
	ifstream fcin;
	fcin.open("dothi.txt");
	fcin>>n;
	fcin>>m;
	int a[m][2],b[n+1]={0};	// b[i] la bac cua dinh i
	for (int i=0;i<m;i++){
		fcin>>a[i][0];
		fcin>>a[i][1];
		b[a[i][0]]++;
		b[a[i][1]]++;
	}
	fcin.close();
	int d[n+1][n];
	for (int i=1;i<=n;i++)
		d[i][0]=i;
	for (int i=1;i<n+1;i++){
		int k=1;
		for (int j=0;j<m;j++){
			if(a[j][0]==i){
				d[i][k]=a[j][1];
				k++;
			}
			if(a[j][1]==i){
				d[i][k]=a[j][0];
				k++;
			}
		}
	}
	int max=b[1],l=0;
	for(int i=1;i<n;i++)
		if(max<=b[i+1])
			max=b[i+1];
	for(int i=1; i<=n;i++)
		if((b[i]<=max-1)&&(l<=b[i])){
			l=b[i];
			h=i;		// h la ten cua dinh co bac <= max-1
		}
	if(h==0)
		h=1;
	int v[n+1]={0};	 // v[i] la stt cua dinh i
	int c,n1=n;		// n1 la stt
	v[h]=n;
	for (int i=n;i>=1;i--){				// danh so cho dinh i la v(i)
		for (int j=1;j<=n;j++)
			if(v[j]==i)
				c=j;
		for (int i1=1; i1<=b[c];i1++)
			if(v[d[c][i1]]==0)
				v[d[c][i1]]=--n1;
	}
	int mau[n+1]={0};
	int c1;
	for (int i=1;i<n+1;i++){
		for (int j=1;j<n+1;j++)
			if(v[j]==i){
				c1=j;	// c1 la dinh co stt la i
				mau[c1]++;
			}
		for (int j=1;j<=b[c1];j++)
			for(int j1=1;j1<=b[c1];j1++)
				if(mau[c1]==mau[d[c1][j1]])
					mau[c1]++;
	}
	vector<string>f{"red","green","blue","yellow","white","purple","grey","pink","brown","orange","darkgreen","gold","yellowgreen","violet",};
	ofstream fcout;
	fcout.open("dothitomau.dot");
	fcout<<"graph dothi"<<endl;
	fcout<<"{"<<endl;
	for (int i=1;i<n+1;i++)
		fcout<<i<<" "<<"[fillcolor="<<f[mau[i]-1]<<", style=filled];"<<endl;
	for (int i=0;i<m;i++)
		fcout<<a[i][0]<<" -- "<<a[i][1]<<";"<<endl;
	fcout<<"}";
	fcout.close();
}

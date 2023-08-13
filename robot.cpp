#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <int> edge[100],a1,b1,a2,b2;
int w[100][100],x=0;
int kcach[100][100],dist[100],flag[100][100];

void bellmanford(int x, int y);
void update(int u, int v);
void robotA(int n,int m,int a,int b,int c,int d,int r,int h);
void robotB(int n,int m,int a,int b,int c,int d,int r,int h);

void printsolution(int h){
    int j;
    cout<<a1[0]<<" "<<h<<endl;
    if(a1.size()>b1.size())
        for(int i=0;i<(a1.size()-b1.size());i++)
            b1.push_back(b1[b1.size()-1]);
    else
        for(int i=0;i<(b1.size()-a1.size());i++)
            a1.push_back(a1[a1.size()-1]);
    for (j =0;j<a1.size()-1;j++){
        cout<<a1[j]<<" "<<b1[j]<<endl;
        cout<<a1[j+1]<<" "<<b1[j]<<endl;
    }
    if(a1.size()<=b1.size())
        cout<<a1[j]<<" "<<b1[j]<<endl;
    x=1;
    for (int i=0;i<100;i++)
        for (int j=0;j<100;j++)
            flag[i][j]=-1;
}
void update(int u, int v){
    if(dist[v]>dist[u]+w[u][v])
        dist[v]=dist[u]+w[u][v];
}
void bellmanford(int x, int n){
    for (int i=0;i<n;i++){
        dist[i]=10^6;
    }
    dist[x]=0;
    for (int i=0;i<n-1;i++)
        for (int j=0;j<n;j++)
            for (int k: edge[j])
                update(j,k);
    for (int i=0;i<n;i++)
        kcach[x][i]=dist[i];
}
int kcachmin(int x, int y, int n){
    if(kcach[x][y]==0)
        bellmanford(x,n);
    return kcach[x][y];
}
void robotA(int n,int m,int a,int b,int c,int d,int r, int h){
        for (int i: edge[a]){
            if(kcachmin(i,b,n)>r)
                if(flag[i][b]==0){
                    flag[i][b]=1;
                    a1.push_back(i);
                    if(i==c&&b==d)
                        printsolution(h);
                    else{
                        robotB(n,m,i,b,c,d,r,h);
                        flag[i][b]=0;
                        a1.pop_back();
                    }
                }
        }
}
void robotB(int n,int m,int a,int b,int c,int d,int r, int h){
        for (int i: edge[b]){
            if(kcachmin(i,a,n)>r)
                if(flag[a][i]==0){
                    flag[a][i]=1;
                    b1.push_back(i);
                    if(a==c&&i==d)
                        printsolution(h);
                    else{
                        robotA(n,m,a,i,c,d,r,h);
                        flag[a][i]=0;
                        b1.pop_back();
                    }
                }
        }
}
int main(){
    int n,m,a,b,c,d,r,h,k;
    cin>>n;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>h;
        cin>>k;
        edge[h].push_back(k);
        edge[k].push_back(h);
        cin>>w[h][k];
        w[k][h]=w[h][k];
    }
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>r;
    cout<<endl<<endl;
    flag[a][b]=1;
    robotA(n,m,a,b,c,d,r,b);
    if(x==0)
        cout<<"khong the";
    return 0;
}

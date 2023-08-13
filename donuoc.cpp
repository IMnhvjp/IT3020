#include <iostream>
#include <vector>

using namespace std;

int ktra[11][5][8]={0},i1=0;
int g[30][3];
vector <int> canh[30];
int visited[30]={0};

void printsolution(int u,int v){    // in canh cua cay
    cout<<"<"<<g[u][0]<<","<<g[u][1]<<","<<g[u][2]<<"> -- "<<"<"<<g[v][0]<<","<<g[v][1]<<","<<g[v][2]<<">;"<<endl;
}

int checkcanh(int u, int v){
    if((g[u][0]==g[v][0])&&(g[v][1]==4||g[v][2]==7||g[v][1]==0||g[v][2]==0))
        return 1;
    else if((g[u][1]==g[v][1])&&(g[v][0]==10||g[v][2]==7||g[v][0]==0||g[v][2]==0))
        return 1;
    else if((g[u][2]==g[v][2])&&(g[v][1]==4||g[v][0]==10||g[v][1]==0||g[v][0]==0))
        return 1;
    else return 0;
}

void sinhkhoi(int x, int y, int z){
    if(!ktra[x][y][z]){
        ktra[x][y][z]=1;
        g[i1][0]=x;
        g[i1][1]=y;
        g[i1][2]=z;
        i1++;
        if(x!=0){
            if ((x-(4-y))<=0)
                sinhkhoi(0,y+x,z);
            else sinhkhoi(x-(4-y),4,z);
            if (x-(7-z)<=0)
                sinhkhoi(0,y,z+x);
            else sinhkhoi(x-(7-z),y,7);
        }
        if(y!=0){
            if(y-(10-x)<=0)
                sinhkhoi(x+y,0,z);
            else sinhkhoi(10,y-(10-x),z);
            if(y-(7-z)<=0)
                sinhkhoi(x,0,z+y);
            else sinhkhoi(x,y-(7-z),7);
        }
        if(z!=0){
            if(z-(10-x)<=0)
                sinhkhoi(x+z,y,0);
            else sinhkhoi(10,y,z-(10-x));
            if(z-(4-y)<=0)
                sinhkhoi(x,y+z,0);
            else sinhkhoi(x,4,z-(4-y));
        }
    }
}
void duyetkhoi(){
    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
            if(i!=j&&checkcanh(i,j))
                    canh[i].push_back(j);
}
void explore(int u){
    visited[u]=1;
    for (int v: canh[u]){
        if(visited[v]==0){
            printsolution(u,v);
            explore(v);
        }
    }
}
void dfs(int u){
    for (u=0;u<21;u++)
        if (visited[u]==0)
            explore(u);
}
int main(){
    cout<<"graph{"<<endl;
    sinhkhoi(0,4,7);    //tao cac dinh cua do thi G
    duyetkhoi();        //tao danh sach canh cua cac dinh
    dfs(0);
    cout<<"}";
    return 0;
}

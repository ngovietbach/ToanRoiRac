#include<iostream>
#include<string.h>
#include<queue>
#include<fstream>
#define MAX 6000
#define oo 1000
using namespace std;

int graph[MAX][MAX];
int sodinh=5757;

int visited[MAX];
int pre[MAX], post[MAX];
int Clock = 1;
void previsit(int v)
{
    pre[v] = Clock;
    Clock++;
}
void postvisit(int v)
{
    post[v]=Clock;
    Clock++;
}
void explore(int v)
{
    visited[v]=1; // 1: true, 0:false
    previsit(v);
    int u;
    for( u=0; u < sodinh; u++)
        if (graph[v][u] == 1)
            if (visited[u]==0) explore(u);
    postvisit(v);
}
int cc=0;
void dfs ()
{   int v;
    for (v=0; v<sodinh; v++)
        visited[v]=0;
    for (v=0; v<sodinh; v++)
        if (visited[v]==0) {
        explore(v);
        cc=cc+1;
    }
}




int dist[MAX];
int truoc[MAX];
void bfs(int s)
{
    queue<int> Q; // Hàngraph d?i m?i ph?n t? có ki?u int  : C++

    for (int u = 0; u < sodinh; u++)
        dist[u] = oo;

    truoc[s] = -1; // Ð?nh s khôngraph có d?nh tru?c vì b?t d?u t? s
    dist[s] = 0;
    Q.push(s);
    while (Q.empty() != true)
    {
        int u = Q.front();
        Q.pop(); // lo?i b? u kh?i hàngraph d?i
        for (int v = 0; v < sodinh; v++)
            if (graph[u][v] == 1) // Có c?nh (u,v) trong E
            {
                if (dist[v] == oo)
                {
                    Q.push(v);    // dua v vào hàng d?i
                    truoc[v] = u; // d?nh tru?c c?a d?nh v là d?nh u
                    dist[v] = dist[u] + 1;
                }
            }
    }
}



int so_sanh(string a,string b){
	int dem=0;
	for(int i=0;i<5;i++){
	if(a[i]!=b[i]){
		dem++;
	}	
	}
	if(dem==1) return 1;
	if(dem==0) return 2;
	return 0;
}

typedef struct{
	string ten;
	int chiso;
}diem;


int main(int argc, char const *argv[])
{   
   string mang[5757];
   int i=0;
   ifstream dothi ("C:\\Users\\Administrator\\Desktop\\danh_sach.txt");
   if (dothi.is_open()){
   	while (!dothi.eof()){
   		dothi >> mang[i];
   		i++;		
   	}
     	 dothi.close(); 	
   }else cout << "Khong mo duoc file";
   
   
   
   
	for(int i=0;i<5757;i++){
		for(int j=0;j<5757;j++){
			if(so_sanh(mang[i],mang[j])==1){
				graph[i][j]=1;
			}
		}
	}
    dfs();
	cout<<"so thanh phan lien thong "<<cc<<endl;
	diem x,y;
	cin>>x.ten>>y.ten;
	for(int i=0;i<5757;i++){
		if(so_sanh(x.ten,mang[i])==2){
			x.chiso=i;
		}
	}
	for(int i=0;i<5757;i++){
		if(so_sanh(y.ten,mang[i])==2){
			y.chiso=i;
		}
	}
	bfs(x.chiso);
	while(y.chiso != x.chiso){
		cout<<mang[y.chiso]<<"<--";
		y.chiso=truoc[y.chiso];
	}
	cout<<x.ten;
	return 0;
}


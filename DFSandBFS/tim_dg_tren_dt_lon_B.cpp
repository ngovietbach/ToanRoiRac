#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <fstream>

#define MAX_N 20001
#define oo 1000
#define MAX 6000

typedef long long lld;
typedef unsigned long long llu;
using namespace std;
int graph[MAX][MAX];
int n=5757;
struct Node
{
    vector<int> adj;
    vector<int> rev_adj;
};
Node graf[MAX_N];

stack<int> S;
bool visited[MAX_N];

int component[MAX_N];
vector<int> components[MAX_N];
int numComponents;

void tpltm_dfs_1(int x)
{
    visited[x] = true;
    for (int i=0;i<graf[x].adj.size();i++)
    {
        if (!visited[graf[x].adj[i]]) tpltm_dfs_1(graf[x].adj[i]);
    }
    S.push(x);
}

void tpltm_dfs_2(int x)
{
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;
    for (int i=0;i<graf[x].rev_adj.size();i++)
    {
        if (!visited[graf[x].rev_adj[i]]) tpltm_dfs_2(graf[x].rev_adj[i]);
    }
}

void tpltm()
{
    for (int i=0;i<n;i++)
    {
        if (!visited[i]) tpltm_dfs_1(i);
    }
    
    for (int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    
    while (!S.empty())
    {
        int v = S.top(); S.pop();
        if (!visited[v])
        {
            tpltm_dfs_2(v);
            numComponents++;
        }
    }
}

int dist[MAX];
int truoc[MAX];
void bfs(int s)
{
    queue<int> Q; // Hàngraph d?i m?i ph?n t? có ki?u int  : C++

    for (int u = 0; u < n; u++)
        dist[u] = oo;

    truoc[s] = -1; // Ð?nh s khôngraph có d?nh tru?c vì b?t d?u t? s
    dist[s] = 0;
    Q.push(s);
    while (Q.empty() != true)
    {
        int u = Q.front();
        Q.pop(); // lo?i b? u kh?i hàngraph d?i
        for (int v = 0; v < n; v++)
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

int sosanh(string a,string b){
	int dem=0;
    priority_queue<char>A;
    priority_queue<char>B;
    for(int i=0;i<5;i++){
        B.push(b[i]);
    }
    for(int i=1;i<5;i++){
    	A.push(a[i]);
    }
    while(!A.empty() && !B.empty()){
    	if(B.top()==A.top()){
    		dem++;
    		A.pop();
    		B.pop();
    	}
    	else B.pop();
    }
		
	return dem;	
}

int sosanh1(string a,string b){
	for(int i=0;i<5;i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}



typedef struct{
	string ten;
	int chiso;
} diem;


int main()
{
    string xau[5757];
    int i=0;
    ifstream dothi ("C:\\Users\\Administrator\\Desktop\\danh_sach.txt");
     if (dothi.is_open()){
         while (!dothi.eof()){
         	dothi >> xau[i];
         	i++;
         }
     	 dothi.close();
     } else cout << "Khong mo duoc file";
     
     for(int i=0;i<n;i++){
     	for(int j=0;j<n;j++){
     		if(i==j){
     			continue;
     		}
     		if(sosanh(xau[i],xau[j])==4){
     		 graf[i].adj.push_back(j);
             graf[j].rev_adj.push_back(i);
			 graph[i][j]=1;	
     		}
     		
     	}
     }
    
    tpltm();
    
    printf("So thanh phan lien thong manh: %d\n", numComponents);
    
    diem th;
    cin>>th.ten;
    for(int i=0;i<5757;i++){
       if(sosanh1(th.ten,xau[i])==1){
       	th.chiso=i;
       }
    }
    for(int i=0;i<5757;i++){
    	if(component[i]==component[th.chiso]){
    		cout<<xau[i]<<" ";
    	}
    }
    cout<<endl;
    diem dau;
    cin>>dau.ten;
    for(int i=0;i<5757;i++){
       if(sosanh1(dau.ten,xau[i])==1){
       	dau.chiso=i;
       }
    }
    diem cuoi;
    cin>>cuoi.ten;
    for(int i=0;i<5757;i++){
       if(sosanh1(cuoi.ten,xau[i])==1){
       	cuoi.chiso=i;
       }
    }
    bfs(dau.chiso);
	while(cuoi.chiso != dau.chiso){
		cout<<xau[cuoi.chiso]<<"<--";
		cuoi.chiso=truoc[cuoi.chiso];
	}
	cout<<dau.ten;
    
    return 0;
}

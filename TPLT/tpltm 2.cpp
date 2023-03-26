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

typedef long long lld;
typedef unsigned long long llu;
using namespace std;

int n, m;
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
    printf("%d ", x);
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
            printf("thanh phan lien thong %d: ", numComponents+1);
            tpltm_dfs_2(v);
            numComponents++;
            printf("\n");
        }
    }
}

int main()
{
    int p,q;
    ifstream dothi ("C:\\Users\\Administrator\\Desktop\\thu.txt");
     if (dothi.is_open())
    {
        dothi >> n;
        dothi >> m;
        while (!dothi.eof()) //Doc file cho den cuoi file
        {
            dothi >> q;
            dothi >> p;
            graf[q].adj.push_back(p);
            graf[p].rev_adj.push_back(q);
        }
        dothi.close();
    }
    else cout << "Khong mo duoc file";
    
    tpltm();
    
    printf("So thanh phan lien thong manh: %d\n", numComponents);
    
    return 0;
}

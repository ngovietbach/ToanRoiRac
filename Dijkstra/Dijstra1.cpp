#include<iostream>
#include<queue>
#include <vector>
#include <stdio.h>
using namespace std;
#define MAX 100
#define oo 1000 
typedef pair<int, int> ii;
vector<ii> graph[MAX];
int sodinh;
int dist[MAX];
int truoc[MAX]; 


void dijkstra(){
	  for (int u = 1; u <= sodinh; u++){
        dist[u] = oo;
	    truoc[u] = 0;
      }
      dist[1]=0;
      truoc[1]=0;
      priority_queue<ii, vector<ii>, greater<ii> > H;
      H.push(ii(0, 1));
	  while (H.size()) {
        int u = H.top().second;
        int du = H.top().first;
        H.pop();
        if (du != dist[u])
            continue;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].second;
            int uv = graph[u][i].first;
            if (dist[v] > du + uv) {
                dist[v] = du + uv;
                truoc[v] = u;
                H.push(ii(dist[v], v));
            }
        }
    }	
}


int main() {
	int socanh;
    int p, q, w;
    scanf("%d%d", &sodinh, &socanh);
    while (socanh--) {
        scanf("%d%d%d", &p, &q, &w);
        graph[p].push_back(ii(w, q));
        graph[q].push_back(ii(w, p));
    }
    dijkstra();
    for (int i = 2; i <= sodinh; i++)
        printf("%d-%d ",truoc[i],i);
        return 0;
}


#include<iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> GRAPH;
void add_directed_edge(GRAPH &graph,int from, int to, int cost){
    graph[from][to] = cost;
}
void add_Undirected_edge(GRAPH &graph,int from, int to, int cost){
    graph[from][to] = graph[to][from] = cost;
}

void print_adjacencyMatrix_WG(GRAPH &graph){
    int nodes = graph.size();
    for(int from =0;from<nodes; ++from){
        for(int to=0;to<nodes; ++to){
            cout<<"From "<<from<<" to "<<to<<" There cost is  "<<graph[from][to]<<endl;
        }
    }
}
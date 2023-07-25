#include<iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> GRAPH;
void add_directed_edge(GRAPH &graph,int from, int to){
    graph[from][to] += 1;
}
void add_Undirected_edge(GRAPH &graph,int from, int to){
    graph[from][to] += 1;
    graph[to][from] += 1;
}

void print_adjacencyMatrix_UWG(GRAPH &graph){
    int nodes = graph.size();
    for(int from =0;from<nodes; ++from){
        for(int to=0;to<nodes; ++to){
            cout<<"From "<<from<<" to "<<to<<" There are "<<graph[from][to]<<"edges"<<endl;
        }
    }
}
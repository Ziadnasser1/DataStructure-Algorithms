#include <iostream>
#include <vector>
using namespace std;

struct edge{
    int to;
    int cost;
};

typedef vector<vector<edge>> GRAPH;

void add_directed_edge(GRAPH &graph,int from, int to, int cost){
    graph[from].push_back({to,cost});
}
void add_undirected_edge(GRAPH &graph,int from, int to, int cost){
    graph[from].push_back({to,cost});
    graph[to].push_back({from,cost});
}
void print_AdjacencyMatrix(GRAPH &graph){
    int nodes = graph.size();
    for(int from =0;from< nodes;++from){
        cout<<"Node "<<from<<"has neighbors ";
        for(int edge=0;edge<graph[from].size();++edge){
            cout<<"to "<<graph[from][edge].to<<" cost"<<graph[from][edge].cost;
        }
        cout<<endl;
    }

}
int main() {
    int nodes;
    cin>>nodes;
    GRAPH graph(nodes);

    add_directed_edge(graph, 0, 1, 5);
    add_directed_edge(graph, 0, 2, 3);
    add_directed_edge(graph, 1, 3, 2);
    add_directed_edge(graph, 2, 3, 7);
    add_directed_edge(graph, 3, 4, 4);

    add_undirected_edge(graph, 1, 4, 6);
    add_undirected_edge(graph, 2, 4, 1);

    print_AdjacencyMatrix(graph);

    return 0;
}





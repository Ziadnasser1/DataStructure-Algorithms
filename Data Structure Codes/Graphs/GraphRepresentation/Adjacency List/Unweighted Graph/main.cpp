#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph,int from,int to){
    graph[from].push_back(to);
}

void add_undirected_edge(GRAPH &graph,int from, int to){
    graph[from].push_back(to);
    graph[to].push_back(from);

}

void print_adjacency_matrix(GRAPH &graph){
    int nodes = graph.size();
    for(int from=0;from<nodes;++from){
        cout<<"Node "<<from<<" has neighbors ";
        for(int to=0;to< (int) graph[from].size();++to){
            cout<<graph[from][to]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    GRAPH graph(nodes);
    int from,to;
    for(int e=0;e<edges;++e){
        cin>>from>>to;
        add_directed_edge(graph,from,to);
    }
    print_adjacency_matrix(graph);
}
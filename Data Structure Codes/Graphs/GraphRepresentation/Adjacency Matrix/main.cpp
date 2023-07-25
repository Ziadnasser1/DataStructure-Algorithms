// #include "UWG.cpp"
#include "WG.cpp"
int main(){
    //UWG
    // int nodes,edges;
    // cin>>nodes>>edges;

    // GRAPH graph(nodes, vector<int>(nodes));
    // for(int e=0;e<edges;++e){
    //     int from,to;
    //     cin>>from>>to;
    //     add_directed_edge(graph,from,to);
    // }
    // print_adjacencyMatrix_UWG(graph);
    
    //WG
    int nodes,edges;
    cin>>nodes>>edges;

    GRAPH graph(nodes, vector<int>(nodes));
    for(int e=0;e<edges;++e){
        int from,to,cost;
        cin>>from>>to>>cost;
        add_Undirected_edge(graph,from,to,cost);
    }
    print_adjacencyMatrix_WG(graph);
}
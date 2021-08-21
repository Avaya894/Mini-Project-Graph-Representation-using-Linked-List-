#include "Ad_List.h"

int main()
{
    //Undirected Graph
    std::cout << "Directed Graph" <<  "\n";
    AdjacencyList a('a', true);
    
    a.addVertex('b');
    a.addVertex('c');
    a.addVertex('d');
    a.addVertex('e');
    a.addVertex('f');
    
    a.addEdge('a', 'b');
    a.addEdge('a', 'c');
    a.addEdge('a', 'd');
    a.addEdge('b', 'f');
    a.addEdge('d', 'e');

    a.traverse();
    std::cout << "\n";

    std::cout << "Are 'a' and 'f' neighbour? " << a.isNeighbour('a', 'f') << "\n";
    std::cout << "Number of vertices of Graph: " << a.numVertices() << "\n";
    std::cout << "Number of edges of vertex 'a' : " << a.numEdges('a') << "\n";

    //Removing Vertex 'a'
    std::cout << "\n";
    std::cout << "Removing Vertex 'a'" << "\n";
    a.removeVertex('a');
    
    std::cout << "\n";
    
// std::cout << a.isNeighbour('b', 'a') << "\n";
    // a.removeEdge('a', 'b');
    a.traverse();
}
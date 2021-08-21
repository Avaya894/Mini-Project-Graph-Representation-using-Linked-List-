//Avaya Bajracharya
//Roll no: 09
//Computer Engineering

//Implement a data structure for representing sparse matrices using linked lists.

#include "Ad_List.h"

int main()
{
    //Undirected Graph
    std::cout << "Undirected Graph \n";
    AdjacencyList a('a', false);
    
    a.addVertex('b');
    a.addVertex('c');
    a.addVertex('d');
    a.addVertex('e');
    a.addVertex('f');
    
    a.addEdge('a', 'b');
    a.addEdge('a', 'c');
    a.addEdge('a', 'd');

    a.traverse();
    std::cout << "\n";

    std::cout << "Are 'a' and 'f' neighbours? " << a.isNeighbour('a', 'f');
    std::cout << std::endl;
    std::cout << "Number of vertices in the graph: " << a.numVertices() << "\n";
    std::cout << "Number of edges of vertex 'a' in the graph: " << a.numEdges('a') << "\n";


    //Removing Vertex 'a'
    std::cout << "\n" << "Removing Vertex 'a'" << "\n";
    a.removeVertex('a');
    a.traverse();


    
}
#ifndef ADJACENCY_lIST
#define ADJACENCY_lIST

#include "Interface.h"
#include "node.h"

class AdjacencyList : public InterfaceGraph
{
private:
    VertexList *head;
    // VertexList *tail;
    VertexList *adlist;
    bool isDirectedGraph;
public:
    AdjacencyList(char vertex,  bool isDirected);
    virtual void addVertex(char v);
    virtual void addEdge(char v1, char v2);
    virtual void addEdge_(char v1, char v2);
    virtual void addEdgeUndirected(char v1, char v2);
    virtual void addEdgeDirected(char v1, char v2);
    virtual void removeVertex(char v);
    virtual void removeVertex_(char v);
    virtual void removeEdge(char v1, char v2);
    virtual void removeEdge_(char v1, char v2);
    virtual void removeEdgeUndirected(char v1, char v2);
    virtual void removeEdgeDirected(char v1, char v2);
    virtual int indegree(char v);
    virtual int outdegree(char v);
    virtual int degree(char v);
    virtual bool isEmpty();
    virtual bool isDirected();
    virtual bool isNeighbour(char v1, char v2);
    virtual void neighbours(char v);
    virtual int numVertices();
    virtual int numEdges(char v);

    VertexList* searchVertex(char v);
    EdgeList* searchEdge(char v1, char v2);
    void traverseEdge(char v);
    std::string traverse_Edge(char v);
    // std::ostream& traverse_Edge(char v, std::ostream& out);
    void traverse();
};



#endif
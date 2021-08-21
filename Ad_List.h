#ifndef ADJACENCY_lIST
#define ADJACENCY_lIST

#include "Interface.h"
#include "node.h"

class AdjacencyList : public InterfaceGraph
{
private:
    VertexList *head;
    VertexList *adlist;
    bool isDirectedGraph;
public:
    AdjacencyList(bool isDirected);
    virtual void addVertex(int v);
    virtual void addEdge(int v1, int v2, int value);
    virtual void addEdge_(int v1, int v2, int value);
    virtual void addEdgeUndirected(int v1, int v2, int value);
    virtual void addEdgeDirected(int v1, int v2, int value);
    virtual void removeVertex(int v);
    virtual void removeVertex_(int v);
    virtual void removeEdge(int v1, int v2);
    virtual void removeEdge_(int v1, int v2);
    virtual void removeEdgeUndirected(int v1, int v2);
    virtual void removeEdgeDirected(int v1, int v2);
    virtual int indegree(int v);
    virtual int outdegree(int v);
    virtual int degree(int v);
    virtual bool isEmpty();
    virtual bool isDirected();
    virtual bool isNeighbour(int v1, int v2);
    virtual void neighbours(int v);
    virtual int numVertices();
    virtual int numEdges(int v);

    VertexList* searchVertex(int v);
    EdgeList* searchEdge(int v1, int v2);
    void traverseEdge(int v);
    std::string traverse_Edge(int v);
    // std::ostream& traverse_Edge(int v, std::ostream& out);
    void traverse();
};



#endif
//Graph Represenation using Adjacency Matrix
#ifndef G_INTERFACE
#define G_INTERFACE

#include <iostream>

class InterfaceGraph
{
public:
    // virtual ~InterfaceGraph() { }
    virtual bool isEmpty() = 0;
    virtual bool isDirected() = 0;
    virtual void addVertex(int v) = 0;
    virtual void addEdge(int v1, int v2, int value) = 0;
    virtual void removeVertex(int v) = 0;
    virtual void removeEdge(int v1, int v2) = 0;
    virtual int numVertices() = 0;
    virtual int numEdges(int v) = 0;
    virtual int indegree(int v) = 0;
    virtual int outdegree(int v) = 0;
    virtual int degree(int v) = 0;
    virtual void neighbours(int v) = 0;
    virtual bool isNeighbour(int v1, int v2) = 0;
};

#endif
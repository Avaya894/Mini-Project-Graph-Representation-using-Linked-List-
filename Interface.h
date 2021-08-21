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
    virtual void addVertex(char v) = 0;
    virtual void addEdge(char v1, char v2) = 0;
    virtual void removeVertex(char v) = 0;
    virtual void removeEdge(char v1, char v2) = 0;
    virtual int numVertices() = 0;
    virtual int numEdges(char v) = 0;
    virtual int indegree(char v) = 0;
    virtual int outdegree(char v) = 0;
    virtual int degree(char v) = 0;
    virtual void neighbours(char v) = 0;
    virtual bool isNeighbour(char v1, char v2) = 0;
};

#endif
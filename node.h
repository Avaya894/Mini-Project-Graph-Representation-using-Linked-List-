#ifndef NODE
#define NODE

class EdgeList
{
public:
    int key; //column
    int value;
    EdgeList *next;

    EdgeList(int v, int value):key(v), value(value), next(nullptr) { }
};


class VertexList
{
public:
    int key; //row
    VertexList *down;
    EdgeList *right;

    VertexList(int vertex) : key(vertex), down(nullptr), right(nullptr) { }
};

#endif
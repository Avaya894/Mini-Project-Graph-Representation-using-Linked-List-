//Avaya Bajracharya
//Roll no: 09
//Computer Engineering

#ifndef NODE
#define NODE

class EdgeList
{
public:
    char key;
    EdgeList *next;

    EdgeList(char v):key(v), next(nullptr) { }
};


class VertexList
{
public:
    char key;
    VertexList *down;
    EdgeList *right;

    VertexList(char vertex) : key(vertex), down(nullptr), right(nullptr) { }
};

#endif
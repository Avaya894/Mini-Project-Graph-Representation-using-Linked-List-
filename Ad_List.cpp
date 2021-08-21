#include "Ad_List.h"
#include <string>
AdjacencyList::AdjacencyList(bool isDirected=true)
{
    adlist = nullptr;
    head = adlist;
    isDirectedGraph = isDirected;
}

void AdjacencyList::addVertex(int v)
{
    VertexList *newnode = new VertexList(v);
    VertexList *temp = head;
    if(head == nullptr)
    {
        head = new VertexList(v);
    }
    else 
    {
        if (head->down == NULL)
        {
            head->down = newnode;
        } 
        else
        {
            while(temp->down != NULL)
            {   
                temp=temp->down;
            }
            temp->down = newnode;
        }
    }
}

void AdjacencyList::addEdge(int v1, int v2, int value)
{
    if(isDirectedGraph)
        addEdgeDirected(v1, v2, value);
    else    
        addEdgeUndirected(v1, v2, value);
}

void AdjacencyList::addEdge_(int v1, int v2, int value)
{
    VertexList* temp = head;
    while(temp!= NULL)
    {
        if(temp->key == v1)
            break;
        temp=temp->down;
    }
    if (temp != NULL)
    {
        if(temp->right == NULL)
        {
            EdgeList *newnode = new EdgeList(v2, value);
            temp->right = newnode;
        }
        else 
        {
            EdgeList *etemp = temp->right;
            while(etemp->next != nullptr)
            {
                etemp=etemp->next;
            }
            EdgeList *newnode = new EdgeList(v2, value);
            etemp->next = newnode;
        }
    } else {
        std::cout << "No such vertex with edge found." << "/n";
    }
}

void AdjacencyList::addEdgeUndirected(int v1, int v2, int value)
{
    addEdge_(v1, v2, value);
    addEdge_(v2, v1, value);
}

void AdjacencyList::addEdgeDirected(int v1, int v2, int value)
{
    addEdge_(v1, v2, value);
}

void AdjacencyList::removeVertex(int v)
{
    VertexList* temp = head;
    while(temp!=nullptr)
    {
        if(isNeighbour(temp->key, v))
        {
            removeEdge(temp->key, v);
        }
        
        temp = temp->down;
    }
    removeVertex_(v);
}


void AdjacencyList::removeVertex_(int v)
{
    VertexList *temp, *prevnode;
    temp = head;
    if(head->key == v)
    {
        head = head->down;
        delete [] temp;
    } else {
        while(temp->down != nullptr && temp->key != v)
        {
            prevnode = temp;
            temp = temp->down;
        }
        if(temp == NULL)
        std::cout << "Vertex Not Found";
        else 
        {
            if(temp->key == v) //Revalidating if the key exists
            {
                prevnode->down = temp->down;
                delete [] temp;
            } else {
                std::cout << "Vertex Not Found";
            }
        }
    }    
}


void AdjacencyList::removeEdge_(int v1, int v2)
{
    VertexList *temp;
    temp = searchVertex(v1);
    if (temp == nullptr)
        std::cout << "Vertex not found. Can't remove Edges specified.";
    else{
        EdgeList *tmp, *prevnode;
        tmp = prevnode = temp->right;
        if(tmp == nullptr)
            std::cout << "Edge not found. Can't remove edge specified.";
        else
        {
            if (tmp->key == v2)
            {
                temp->right = tmp->next;
                delete [] tmp;
            } 
            else 
            {
                while(tmp->next != nullptr)
                {
                    if(tmp->key == v2)
                        {
                            break;
                        }
                    prevnode = tmp;
                    tmp=tmp->next;
                }
                if(tmp->key == v2)
                {
                    prevnode->next = tmp->next;
                    delete [] tmp;
                }
            }
            
        }
    }
}


void AdjacencyList::removeEdgeUndirected(int v1, int v2)
{
    removeEdge_(v1, v2);
    removeEdge_(v2, v1);
}

void AdjacencyList::removeEdgeDirected(int v1, int v2)
{
    removeEdge_(v1, v2);
}

void AdjacencyList::removeEdge(int v1, int v2)
{
    if(isDirectedGraph)
        removeEdgeDirected(v1, v2);
    else   
        removeEdgeUndirected(v1, v2);
}

int AdjacencyList::indegree(int v)
{
    VertexList *temp = head;
    EdgeList *tmp;
    int indegree = 0;
    if(temp == nullptr)
        std::cout << "No such vertex found";
    else
    {
        while(temp!=nullptr)
        {
            tmp=temp->right;
            while(tmp!=nullptr)
            {
              if(tmp->key == v)
                indegree++;
            }
            temp=temp->down;
        }
    }
    return indegree;
}

int AdjacencyList::outdegree(int v) 
{
    VertexList *temp = head;
    EdgeList *tmp;
    int outdegree = 0;
    while(temp != nullptr)
    {
        if(temp->key == v)
        {
            tmp = temp->right;
            while(tmp != nullptr)
            {
                outdegree++;
                tmp =tmp->next;
            }
            break;
        }
        temp = temp->down;
    }
    if(temp == nullptr)
        std::cout << "Vertex not found.";
    return outdegree;
}

int AdjacencyList::degree(int v)
{
    return indegree(v) + outdegree(v);
}

VertexList* AdjacencyList::searchVertex(int v)
{
    VertexList* temp = head;
    while(temp!= NULL)
    {
        if(temp->key == v)
            return temp;
        temp=temp->down;
    }
    return NULL;
}

EdgeList* AdjacencyList::searchEdge(int v1, int v2)
{
    EdgeList *tmp = searchVertex(v1)->right;
    if(tmp == nullptr)
        return nullptr;
    else
    {
        while(tmp != nullptr)
        {
            if(tmp->key == v2)
                return tmp;
            tmp=tmp->next;
        }
    }
    return tmp;
}


void AdjacencyList::traverseEdge(int v)
{
    EdgeList* epoint = searchVertex(v)->right;
    while(epoint != NULL)
    {
        std::cout << epoint->key << ", " << epoint->value << " -- ";
        epoint=epoint->next;
    }
}

void AdjacencyList::traverse()
{
    VertexList *temp;
    temp = head;
    // std::cout << "head -> ";
    while(temp != NULL)
    {
        std::cout << temp->key << traverse_Edge(temp->key) << "\n";
        temp = temp->down;
    }
}

std::string AdjacencyList::traverse_Edge(int v)
{
    EdgeList* epoint = searchVertex(v)->right;
    std::string astring = " :: <";
    while(epoint != NULL)
    {
        astring = astring + " -- " + std::to_string(epoint->key) + ", " + std::to_string(epoint->value) ;
        epoint=epoint->next;
    }
    return astring;
}


bool AdjacencyList::isEmpty()
{
    return head==nullptr;
}

bool AdjacencyList::isDirected()
{
    return isDirectedGraph;
}

bool AdjacencyList::isNeighbour(int v1, int v2)
{
    if(searchEdge(v1, v2) == nullptr)
        return false;
    else    
        return true;
}

void AdjacencyList::neighbours(int v)
{
    traverseEdge(v);
}

int AdjacencyList::numVertices()
{
    VertexList *temp = head;
    int n_vertices = 0;
    while(temp != NULL)
    {
        n_vertices++;
        temp = temp->down;
    }
    return n_vertices;
}

int AdjacencyList::numEdges(int v)
{
    EdgeList *tmp = searchVertex(v)->right;
    int n_edges = 0;
    while(tmp != nullptr)
    {
        n_edges++;
        tmp=tmp->next;
    }
    return n_edges;
}

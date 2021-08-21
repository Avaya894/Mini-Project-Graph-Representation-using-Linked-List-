#include "Ad_List.h"
#include <iostream>


void create_sparse_list(int sparsematrix[4][5], int row, int column, AdjacencyList &ad)
{
    int i, j;
    for (i=0; i < row; i++)
    {
        ad.addVertex(i);
    }
    for (i=0; i<row; i++)
    {
        for (j=0; j < column; j++)
        {
            if(sparsematrix[i][j] != 0)
            {
                ad.addEdge(i, j, sparsematrix[i][j]);
                // std::cout << sparsematrix[i][j] << " ";
            }
        }
    }
}

void sparse_traverse(AdjacencyList &ad)
{
    ad.traverse();
}
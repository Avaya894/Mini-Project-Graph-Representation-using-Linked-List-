#include "Ad_List.h"
#include "sparse.cpp"

int main()
{
    int sparse_matrix[4][5] =  
    {  
        {0 , 0 , 7 , 0 , 9 },  
        {0 , 0 , 5 , 7 , 0 },  
        {0 , 0 , 0 , 0 , 0 },  
        {0 , 2 , 3 , 0 , 0 },
    };  
    AdjacencyList sparser(true);
    AdjacencyList ad(true);
    create_sparse_list(sparse_matrix, 4, 5, sparser);
    std::cout << "Sparse Matrix Representation: " << "\n";
    sparse_traverse(sparser);
}
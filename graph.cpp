#include <iostream>
using namespace std;

class AdjacencyMatrixGraph{
    private: 
        int **matrix;
        int nodes;
    public:
    AdjacencyMatrixGraph(int nodes){
        this->nodes = nodes;
        matrix = new int*[nodes];

        for (int i = 0; i < nodes; i++)
        {
            matrix[i] = new int[nodes];
            for (int j = 0; j < nodes; j++)
            {
                matrix[i][j] = 0;
            }
        }      
    }  

    void display(){
        for (int k = 0; k < nodes; k++)
        {
            for (int b = 0; b < nodes; b++)
            {
                cout << matrix[k][b] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    void add_edge(int origin, int destination){
        if (destination < 0 || origin < 0 || origin > nodes || destination > nodes)
        {
            return;
        }
        
        matrix[origin][destination] = 1;
    }

    void remove_edge(int origin, int destination){
         if (destination < 0 || origin < 0 || origin > nodes || destination > nodes)
        {
            return;
        }

        matrix[origin][destination] = 0;
    }
};

int main(){
    AdjacencyMatrixGraph adjacentMatrix(5);
    adjacentMatrix.display();
    adjacentMatrix.add_edge(2, 3);
    adjacentMatrix.display();
}
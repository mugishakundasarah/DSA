#include <iostream>
using namespace std;

class AdjacencyMatrix {
    private:
        int nodes;
        int **matrix;
    public: 
        AdjacencyMatrix(int nodes) {
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
            for (size_t i = 0; i < nodes; i++)
            {
                for (int j = 0; j < nodes; j++)
                {
                    cout << matrix[i][j] << "\t";
                }
                cout << endl;   
            }
            
        }

        void add_edge(int origin, int destination){
            if (origin < 0 || destination < 0 || origin > nodes || destination > nodes)
            {
                return;
            }
            matrix[origin][destination] = 1;
        }

        void remove_edge(int origin, int destination){
            if (origin < 0 || destination < 0 || origin >= nodes || destination >= nodes)
            {
                return;
            }
            matrix[origin][destination] = 0;
        }
};

int main(){
    AdjacencyMatrix matrix(2);
    matrix.display();
    matrix.add_edge(0,1);
    cout << endl;
    matrix.display();

    matrix.add_edge(1,0);
    cout << endl;
    matrix.display();

    matrix.remove_edge(1,0);
    cout << endl;
    matrix.display();
}
#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

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

class AdjacencyListGraph{
    private: 
        int nodes;
        vector<int> *list;
    public:
     AdjacencyListGraph(int nodes){
         this->nodes = nodes;
         this->list = new vector<int>[nodes];
    }

    void display(){
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < list[i].size() ; j++)
            {
                cout << "->" << list[i][j];
            }
            cout << endl;
        }
               
    }

    void add_edge(int origin, int destination){
        list[origin].push_back(destination);
        list[destination].push_back(origin);
    }
    void BFS(int startingVertex){
        vector<bool> visited(nodes, false);
        std::list<int> queue;

        cout << "BFS result from " << startingVertex << " : " << endl;
        queue.push_back(startingVertex);
        visited[startingVertex] = true;
        while (!queue.empty())
        {
            int current = queue.front();
            for(auto i=list[current].begin(); i!=list[current].end(); i++){
                int adjVertex = *i;
                if(!visited[adjVertex]){
                    queue.push_back(adjVertex);
                    visited[adjVertex] = true;
                }
            }
            visited[current] = true;
            queue.pop_front();
        }
        
    }
    void DFS(int startingVertex){
        vector<bool> visited(nodes, false);
        stack<int> stack;

        stack.push(startingVertex);
        cout << "DFS RESULT from " << startingVertex << ":" << endl;

        while (!stack.empty())
        {
            int current = stack.top();
            cout << current << " " << endl;
            visited[current] = true;
            stack.pop();
            for(auto i=list[current].begin(); i!=list[current].end(); i++){
                int adjVertex = *i;
                if(!visited[adjVertex]){
                    stack.push(adjVertex);
                }
            }
        }
               
    }
};

int main(){
    // AdjacencyMatrixGraph adjacentMatrix(5);
    // adjacentMatrix.display();
    // adjacentMatrix.add_edge(2, 3);
    // adjacentMatrix.display(); 

    // AdjacencyListGraph list(5);
    // list.add_edge(3, 2);
    // list.display();

    AdjacencyListGraph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.display();
    g.BFS(1);
    g.DFS(1);
}
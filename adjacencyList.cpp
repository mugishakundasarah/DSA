#include <iostream>
#include <vector>

using namespace std;

class AdjacencyList {
    private: 
        int nodes;
        vector <int>*list;
    public: 
        AdjacencyList(int nodes){
            this->nodes = nodes;
            list = new vector<int>[nodes];
        }
    void display() {
        for (int i = 0; i < nodes; i++)
        {
            for (auto v : list[i])
            {
                cout << " -> " << v;
            }
            cout << endl;
        }
    }

    void delete_edge(int origin, int destination){
        for (int i = 0; i < list[origin].size(); i++)
        {
            if(list[origin][i] == destination){
                list[origin].erase(list[origin].begin() + i);
                break;
            }
        }
        
        for (int i = 0; i < list[destination].size(); i++)
        {
            if(list[destination][i] == origin){
                list[destination].erase(list[destination].begin() + i);
                break;
            }
        }
        
    }

    void add_edge(int origin , int destination){
        list[origin].push_back(destination);
        list[destination].push_back(origin);
    }
};


int main(){
    AdjacencyList list(5);
    list.add_edge(1,2);
    list.display();
    
    
    // list.add_edge(0,1);
    // list.add_edge(1, 1);
    // list.add_edge(1,0);
    // list.display();
    // list.delete_edge(1,0);
    // list.display();
}
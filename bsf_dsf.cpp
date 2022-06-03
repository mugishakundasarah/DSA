#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int numNodes;
		list<int> *adjList;
		
	public:
		Graph(int numNodes){
			this->numNodes = numNodes;
			adjList = new list<int> [numNodes];
		}
		
		void add_edge(int src, int dest){
			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
		
		void display(){
			for(int i=0; i<numNodes; i++){
				cout << i << ": ";
				for(auto node:adjList[i]){
					cout << i << " --> " << node << "    ";
				}
				
				cout << endl;
			}
		}
	
		void BFS(int startingVertex){
			list<int> queue;
			vector<bool> visited(numNodes, false);
			
			cout << "BFS result from " << startingVertex << ": " << endl;
			queue.push_back(startingVertex);
			visited[startingVertex] = true;
			
			while(!queue.empty()){
				int current = queue.front();
				cout << current << "\t";
				for(auto i = adjList[current].begin(); i!=adjList[current].end(); ++i){
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
	
};

int main(){

	Graph g(4);
	g.add_edge(0, 1);
	g.add_edge(1, 2);
	g.add_edge(2, 3);
	g.add_edge(3, 3);
	g.add_edge(1, 3);
	
	g.display();
	
	cout << endl << endl;
	g.BFS(2);

	return 0;
}
#include <iostream>
#include <vector>
#include <map>


using namespace std;

#define INF 1000000000;

struct Edge{
	int destinity, weight;
	Edge(int dest, int w){
		destinity = dest;
		weight = w;
	}
};


void printGraph(map<int, vector<Edge>>& adjacentyList, int Vertices){
	

	for(auto it : adjacentyList){
		for(auto vec : it.second){
			cout << "Edge from node " << it.first << " to node " << vec.destinity << " with weight " << vec.weight << endl;
		}
	}
	
}

bool findPath(map<int,vector<Edge>> & adjacentList, int source, int destinity, int weight){
	auto searchQueue = adjacentList[source];
	
	while (!searchQueue.empty())
	{
		auto edge = searchQueue.back();
		if(edge.destinity == destinity){
			cout << "road exist" << endl;
			return true;
		}
		else{
			searchQueue.pop_back();
			searchQueue += adjacentList[edge];

		}
	}
	return false;
}


void addEdgeDirectedWithWeight(map<int, vector<Edge>>& adjacentList, int source, int destinity, int weight){
	adjacentList[source].push_back(Edge(destinity, weight));
	
}

int main(){

    int Z, N;

	cin >> N >> Z;

    int firstBuild, secondBuild, high;
	map<int, vector<Edge>> edges;

    for(int i=0; i < Z; i++){
		cin >> firstBuild >> secondBuild >> high;
		


		addEdgeDirectedWithWeight(edges, firstBuild, secondBuild, high);
		
	
    }

	printGraph(edges, N);

    return 0;
}






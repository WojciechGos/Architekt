#include <iostream>
#include <vector>
#include <map>
#include <queue>


using namespace std;

#define INF 1000000000;


struct Edge{
	int destinity, weight;
	Edge(int dest, int w){
		destinity = dest;
		weight = w;
	}
};


void printAcjacent(const vector<Edge>& adjacentList, int source){
	for(auto it: adjacentList){
		cout << "Edge{ " << source << " " << it.destinity << "} " << it.weight << endl;
	}
}



void printGraph(map<int, vector<Edge>>& adjacentyList, int Vertices){
	

	for(auto it : adjacentyList){
		for(auto vec : it.second){
			cout << "Edge from node " << it.first << " to node " << vec.destinity << " with weight " << vec.weight << endl;
		}
	}
	
}

bool findPath(map<int,vector<Edge>> & adjacentList, int source, int destinity, int weight){
	cout << "Find Path: start" << endl;
	auto searchQueue = adjacentList[source];


	printAcjacent(adjacentList[source], source);
	
	while (!searchQueue.empty())
	{
		cout << "searchQueue.front() - " << searchQueue.front().destinity << endl;
	
		auto edge = searchQueue.front();
		searchQueue.erase(searchQueue.begin());
		if(edge.destinity == destinity){
			cout << "road exist" << endl;
			return true;
		}
		else{
			
			searchQueue.insert(searchQueue.end(), adjacentList[edge.destinity].begin(), adjacentList[edge.destinity].end());
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
	if(findPath(edges, 4, 1, 0)){
		cout << "Yes" << endl;
	}else{
		cout << "No " << endl;
	}

    return 0;
}






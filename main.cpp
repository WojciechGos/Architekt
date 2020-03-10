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

// ostream & operator << (ostream& os, vector<pair<int,int>> vpair){

// 	for(auto it : vpair){
// 		os << "{" << it.first << " " << it.second << "}";
// 	}

// 	return os;
// }

void findPath(vector<pair<int, int>> adjacentList[], int source, int destinity, int weight);

void addEdgeDirectedWithWeight(map<int, vector<Edge>> adjacentList, int source, int destinity, int weight){
	adjacentList[source].push_back(Edge(destinity, weight));
	cout << "addEdge: ";
	
	// for(const auto& it: adjacentList[source]){
	// 	cout << source << " ";
	// 	cout << it.first << " " << it.second << endl;
	// }
	
}



void printGraph(map<int, vector<Edge>> adjacentyList, int Vertices){
	
	cout << "Print Graph" << endl;
	for(auto it : adjacentyList){
		for(auto vec : it.second){
			cout << "Edge from node " << it.first << " to node " << vec.destinity << " with weight " << vec.weight << endl;
		}
	}
	
}

int main(){

    int Z, N;

	cin >> N >> Z;

    int firstBuild, secondBuild, high;
	map<int, vector<Edge>> edges;

    for(int i=0; i < Z; i++){
		cin >> firstBuild >> secondBuild >> high;
		cout << "The egde between " << firstBuild << " and " << secondBuild << " with weight " << high << endl;


		addEdgeDirectedWithWeight(edges, firstBuild, secondBuild, high);
		
	
    }

	printGraph(edges, N);

    return 0;
}



void findPath(vector<pair<int, int>> adjacentList[], int source, int destinity, int weight){

	

	
}


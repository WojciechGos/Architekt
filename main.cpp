#include <iostream>
#include <vector>
#include <map>


using namespace std;

#define INF 1000000000;

// ostream & operator << (ostream& os, vector<pair<int,int>> vpair){

// 	for(auto it : vpair){
// 		os << "{" << it.first << " " << it.second << "}";
// 	}

// 	return os;
// }

void findPath(vector<pair<int, int>> adjacentList[], int source, int destinity, int weight);

void addEdgeDirectedWithWeight(map<int, vector<pair<int,int>>> adjacentList, int source, int destinity, int weight){
	adjacentList[source].push_back(make_pair(destinity, weight));
	cout << "addEdge: ";
	
	for(const auto& it: adjacentList[source]){
		cout << source << " ";
		cout << it.first << " " << it.second << endl;
	}
	
}



void printGraph(map<int, vector<pair<int,int>>> adjacentyList, int Vertices){
	
	cout << "Print Graph" << endl;
	// for(int i=0; i<Vertices; i++){
	// 	for(auto it = adjacentyList[i]; it != adjacentyList; it++){
	// 		cout << "Node " << it->first << " has edge to " << it->second << endl;
	// 	}
	// }
	// for(const auto & it : adjacentyList){
	// 	cout << it.first << " " << it.second << endl;
	// }
	
}

int main(){

    int Z, N;

	cin >> N >> Z;

    int firstBuild, secondBuild, high;
	map<int, vector<pair<int,int>>> edges;

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


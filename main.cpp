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


void printAdjacent(const vector<Edge>& adjacentList, int source){
	cout << endl;
	for(auto it: adjacentList){
		cout << "Edge{ " << source << " " << it.destinity << "} " << it.weight << endl;
	}
}

bool isNotIn(int destinationNode, const vector<int>& processed){

	for(auto it : processed){
		if(it == destinationNode){
			return true;
		}
	}

	return false;
}

void printGraph(const map<int, vector<Edge>>& adjacentyList){
	

	for(auto it : adjacentyList){
		for(auto vec : it.second){
			cout << "Edge from node " << it.first << " to node " << vec.destinity << " with weight " << vec.weight << endl;
		}
	}
	
}

int findLowestCostNode(const vector<Edge>& edges){
	int low = 999999;
	for(auto it: edges){
		if(low > it.weight){
			low = it.weight;
		}
	}
	return low;
}

bool findPath(map<int,vector<Edge>>& adjacentList, const int& source, const int& destinity, const int& weight, vector<Edge>& road){

	auto searchQueue = adjacentList[source];
	vector<int> processed;
	

    // printAdjacent(adjacentList[source], source);
	
	while (!searchQueue.empty())
	{
		cout << "searchQueue.front() - " << searchQueue.front().destinity << " weight=" <<  searchQueue.front().weight << endl;

		road.push_back(searchQueue.front());

		processed.push_back(searchQueue.front().destinity);
		auto edge = searchQueue.front();
		searchQueue.erase(searchQueue.begin());

		if(edge.destinity == destinity && isNotIn(edge.destinity, processed) ){
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
	weight = -1*weight;
	adjacentList[destinity].push_back(Edge(source, weight));
}


int main(){

    int Z, N;

	cin >> N >> Z;

    int firstBuild, secondBuild, high;
	map<int, vector<Edge>> edges;
	vector<Edge> road;
	int roadCost = 0;

    for(int i=0; i < Z; i++){
		cin >> firstBuild >> secondBuild >> high;
		cout << endl;
		cout << "FirstBuild=" << firstBuild << " SecondBuild=" << secondBuild << " Weight=" << high << endl;
		cout << endl;
		printGraph(edges);

		if(findPath(edges,firstBuild, secondBuild, high, road)){
			for(auto it: road){
				roadCost += it.weight;
			}
			if(roadCost == high){
				addEdgeDirectedWithWeight(edges, firstBuild, secondBuild, high);
			}
		}else{
			addEdgeDirectedWithWeight(edges, firstBuild, secondBuild, high);
		}
		
		road.clear();
		
	
    }

	
	

    return 0;
}






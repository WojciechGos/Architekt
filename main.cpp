#include <iostream>
#include <vector>
#include <map>
#include <queue>


using namespace std;

#define INF 1000000000


struct Edge{
	int value, destinity, weight;
	Edge(int dest, int w){
		destinity = dest;
		weight = w;
	}
	Edge(int val, int dest, int w){
		destinity = dest;
		weight = w;
		value = val;
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
			return false;
		}
	}

	return true;
}


Edge findLowestCostNode(const vector<Edge>& edges){
	int low = INF;
	Edge node(INF, INF);

	for(auto it: edges){
		if(low > it.weight){
			low = it.weight;
			node = it;
		}
	}
	return node;
}

int findUnprocessedNode(){



	return 0;
}

bool findPath(map<int,vector<Edge>>& adjacentList, const int& source, const int& destinity, const int& weight, int& cost){
	// cost = 0;

	auto searchQueue = adjacentList[source];
	vector<int> processed; 
	processed.push_back(source);
	auto edge = searchQueue.front();
    // printAdjacent(adjacentList[source], source);
	
	while (!searchQueue.empty())
	{
		// cout << "searchQueue.front() - " << searchQueue.front().destinity << " weight=" <<  searchQueue.front().weight << endl;

		
		auto edge = searchQueue.front();
		cout << "here1" << endl;
		cost += edge.weight;
		cout << "Here2" << endl;
		processed.push_back(searchQueue.front().destinity);
		searchQueue.erase(searchQueue.begin());
		cout << "if statement" << endl;
		if(edge.destinity == destinity){
			return true;
		}
		else{
			cout << "else statement" << endl;
			for(auto it: adjacentList[edge.destinity]){
				if(isNotIn(it.destinity, processed)){
					searchQueue.push_back(it);
				}
			}
		}
	}
	return false;
}


void addEdgeDirectedWithWeight(map<int, vector<Edge>>& adjacentList, int source, int destinity, int weight){
	adjacentList[source].push_back(Edge(source, destinity, weight));
	weight = -1*weight;
	adjacentList[destinity].push_back(Edge(destinity, source, weight));
}


int main(){

    int Z, N;

	cin >> N >> Z;

    int firstBuild, secondBuild, high;
	vector<string> result;
	map<int, vector<Edge>> edges;
	vector<Edge> road;
	int roadCost = 0;

    for(int i=0; i < Z; i++){
		cin >> firstBuild >> secondBuild >> high;
		cout << endl;
		cout << "FirstBuild=" << firstBuild << " SecondBuild=" << secondBuild << " Weight=" << high << endl;
		cout << endl;
		

		if(findPath(edges,firstBuild, secondBuild, high, roadCost)){
			if(roadCost == high){
				addEdgeDirectedWithWeight(edges, firstBuild, secondBuild, high);
				result.push_back("YES");
			}else
			{
				result.push_back("NO");
			}
			
		}else{
			addEdgeDirectedWithWeight(edges, firstBuild, secondBuild, high);
			result.push_back("YES");
		}
	
    }
	for(auto it: result){
		cout << it << endl;
	}

	
	

    return 0;
}






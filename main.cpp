#include <iostream>
#include <vector>

using namespace std; 

void addEdge(vector<int> adj[], int u, int v) { 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

int findPos(string val, vector<string> v) {
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) == val) {
			return i;
		}
	}
	return 0;
}

void colorGraph(vector<int> adj[], int V) {

	string colored[V];
	int coloredOrNot[V];
	vector<string> colors;

	// Initially, none of the vertices are colored
	// coloredOrNot[i] is '0' if not colored. Otherwise, '1'
	for (int i = 0; i < V; i++) {
		coloredOrNot[i] = 0;
		colored[i] = "none";
	}

	for (int i = 0; i < V; i++) {
		colors.push_back("red");
		colors.push_back("blue");
		colors.push_back("green");


		for (auto j : adj[i]) {
			
			if(coloredOrNot[j] == 1) {
				int pos = findPos(colored[j], colors);
				//cout << "For vertex " << j  << "; " << colors.at(pos) << "\n";
				colors.erase(colors.begin() + pos);
				
			}
		}

		colored[i] = colors.front();
		coloredOrNot[i] = 1;
		colors.clear();
	
	}
	
	for(int i = 0; i < V; i++) {
	
		cout << "Color at vertex " << i << " is: " << colored[i] << endl;
	}
}

int main() { 
	int V = 10; 

	vector<int> adj[V]; 
	
	addEdge(adj, 0, 1); 
	addEdge(adj, 0, 9); 
	addEdge(adj, 1, 2); 
	addEdge(adj, 1, 4); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 4, 5); 
	addEdge(adj, 4, 6);
	addEdge(adj, 4, 9);
	addEdge(adj, 5, 6);
	addEdge(adj, 7, 8);
	addEdge(adj, 8, 9);

	colorGraph(adj, V); 
	return 0; 
} 

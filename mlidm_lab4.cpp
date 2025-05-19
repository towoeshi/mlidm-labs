#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
const vector<string> vertexNames = {
    "a", "b", "c", "d", "e",
    "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o",
    "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y",
    "z"
};

void findMinDistance(vector<vector<int>> graph, int start, int end) {
    vector<int> dist(graph.size(), INF);
    vector<bool> visited(graph.size(), false);
    vector<int> prev(graph.size(), -1);

    dist[start] = 0;

    for (int i = 0; i < graph.size(); ++i) {
        int minDist = INF;
        int u = -1;
        for (int j = 0; j < graph.size(); ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) 
            break;

        visited[u] = true;
        for (int v = 0; v < graph.size(); ++v) {
            if (u == v || graph[u][v] == 0) 
                continue;
            
            if (dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[end] != INF) {
        cout << "shortest path from " << start+1 << " to " << end+1 << " is " << dist[end] << endl;
    }
    else {
        cout << "no path from " << start+1 << " to " << end+1 << endl;
    }

    vector<int> path;
    for (int v = end; v != -1; v = prev[v]) {
        path.push_back(v);
    }

    

    reverse(path.begin(), path.end());

    cout << "path is: ";
    for (int i = 0; i < path.size(); ++i) {
        if (i > 0) cout << " -> ";
        cout << vertexNames[path[i]];
    }


}
int main() {

	vector<vector<int>> graph = { 
        {0, 2, 0, 3, 0, 0},
		{2, 0, 1, 0, 4, 0},
		{0, 1, 0, 0, 0, 5},
		{3, 0, 0, 0, 2, 0},
		{0, 4, 0, 2, 0, 1},
		{0, 0, 5, 0, 1, 0}};


	int start, finish;
	cout << "enter the start point (from a to " << vertexNames[graph.size()-1] << "): ";
	cin >> start;
	start--;

	cout << "enter the finish point (from a to " << vertexNames[graph.size() - 1] << "): ";
	cin >> finish;
	finish--;

	if (start < 0 || start > graph.size() || finish < 0 || finish > graph.size()) {
		cout << "incorrect point entry";
		return 1;
	}
    
	findMinDistance(graph, start, finish);

	return 0;
}
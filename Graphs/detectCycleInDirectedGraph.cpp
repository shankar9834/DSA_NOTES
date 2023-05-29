//29 may 2023
//source - https://www.geeksforgeeks.org/detect-cycle-in-a-graph/



#include<bits/stdc++.h>
using namespace std;



using namespace std;

/*
1)Calculate the in-degree (number of incoming edges) for each vertex in the DAG and set the starting value of 
the visited nodes count to 0.
2)Select all of the vertices with in-degree values of 0, then enqueue them all.
3)Add one more visited node to the count after removing a vertex from the queue (Dequeue operation).
4)For each of its neighbouring nodes or vertices, reduce in-degree by 1.
5)Add a node or vertex to the queue if the in-degree of any nearby nodes or vertices is lowered to zero.
 Up until the queue is empty, repeat step 3.
6)The topological sort is not possible for the provided graph if the number of 
visited nodes is not equal to the number of graph vertices.

*/

//using bfs --> kahns algorithm

class Graph {
private:
	int V; // number of vertices
	vector<vector<int>> adj; // adjacency list

public:
	Graph(int V) {
		this->V = V;
		adj.resize(V);
	}

	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}

	bool isCyclic() {
		vector<int> inDegree(V, 0); // stores in-degree of each vertex
		queue<int> q; // queue to store vertices with 0 in-degree
		int visited = 0; // count of visited vertices

		// calculate in-degree of each vertex
		for (int u = 0; u < V; u++) {
			for (auto v : adj[u]) {
				inDegree[v]++;
			}
		}

		// enqueue vertices with 0 in-degree
		for (int u = 0; u < V; u++) {
			if (inDegree[u] == 0) {
				q.push(u);
			}
		}

		// BFS traversal
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			visited++;

			// reduce in-degree of adjacent vertices
			for (auto v : adj[u]) {
				inDegree[v]--;
				// if in-degree becomes 0, enqueue the vertex
				if (inDegree[v] == 0) {
					q.push(v);
				}
			}
		}

		return visited != V; // if not all vertices are visited, there is a cycle
	}
};



// method 2
// use dfs to solve 

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int vis[100005];
   bool dfs(int v,vector<int>adj[])
    {
        bool fans=false;
        vis[v]=1;
        
        for(auto child:adj[v])
        {
            if(vis[child]==0) {
               fans|=dfs(child,adj);
            }
            else if(vis[child]==1)
            {
                return true;
            }
        }
        vis[v]=2;
        
        return fans;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        bool ans=false;
        memset(vis,0,sizeof(vis));
           for(int i=0;i<V;i++)
           {
               if(vis[i]==0)
               {
                    ans|=dfs(i,adj);
               }
              
           }
           
           return ans;
        
    }
};



int main() {
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(4, 5);
	g.addEdge(5, 3);

	if (g.isCyclic()) {
		cout << "Graph contains cycle." << endl;
	} else {
		cout << "Graph does not contain cycle." << endl;
	}

	return 0;
}

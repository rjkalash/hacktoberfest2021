#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int v;
	list<int> *adj;
	public:
		Graph(int v);
		void addEdge(int u, int w);
    	int isEulerian();
    	bool isConnected();
    	void DFS_recur(int currv, bool visited[]);
};
Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}
void Graph::addEdge(int u, int w)
{
	adj[u].push_back(w);
}
void Graph::DFS_recur(int currv, bool visited[])
{
	visited[currv] = true;
	cout<<currv<<" ";
	list<int>::iterator i;
	for (i=adj[currv].begin(); i!=adj[currv].end(); i++)
	{
		if (visited[*i] == false)
		DFS_recur(*i, visited);
	}
}
bool Graph::isConnected()
{
    bool visited[v];
    int i;
    for (i = 0; i < v; i++)
        visited[i] = false;
    for (i = 0; i < v; i++)
        if (adj[i].size() != 0)
            break;
    if (i == v)
        return true;
    DFS_recur(i, visited);
    for (i = 0; i < v; i++)
       if (visited[i] == false && adj[i].size() > 0)
            return false;
    return true;
}
int Graph::isEulerian()
{
    if (isConnected() == false)
        return 0;
    int odd = 0;
    for (int i = 0; i < v; i++)
        if (adj[i].size() & 1)
            odd++;
    if (odd > 2)
        return 0;
    return (odd)? 1 : 2;
}
void test(Graph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "\nGraph is not Eulerian\n";
    else if (res == 1)
        cout << "\nGraph has a Euler path\n";
    else
        cout << "\nGraph has a Euler cycle\n";
}
int main()
{
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(0, 3);
    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 1);
    g1.addEdge(3, 0);
    g1.addEdge(3, 4);
    g1.addEdge(4, 3);
    test(g1);
	return 0;
}


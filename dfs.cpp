#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void addEdge(int u,int v,vector<int>* V)
{
	V[u].push_back(v);
}
void DFS(int s,vector<int>* adj,int n)
{
	// Initially mark all verices as not visited 
    int visited[n+1]={0};
  
    // Create a stack for DFS 
    stack<int> stack; 
  
    // Push the current source node. 
    stack.push(s); 
  	
  	vector<int>::iterator i;
    while (!stack.empty()) 
    { 
        // Pop a vertex from stack and print it 
        s = stack.top(); 
        stack.pop(); 
  
        // Stack may contain same vertex twice. So 
        // we need to print the popped item only 
        // if it is not visited. 
        if (!visited[s]) 
        { 
            cout << s << " "; 
            visited[s] = true; 
        } 
  
        // Get all adjacent vertices of the popped vertex s 
        // If a adjacent has not been visited, then push it 
        // to the stack. 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
            if (!visited[*i]) 
                stack.push(*i); 
    }  
}
int main()
{
	int n,e,u,v;
	cout<<"Enter no of vertices"<<endl;
	cin>>n;
	cout<<"Enter no of Edges"<<endl;
	cin>>e;
	int copy=n;
	vector<int> V[n+1];
	for(int i=0;i<e;i++)
	{
		cout<<"Enter from"<<endl;
		cin>>u;
		cout<<"Enter To"<<endl;
		cin>>v;
		addEdge(u,v,V);
	}
	cout<<"Graph Representation using Adjacency List is"<<endl;
	vector<int>::iterator it;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<"->";
		for(it=V[i].begin();it!=V[i].end();it++)
		{
			cout<<*it<<" ";
		}	
		cout<<endl;
	}
	cout<<"Depth First traversal of the Graph is ";
	DFS(1,V,n);
	return 0;
}

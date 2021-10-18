#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10

struct Graph *graph;
struct Graph *tr;
int stack[MAX_SIZE], top;

struct adjlist_node{
int dest;
struct adjlist_node *next;
};

struct adj_list{
struct adjlist_node *head;
};

struct Graph{
int V;
int *visited;
struct adj_list *arr;
};

void push(int x){
if (top >= MAX_SIZE - 1){
printf("\nStack is overflow");
}
else{
top++;
stack[top] = x;
}
}

void pop(){
if (top <= -1){
printf("\nStack is underflow");
}
else{
top-- ;
}
}

struct adjlist_node *new_adjlist_node(int dest){
struct adjlist_node *newNode = (struct adjlist_node *)malloc(sizeof(struct adjlist_node));
newNode->dest = dest;
newNode->next = NULL;
return newNode;
}

struct Graph *create_graph(int V){
struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
graph->V = V;
graph->arr = (struct adj_list *)malloc(V * sizeof(struct adj_list));
int i;
for (i = 0; i < V; ++i)
graph->arr[i].head = NULL;
return graph;
}

void transpose(struct Graph *tr, int src, int dest){
struct adjlist_node *newNode = new_adjlist_node(src);
newNode->next = tr->arr[dest].head;
tr->arr[dest].head = newNode;
}

void add_edge(struct Graph *graph, struct Graph *tr, int src, int dest){
struct adjlist_node *newNode = new_adjlist_node(dest);
newNode->next = graph->arr[src].head;
graph->arr[src].head = newNode;
transpose(tr, src, dest);
}

void print_graph(struct Graph *graph1){
int v;
for (v = 0; v < graph1->V; v++){
struct adjlist_node *temp = graph1->arr[v].head;
while (temp){
printf("(%d -> %d)\t", v, temp->dest);
temp = temp->next;
}
}
}

void fill_order(struct Graph *graph, int v, bool visited[], int *stack){
visited[v] = true;
int i = 0;
struct adjlist_node *temp = graph->arr[v].head;
while (temp){
if (!visited[temp->dest])
{
fill_order(graph, temp->dest, visited, stack);
}
temp = temp->next;
}
push(v);
}

void dfs_recursive(struct Graph *tr, int v, bool visited[]){
visited[v] = true;
printf("%d ", v);
struct adjlist_node *temp = tr->arr[v].head;
while (temp){
if (!visited[temp->dest]){
dfs_recursive(tr, temp->dest, visited);
}
temp = temp->next;
}
}

void strongly_connected_components(struct Graph *graph, struct Graph *tr, int V){
bool visited[V];
int i;
for (i = 0; i < V; i++)
visited[i] = false;
for (i = 0; i < V; i++){
if (visited[i] == false){
fill_order(graph, i, visited, stack);
}
}
int count = 1;
for (i = 0; i < V; i++)
visited[i] = false;
while (top != -1){
int v = stack[top];
pop();
if (visited[v] == false){
printf("Strongly connected component %d: \n", count++);
dfs_recursive(tr, v, visited);
printf("\n");
}
}
}

int main(){
top = -1;
int v = 8;
struct Graph *graph = create_graph(v);
struct Graph *tr = create_graph(v);
int src, dest, choice; 
printf("1. Construct graph  2. Stop ");
scanf("%d", &choice);
while(choice == 1){
    printf("Enter Source and destination: ");
    scanf("%d %d", &src, &dest);
    add_edge(graph, tr, src, dest);
    printf("1. Construct graph  2. Stop ");
    scanf("%d", &choice);
}
printf("\n");
printf("Graph:\n");
print_graph(graph);
printf("\n");
printf("Graph transpose\n");
print_graph(tr);
printf("\n");
strongly_connected_components(graph, tr, v);

return 0;
}

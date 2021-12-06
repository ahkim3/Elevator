/*
	Name: Andrew Kim
	Date: 12/5/2021
	Title: Programming Assignment #3

	References:
		1) https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
*/

#include <iostream>
#include <queue>

using namespace std;


// This class represents a directed graph using
// adjacency list representation
class Graph
{
	int vertices; // No. of vertices

	// Pointer to an array containing adjacency
	// lists
	vector<int>* adj;
public:
	Graph(int vertices); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints BFS traversal from a given source s
	void BFS(int s);
};

Graph::Graph(int vertices)
{
	this->vertices = vertices;
	adj = new vector<int>[vertices];
}


// Add the weight of a new edge to a vertex's adjacency list
void Graph::addEdge(int vertex, int weight)
{
	adj[vertex].push_back(weight);
}

void Graph::BFS(int startVertex)
{
	// Mark all the vertices as not visited
	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visited[i] = false;

	// Create a queue for BFS
	queue<int> queue;

	// Mark the current node as visited and enqueue it
	visited[startVertex] = true;
	queue.push(startVertex);

	// 'i' will be used to get all adjacent
	// vertices of a vertex
	vector<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		startVertex = queue.front();
		cout << startVertex << " ";
		queue.pop();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (i = adj[startVertex].begin(); i != adj[startVertex].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push(*i);
			}
		}
	}
}


int main()
{
	int floors, start, goal, up, down;

	// Obtain user input
	cout << "Please enter desired floors, start, goal, up, and down inputs: ";
	cin >> floors >> start >> goal >> up >> down;
	cout << endl;

	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}

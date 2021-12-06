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
	vector<int>* adjList;
public:
	Graph(int);

	// function to add an edge to graph
	void addEdge(int, int);

	// prints BFS traversal from a given source s
	void BFS(int, int);
};


Graph::Graph(int vertices)
{
	this->vertices = vertices;
	adjList = new vector<int>[vertices];
}


// Add the weight of a new edge to a vertex's adjacency list
void Graph::addEdge(int vertex, int weight)
{
	adjList[vertex].push_back(weight);
}

void Graph::BFS(int startVertex, int goal)
{
	queue<int> queue;

	// Mark all the vertices as not visited
	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visited[i] = false;

	// Mark the current node as visited and enqueue it
	visited[startVertex] = true;
	queue.push(startVertex);

	// 'i' will be used to get all adjacent
	// vertices of a vertex
	vector<int>::iterator i;

	while (!queue.empty())
	{
		if (startVertex == goal)
			return;

		// Dequeue a vertex from queue and print it
		startVertex = queue.front();
		cout << startVertex << " ";

		queue.pop();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (i = adjList[startVertex].begin(); i != adjList[startVertex].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push(*i);
			}
		}
	}
}


/*bool bfs(vector<int>& trackFloors, int floors, int start, int goal, int up, int down)
{
	queue<PII> q;

	q.push(make_pair(start, 0));
	int press = 0;
	while (!q.empty())
	{
		PII top = q.front();
		q.pop();

		if (press == top.second || top.first == goal)
			trackFloors.push_back(top.first);

		press = top.second;

		visited[top.first] = true;


		if (top.first == goal)
		{
			return true;
		}
		press++;
		if (top.first + up <= floors && visited[top.first + up] == false)
		{
			visited[top.first + up] = true;
			q.push(make_pair(top.first + up, press));
		}
		if (top.first - down >= 0 && visited[top.first - down] == false)
		{
			visited[top.first - down] = true;
			q.push(make_pair(top.first - down, press));
			//if (start < goal && top.first > goal)
			//    trackFloors.pop_back();
		}
	}
	return false;
}*/


int main()
{
	int floors, start, goal, up, down;

	// Obtain user input
	cout << "Please enter desired floors, start, goal, up, and down inputs: ";
	cin >> floors >> start >> goal >> up >> down;
	cout << endl;

	// Create a graph given in the above diagram
	Graph g(floors);

	for (int i = start; i <= floors - up; i += up)
		g.addEdge(i, i + up);
	g.addEdge(11, 10);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(start, goal);

	return 0;
}

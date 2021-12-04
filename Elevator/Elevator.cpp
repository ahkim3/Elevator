#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Define Global Variables and Prototypes
#define MAX 100

#define initial 1 // white
#define waiting 2 // grey
#define visited 3 // black

int n; // no. of vertices
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int pop_queue();
int isEmpty_queue();

using namespace std;


int main()
{
    create_graph();
    BF_Traversal();
    return 0;
}

// BF_Traversal Function
void BF_Traversal()
{
    int v;

    for (v = 0; v < n; v++)
        state[v] = initial;

    printf("Enter Start Vertex for BFS: \n");
    cin >> v;
    BFS(v);
}

// BFS Function
void BFS(int v)
{
    int i;

    insert_queue(v);
    state[v] = waiting;

    while (!isEmpty_queue())
    {
        v = pop_queue();
        printf("%d ", v);
        state[v] = visited;

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && state[i] == initial)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}


// insert_queue Function
void insert_queue(int vertex)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

// isEmpty_queue Function
int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

// Pop_queue Function
int pop_queue()
{
    int pop_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    pop_item = queue[front];
    front = front + 1;
    return pop_item;
}

// create_graph Function
void create_graph()
{
    int count, max_edge, origin, destin;

    printf("Enter Number of Vertices : ");
    cin >> n;
    max_edge = n * (n - 1);

    for (count = 1; count <= max_edge; count++)
    {
        cout << "Enter Edge " << count << " (-1 -1 to quit) :";
        cin >> origin >> destin;

        if ((origin == -1) && (destin == -1))
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("Invalid Edge!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}

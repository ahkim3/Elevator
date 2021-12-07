/*
    Name: Andrew Kim
    Pawprint: AHKYQX
    Assignment: CS3050 Prog3 2021F
    Date: 12/5/2021

    References:
    1) https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
    2) https://stackoverflow.com/questions/5289597/how-to-use-vectorpush-back-with-a-struct
    3) https://www.cplusplus.com/reference/algorithm/reverse/
*/

#include <iostream>
#include <queue>
#include <algorithm> // Used for std::reverse


using namespace std;


bool visited[101];
struct node {
    int value;
    bool upDirection; // True if node is upwards in relation to previous node
};


node createNode(int value, bool upDirection)
{
    node myNode = { value, upDirection };
    return myNode;
}


bool bfs(vector<int>& trackFloors, int floors, int start, int goal, int up, 
    int down)
{
    queue<node> queue;
    vector<node> trackNodes;

    queue.push(createNode(start, true));

    while (!queue.empty())
    {
        node front = queue.front();
        queue.pop();

        trackNodes.push_back(front);

        visited[front.value] = true;

        // Found goal floor
        if (front.value == goal)
        {
            int searchValue;
           
            // Backtrack to isolate path
            while (front.value != start)
            {
                trackFloors.push_back(front.value);

                if (front.upDirection) // Need to subtract to get prior node
                    searchValue = front.value - up;
                else // Need to add to get prior node
                    searchValue = front.value + down;

                // Find previous node
                for (int i = trackNodes.size() - 1; i >= 0; i--)
                {
                    if (trackNodes.at(i).value == searchValue)
                    {
                        front = trackNodes.at(i);
                        trackNodes.erase(trackNodes.begin() + i);
                        break;
                    }
                }
            }

            trackFloors.push_back(start); // Add final node
            reverse(trackFloors.begin(), trackFloors.end()); // Fix order

            return true;
        }

        // Found valid higher floor
        if (front.value + up <= floors && visited[front.value + up] == false)
        {
            visited[front.value + up] = true;
            queue.push(createNode(front.value + up, true));
        }

        // Found valid lower floor
        if (front.value - down >= 0 && visited[front.value - down] == false)
        {
            visited[front.value - down] = true;
            queue.push(createNode(front.value - down, false));
        }
    }
    return false;
}


int main()
{
    vector<int> trackFloors;
    int floors, start, goal, up, down;
    bool success;

    cin >> floors >> start >> goal >> up >> down;

    success = bfs(trackFloors, floors, start, goal, up, down);
    cout << endl;

    if (success)
    {
        for (unsigned int i = 0; i < trackFloors.size() - 1; i++) // Print all but last
            cout << trackFloors.at(i) << " -> ";
        cout << trackFloors.at(trackFloors.size() - 1) << endl; // Print last floor
    }
    else
        cout << "use the stairs" << endl;
    return 0;
}

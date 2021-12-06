#include <iostream>
#include <queue>

using namespace std;

#define MAX 10000005
#define PII pair<int, int>
vector<vector<int>> adj;

bool visited[MAX];

bool bfs(vector<int>& trackFloors, int floors, int start, int goal, int up, int down)
{
    queue<PII> q;

    q.push(make_pair(start, 0));
    int press = 0;
    while (!q.empty())
    {
        PII top = q.front();
        q.pop();

        //if (press == top.second || top.first == goal)
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
}

int main()
{
    vector<int> trackFloors;
    int floors, start, goal, up, down;
    bool success;

    cin >> floors >> start >> goal >> up >> down;

    success = bfs(trackFloors, floors, start, goal, up, down);

    if (success)
        for (int i : trackFloors)
            cout << i << ' ';
    else
        cout << "use the stairs" << endl;
    return 0;
}
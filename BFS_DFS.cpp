/*
Author: Pin Chen
Date: May 16. 2018
Description:
    For a class HW to implant Breadth First and Depth First search algorithms.
Using Adjacency Set to present a graph. Travel through the graph, and print
vertices out in visited-order.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std; // to save typing.

class Graph
{
private:
    int num_of_vertex;
    vector<int> *AdjS;
public:
    Graph(int V);
    ~Graph();
    void addEdge(int from, int to);
    void BFS(int Start);
    void DFS(int Start);
};

Graph::Graph(int V)
{
    this->num_of_vertex = V;
    AdjS = new vector<int>[V];
}
Graph::~Graph()
{
    delete [] AdjS;
}
void Graph::addEdge(int from, int to)
{
    AdjS[from-1].push_back(to);  // '-1',Vector starts from index 0
}


//BFS: uses queue to store vertices.
//From each vertex, go through all its connected "friends".
void Graph::BFS(int Start)
{
    bool visited[this->num_of_vertex];
    queue<int> q;
    q.push(Start);
    visited[Start] = true;
    cout << "BFS: "<< Start<< " ";

    vector<int>::iterator i;
    while(!q.empty())
    {
        Start = q.front();
        q.pop();  //it is visited, so we could pop it right away.
        for (i = AdjS[Start-1].begin(); i != AdjS[Start-1].end(); i++)
        {
            if (!visited[*i])
            {
                q.push(*i);
                cout << *i << " ";
                visited[*i] = true;
            }
        }
    }
    cout << endl;
}

//DFS: uses stack to stored the vertices.
//push a "closest friend" into stack, and find that friends' "closest friend".
void Graph::DFS(int Start)
{
    bool visited[this->num_of_vertex];
    stack<int> s;
    s.push(Start);
    visited[s.top()]= true;
    cout << "DFS: "<< Start <<" ";

    vector<int>::iterator i;
    while(!s.empty())
    {
        int top = s.top();
        for(i = AdjS[top-1].begin(); i != AdjS[top-1].end(); i++)
        {
            if (!visited[*i])
                {
                s.push(*i);
                visited[*i] = true;
                cout << *i << " ";
                break;    //just get the first visited V.
                }
        }
        if(i == AdjS[top-1].end())  //if this vertex has no more child, pop it.
        {
            s.pop();
        }
    }
    cout << endl;
}


int main()
{
    Graph a(8);
    a.addEdge(1,2);
    a.addEdge(1,4);
    a.addEdge(1,7);
    a.addEdge(2,1);
    a.addEdge(2,5);
    a.addEdge(2,6);
    a.addEdge(3,6);
    a.addEdge(3,8);
    a.addEdge(4,1);
    a.addEdge(5,2);
    a.addEdge(5,7);
    a.addEdge(6,2);
    a.addEdge(6,3);
    a.addEdge(7,1);
    a.addEdge(7,5);
    a.addEdge(8,3);
    a.BFS(1);
    a.DFS(1);
    return 0;
}

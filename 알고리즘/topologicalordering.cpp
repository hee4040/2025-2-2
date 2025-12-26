#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
  int V;
  list<int>* adj;
  void DFS(int v, bool visited[], stack<int>& Stack);

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

void Graph::DFS(int v, bool visited[], stack<int>& Stack){
  visited[v]=true;
  list<int>::iterator i;                                      // linked list 내부 순서를 나타냄
  for(i=adj[v].begin(); i != adj[v].end(); ++i)
    if(!visited[*i])                                          // 방문하지 않았었으면 dfs탐색을 해준다
      DFS(*i, visited, Stack);

  Stack.push(v);                                              // 방문한 노드는 스택에 넣는다
}

void Graph::topologicalSort(){
  stack<int> Stack;

  bool* visited = new bool[V];
  for(int i=0; i<V; i++)                // visited배열을 false로 채움
    visited[i] = false;                       

  for(int i=0; i<V; i++)                // 방문하지 않았던 노드면 dfs탐색을 한다
    if(visited[i]==false)
      DFS(i, visited, Stack);

  while (Stack.empty()==false){         // 스택에 쌓은걸 거꾸로 꺼내준다
    cout << Stack.top() << " ";
    Stack.pop();
  }
}
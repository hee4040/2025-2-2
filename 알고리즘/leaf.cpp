/*
#include <iostream>
using namespace std;

struct node{
  int key;
  struct node *left, *right;
};

struct node *newNode(int item){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp -> key = item;
  temp -> left = temp -> right = NULL;
  return temp;
};

struct node *insert(struct node *node, int key){
  if (node == NULL) return newNode(key);

  if(key < node -> key)
};

void findPath(struct node *node, vector<int>& path){
  int sum[//리프 노드 개수];
  int sum_all=0;
  if (node == NULL) return;

  path.push_back(node -> key);

  if (node->left == NULL && node->right == NULL) {
    for (int n=0; n < //리프 노드 개수; n++){
      for (int i = 0; i < path.size(); i++) {
        sum = path[i] * 10^i;  // 대충 아런 느낌이다
      }
    }
    sum_all+=sum[n];
  }

  else {
    findPath(node->left, path);
    findPath(node->right, path);
  }

  path.pop_back();

  return sum_all;
}

int main() {
	int size;
	cin >> size;
	
	int *input = new int[size];
	for (int idx = 0; idx < size; idx++) {
		cin >> input[idx];
	}
	
  vector<int> path;
	int total = findPath(root, path);

  cout << total << endl;

  delete[] input;
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <cmath> // pow 사용
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// 새 노드 생성
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};

// BST 삽입 (입력값을 트리에 넣는 용도)
struct node *insert(struct node *node, int key) {
  struct node *new_node = newNode(key);
  if (node == NULL) return newNode(key);

  if (key < node->key)
      node->left = insert(node->left, key);
  else
      node->right = insert(node->right, key);

  return node;
};

// 루트 → 리프 경로의 숫자 합 구하기
int findPath(struct node *node, vector<int> &path) {
    if (node == NULL) return 0;

    path.push_back(node->key);

    int sum_all = 0;

    // 리프 노드일 때
    if (node->left == NULL && node->right == NULL) {
        int num = 0;
        // path의 각 노드를 숫자로 합치기
        for (int i = 0; i < path.size(); i++) {
            num = num * 10 + path[i];
        }
        sum_all += num;
    } 
    else {
        // 왼쪽과 오른쪽 탐색
        sum_all += findPath(node->left, path);
        sum_all += findPath(node->right, path);
    }

    path.pop_back(); // 백트래킹
    return sum_all;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int idx = 0; idx < size; idx++) {
        cin >> input[idx];
    }

    // 트리 구성
    struct node *root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert(root, input[i]);
    }

    vector<int> path;
    int total = findPath(root, path);

    cout << total << endl;

    delete[] input;
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <queue>
//#include <cmath>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// 새 노드 생성
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};

// ⚙️ 완전 이진 트리 방식의 삽입 (왼쪽부터 빈 자리 채우기)
struct node *insert(struct node *root, int key) {
    struct node *new_node = newNode(key);

    if (root == NULL)
        return new_node;  // 첫 노드는 루트

    queue<struct node *> q;
    q.push(root);

    while (!q.empty()) {
        struct node *temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new_node;
            break;
        } else if (temp->right == NULL) {
            temp->right = new_node;
            break;
        } else {
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    return root;
}

// DFS로 루트→리프 경로 숫자 합 구하기
int findPath(struct node *node, vector<int> &path) {
    if (node == NULL) return 0;

    path.push_back(node->key);

    int sum_all = 0;

    if (node->left == NULL && node->right == NULL) {
        int num = 0;
        for (int i = 0; i < path.size(); i++) {
            num = num * 10 + path[i];
        }
        sum_all += num;
    } else {
        sum_all += findPath(node->left, path);
        sum_all += findPath(node->right, path);
    }

    path.pop_back();
    return sum_all;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int idx = 0; idx < size; idx++) {
        cin >> input[idx];
    }

    struct node *root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert(root, input[i]); // 🔹 순서대로 왼쪽부터 삽입
    }

    vector<int> path;
    int total = findPath(root, path);

    cout << total << endl;

    delete[] input;
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->key = val;
    temp->left = temp->right = nullptr;
    return temp;
}

// 완전 이진 트리 삽입 (BFS)
Node* insert(Node* root, int val) {
    Node* new_node = newNode(val);
    if (root == nullptr) return new_node;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();

        if (cur->left == nullptr) {
            cur->left = new_node;
            break;
        } else if (cur->right == nullptr) {
            cur->right = new_node;
            break;
        } else {
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return root;
}

// DFS로 루트→리프 경로 문자열 만들기
long long findPath(Node* node, string path) {
    if (node == nullptr) return 0;

    path += to_string(node->key); // 문자로 이어붙이기

    if (node->left == nullptr && node->right == nullptr) {
        // 리프 도달 → 문자열 그대로 숫자로 변환
        return stoll(path);
    }

    long long sum = 0;
    sum += findPath(node->left, path);
    sum += findPath(node->right, path);
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, vals[i]);
    }

    cout << findPath(root, "") << "\n";
    return 0;
}

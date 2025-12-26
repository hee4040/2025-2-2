/*
#include <iostream>
#include <vector>
using namespace std;

void sort() {
  // 길이 구해서 배열에 넣기
  // 배열을 정렬(algorithm라이브러리 사용해서)
  // 거기서 k번째 뽑기
  // 만약에 거리가 같은게 존재하면 같은걸 x좌표가 큰 순서대로 y좌표가 큰 순서대로 배열
  // 좌표가 리턴
};

int main() {
	int n;
	cin >> n;
	
	int k;
	cin >> k;

	vector<pair<int,int>> pts(n);

	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		pts[i] = {x, y};
	}
  
  // 함수에서 좌표가 리턴
  sort();
  
	return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> pts;  // 전역으로 선언
int k;                      // 전역으로 선언

long long dist(const pair<int,int>& p) {
    return p.first * p.first + p.second * p.second;
}

bool compare(const pair<int,int>& a, const pair<int,int>& b){
  long long da = dist(a);
  long long db = dist(b);

  if (da != db) return da > db;       // 거리 큰 순
  if (a.first != b.first) return a.first > b.first; // x 큰 순
  return a.second > b.second;         // y 큰 순
}

pair<int,int> sort() {
    sort(pts.begin(), pts.end(), compare);
    return pts[k-1]; // k번째 점 리턴
}

int main() {
    int n;
    cin >> n;
    
    cin >> k;
    pts.resize(n);

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }
  
    // 함수에서 좌표가 리턴
    pair<int,int> m = sort();
    cout << m.first << " " << m.second << "\n";
  
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dist(const pair<int,int>& p) {
    return 1LL * p.first * p.first + 1LL * p.second * p.second;
}

// compare 함수 (정렬 기준)
bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    long long da = dist(a);
    long long db = dist(b);

    if (da != db) return da > db;              // 거리 큰 순
    if (a.first != b.first) return a.first > b.first; // x 큰 순
    return a.second > b.second;                // y 큰 순
}

// main에서 pts, k를 받아오는 함수
pair<int,int> sort(vector<pair<int,int>>& pts, int k) {
    sort(pts.begin(), pts.end(), compare);
    return pts[k-1]; // k번째 점 리턴
}

int main() {
    int n;
    cin >> n;
    
    int k;
    cin >> k;

    vector<pair<int,int>> pts(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    // 함수에서 좌표가 리턴
    pair<int,int> ans = sort(pts, k);
    cout << ans.first << " " << ans.second << "\n";

    return 0;
}

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>   // 실행 시간 측정용
using namespace std;

// 전역 변수를 활용한 입출력 최적화
// main 함수가 실행되기 전에 호출됩니다.
int init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

long long dist(const pair<int,int>& p) {
    return 1LL * p.first * p.first + 1LL * p.second * p.second;
}

// compare 함수 (정렬 기준)
bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    long long da = dist(a);
    long long db = dist(b);

    if (da != db) return da > db;              // 거리 큰 순
    if (a.first != b.first) return a.first > b.first; // x 큰 순
    return a.second > b.second;                // y 큰 순
}

// main에서 pts, k를 받아오는 함수
pair<int,int> mySort(vector<pair<int,int>>& pts, int k) {
    sort(pts.begin(), pts.end(), compare);
    return pts[k-1]; // k번째 점 리턴
}

int main() {
    int n;
    cin >> n;
    
    int k;
    cin >> k;

    vector<pair<int,int>> pts(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    // 시간 측정 시작
    auto start = chrono::high_resolution_clock::now();

    // 함수에서 좌표가 리턴
    pair<int,int> ans = mySort(pts, k);

    // 시간 측정 끝
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << ans.first << " " << ans.second << "\n";
    cout << "실행 시간: " << elapsed.count() << "초\n";

    return 0;
}

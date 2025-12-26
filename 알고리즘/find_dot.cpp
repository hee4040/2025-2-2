/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void partition(vector<int> arr, int l, int r, int x){
  int i;
  for(i=l; i<r; i++)
    if(arr[i]==x)
      break;
  swap(&arr[i], &arr[r]);

  i=l;
  for(int j=l; j<=r-1; j++)
  {
    if(arr[j]<=x)
    {
      swap(&arr[i], &arr[j]);
        i++;
    }
  }
  swap(&arr[i], &arr[r]);
  return i;
  // 길이 구하는 식
  // 길이를 vector든 배열에 넣어줌 
  // 정렬(pivot)으로
  // 거기서 k번째를 뽑아낸다
};

void select(int arr[], int l, int r, int k){
  if(k>=0 && k < r - 1 + 1){
    int n = r-l+1;
    int pivot = arr[l+rand()%n];
    int pos = partition(arr, l, r, pivot);

    if(pos-1==k)
      return arr[pos];
    if(pos-1>k)
      return select(arr, l, pos-1, k);
    else
      return select(arr, pos+1, r, k-pos+1-1);
  }
}

int main() {
	int n;
	cin >> n;
	
	int k;
	cin >> k;

	vector<pair<int,int>> pts(n);
  vector<int> arr(n);

	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		pts[i] = {x, y};
	}

  // 거리 계산해서 arr에 채워주기
  for (int i = 0; i < n; i++) {
      int x = pts[i].first;
      int y = pts[i].second;
      arr[i] = x * x + y * y; // 원점까지 거리 제곱
  }

  select(arr, 0, n-1, n);
  cout << pts[pos] << endl;

	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// arr: 거리 배열, pts: 좌표 배열
int partition(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int x) {
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            swap(pts[i], pts[j]); // 좌표도 같이 swap
            i++;
        }
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);
    return i;
}

pair<int,int> selectK(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int k) {
    if (k >= 0 && k < r - l + 1) {
        int n = r - l + 1;
        int pivot = arr[l + rand() % n];
        int pos = partition(arr, pts, l, r, pivot);

        if (pos == l + k) // k번째 원소 찾음
            return pts[pos];
        if (pos > l + k)
            return selectK(arr, pts, l, pos - 1, k);
        else
            return selectK(arr, pts, pos + 1, r, k - (pos - l + 1));
    }
    return {-1, -1}; // out of range
}

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<pair<int, int>> pts(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
        arr[i] = x * x + y * y; // 원점까지 거리 제곱
    }

    pair<int,int> kthPoint = selectK(arr, pts, 0, n - 1, k - 1); // k번째 (1-indexed → 0-indexed)
    cout << kthPoint.first << " " << kthPoint.second << endl;

    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int partition(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int x, int pivotX) {
    int i;
    for (i = l; i < r; i++){
        if (arr[i] == x && pts[i].first == pivotX) // pivot 찾기
            break;
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] < x || (arr[j] == x && pts[j].first > pivotX)) {
            swap(arr[i], arr[j]);
            swap(pts[i], pts[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);
    return i;
}

pair<int,int> selectK(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int k) {
    if (k >= 0 && k < r - l + 1) {
        int n = r - l + 1;
        int pivotIdx = l + rand() % n;
        int pivot = arr[pivotIdx];
        int pivotX = pts[pivotIdx].first;

        int pos = partition(arr, pts, l, r, pivot, pivotX);

        if (pos == l + k) // k번째 원소 찾음
          if (arr[pos] != 1){
          
          }
            return pts[pos];
        if (pos > l + k)
            return selectK(arr, pts, l, pos - 1, k);
        else
            return selectK(arr, pts, pos + 1, r, k - (pos - l + 1));
    }
    return {-1, -1}; // out of range
}

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<pair<int, int>> pts(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
        arr[i] = x * x + y * y; // 원점까지 거리 제곱
    }

    pair<int,int> kthPoint = selectK(arr, pts, 0, n - 1, k - 1); // k번째 (1-indexed → 0-indexed)
    cout << kthPoint.first << " " << kthPoint.second << endl;

    return 0;
}
*/

/*  중복된거 내에서 k번째를 찾아버림
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// 배열 partition
int partition(int arr[], int l, int r, int x) {
    int i;
    for (i = l; i < r; i++) {
        if (arr[i] == x) break;
    }
    swap(arr[i], arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

// k번째 거리값 찾기 (0-indexed)
int selectKthDist(int arr[], int l, int r, int k) {
    if (k >= 0 && k <= r - l) {
        int n = r - l + 1;
        int pivot = arr[l + rand() % n];
        int pos = partition(arr, l, r, pivot);

        if (pos == l + k) return arr[pos];
        if (pos > l + k) return selectKthDist(arr, l, pos - 1, k);
        else return selectKthDist(arr, pos + 1, r, k - (pos - l + 1));
    }
    return -1; // out of range
}

// tie-break 규칙 적용해서 점 선택
pair<int,int> choosePoint(vector<pair<int,int>>& pts, int dist) {
    pair<int,int> best = {-1000000000, -1000000000}; // 아주 작은 초기값
    for (auto &p : pts) {
        int d = p.first * p.first + p.second * p.second;
        if (d == dist) {
            // 더 좋은 후보면 갱신
            if (p.first > best.first || (p.first == best.first && p.second > best.second)) {
                best = p;
            }
        }
    }
    return best;
}

int main() {
    int n; cin >> n;
    int k; cin >> k;

    vector<pair<int,int>> pts(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y};
        arr[i] = x * x + y * y;
    }

    // 배열로 넘겨야 하므로 pointer 사용
    int kthDist = selectKthDist(arr.data(), 0, n - 1, k - 1);
    pair<int,int> ans = choosePoint(pts, kthDist);

    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
*/

/* 같은 거리 일때는 구현 but 작은거리를 고르게 됨
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int partition(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int x, int pivotX) {
    int i;
    for (i = l; i < r; i++){
        if (arr[i] == x && pts[i].first == pivotX) // pivot 찾기
            break;
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] < x || (arr[j] == x && pts[j].first > pivotX)) {
            swap(arr[i], arr[j]);
            swap(pts[i], pts[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);
    return i;
}

// 같은 거리인 점들 중 정렬 후 반환
pair<int,int> chooseFromSameDist(vector<pair<int,int>>& pts, vector<int>& arr, int dist, int k) {
    // dist보다 작은 거리 개수 세기
    int cntLess = 0;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] > dist) cntLess++;
    }

    // dist와 같은 점들 모으기
    vector<pair<int,int>> same;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] == dist) same.push_back(pts[i]);
    }

    // x 내림차순, y 내림차순 정렬
    sort(same.begin(), same.end(), [](auto &a, auto &b){
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });

    // 그룹 안에서의 인덱스 = (전체 k - 더 작은 원소 개수) - 1
    int idxInSame = k - cntLess - 1;
    return same[idxInSame];
}


pair<int,int> selectK(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int k) {
    if (k >= 0 && k < r - l + 1) {
        int n = r - l + 1;
        int pivotIdx = l + rand() % n;
        int pivot = arr[pivotIdx];
        int pivotX = pts[pivotIdx].first;

        int pos = partition(arr, pts, l, r, pivot, pivotX);

        if (pos == l + k) { // k번째 원소 찾음
          if (arr[pos] != 1){
            int dist = arr[pos];
            return chooseFromSameDist(pts, arr, dist, k+1);
          }
          else return pts[pos];
        }
        if (pos > l + k)
            return selectK(arr, pts, l, pos - 1, k);
        else
            return selectK(arr, pts, pos + 1, r, k - (pos - l + 1));
    }
    return {-1, -1}; // out of range
}

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<pair<int, int>> pts(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
        arr[i] = x * x + y * y; // 원점까지 거리 제곱
    }

    pair<int,int> kthPoint = selectK(arr, pts, 0, n - 1, k - 1);
    cout << kthPoint.first << " " << kthPoint.second << endl;

    return 0;
}
*/

/* O(n)은 보장 안되지만 답은 나옴
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// partition: pivot보다 "큰 거리"(먼 점)을 왼쪽으로 보내기
int partition(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int x, int pivotX) {
    int i;
    for (i = l; i < r; i++) {
        if (arr[i] == x && pts[i].first == pivotX) // pivot 찾기
            break;
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] > x || (arr[j] == x && pts[j].first > pivotX)) { // ★ 부등호 방향 바뀜
            swap(arr[i], arr[j]);
            swap(pts[i], pts[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);
    return i;
}

// 같은 거리인 점들 중 정렬 후 반환
pair<int,int> chooseFromSameDist(vector<pair<int,int>>& pts, vector<int>& arr, int dist, int k) {
    // dist보다 "큰" 거리 개수 세기 (먼 점이 먼저 나오니까)
    int cntGreater = 0;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] > dist) cntGreater++;
    }

    // dist와 같은 점들 모으기
    vector<pair<int,int>> same;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] == dist) same.push_back(pts[i]);
    }

    // x 내림차순, y 내림차순 정렬
    sort(same.begin(), same.end(), [](auto &a, auto &b){
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });

    // 그룹 안에서의 인덱스 = (전체 k - 더 큰 원소 개수) - 1
    int idxInSame = k - cntGreater -1;
    return same[idxInSame];
}

pair<int,int> selectK(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int k, int k1) {
    if (k >= 0 && k < r - l + 1) {
        int n = r - l + 1;
        int pivotIdx = l + rand() % n;
        int pivot = arr[pivotIdx];
        int pivotX = pts[pivotIdx].first;

        int pos = partition(arr, pts, l, r, pivot, pivotX);

        if (pos == l + k) { // k번째 원소 찾음
            int dist = arr[pos];
            return chooseFromSameDist(pts, arr, dist, k1);
        }
        if (pos > l + k)
            return selectK(arr, pts, l, pos - 1, k, k1);
        else
            return selectK(arr, pts, pos + 1, r, k - (pos - l + 1), k1);
    }
    return {-1, -1}; // out of range
}

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<pair<int, int>> pts(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
        arr[i] = x * x + y * y; // 원점까지 거리 제곱
    }

    pair<int,int> kthPoint = selectK(arr, pts, 0, n - 1, k - 1, k);
    cout << kthPoint.first << " " << kthPoint.second << endl;

    return 0;
}
*/

/* main다르게 했을때 답은 나옴 미디언 그건 안씀
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// partition: pivot보다 "큰 거리"(먼 점)을 왼쪽으로 보내기
int partition(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int x, int pivotX) {
    int i;
    for (i = l; i < r; i++) {
        if (arr[i] == x && pts[i].first == pivotX) break; // pivot 찾기
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] > x || (arr[j] == x && pts[j].first > pivotX)) {
            swap(arr[i], arr[j]);
            swap(pts[i], pts[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);
    return i;
}

// ---------------------- 같은 거리 그룹 내 Quickselect ------------------------
int partitionSame(vector<pair<int,int>>& same, int l, int r, pair<int,int> pivot) {
    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first != b.first) return a.first > b.first; // x 큰 순
        return a.second > b.second;                       // y 큰 순
    };

    int i;
    for (i = l; i < r; i++) if (same[i] == pivot) break;
    swap(same[i], same[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (cmp(same[j], pivot)) {
            swap(same[i], same[j]);
            i++;
        }
    }
    swap(same[i], same[r]);
    return i;
}

pair<int,int> quickselectSame(vector<pair<int,int>>& same, int l, int r, int k) {
    if (l <= r) {
        int pivotIdx = l + rand() % (r - l + 1);
        auto pivot = same[pivotIdx];
        int pos = partitionSame(same, l, r, pivot);

        if (pos == l + k) return same[pos];
        if (pos > l + k) return quickselectSame(same, l, pos - 1, k);
        else return quickselectSame(same, pos + 1, r, k - (pos - l + 1));
    }
    return {-1,-1};
}

// 같은 거리인 점들 중에서 k번째 반환
pair<int,int> chooseFromSameDist(vector<pair<int,int>>& pts, vector<int>& arr, int dist, int k1) {
    int cntGreater = 0;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] > dist) cntGreater++;
    }

    vector<pair<int,int>> same;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] == dist) same.push_back(pts[i]);
    }

    int idxInSame = (k1 - cntGreater) - 1; // 그룹 내 index
    return quickselectSame(same, 0, (int)same.size() - 1, idxInSame);
}
// -------------------------------------------------------------------------------

pair<int,int> selectK(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int k, int k1) {
    if (k >= 0 && k < r - l + 1) {
        int n = r - l + 1;
        int pivotIdx = l + rand() % n;
        int pivot = arr[pivotIdx];
        int pivotX = pts[pivotIdx].first;

        int pos = partition(arr, pts, l, r, pivot, pivotX);

        if (pos == l + k) {
            int dist = arr[pos];
            return chooseFromSameDist(pts, arr, dist, k1);
        }
        if (pos > l + k)
            return selectK(arr, pts, l, pos - 1, k, k1);
        else
            return selectK(arr, pts, pos + 1, r, k - (pos - l + 1), k1);
    }
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int k; cin >> k;

    vector<pair<int,int>> pts(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y};
        arr[i] = x * x + y * y;
    }

    auto ans = selectK(arr, pts, 0, n - 1, k - 1, k);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
*/

/* main같게 하지만 빅오는 다름 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// partition: pivot보다 "큰 거리"(먼 점)을 왼쪽으로 보내기
int partition(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int x, int pivotX) {
    int i;
    for (i = l; i < r; i++) {
        if (arr[i] == x && pts[i].first == pivotX) break; // pivot 찾기
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] > x || (arr[j] == x && pts[j].first > pivotX)) {
            swap(arr[i], arr[j]);
            swap(pts[i], pts[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);
    return i;
}

// ---------------------- 같은 거리 그룹 내 Quickselect ------------------------
int partitionSame(vector<pair<int,int>>& same, int l, int r, pair<int,int> pivot) {
    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first != b.first) return a.first > b.first; // x 큰 순
        return a.second > b.second;                       // y 큰 순
    };

    int i;
    for (i = l; i < r; i++) if (same[i] == pivot) break;
    swap(same[i], same[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (cmp(same[j], pivot)) {
            swap(same[i], same[j]);
            i++;
        }
    }
    swap(same[i], same[r]);
    return i;
}

pair<int,int> quickselectSame(vector<pair<int,int>>& same, int l, int r, int k) {
    if (l <= r) {
        int pivotIdx = l + rand() % (r - l + 1);
        auto pivot = same[pivotIdx];
        int pos = partitionSame(same, l, r, pivot);

        if (pos == l + k) return same[pos];
        if (pos > l + k) return quickselectSame(same, l, pos - 1, k);
        else return quickselectSame(same, pos + 1, r, k - (pos - l + 1));
    }
    return {-1,-1};
}

// 같은 거리인 점들 중에서 k번째 반환
pair<int,int> chooseFromSameDist(vector<pair<int,int>>& pts, vector<int>& arr, int dist, int k1) {
    int cntGreater = 0;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] > dist) cntGreater++;
    }

    vector<pair<int,int>> same;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] == dist) same.push_back(pts[i]);
    }

    int idxInSame = (k1 - cntGreater) - 1; // 그룹 내 index
    return quickselectSame(same, 0, (int)same.size() - 1, idxInSame);
}
// -------------------------------------------------------------------------------

pair<int,int> selectK(vector<pair<int,int>>& pts, int k) {
    int n = pts.size();
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x = pts[i].first;
        int y = pts[i].second;
        arr[i] = x * x + y * y;
    }

    function<pair<int,int>(int,int,int,int)> solve = [&](int l, int r, int k0, int k1) -> pair<int,int> {
        if (k0 >= 0 && k0 < r - l + 1) {
            int n = r - l + 1;
            int pivotIdx = l + rand() % n;
            int pivot = arr[pivotIdx];
            int pivotX = pts[pivotIdx].first;

            int pos = partition(arr, pts, l, r, pivot, pivotX);

            if (pos == l + k0) {
                int dist = arr[pos];
                return chooseFromSameDist(pts, arr, dist, k1);
            }
            if (pos > l + k0)
                return solve(l, pos - 1, k0, k1);
            else
                return solve(pos + 1, r, k0 - (pos - l + 1), k1);
        }
        return {-1,-1};
    };

    return solve(0, n - 1, k - 1, k);
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

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

    auto ans = selectK(pts, k);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// ---------------------- partition ----------------------
int partition(vector<int>& arr, vector<pair<int,int>>& pts, int l, int r, int x, int pivotX) {
    int i;
    for (i = l; i < r; i++) {
        if (arr[i] == x && pts[i].first == pivotX) break; // pivot 찾기
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] > x || (arr[j] == x && pts[j].first > pivotX)) {
            swap(arr[i], arr[j]);
            swap(pts[i], pts[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    swap(pts[i], pts[r]);
    return i;
}

// ---------------------- median of medians ----------------------
int medianOfMedians(vector<int>& arr, int l, int r) {
    int n = r - l + 1;
    if (n <= 5) {
        vector<int> tmp;
        for (int i = l; i <= r; i++) tmp.push_back(arr[i]);
        sort(tmp.begin(), tmp.end(), greater<int>()); // 큰 값 기준
        return tmp[tmp.size() / 2];
    }

    vector<int> medians;
    for (int i = l; i <= r; i += 5) {
        int subR = min(i + 4, r);
        vector<int> group;
        for (int j = i; j <= subR; j++) group.push_back(arr[j]);
        sort(group.begin(), group.end(), greater<int>());
        medians.push_back(group[group.size() / 2]);
    }

    return medianOfMedians(medians, 0, (int)medians.size() - 1);
}


// ---------------------- 같은 거리 그룹 내 Quickselect ------------------------
int partitionSame(vector<pair<int,int>>& same, int l, int r, pair<int,int> pivot) {
    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first != b.first) return a.first > b.first; // x 큰 순
        return a.second > b.second;                       // y 큰 순
    };

    int i;
    for (i = l; i < r; i++) if (same[i] == pivot) break;
    swap(same[i], same[r]);

    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (cmp(same[j], pivot)) {
            swap(same[i], same[j]);
            i++;
        }
    }
    swap(same[i], same[r]);
    return i;
}

pair<int,int> quickselectSame(vector<pair<int,int>>& same, int l, int r, int k) {
    if (l <= r) {
        int pivotIdx = l + rand() % (r - l + 1);
        auto pivot = same[pivotIdx];
        int pos = partitionSame(same, l, r, pivot);

        if (pos == l + k) return same[pos];
        if (pos > l + k) return quickselectSame(same, l, pos - 1, k);
        else return quickselectSame(same, pos + 1, r, k - (pos - l + 1));
    }
    return {-1,-1};
}

// 같은 거리인 점들 중에서 k번째 반환
pair<int,int> chooseFromSameDist(vector<pair<int,int>>& pts, vector<int>& arr, int dist, int k1) {
    int cntGreater = 0;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] > dist) cntGreater++;
    }

    vector<pair<int,int>> same;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (arr[i] == dist) same.push_back(pts[i]);
    }

    int idxInSame = (k1 - cntGreater) - 1; // 그룹 내 index
    return quickselectSame(same, 0, (int)same.size() - 1, idxInSame);
}
// -------------------------------------------------------------------------------

pair<int,int> selectK(vector<pair<int,int>>& pts, int k) {
    int n = pts.size();
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int x = pts[i].first;
        int y = pts[i].second;
        arr[i] = x * x + y * y;
    }

    function<pair<int,int>(int,int,int,int)> solve = [&](int l, int r, int k0, int k1) -> pair<int,int> {
        if (k0 >= 0 && k0 < r - l + 1) {
            int pivot = medianOfMedians(arr, l, r);
            int pivotX = 0; // tie-break는 arr만 쓰므로 무시 가능

            int pos = partition(arr, pts, l, r, pivot, pivotX);

            if (pos == l + k0) {
                int dist = arr[pos];
                return chooseFromSameDist(pts, arr, dist, k1);
            }
            if (pos > l + k0)
                return solve(l, pos - 1, k0, k1);
            else
                return solve(pos + 1, r, k0 - (pos - l + 1), k1);
        }
        return {-1,-1};
    };

    return solve(0, n - 1, k - 1, k);
}

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

    auto ans = selectK(pts, k);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}

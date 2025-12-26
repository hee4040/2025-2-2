
// #include <iostream>
// using namespace std;

// /*header call here*/
// // #include <>

// /*global variable declare here*/


// /*function declare here*/
// void function(int s, int &input[]){
//   int n=1;
//   int k=1;
//   while (k<s){
//     int cross[4];
//     int same_max;
//     cross=[k-3, k, k+1, k+2];
//     for(int i : input){
//       for(int j : cross){
//         if(i==j){
//           int same[]+=i;
//           same_max = same.max();
//           k = same_max - n;
//         }
//         else
//           return n;
//       }
//     }
//     n=same_max;
//   }
// }

// /*
// 1. k만큼 움직이면 다음은 [k-3, k, k+1, k+2]로 이동 가능 
// 2. 위의 배열안과 실제 돌덩어리 개수 배열을 비교하여 위의 배열에서 큰것중에 겹치는거 출력
// 3. 위의 배열 중에 0,1,2가 k로 덮임
// 4. 반복
// */

// int main() {
// 	int size;
// 	cin >> size;
	
// 	int *input = new int[size];
// 	for (int idx = 0; idx < size; idx++) {
// 		cin >> input[idx];
// 	}
	
//   /*local variable declare here*/


//   /*function call here*/
// 	function(size,input);

//   delete[] input;
// 	return 0;
// }

/*점프 간격 구하고 젤 큰 거 찾아서 다음 구하기*/
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// /*header call here*/
// // #include <>

// /*global variable declare here*/


// /*function declare here*/
// void location(int s, int input[]) {
//     int n = 1;
//     int k = 1;

//     while (true) {
//         vector<int> cross = {k - 3, k, k + 1, k + 2};
//         vector<int> same;

//         // cross와 input의 공통 원소를 찾음
//         for (int i = 0; i < s; i++) {
//             for (int j : cross) {
//                 if (input[i] == j + n) {
//                     same.push_back(input[i]);
//                 }
//             }
//         }

//         for (auto it = same.begin(); it != same.end(); ) {
//             if (*it <= n) {
//                 it = same.erase(it);  // 지우고 다음 원소 iterator 반환
//             } else {
//                 ++it;
//             }
//         }


//         if (same.empty()) {
//             cout << n << endl;
//             return;
//         }

//         int same_max = *max_element(same.begin(), same.end());

//         // 이전 상태와 동일하면 (더 이상 변화 없음)
//         if (k == 0) {
//             cout << n << endl;
//             return;
//         }

//         k = same_max - n;
//         n = same_max;
//     }
// }

// /*
// 1. k만큼 움직이면 다음은 [k-3, k, k+1, k+2]로 이동 가능 
// 2. 위의 배열안과 실제 돌덩어리 개수 배열을 비교하여 위의 배열에서 큰것중에 겹치는거 출력
// 3. 위의 배열 중에 0,1,2가 k로 덮임
// 4. 반복
// */

// int main() {
//     int size;
//     cin >> size;
    
//     int *input = new int[size];
//     for (int idx = 0; idx < size; idx++) {
//         cin >> input[idx];
//     }
    
//     /*local variable declare here*/


//     /*function call here*/
//     location(size, input);

//     delete[] input;
//     return 0;
// }


/* 내가 짠 초안*/
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void location(int s, vector<int> &input){
//   int v = 1;
//   int past_i;
//   int d={};

//   for (int i : input){
//     if(i==0) return 0;
//     else if (i==1) d[1] = {-3, 1, 2, 3};
//     else{
//       for (int j : d[past_i]){
//         d[i].insert(j-3,j,j+1,j+2);
//       }
//     }
//     past_i = i;
//   }
// }

// int main() {
//     int size;
//     cin >> size;
    
//     int *input = new int[size];
//     for (int idx = 0; idx < size; idx++) {
//         cin >> input[idx];
//     }
    
//     /*local variable declare here*/

//     /*function call here*/
//     location(size, input);

//     delete[] input;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int location(int s, vector<int>& input) {

    // 돌 좌표들을 빠르게 찾기 위해 set 사용
    unordered_set<int> exists(input.begin(), input.end());

    // dp[x] = x에 도달했을 때 가능한 jump 거리들의 집합
    unordered_map<int, unordered_set<int>> d;

    // 첫 점프는 반드시 거리 1
    if (!exists.count(1)) return 0;
    d[1].insert(1);

    int answer = 1;

    int past_i = 1; // 첫 점프 결정 이후 시작

    for (int i : input) {

        // 시작점(0)은 건너뜀
        if (i == 0) continue;

        // dp에 기록된 jump 거리들이 있을 때
        if (!d[i].empty()) {

            for (int k : d[i]) {

                // k 기준 다음 jump 후보
                vector<int> nextK = {k - 3, k, k + 1, k + 2};

                for (int nk : nextK) {
                    if (nk <= 0) continue;

                    int nextPos = i + nk;

                    if (exists.count(nextPos)) {
                        d[nextPos].insert(nk);
                        answer = max(answer, nextPos);
                    }
                }
            }
        }
    }

    return answer;
}


/*
1. jump 거리는 {k-3, k, k+1, k+2}
2. dp[x] = x 좌표에 도달했을 때 가능한 jump 거리들
3. 첫 점프는 0→1 거리 1
4. dp를 이용해 다음 점프 가능 좌표를 기록
5. 가장 멀리 도달한 좌표 answer 반환
*/

int main() {
    int size;
    cin >> size;

    vector<int> input(size);
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    cout << location(size, input) << endl;

    return 0;
}

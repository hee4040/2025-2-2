#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* hearder call here */
// #include <>

/* function declare here */
// int health(int m, vector<vector<int>> d){
//   int i=0, j=0, k;
//   int dist[m][m];
//   while(i<m && j <m){
//     for(int k=0; k<m*m; k++){
//       for(i=0; i<m; i++){
//         for(j=0; j<m; j++){
//           if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j]=dist[i][k] + dist[k][j];
//         }
//       }
//     }
//   }
//   return dist[m][m];
// };

// int health(int m, vector<vector<int>> d){
//   int i=0, j=0, k,a;
//   int dist[][m];
//   for(k=0; k<m+m-2; k++){
//     for(a=0, a<m*m; a++){
//       dist[k+1][a]=min(dist[k][a], dist[k][a]+d[k])
//     }
//   }
// };

int health(int m, vector<vector<int>> &d) {

    vector<vector<int>> dp(m, vector<int>(m, 1e9));   // 초기값 무한대로 설정, dp는 필요한 hp 저장

    dp[m-1][m-1] = max(1, 1 - d[m-1][m-1]);  // 도착점 처리(오른쪽 아래에서 왼쪽 위로), 체력이 1보다 작아지면 안됨

    for (int i = m-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {

            if (i == m-1 && j == m-1) continue;  // 이미 처리

            int need = 1e9;    // 처음 필요한 체력 크게 잡기

            if (i + 1 < m)
                need = min(need, dp[i+1][j]);

            if (j + 1 < m)
                need = min(need, dp[i][j+1]);

            dp[i][j] = max(1, need - d[i][j]);
        }
    }

    return dp[0][0];
}

int main(){
	int m, n;
	cin >> m >> n;

	vector<vector<int>> dungeon(m, vector<int>(n));
	for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
					cin >> dungeon[i][j];
			}
	}

  /* variable declare here */
	int result = health(m, dungeon);

  /* function call here */
	cout << result << endl;

	return 0;
}
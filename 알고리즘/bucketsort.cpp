#include<iostream>
#include <vector>
#define bucket_number 10
using namespace std;

static void bucketsort(int array[], int n, int k){
  vector<int> bucket[bucket_number];

  for(int i=0; i<n; i++){                          // 각 요소를 알맞은 버킷에 분배
    int b = array[i] / ceil (k/bucket_number);     // ceil-> 버킷이 담당할 범위 크기
    bucket[b].push_back(array[i]);
  }

  if(bucket_number<k){                             // 각 버킷 내부 정렬
    for(int i=0; i<bucket_number; i++)
      sort(bucket[i].begin(), bucket[i].end());
  }

  int m=0;
  for(int i=0; i<bucket_number; i++){              // 버킷들 순서대로 합치기
    for(int j=0; j<bucket[i].size(); j++){
      array[m] = bucket[i][j];
      m++;
    }
  }
}
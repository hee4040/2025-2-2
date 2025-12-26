#include <iostream>
using namespace std;

void mergesort(int arr[], int l, int r){      // recurse하는 과정
  if(l<r){
    int m =(l+r)/2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}

void merge(int arr[], int l, int m, int r){     // merge하는 과정
  int i, j, k=l;
  int n1 = m-l+1;
  int n2 = r-m;

  int L[n1], R[n2];
  for(i=0; i<n1; i++)    // 왼, 오 배열에 저장해준다
    L[i] = arr[l+i];
  for(j=0; j<n2; j++)
    R[j] = arr[m + 1 +j];

  while (i<n1 && j<n2)     // 왼, 오 두 배열을 비교해 작은 값을 새 배열 arr에 넣어준다
  {
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i<n1)               // 비교한 후 남은 원소들을 arr배열에 채워넣어준다
  {
    arr[k] = L[i];
    i++;
    k++;
  }  
  
  while (j<n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }  
}
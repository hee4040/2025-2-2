void countingsort(int array[], int n){
  int count[k+1];                       // 정렬할 배열에 맞춰 정해주는 값
  for(int i=0; i<k+1; i++)              // count배열 0으로 초기화
    count[i] = 0;

  for(int i=0; i<n; i++)                // array배열에 들어있는 값의 count배열 자리의 크기를 증가
    count[array[i]]++;

  for(int i=0, j=0; i<=k; i++){         // count배열이 0이 아닌 경우 앞에서부터 그 위치를 array배열에 추가
    while(count[i]>0){
      array[j] = i;
      j++;
      count[i]--;
    }
  }
}
void quicksort(int array[], int l, int r){
  if(l < r){
    int pivot = array[r];
    int pos = partition(array, l, r, pivot);

    quicksort(array, l, pos-1);
    quicksort(array, pos+1, r);
  }
}

int partition(int arr[], int l, int r, int x){
  int i;
  for(i=l; i<r; i++)
    if(arr[i] == x)
      break;                    // pivot의 실제 위치 기억
  swap(&arr[i], &arr[r]);       // pivot을 끝으로 옮겨준다

  i=l;
  for(int j=l; j<=r-1; j++){
    if(arr[j] <= x){            // pivot보다 작거나 같은 원소를 i왼쪽으로 옮겨준다
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[r]);      // pivot을 i의 자리에 놓는다
  return i;
}
/*
#include <iostream>
using namespace std;

void sort(int arr[], int size){
  if (size <= 1) return; // 기저 조건

  int mid = size / 2 + size % 2;
  int left[mid];         // 왼쪽 절반
  int right[size - mid]; // 오른쪽 절반
  int result[size];      // 병합 결과

  // arr -> left 복사
  for (int i = 0; i < mid; i++) {
    left[i] = arr[i];
  }
  // arr -> right 복사
  for (int i = mid; i < size; i++) {
    right[i - mid] = arr[i];
  }

  // 재귀 호출
  sort(left, mid);
  sort(right, size - mid);

  // 병합 과정
  int n = 0, m = 0, k = 0;
  while (n < mid && m < size - mid) {
    if (left[n] > right[m]) {
      result[k] = right[m];
      k++;
      m++;
    } else {
      result[k] = left[n];
      k++;
      n++;
    }
  }
  while (n < mid) {
    result[k] = left[n];
    k++;
    n++;
  }
  while (m < size - mid) {
    result[k] = right[m];
    k++;
    m++;
  }

  // result -> arr 복사
  for (int i = 0; i < size; i++) {
    arr[i] = result[i];
  }

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){
  int size;
  cin >> size;

  int * input = new int[size];
  for (int idx = 0; idx < size; idx++){
    cin >> input[idx];
  }

  sort(input, size);

  delete[] input;
  return 0;
}
*/

#include <iostream>
using namespace std;

void sort(int arr[], int l, int r) {
    if (l >= r) return; // 기저 조건: 원소 1개면 이미 정렬됨

    int mid = (l + r) / 2;

    // 왼쪽/오른쪽 재귀
    sort(arr, l, mid);
    sort(arr, mid + 1, r);

    // 병합 과정
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
          arr[k] = left[i];
          k++;
          i++;
        }
        else {
          arr[k] = right[j];
          k++;
          j++;
        }
    }
    while (i < n1) {
      arr[k] = left[i];
      k++;
      i++;
    }
    while (j < n2) {
      arr[k] = right[j];
      k++;
      j++;
    }

    // 현재 단계 출력 (arr[l..r])
    for (int x = l; x <= r; x++) {
        cout << arr[x] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cin >> size;

    int* input = new int[size];
    for (int idx = 0; idx < size; idx++) {
        cin >> input[idx];
    }

    sort(input, 0, size - 1);

    delete[] input;
    return 0;
}


/* 제출한 머지 소트 구현한 함수
void sort(int arr[], int l, int r) {
	if (l>=r) return;

	int mid = (l + r) / 2;

	sort(arr, l, mid);
	sort(arr, mid + 1, r);
	
	int i = mid - l + 1;
	int j = r - mid;
	int left[i];
	int right[j];

	for(int n=0; n<i; n++) left[n]=arr[l + n];
	for(int m=0; m<j; m++) right[m]=arr[mid + 1 + m];

	int a=0, b=0, k=l;
	while(a<i && b<j){
		if(left[a] >= right[b]){
			arr[k]=right[b];
			k++;
			b++;
		}
		else{
			arr[k]=left[a];
			k++;
			a++;
		}
	}

	while(a<i) {
		arr[k]=left[a];
		k++;
		a++;
	}
	while(b<j) {
		arr[k]=right[b];
		k++;
		b++;
	}

	for(int k=l; k<=r; k++) cout << arr[k] << " ";
	cout << endl;
};
*/
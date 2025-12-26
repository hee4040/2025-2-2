void radixsort(int array[], int size){
  int max = getMax(array, size);                       // 최대 자릿수

  for(int place =1; max/place > 0; place *= 10)        // place는 현재 자릿수
    countingsort(array, size, place);
}

void countingsort(int array[], int size, int place){
  const int max = 10;
  int* output = new int[size];                        // 정렬 결과 임시 저장용 배열
  int* count = new int[max];                          // 각 자릿수의 등장 횟수를 저장하는 배열

  for(int i=0; i<max; ++i)                            // count[]를 0으로 초기화
    count[i] = 0;

  for(int i=0; i<size; i++){                          // 각 자릿수 빈도 세기
    key = (array[i] / place) % 10;                    // 현재 자리의 숫자만 추출
    count[key]++;
  }

  for(int i=1; i<max; i++)                            // 각 자리의 누적 위치 정보를 count에 저장해줌
    count[i] += count[i-1];                           

  for(int i=size-1; i>=0; i--){                       // output배열 채우기
    key = (array[i]/place) % 10;
    output[count[key]-1] = array[i];
    count[key]--;
  }

  for (int i = 0; i < size; i++){                     // 정렬 결과 복사
    array[i] = output[i];
  }
}
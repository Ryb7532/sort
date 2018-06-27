#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int i, j, l, pivot, z;

// 先頭の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
  for(i = j = l = 1; i < n; i++){
    if(A[i] < pivot){
      z = A[l];
      A[l] = A[j];
      A[j] = A[i];
      A[i] = z;
      j++;
      l++;
    }
    else if(A[i] == pivot){
      z = A[l];
      A[l] = A[i];
      A[i] = z;
      l++;
    }
  }

  if(j <= k+1 && l >= k+1) return pivot;
  else if(l < k+1) return quick_select(A+l, n-l, k-l);
  else if(j > k+1) return quick_select(A+1, j-1, k);
  else return 0;
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}

#include <stdio.h>

#define N 100000

int B[N];

void Ssort(int A[], int n){
  int i, j, min, z;
  for(i = 0; i < n; i++){
    min = i;
    for(j = i+1; j < n; j++){
      if(A[j] < A[min]){
        min = j;
      }
    }
    z = A[i];
    A[i] = A[min];
    A[min] = z;
  }
}

void Isort(int A[], int n){
  int i, j, k, z;
  for(i = 1; i < n; i++){
    for(j = 0; j < i && A[j] < A[i]; j++) ;
    z = A[i];
    for(k = i; k > j; k--) A[k] = A[k-1];
    A[j] = z;
  }
}

void Msort(int A[], int n){
  int i, j, k;
  if(n <= 1) return;
  Msort(A, n/2);
  Msort(A+n/2, n - n/2);
  i = j = k = 0;
  while(i < n/2 && j < n - n/2){
    if(A[i] < A[n/2 + j]) B[k++] = A[i++];
    else B[k++] = A[n/2 + j++];
  }
  while(i < n/2) B[k++] = A[i++];
  while(j < n - n/2) B[k++] = A[n/2 + j++];
  for(i=0; i < n; i++) A[i] = B[i];
}

int main(){
  int i;
  int C[N];
  C[0] = 2394837;
  for(i=1;i<N;i++) C[i] = (long long int) C[i-1] * C[0] % 1000000007;
//  for(i=0;i<N;i++) C[i] = N-i;

//  Msort(C, N);
  Ssort(C, N);
//  Isort(C, N);

  for(i=0;i<N;i++) printf("%d\n", C[i]);

  return 0;
}

#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int quick_select(int A[], int n, int k){
  int i, j, pivot;

// 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k+1) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+1, j-1, k);
}

int m_of_m(int A[], int n, int k){
if(n <=5){
return quick_select(A, n, k);
}
else{
int X[n/5];
int i, j, x, pivot;
for(i = 0; i < n/5; i++){
         X[i] = quick_select(A+5*i, 5, 2);
      }
pivot = quick_select(X, n/5, n/10);
   for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }
int B[0]; 
int C[0];
int b=0;
int c=0;
for(i = 0; i<n; i++ ){
if(A[i] <= pivot){
    B[b]=A[i];
    b++;
    }
else{
     C[c]=A[i];
     c++;
      }
}
if(b==k+1){
return pivot ;
}
else if(b<k){
return quick_select(C, c, k-b);
}
else {
return quick_select(B, b, k+1);
}
}
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}

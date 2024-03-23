#include <stdio.h>
#include <time.h>


// 시간 구하기

long long factorial_rec(long n) {               // factorial_rec함수(재귀)
    if (n <= 1)
        return 1;
    else return n * factorial_rec(n - 1);
}

long long factorial_iter(long n) {              // fact_iter 함수(반복)
    long long i, r = 1;
    for (i = 1; i <= n; i++)
        r = r * i;
    return r;
}

int main(void) {                               // 시간 구하기 
    int n = 20;
    double r_rec, r_iter;
    clock_t start_rec, end_rec, start_iter, end_iter;

    start_rec = clock();
    long long result_rec = factorial_rec(n);
    end_rec = clock();

    start_iter = clock();
    long long result_iter = factorial_iter(n);
    end_iter = clock();

    r_rec = (double)(end_rec - start_rec) / CLOCKS_PER_SEC;
    r_iter = (double)(end_iter - start_iter) / CLOCKS_PER_SEC;

    printf("rec : %lld\n", result_rec);
    printf("Time_rec : %lf\n", r_rec);
    printf("iter : %lld\n", result_iter);
    printf("Time_iter : %lf\n", r_iter);


    return 0;
}


//// 재귀 함수
//
//long long factorial_rec(long n);
//
//long long main(void) {
//	long n = 20;
//	long long total = factorial_rec(n);
//	printf("rec 결과 : %lld", total);
//	return 0;
//}
//
//long long factorial_rec(long n) {
//	
//	if (n <= 1) return 1;
//	else return (n * factorial_rec(n - 1));
//
//}
//
//// 반복 함수
//
//long long factorial_iter(long n);
//
//long long main_aa(void) {
//
//	long long n = 0;
//	long long total = factorial_iter(20);
//	printf("iter 결과 : %lld", total);
//	return 0;
//
//}
//
//long long factorial_iter(long n) {
//
//	long long i, r = 1;
//	for (i = 1; i <= n; i++)
//		r = r * i;
//	return(r);
//}
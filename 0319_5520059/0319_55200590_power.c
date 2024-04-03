#include <stdio.h>
#include <time.h>

double power_rec(double x, int n) {      // 재귀함수

	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power_rec(x * x, n / 2);
	else return x * power_rec(x * x, (n - 1) / 2);
}

double power_iter(double x, int n) {     // 반복함수       

	int i = 0;
	double r = 1.0;
	for (i = 0; i < n; i++)
		r = r * x;
	return r;
}

int main(void) {                 // 시간 측정 

	double x = 13;
	int n = 21;
	clock_t start_rec, stop_rec, start_iter, stop_iter;
	double r_rec, r_iter;

	start_rec = clock();             // 재귀함수 측정 시작
	r_rec = power_rec(x, n);         // 
	stop_rec = clock();              // 재귀함수 측정 종료

	start_iter = clock();        // 반복함수 측정 시작
	r_iter = power_iter(x, n);
	stop_iter = clock();        // 반복함수 측정 종료 

	double t_r_rec = (double)(stop_rec - start_rec) / CLOCKS_PER_SEC;           // 재귀함수 걸린 시간
	double t_r_iter = (double)(stop_iter - start_iter) / CLOCKS_PER_SEC;        // 반복함수 걸린 시간

	printf("Rec: %lf\n", r_rec);         // 13의 21제곱 출력(재귀)
	printf("Time : %lf\n", t_r_rec); ;;  // 재귀함수 걸린 시간 출력
	printf("Iter: %lf\n", r_iter);       // 13의 21제곱 출력(반복)
	printf("Time : %lf\n", t_r_iter);    // 반복함수 걸린 시간

	return 0;
}

//// 거듭제곱 재귀 함수 rec
//
//double power_rec(double x, int n);
//
//double main(void) {
//
//	double x = 13;
//	int n = 21;
//	double total = power_rec(x, n);
//	printf("%lf", total);
//}
//
//double power_rec(double x, int n) {
//
//	if (n == 0) return 1;
//	else if ((n % 2) == 0)
//		return power_rec(x * x, n / 2);
//	else return x * power_rec(x * x, (n - 1) / 2); 
//}
//
//// 거듭제곱 반복 함수 iter
//
//double power_iter(double x, int n);
//
//double main(void) {
//
//	double x = 13;
//	int n = 21;
//	double total = power_iter(x, n);
//	printf("%lf", total);
//}
//
//double power_iter(double x, int n) {
//
//	int i = 0;
//	double r = 1.0;
//	for (i = 0; i < n; i++)
//		r = r * x;
//	return r;
//}

#include <stdio.h>
#include <time.h>

double power_rec(double x, int n) {      // Àç±ÍÇÔ¼ö

	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power_rec(x * x, n / 2);
	else return x * power_rec(x * x, (n - 1) / 2);
}

double power_iter(double x, int n) {     // ¹Ýº¹ÇÔ¼ö       

	int i = 0;
	double r = 1.0;
	for (i = 0; i < n; i++)
		r = r * x;
	return r;
}

int main(void) {                 // ½Ã°£ ÃøÁ¤ 

	double x = 13;
	int n = 21;
	clock_t start_rec, stop_rec, start_iter, stop_iter;
	double r_rec, r_iter;

	start_rec = clock();
	r_rec = power_rec(x, n);
	stop_rec = clock();

	start_iter = clock();
	r_iter = power_iter(x, n);
	stop_iter = clock();

	double t_r_rec = (double)(stop_rec - start_rec) / CLOCKS_PER_SEC;
	double t_r_iter = (double)(stop_iter - start_iter) / CLOCKS_PER_SEC;

	printf("Rec: %lf\n", r_rec);
	printf("Time : %lf\n", t_r_rec);
	printf("Iter: %lf\n", r_iter);
	printf("Time : %lf\n", t_r_iter);
	return 0;
}



//// °ÅµìÁ¦°ö Àç±Í ÇÔ¼ö rec
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
//// °ÅµìÁ¦°ö ¹Ýº¹ ÇÔ¼ö iter
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
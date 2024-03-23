#include <stdio.h>
#include <time.h>

double power_rec(double x, int n) {      // ����Լ�

	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power_rec(x * x, n / 2);
	else return x * power_rec(x * x, (n - 1) / 2);
}

double power_iter(double x, int n) {     // �ݺ��Լ�       

	int i = 0;
	double r = 1.0;
	for (i = 0; i < n; i++)
		r = r * x;
	return r;
}

int main(void) {                 // �ð� ���� 

	double x = 13;
	int n = 21;
	clock_t start_rec, stop_rec, start_iter, stop_iter;
	double r_rec, r_iter;

	start_rec = clock();             // ����Լ� ���� ����
	r_rec = power_rec(x, n);         // 
	stop_rec = clock();              // ����Լ� ���� ����

	start_iter = clock();        // �ݺ��Լ� ���� ����
	r_iter = power_iter(x, n);
	stop_iter = clock();        // �ݺ��Լ� ���� ���� 

	double t_r_rec = (double)(stop_rec - start_rec) / CLOCKS_PER_SEC;           // ����Լ� �ɸ� �ð�
	double t_r_iter = (double)(stop_iter - start_iter) / CLOCKS_PER_SEC;        // �ݺ��Լ� �ɸ� �ð�

	printf("Rec: %lf\n", r_rec);         // 13�� 21���� ���(���)
	printf("Time : %lf\n", t_r_rec); ;;  // ����Լ� �ɸ� �ð� ���
	printf("Iter: %lf\n", r_iter);       // 13�� 21���� ���(�ݺ�)
	printf("Time : %lf\n", t_r_iter);    // �ݺ��Լ� �ɸ� �ð�

	return 0;
}

//// �ŵ����� ��� �Լ� rec
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
//// �ŵ����� �ݺ� �Լ� iter
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

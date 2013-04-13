#include "convex_ops.h"

double argmin(convex_function * fun, double a, double b, size_t N) {
	double x = a;
	double fx = fun->f(x);
	for (size_t i = 1; i < N; ++i) {
		double y = a + (b-a)*i/N;
		double fy = fun->f(y);
		if (fy < fx) {
			x = y;
			fx = fy;
		}
	}
	return x;
}

#include <sstream>
#include <iostream>
#include <limits>
#include <cmath>

#include "convex.h"
#include "convex_ops.h"

class quadratic : public convex_function_impl<quadratic> {
private:
	friend class convex_function_impl<quadratic>;

	double f_impl(double x) {
		return a*x*x + b*x + c;
	}

public:
	double a;
	double b;
	double c;
};

int main(int argc, char ** argv) {
	if (argc < 4) {
		std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
		return 1;
	}
	quadratic q;
	std::stringstream(argv[1]) >> q.a;
	std::stringstream(argv[2]) >> q.b;
	std::stringstream(argv[3]) >> q.c;
	double a = std::numeric_limits<double>::lowest();
	double b = std::numeric_limits<double>::max();
	while (true) {
		double fa = q.f(a);
		if (!std::isfinite(fa)) a /= 2;
		else break;
	}
	while (true) {
		double fb = q.f(b);
		if (!std::isfinite(fb)) b /= 2;
		else break;
	}
	size_t nchunks = 100000;
	double c = 0.5;
	double eps = 1e-10;
	std::cout << "Search for argmin in [" << a << ", " << b << "]\n"
		<< "nchunks = " << nchunks
		<< "  c = " << c
		<< "  eps = " << eps
#ifdef STATIC_ARGMIN
		<< "  STATIC_ARGMIN"
#else
		<< "  !STATIC_ARGMIN"
#endif
		<< "\nf(x) = " << q.a << " x^2 + " << q.b << " x + " << q.c
		<< std::endl;
	while ((b-a) > eps) {
		//std::clog << std::string(50, ' ') << "\r[" << a << ", " << b << "]";
		double windowRadius = (b-a)*c/2;
#ifdef STATIC_ARGMIN
		double x = argmin(&q, a, b, nchunks);
#else
		double x = q.argmin(a, b, nchunks);
#endif
		a = x-windowRadius;
		b = x+windowRadius;
	}
	//std::clog << std::endl;
	std::cout << "Minimum estimate is at x = "
		<< a << ", f(x) = " << q.f(a) << std::endl;
	return 0;
}

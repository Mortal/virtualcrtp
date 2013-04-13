#ifndef CONVEX_H
#define CONVEX_H

template <typename T>
class convex_function_impl;

class convex_function {
public:
	virtual double f(double x) = 0;

	virtual double argmin(double a, double b, size_t N) = 0;

	virtual double integrate(double a, double b, double delta) = 0;

private:
	template <typename T>
	friend class convex_function_impl;

	// Nobody should implement this directly;
	// derive from convex_function_impl instead.
	convex_function() {}
};

template <typename child_t>
class convex_function_impl : public convex_function {
private:
	// CRTP magic.
	child_t & self() { return *static_cast<child_t *>(this); }

public:
	virtual double f(double x) final override {
		return self().f_impl(x);
	}

	virtual double argmin(double a, double b, size_t N) final override {
		double x = a;
		double fx = self().f_impl(x);
		for (size_t i = 1; i < N; ++i) {
			double y = a + (b-a)*i/N;
			double fy = self().f_impl(y);
			if (fy < fx) {
				x = y;
				fx = fy;
			}
		}
		return x;
	}

	virtual double integrate(double a, double b, double delta) final override {
		double v = 0.0;
		size_t N = (b-a)/delta;
		for (size_t i = 0; i < N; ++i) {
			v += self().f_impl(a + (b-a)*i/delta);
		}
		return v;
	}
};

#endif // CONVEX_H

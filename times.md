Run times
=========

Configuration:

    Search for argmin in [-3.35195e+153, 3.35195e+153]
    nchunks = 100000  c = 0.5  eps = 1e-10  !STATIC_ARGMIN
    f(x) = 5 x^2 + 1000.6 x + 0.123
    Minimum estimate is at x = -100.06, f(x) = -50059.9

Using ::argmin -O0:
(0m0.892s, 0m0.894s, 0m0.895s, 0m0.898s, 0m0.902s)

Using convex_function_impl::argmin -O3:
(0m0.805s, 0m0.809s, 0m0.811s, 0m0.813s, 0m0.814s)

Using ::argmin -O1:
(0m0.741s, 0m0.742s, 0m0.744s, 0m0.744s, 0m0.747s)

Using convex_function_impl::argmin -O0:
(0m0.628s, 0m0.629s, 0m0.633s, 0m0.634s, 0m0.635s)

Using ::argmin -O3:
(0m0.566s, 0m0.567s, 0m0.570s, 0m0.571s, 0m0.571s)

Using convex_function_impl::argmin -O1:
(0m0.480s, 0m0.482s, 0m0.483s, 0m0.484s, 0m0.487s)


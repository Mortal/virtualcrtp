Test of virtual method call overhead.

Given a convex function, search for a global minimum in a brute force manner.

In one configuration, each evaluation of the convex function is a virtual
method call.

In another, only the invocation of the `argmin` algorithm is a virtual method
call, and CRTP is used to avoid virtual table lookups in the tight loop.

See `times.md` for run times.

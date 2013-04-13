CXXFLAGS ?=
CXXFLAGS += -std=c++11 -Wall -Wextra
all: a.out

clean:
	$(RM) a.out convex_ops.o main.o

a.out: convex_ops.o main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.cpp convex_ops.h convex.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@

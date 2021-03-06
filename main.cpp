
#include <cstdio>

#include "function.hpp"
#include "bind.hpp"

void test(int a, int b)
{
	printf("%d %d\n", a, b);
}

class Functor
{
public:
	void operator()(int a, int b)
	{
		printf("(%d, %d)\n", a, b);
	}
};


int main()
{
	function<void(int,int)> f(&test);
	f(9394, 2);

	Functor functor;
	function<void(int, int)> f2(functor);
	f2(2, 3);

	auto ff = bind(&test, _2, _1);
	ff(3, 6);

	system("pause");
}
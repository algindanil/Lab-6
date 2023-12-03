#include <iostream>
#include <cmath>

float rsqrt(float num)
{
    float result = 1.0 / sqrt(static_cast<double>(num));
    return result;
}

int main()
{
	for (int i = 1000; i <= 1000000; ++i)
	{
		float result = rsqrt(i);
		std::cout << "The inverse sqrt of " << i << " is " << result << std::endl;
	}

	return 0;
}

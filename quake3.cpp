#include <iostream>

float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;						// evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);			// what the fuck?
	y = *(float*)&i;
	y = y * (threehalfs - (x2*y*y));	// 1st iteration
	// y = y * (threehalfs - (x2*y*y));	// 2nd iteration, this can be removed

	return y;
}

int main()
{
	for (int i = 1000; i <= 1000000; ++i)
	{
		double result = Q_rsqrt(static_cast<double>(i));
		std::cout << "The inverse sqrt of " << i << " is " << result << std::endl;
	}

	return 0;
}

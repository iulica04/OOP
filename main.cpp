#include "Math.h"
#include<iostream>

using namespace std;

int main()
{
	printf("%d\n", Math::Add(2, 3));
	printf("%d\n", Math::Add(2, 3, 4));
	printf("%d\n", Math::Add(2.0, 3.0));
	printf("%d\n", Math::Add(2.0, 3.0, 4.0));
	printf("%d\n", Math::Mul(2, 5));
	printf("%d\n", Math::Mul(2, 5, 2));
	printf("%d\n", Math::Mul(3.0, 5.0));
	printf("%d\n", Math::Mul(3.0, 5.0, 2.0));
	printf("%d\n", Math::Add(4, 1, 2, 3, 4));


	printf("%s\n", Math::Add(nullptr, nullptr));
	printf("%s\n", Math::Add(nullptr, "nume"));
	printf("%s\n", Math::Add("nume", nullptr));
	printf("%s\n", Math::Add("nume1", "nume2"));
}
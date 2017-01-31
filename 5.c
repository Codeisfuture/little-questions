#include <stdio.h>
void main()
{
	float finalDegree,m, n;
	scanf("%f:%f", &m, &n);
	if (m > 12) {
		m = m - 12;
	}
	finalDegree = m * 30 - n / 5 * 30 + n / 2;
	if (finalDegree < 0) {
		finalDegree = 0 - finalDegree;
	}
	if (finalDegree >180.0) {
		finalDegree = 360.0 - finalDegree;
	}
	printf("%.3f\n", finalDegree);
}

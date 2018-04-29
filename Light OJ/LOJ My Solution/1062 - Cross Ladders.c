#include <stdio.h>
#include <math.h>
#define min(x,y) (x < y? x:y)

int main()
{
	int tc, cn = 1, i, j, k;
	double hi, lo, mid, x, y, c, ans, k1, k2, h;

	scanf ("%d", &tc);
	while ( tc-- ) {
		scanf ("%lf%lf%lf", &x,&y,&c);

		hi = min(x,y);
		lo = 0; k = 100;
		while (k--) {
			mid = (hi+lo)/2.0;
			k1 = sqrt (y*y-mid*mid);
			k2 = sqrt (x*x-mid*mid);
			h = k1*k2/(k1+k2);
			if (h > c) lo = mid;
			else hi = mid;
		}
		ans = (hi + lo)/2.0;
		printf ("Case %d: %.8lf\n", cn++, ans);
	}

	return 0;
}

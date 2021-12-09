
// gcc -O3 -cat /proc/cpuinfoS -ftree-vectorize -ftree-vectorizer-verbose=2 sse_ex01.cpp 

void f(int * __restrict__ a, int * __restrict__ b, int * __restrict__ c, int * __restrict__ d,
       int * __restrict__ e, int * __restrict__ f, int * __restrict__ g, int * __restrict__ h,
       int * __restrict__ o)
{
    int i;

    for (i = 0; i < 8; ++i)
        o[i] = a[i]*e[i] + b[i]*f[i] + c[i]*g[i] + d[i]*h[i];
}
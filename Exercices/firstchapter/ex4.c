#include <stdio.h>

void diviser(int *t, int *t1, int *t2, int n)
{
    int i = 0, j = 0, m1 = n / 2;
    for (; i < m1; i++)
        t1[i] = t[i];
    for (; i < n; i++, j++)
        t2[j] = t[i];
}

void fusionner(int *t, int *t1, int *t2, int n)
{
    int i = 0, j = 0, k = 0, m1 = n / 2, m2 = n - m1;
    while (i < m1 && j < m2)
    {
        if (t1[i] < t2[j])
            t[k++] = t1[i++];
        else
            t[k++] = t2[j++];
    }
    while (i < m1)
        t[k++] = t1[i++];
    while (j < m2)
        t[k++] = t2[j++];
}

void tri_fusion(int *t, int n)
{
    if (n > 1)
    {
        int m1 = n / 2, m2 = n - m1;
        int t1[m1], t2[m2];
        diviser(t, t1, t2, n);
        tri_fusion(t1, m1);
        tri_fusion(t2, m2);
        fusionner(t, t1, t2, n);
    }
}


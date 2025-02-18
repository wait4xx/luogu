//
// Created by XX on 2025/02/15.
//

#include <stdio.h>
struct carpet {
    int a;
    int b;
    int g;
    int k;
};

int main() 
{
    int n;
    scanf("%d", &n);
    struct carpet carpets[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &carpets[i].a, &carpets[i].b, &carpets[i].g, &carpets[i].k);
    }
    int x, y;
    scanf("%d %d", &x, &y);
    int flag = 0;
    for (int i = n - 1; i >= 0; i--) 
    {
        if (x >= carpets[i].a && x <= carpets[i].a + carpets[i].g && y >= carpets[i].b && y <= carpets[i].b + carpets[i].k) 
        {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
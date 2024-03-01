#include <stdio.h>
#include <math.h>

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        double sum = 0.0;
        double num = (double)n;
        for (int i = 0; i < m; i++) {
            sum += num;
            num = sqrt(num);
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}

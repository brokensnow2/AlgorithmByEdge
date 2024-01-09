#include <stdio.h>
#include <string.h>
/**
 * This time, 
 * you are supposed to find A+B where A and B are two polynomials.
 * Input Specification:
 * Each input file contains one test case. 
 * Each case occupies 2 lines, 
 * and each line contains the information of a polynomial:
 * 2 1 2.4 0 3.2
 * 2 2 1.5 1 0.5
 * 
 * Output Specification:
 * For each test case you should output the sum of A and B in one line,
 *  with the same format as the input. 
 * Notice that there must be NO extra space at the end of each line.
 *  Please be accurate to 1 decimal place.
 * 
*/



#include <stdio.h>

int main() {
    int maxDegreeA, maxDegreeB;
    scanf("%d", &maxDegreeA);
    int exponentsA[maxDegreeA];
    double coefficientsA[maxDegreeA];

    for (int i = 0; i < maxDegreeA; i++) {
        scanf("%d %lf", &exponentsA[i], &coefficientsA[i]);
    }

    scanf("%d", &maxDegreeB);
    int exponentsB[maxDegreeB];
    double coefficientsB[maxDegreeB];

    for (int i = 0; i < maxDegreeB; i++) {
        scanf("%d %lf", &exponentsB[i], &coefficientsB[i]);
    }

    int i = 0, j = 0, count = 0;
    int exponents[maxDegreeB + maxDegreeA];
    double coefficients[maxDegreeB + maxDegreeA];

    while (i < maxDegreeA && j < maxDegreeB) {
        if (exponentsA[i] > exponentsB[j]) {
            exponents[count] = exponentsA[i];
            coefficients[count] = coefficientsA[i];
            i++;
        } else if (exponentsA[i] < exponentsB[j]) {
            exponents[count] = exponentsB[j];
            coefficients[count] = coefficientsB[j];
            j++;
        } else {
            exponents[count] = exponentsA[i];
            coefficients[count] = coefficientsA[i] + coefficientsB[j];
            if (coefficients[count] == 0.0) {
                count--;
            }
            i++;
            j++;
        }
        count++;
    }

    while (i < maxDegreeA) {
        exponents[count] = exponentsA[i];
        coefficients[count] = coefficientsA[i];
        i++;
        count++;
    }

    while (j < maxDegreeB) {
        exponents[count] = exponentsB[j];
        coefficients[count] = coefficientsB[j];
        j++;
        count++;
    }

    printf("%d", count);
    for (int i = 0; i < count; i++) {
        printf(" %d %.1lf", exponents[i], coefficients[i]);
    }

    return 0;
}
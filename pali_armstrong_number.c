#include <stdio.h>
#include <math.h>
int ispali(int num) {
    int originalNum = num, remainder, sum = 0;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        sum = sum * 10 + remainder;
        originalNum /= 10;
    }
    return (sum == num);
}
int isarm(int num) {
    int originalNum = num, sum = 0, digits = 0, lastDigit;
    while (originalNum != 0) {
        originalNum /= 10;
        ++digits;
    }
    originalNum = num;
    while (originalNum != 0) {
        lastDigit = originalNum % 10;
        sum += pow(lastDigit, digits);
        originalNum /= 10;
    }
    return (sum == num);
}
int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (isarm(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    if (ispali(num)) {
        printf("%d is a palindrome number.\n", num);
    } else {
        printf("%d is not a palindrome number.\n", num);
    }
    return 0;
}

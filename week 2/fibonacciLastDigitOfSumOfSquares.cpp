/*
    Calculates last digit of fibonacci numbers sum of squares
*/
#include <iostream>

int getPisanoPeriod(long long m) {
    int a = 0;
    int b = 1;
    int c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        // it means that the next iteration started and we need to stop
        if (a == 0 && b == 1) {
            return i + 1;
        }
    }
}

int fibModM(long long n, long long m) {
    // to solve this we need to calculate pisano period's length
    int remainder = n % getPisanoPeriod(m);

    int first = 0;
    int second = 1;

    int res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res;
}

int fibLastSumDigit(long long n) {
	// https://math.stackexchange.com/questions/2613609/summation-of-squares-of-fibonacci-numbers
    return (fibModM(n, 10) * fibModM(n + 1, 10)) % 10;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << fibLastSumDigit(n) << std::endl;
    return 0;
}

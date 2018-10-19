#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() {
    cout << sum(4) << endl;
    cout << fact(4) << endl;
    return 0;
}

/**
 * PRINCIPLE OF MATHEMATICAL INDUCTION
 * note*: Recursion is based on PMI
 * 
 * PMI:
 * F(n) is true for all n.
 * 1. Base: Prove F(0) and/or F(1) is true.
 * 2. Induction Hypothesis: Assume that F(k) is true.
 * 3. Induction Step: Using (2) prove the F(k) is true.
 * 
 * Example: Sum of first n natural nums
 * sigma(n) = n(n + 1) / 2
 * 
 * 1. Base case: (Always make the base case first) [MOST IMP]
 *      F(0):
 *      sigma(0) = 0 (LHS)
 *      sigma(0) = 0(0 + 1) / 2 = 0 (RHS)
 *      LHS == RHS (proved)
 * 
 *      F(1):
 *      sigma(1) = 1 (LHS)
 *      sigma(1) = 1(1 + 1) / 2 = (1 * 2) / 2 = 1 (RHS)
 *      LHS == RHS (proved)
 * 
 * 2. Induction Hypothesis:
 *      Assume: sigma(k) = k(k + 1) / 2 (to be true)
 * 
 * 3. Induction Step:
 *      Our task is to prove:
 *      sigma(k + 1) = (k + 1)(k + 2) / 2 (is also true)
 * 
 *      Proof:
 *      sigma(k + 1) = k + 1 + sigma(k)
 *                   = k + 1 + (k(k + 1) / 2)
 *                   = 2(k + 1) / 2 + k(k + 1) / 2 [taking (k + 1) as common]
 *                   = (k + 1)(k + 2) / 2
 *                   = sigma(k + 1)
 *      LHS == RHS (proved)
 * 
 * Intuition: Basically you can prove any step using the base
 *            case alone as demonstrated above like a step ladder
 *            starting from the bottom. Once we know how to take
 *            one step in a direction, we can take k number of
 *            steps in the same direction.
 */
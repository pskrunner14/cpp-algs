/**
 * Recurrence Relation:
 * 
 * ex. factorial using recursion
 *      T(n) = k + T(n - 1)
 *      T(n - 1) = k + T(n - 2)
 *      T(n - 2) = k + T(n - 3)
 *      ...
 *      ...
 *      T(1) = k + T(0)
 *      T(0) = k
 *      -----------------------
 *     Adding all of them:
 *      T(n) = k + k + k ... (n + 1) times
 *      T(n) = k(n + 1) = kn + k
 *     So factorial is O(n) time complexity.
 * 
 * ex. binary search recurrence relation
 *      T(n) = k + T(n / 2)
 *      T(n / 2) = k + T(n / 4)
 *      T(n / 4) = k + T(n / 8)
 *      ...
 *      ...
 *      T(1) = k
 *      -----------------------
 *     Adding all of them:
 *      T(n) = k + k + k ... (how many times?) x times
 *      series is : n, n / 2, n / 2^2, ..., n / 2^x
 *      i.e. n / 2^x = 1
 *          => n = 2^x
 *          => x = log(n) times
 *      T(n) = k*log(n)
 *     So binary search is O(logn) time complexity.
 *
 * ex. merge sort recurrence relation:
 *     Pseudocode:
 *      1. Check base case -> k
 *      2. Recursive call on first half -> T(n / 2)
 *      3. Recursive call on second half -> T(n / 2)
 *      4. Merge the two sorted arrays -> kn
 * 
 *      T(n) = k + 2T(n / 2) + kn
 *      T(n) = 2T(n / 2) + kn
 *      2T(n / 2) = 4T(n / 4) + kn
 *      4T(n / 4) = 8T(n / 8) + kn
 *      ...
 *      ...
 *      2^xT(1) = k
 *      --------------------------
 *     Adding all of them:
 *      T(n) = kn + kn + kn + ... x times
 *      (n / 2^x) = 1
 *      => x = logn
 *      => T(n) = kn*logn
 *     So merge sort is O(nlogn) time complexity.
 */
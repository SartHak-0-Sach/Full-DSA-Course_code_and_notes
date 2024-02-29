#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

void countPrimes(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) // brute force approach- picking each number from i loop and checking if it is prime in j loop
        {
            if (i % j == 0) // this is optimized brute force approach because we only traversing j till sqrt(i) but complexity remains same
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            count++;
        }
    }
    cout << count << endl;
}

int countPrimes2(int n)
{
    int count = 0;
    vector<bool> primeNos(n + 1, true); // my code for count primes program
    primeNos[0] = primeNos[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (primeNos[i])
            count++;
        for (int j = 2 * i; j < n; j += i)
            primeNos[j] = false;
    }
    return count;
}

int countPrimes3(int n)
{
    if (n <= 1)
        return 0;

    vector<bool> primes(n + 1, 1); // optimized approach for solving this question
    primes[0] = primes[1] = 0;
    int cnt = 1;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                if (primes[j])
                    cnt++;
                primes[j] = 0; // better space optimized approach than the chatGPT code mentioned below which is better time optimized approach
            }
        }
    }

    return n - cnt - 1;
}

int countPrimes4(int n)
{
    if (n <= 1)
        return 0;

    vector<int> primes(n + 1, 1); // chatGPT most optimized code
    primes[0] = primes[1] = 0;

    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (primes[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            cnt++;
        }
    }

    return cnt;
}
/*
Ways to optimize this code further-
Memory Optimization: While the current implementation uses a vector to store prime flags, if memory usage is a concern for very large values of n, you might consider using a bitset instead of a vector<bool>. This can reduce memory consumption.

Loop Unrolling: For very large values of n, loop unrolling might provide a slight performance improvement. Instead of incrementing by i in the inner loop, you can increment by multiples of i to reduce the number of iterations.

Parallelization: If you're dealing with extremely large ranges of n and have access to parallel processing capabilities, you might explore parallelizing certain parts of the algorithm to further improve performance.

Algorithmic Improvements: While the Sieve of Eratosthenes is one of the most efficient algorithms for counting primes, there might be alternative algorithms or optimizations suitable for specific ranges of n or requirements.

Using a vector<bool> and a bitset for representing boolean flags have differences in terms of memory usage due to their underlying implementations.

Memory Usage:

vector<bool>: Internally, vector<bool> typically uses a single bit for each boolean value. However, due to memory alignment and implementation details, each boolean value is often stored as a full byte (8 bits) instead of a single bit. This means that each boolean value consumes more memory (usually 1 byte) than necessary.
bitset: bitset is designed to be more memory-efficient for representing fixed-size sequences of boolean flags. Each boolean value in a bitset is stored as a single bit, meaning that it consumes only 1 bit of memory. This makes bitset more memory-efficient compared to vector<bool>.
Memory Overhead:

vector<bool>: Apart from the memory used to store the boolean values, vector<bool> also incurs additional memory overhead due to its dynamic resizing mechanism. This overhead includes memory for the vector's capacity, size, and pointers.
bitset: bitset has a fixed size determined at compile time, so there is no dynamic resizing overhead. The memory usage of a bitset is purely based on the size of the bitset (number of bits) and is constant.
Flexibility:

vector<bool>: vector<bool> is dynamic in size and can grow or shrink as needed. It's suitable for situations where the size of the boolean sequence is not known at compile time or needs to change dynamically.
bitset: bitset has a fixed size determined at compile time, making it suitable for situations where the size is known in advance and doesn't need to change.
In summary, if memory efficiency is crucial and the size of the boolean sequence is fixed or known at compile time, bitset is generally preferred due to its efficient memory usage. However, if dynamic resizing is required or the size is unknown until runtime, vector<bool> might be more appropriate despite its higher memory overhead.

Using std::bitset is a valid approach for storing boolean flags efficiently, especially when the size of the array is known at compile time and relatively small.

However, in the case of the Sieve of Eratosthenes algorithm, the size of the array depends on the input n, which can be large (up to 10^6 in this case). Using std::bitset<1000001> would allocate memory for 1 million bits, which can be quite large and may cause stack overflow issues on some systems due to the limited size of the stack.

On the other hand, std::vector<bool> dynamically allocates memory from the heap, which allows it to handle larger sizes without causing stack overflow. Additionally, std::vector<bool> provides a more flexible and safer approach for managing memory compared to std::bitset, especially when dealing with large arrays whose size is determined at runtime.

Therefore, for algorithms like the Sieve of Eratosthenes where the array size depends on runtime input and can be large, it's generally safer and more practical to use std::vector<bool> over std::bitset.
*/

int countPrimes5(int n)
{
    if (n <= 1)
        return 0;

    // Using bitset for memory efficiency
    std::bitset<1000001> primes; // Assumed upper limit for n
    primes.set();                // Set all bits to 1

    primes[0] = primes[1] = 0;
    int cnt = 0;

    // Unroll the loop and increment by multiples of i
    for (int i = 2; i * i <= n; ++i)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i) // bitset code is also correct but was giving runtime error on leetcode, reason mentioned below
            {
                primes[j] = 0;
            }
        }
    }

    // Count prime numbers
    for (int i = 2; i < n; ++i)
    {
        if (primes[i])
        {
            ++cnt;
        }
    }

    return cnt;
}

/*
The error encountered while using std::bitset in the Sieve of Eratosthenes code is likely due to exceeding the stack size limit.

When you create a std::bitset with a large number of bits, the memory required for it is allocated on the stack. The stack has a limited size, typically a few megabytes, depending on the system and compiler settings. If the memory required for the std::bitset exceeds this limit, it can cause a stack overflow error.

This error occurs because the stack is used for storing local variables, function call information, and other runtime data. When the stack size is exceeded, it means that the program is trying to use more memory on the stack than is available, leading to the error.

To avoid this error, you can use dynamic memory allocation (e.g., std::vector<bool>) or reduce the size of the data structure being allocated on the stack. In this case, using std::vector<bool> instead of std::bitset helps prevent stack overflow because std::vector<bool> allocates memory on the heap, which typically has a much larger size limit compared to the stack.
*/

void findFactorial(int n)
{
    int n;
    cin >> n;
    if (n < 0)
        cout << "Error" << endl;
    else
    {
        long long int result = 1;
        for (int i = 2; i <= n; i++)
            result *= i;
        cout << result << endl;
    }
}

void multiply(int res[], int &size, int x)
{
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        res[size] = carry % 10;
        carry /= 10;
        size++;
    }
}

void factorial(int n)
{
    int result[500]; // Assuming the maximum size of the result
    result[0] = 1;
    int size = 1;

    for (int i = 2; i <= n; i++)
    {
        multiply(result, size, i);
    }

    // Print the result in reverse order
    for (int i = size - 1; i >= 0; i--)
    {
        cout << result[i];
    }
}



int main()
{
    int n;
    cin >> n;
    countPrimes(n);
    cout << countPrimes2(n) << endl;
    cout << countPrimes3(n) << endl;
    cout << countPrimes4(n) << endl;
    cout << countPrimes5(n) << endl;
    findFactorial(n);
    factorial(n);
    return 0;
}
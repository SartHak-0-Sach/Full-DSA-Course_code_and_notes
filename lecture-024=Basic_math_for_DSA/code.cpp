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

int modularExponentiation(int x, int n, int m)
{
    long long int product = 1; // slower approach
    while (n--)
    {
        product *= x;
        if (product > m)
            product %= m;
    }
    return (product % m);
}

int modularExponentiation2(int x, int n, int m)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (1LL * (res) * (x)) % m; // faster approach
        }
        x = (1LL * (x) * (x)) % m;
        n = n >> 1;
    }
    return (res);
}

long long int factorialAgain(long long int n, long long int p)
{
    // Calculate factorial of (3 * n)
    long long int factorial = 1;
    for (long long int i = 1; i <= 3 * n; ++i)
    {
        factorial = (factorial * i) % p;
    }

    // Calculate power of 6 raised to the power of n
    long long int power = 1;
    for (long long int i = 1; i <= n; ++i)
    {
        power = (power * 6) % p;
    }

    // Calculate modular inverse of power
    long long int inverse_power = 1;
    long long int base = power;
    long long int exponent = p - 2;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            inverse_power = (inverse_power * base) % p; // correct approach according to me
        }
        base = (base * base) % p;
        exponent >>= 1;
    }

    // Calculate result
    long long int result = (factorial * inverse_power) % p;
    return result;
}

#define ll long long int
ll power(ll b, ll p, ll m)
{
    ll r = 1;
    b %= m;
    while (p > 0)
    {
        if (p & 1)
        {
            r = r * b % m; // real solution to above problem using Wilson theorem as above solution gave wrong result
        }
        b = b * b % m;
        p >>= 1;
    }
    return r;
}

ll factorialAgain2(ll n, ll p)
{
    n = ((n * 3) % p + p) % p; // most weird shit ever. Giving WA otherwise
    ll dem = power(6, n / 3, p);
    // weird cannot gives WA if dem is calculated before hand like power(6, n, p);
    ll num = p - 1;
    for (int i = n + 1; i <= p - 1; ++i)
        num = (num * power(i, p - 2, p)) % p;
    ll ans = num * power(dem, p - 2, p) % p;
    return ans;
}

/*
Time Complexity : O((N - P)*log(N))
Space Complexity : O(1)

Where ‘N’ is the number given and ‘P’ is the given prime number.
*/

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;

    x = x % p;
    while (y > 0)
    {
        // If y is odd, multiply x with result.
        if (y & 1)
        {
            res = (res * x) % p;
        }

        // The y must be even now.
        y = y >> 1;

        x = (x * x) % p;
    }

    return res;
}

long long int modInverse(long long int a, long long int p)
{
    return power(a, p - 2, p);
}

long long int modMultiplication(long long int a, long long int b, long long int m)
{
    a = a % m;
    b = b % m;

    return (((a * b) % m) + m) % m;
}

long long int modDivision(long long int a, long long int b, long long int m)
{
    a = a % m;
    b = b % m;

    return (modMultiplication(a, modInverse(b, m), m) + m) % m;
}

long long int factorialAgain3(long long int n, long long int p) // another solution to above problem
{
    n = modMultiplication(n, 3, p);

    long long int num = (p - 1);

    for (long long int i = n + 1; i < p; i++)
    {
        num = (num * modInverse(i, p)) % p;
    }

    long long int den = 1;
    den = power(6, n / 3, p);

    long long int ans = modDivision(num, den, p);

    return ans;
}

// C++ program to compute factorial of big numbers
#include <iostream>
using namespace std;

// Maximum number of digits in output
#define MAX 500

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3
    // * 4...*n
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}

// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

// Driver program
int main()
{
    factorial(100);
    return 0;
}

/*
Factorial of given number is
93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
*/

// C++ program to find large
// factorials using BigInteger

#define ull unsigned long long

// Returns Factorial of N
ull factorial2(int N)
{

    // Initialize result
    ull f = 1; // Or BigInt 1

    // Multiply f with 2, 3, ...N
    for (ull i = 2; i <= N; i++)
        f *= i;

    return f;
}

// Driver method
// int main()
// {
// 	int N = 20;
// 	cout << factorial(N) << endl;
// }

/*
Output
2432902008176640000
*/

//* Node Class
class Node
{
public:
    int data;
    Node *prev;
    Node(int n)
    {
        data = n;
        prev = NULL;
    }
};

//* Function to perform desired operation
void Multiply(Node *head, int i)
{
    Node *temp = head,
         *prevPtr = head; // Temp variable for keeping head

    int carry = 0;

    //* Perform operation until temp becomes NULL
    while (temp != NULL)
    {
        int prod = temp->data * i + carry;
        temp->data = prod % 10; //* Stores the last digit
        carry = prod / 10;
        prevPtr = temp;    //* Change Links
        temp = temp->prev; //* Moving temp to next node
    }

    //* If carry is greater than 0 then we create new nodes
    //* to store remaining digits.
    while (carry != 0)
    {
        prevPtr->prev = new Node((int)(carry % 10));
        carry /= 10;
        prevPtr = prevPtr->prev;
    }
}

//* Using head recursion to print the linked list's data in reverse
void print(Node *head)
{
    if (head == NULL)
        return;
    print(head->prev);
    cout << head->data; // Print linked list in reverse order
}

// Driver code
// int main()
// {
// 	int n = 100;
// 	Node *head = new Node(1); // Create a node and initialise it by 1

// 	for(int i = 2; i <= n; i++)
// 		Multiply(head, i); // Run a loop from 2 to n and
// 							// multiply with head's i
// 	cout << "Factorial of " << n << " is : \n";
// 	print(head); // Print the linked list
// 	cout << endl;
// 	return 0;
// }

/*
Factorial of 100 is :
93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
*/

int count2 = 0;
int count5 = 0;
void updateCount(int n)
{
    while (true)
    {
        bool found = false;
        if (n % 5 == 0)
        {
            count5++;
            n /= 5;
            found = true;
        }
        else if (n % 2 == 0) // my brute force solution
        {
            count2++;
            n /= 2;
            found = true;
        }
        if (!found)
            break;
    }
}
int trailingZeroes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0 || i % 5 == 0)
            updateCount(i);
    }
    int ans = min(count2, count5);
    return ans;
}

// class Solution {
// public:

//     int findFactorial(int n){

//         long long factorial=1;

//         for(int i=1;i<=n;i++){
//             factorial*=i;
//         }
//       return factorial;
//     }

//     int trailingZeroes(int n){

//         if(n==0) return 0;
//         int cntZeroes=0;

//         int factorial=findFactorial(n);
//          while (factorial % 10 == 0) {
//             cntZeroes++;
//             factorial /= 10;
//         }
//         return cntZeroes;
//     }
// };

int trailingZeroes2(int n)
{
    int cntZeroes = 0;
    for (int i = 5; n / i > 0; i *= 5) // most optimized approach solution of this problem
    {
        cntZeroes += n / i;
    }
    return cntZeroes;
}

int main(int argc, char const *argv[])
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
    cout << modularExponentiation(2, 3, 3) << endl;
    cout << modularExponentiation2(2, 3, 3) << endl;
    cout << factorialAgain(3, 1000000007) << endl;
    cout << factorialAgain2(3, 1000000007) << endl;
    cout << factorialAgain3(3, 1000000007) << endl;
    return 0;
}
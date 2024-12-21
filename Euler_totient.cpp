////kaj hocche Phi(n)-- 1-n er modde koto gula n sathe gcd  1
///eta complexity hocce n * log log(n)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    long long phi[n+10];
    for(int i=1;i<=n;i++)
    {
        phi[i]=i;
    }
    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=n;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<phi[i]<<endl;
    }
    return 0;
}
/*
using seive
#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Euler Totient Function using a sieve
vector<int> computeTotient(int n) {
    vector<int> phi(n + 1);

    // Initialize phi[i] to i
    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }

    // Compute totient values using a sieve
    for (int p = 2; p <= n; p++) {
        if (phi[p] == p) { // p is a prime number
            for (int k = p; k <= n; k += p) {
                phi[k] -= phi[k] / p;
            }
        }
    }

    return phi;
}

int main() {
    int n;
    cout << "Enter the maximum value for Euler Totient Function calculation: ";
    cin >> n;

    // Compute totient values for all numbers up to n
    vector<int> totients = computeTotient(n);

    // Display the results
    for (int i = 1; i <= n; i++) {
        cout << "phi(" << i << ") = " << totients[i] << endl;
    }

    return 0;
}
*/
/// only n er jonno
/*
#include <iostream>
using namespace std;

// Function to calculate the Euler Totient Function
int phi(int n) {
    int result = n; // Start with n
    for (int p = 2; p * p <= n; ++p) {
        // Check if p is a prime factor of n
        if (n % p == 0) {
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    // If n has a prime factor greater than sqrt(n)
    if (n > 1)
        result -= result / n;

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Euler Totient Function value for " << n << " is: " << phi(n) << endl;
    return 0;
}
*/


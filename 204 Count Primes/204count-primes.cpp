class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0; //edge case, n = 1/1/2 : strictly less than n
        vector<bool> isPrime(n, true); //a boolean vector of size n (0 to n-1) with all values true
        isPrime[0] = isPrime[1] = false; //0 and 1 are not prime numbers
        for(int i = 2 ; i*i <= n; i++){ //iterate from i = 2 to floor(sqrt(n))
            if(isPrime[i]){ //if i is a prime, mark its multiples until n as not prime then
                for(int j = i*i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }
};
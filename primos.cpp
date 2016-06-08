#include <bitset>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
ll _sieve_size;
bitset <10000010> bs;
vi primes;

void sieve(ll upperbound){
    _sieve_size = upperbound +1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll  i = 2; i<= _sieve_size;i++) {
        if(bs[i]){
            for(ll j = i*i ; j <= _sieve_size; j+=i) bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

bool isPrime(ll N){
    if(N <= _sieve_size) return bs[N];
    for(int i =0;i<(int)primes.size();i++) if(N%primes[i] == 0) return false;
    return true;

}

vi primeFactors(ll N){
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while(N !=1 && (PF*PF <=N)){
        while(N%PF == 0){
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if(N!= 1) factors.push_back(N);
    return factors;
}

int main(){
    sieve(10000000);
    printf("%d\n",isPrime(2147483647)); ///numero primo
    printf("%d\n",isPrime(136117223861LL)); ///número irmão -> que não é primo HAHAHAHAHAHAHAHA muito boa
    vi factors = primeFactors(2147483647);
    return 0;

}




#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <algorithm>

using namespace std;

/*!
@fn gcd
@brief gcd(x, y)
*/
template<class T>
T gcd(T x, T y)
{
    if (x < y) {
        swap(x, y);
    }

    if (y == 0) {
        return x;
    }

    do
    {
        T r = x % y;
        x = y;
        y = r;
    } while (y);

    return x;
}

/*!
@fn lcm
@brief lcm(x, y)
*/
template<class T>
T lcm(T x, T y)
{
    return x / gcd(x, y) * y;
}

/*!
@fn modpow
@brief base^exp % mod
*/
template<class T>
T modpow(T base, T exp, T mod)
{
    base %= mod;
    T res = 1;

    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }

        base = (base * base) % mod;
        exp >>= 1;
    }

    return res;
}

/*!
@fn is_prime
@brief xが素数かどうかを判定する
*/
template<class T>
bool is_prime(T x)
{
    if (x == 2) {
        return true;
    }

    if (x % 2 == 0) {
        return false;
    }

    for (T i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

#endif

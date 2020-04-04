from math import sqrt


def gcd(a: int, b: int) -> int:
    """
    Euclid's Algorithm
    returns greatest common divisor or a,b
    done irtetarativley,so no worry of recurrsion depth!
    """
    while b != 0:
        a, b = b, a % b
    return a


def lcm(a: int, b: int) -> int:
    """
    returns least common multiple or a,b
    """
    if a == 0 and b == 0:
        return 0
    return a//gcd(a, b)*b


def is_prime(n: int) -> bool:
    """
    returns True if n is prime
    else    False
    Complexity: O(sqrt(n))
    """
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    i = 3
    while i*i <= n:
        if n % i == 0:
            return False
        i += 2
    return True


def number_of_divisors(n: int) -> int:
    """
        returns number of divisiors on n
        Complexity: O(sqrt(n))
    """
    i = 1
    tau = 0
    while i*i <= n:
        if n % i == 0:
            tau += 1
            d = n//i
            if i != d:
                tau += 1

        i += 1
    return tau


def sum_of_divisons(n: int) -> int:
    """
        returns sum of divisiors on n
        Complexity: O(sqrt(n))
    """
    i = 1
    sod = 0
    while i*i <= n:
        if n % i == 0:
            sod += i
            if i != (n/i):
                sod += (n//i)
        i += 1
    return sod


def get_primes_upto(n: int) -> list:
    """
        Uses Sieve of Eratosthenes to find
        primes upto n
    """
    isPrime = [1 for _ in range(n+5)]
    primes = []

    if n > 2:
        primes.append(2)

    limit = sqrt(n+0.0) + 2
    for i in range(3, n + 1, 2):
        if isPrime[i] == 1:
            primes.append(i)
            if i < limit:
                for j in range(i*i, n + 1, 2*i):
                    isPrime[j] = 0

    return primes


def is_square(n: int) -> bool:
    """
    Tests wheather n is perfect square or not
    Complexity: O(1)
    """
    root = sqrt(n)
    return int(root) == root


class Fraction:
    """
    Fraction Class: Keeps any Fraction in lowest form
    +,-,*,/ operator is overloaded
    Fraction(1,2) + 1 |
    1 + Fraction(1,2) | Both works 
    For,+,-,*,/
    """

    def __init__(self, a=0, b=1):
        self.a = int(a)
        self.b = int(b)
        self._normalize()

    def _normalize(self):
        if self.b < 0:
            self.b = -self.b
            self.a = -self.a
        g = gcd(abs(self.a), abs(self.b))
        if g > 0:
            self.a //= g
            self.b //= g

    def __add__(self, other):
        a, b = self.a, self.b
        c, d = other.a, other.b
        return Fraction(a*d + b*c, b*d)

    def __radd__(self, other: int):
        return Fraction(other) + self

    def __sub__(self, other):
        a, b = self.a, self.b
        c, d = other.a, other.b
        return Fraction(a*d - b*c, b*d)

    def __rsub__(self, other):
        return Fraction(other) - self

    def __mul__(self, other):
        a, b = self.a, self.b
        c, d = other.a, other.b
        return Fraction(a*c, b*d)

    def __rmul__(self, other):
        return Fraction(other) * self

    def __truediv__(self, other):
        return self * Fraction(other.b, other.a)

    def __rtruediv__(self, other):
        return Fraction(other)/self

    def __str__(self):
        if self.b == 1:
            return str(self.a)
        return str(self.a) + '/' + str(self.b)

    def __float__(self):
        return self.a/self.b

    def __int__(self):
        return self.a//self.b

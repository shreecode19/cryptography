#WAP to implement Euler's Totient Function.

def euler_phi(n):
    if n <= 0:
        return 0
    if n == 1:
        return 1

    result = n  

    
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1

    
    if n > 1:
        result -= result // n

    return result


if __name__ == "__main__":
    num = int(input("Enter an integer n to calculate Euler's Totient function: "))
    phi = euler_phi(num)
    print(f"Phi({num}) = {phi}")

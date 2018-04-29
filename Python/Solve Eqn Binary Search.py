# Finding Approximate Soln to Equation with Binary Search
# Moaz Mahmud
# Equation is e^x + x = 3

import math

def f(x):
    return ( ( (12*x*x) - (48*x) + 20 ) ) # This is where u put Eqn

# NOTE: Write the  left side keeping 0(zero) in Right Side Of EQN
# EG: to find x^5 + x^3 + x = 6.Keep 0 in RHS.
# So,x^5 + x^3 + x - 6 = 0. then write LHS.

low = 2
up  = 0
mid = (low + up)/2 # Guessed oned in middle
# Find low and up such that,f(low) < 0 and f(up) > 0
# This means there must be a Soln low < x < up

t = 300
# We would run the method t times
# The more you take the more close the Soln goes

while t >= 0:
    if( f(mid) == 0 ):
        break # if f(mid) = 0 that means mid is a soln
    elif( f(mid) > 0 ):
        up = mid
        # If f(mid) > 0 this means this has becom our new upper point
    else:
        low = mid
        # If f(mid) < 0 this means this has becom our new lower point
        
    mid = (up + low)/2 # Guessed oned in middle again
    t = t - 1

# After t times ratation our Approximate Soln is Gessed one :D
# So print out mid

print("Solution %.20lf" %(mid))

input("Press Anykey to Exit")
# This is just to preserve Screen

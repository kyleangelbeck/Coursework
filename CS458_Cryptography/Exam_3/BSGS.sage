# I shoved all of this into a function so that we can just return when we find n to break the loops
def findn():
    # Compute m from given prime
    prime = 64627
    m = floor(sqrt(64627))

    # Create Elliptic curve using prime and given a,b
    E = EllipticCurve(GF(prime), [1,6])

    # Given points
    # (47884,24106) = n * (52458,4831)
    P = E(52458,4831)
    Q = E(47884,24106)

    # Baby Step
    dict = {}
    for i in range(0,m):
        dict[i] = i * P

        
    # Giant Step
    for i in range (0,m):
        temp = i * m * P
        temp = Q - temp
        for a, b in dict.items():
            # If we find a point in the dict that is equal to our temp point, then we can compute our n
            if b == temp:
                # Return so we don't keep looping
                return i*m + a

# Print n
print("n: " + str(findn()))

# https://www.hackerrank.com/challenges/password-cracker/problem

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'passwordCracker' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING_ARRAY passwords
#  2. STRING loginAttempt
#

def passwordCracker(passwords, loginAttempt):
    # Write your code here
    n = len(loginAttempt)
    # record which password is used for each step, 
    # -1 means unable to find a valid password concatenation
    dp = [-1] * n
    
    dt = {} # dictionary: key(password), value(index in list "passwords")
    for i, password in enumerate(passwords):
        dt[password] = i
        
    for i in range(n):
        # loginAttempt[0:i+1] is valid combination
        if loginAttempt[:i + 1] in dt:
            dp[i] = dt[loginAttempt[:i + 1]]
            continue
        
        for end_of_last_word in range(i):
            # loginAttempt[0:end_of_last_word+1] is an invalid password combination,
            # no need to look into loginAttempt[end_of_last_word+1:i+1]
            if dp[end_of_last_word] < 0:
                continue
            
            # loginAttempt[0:end_of_last_word+1] and 
            # loginAttempt[end_of_last_word+1:i+1] are both valid
            if loginAttempt[end_of_last_word + 1:i + 1] in dt:
                dp[i] = dt[loginAttempt[end_of_last_word + 1:i + 1]]
                break
    
    # can't find a combination for the whole loginAttempt          
    if dp[-1] < 0:
        return "WRONG PASSWORD"
    
    # reconstruct the list of passwords used in loginAttempt
    idx = n - 1
    ans = []
    while idx >= 0:
        element_idx = dp[idx]
        ans.append(passwords[element_idx])
        idx -= len(passwords[element_idx])
        
    return " ".join(reversed(ans))
    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        passwords = input().rstrip().split()

        loginAttempt = input()

        result = passwordCracker(passwords, loginAttempt)

        fptr.write(result + '\n')

    fptr.close()

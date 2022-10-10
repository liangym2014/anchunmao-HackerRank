# https://www.hackerrank.com/challenges/richie-rich/problem
def highestValuePalindrome(s, n, k):
    idx = set()  # element differ at indices
    mid = n // 2
    s = list(s)     
    for i in range(mid):
        if s[i] != s[-1 - i]:
            if s[i] > s[-1 - i]:
                s[-1 - i] = s[i]
            else:
                s[i] = s[-1 - i]
            k -= 1
            if k < 0:
                return "-1"
            idx.add(i)
    
    i = 0
    while k:
        if i < mid:
            if s[i] != '9':
                if i not in idx:  # two changes
                    if k < 2:
                        i += 1
                        continue
                    else:
                        k -= 2
                else: # only count one change
                    k -= 1

                s[i] = '9'
                s[-1 - i] = '9'
            i += 1
        else:
            if n & 1:
                s[mid] = '9'
            break

            
    return "".join(s) 

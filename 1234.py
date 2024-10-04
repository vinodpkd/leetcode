import random
from collections import Counter

letters = ['Q','W','R','E']

n = random.randint(1,10) #n*4 is the length of string

len_stri = n*4

stri = [random.choice(letters) for i in range(n*4)]

stri = "".join(stri)

print('string is "' + stri + '"')

dct = dict(Counter(stri)) #dictionary to count the frequency of letters

for let in letters:
    if let not in dct.keys():
        dct[let] = 0 #No letter means frequency is zero

#print frequency of each letter
print("Before replacement")
for k in sorted(dct.keys()):
    print(k,":",dct[k])

##e = {}
##
##for let in letters:
##    e[let] = [m.start() for m in re.finditer(let, s)]

dct_more = {} #letters which has frequency MORE than n
for k in sorted(dct.keys()):
    if dct[k] < n:
        dct_more[k] = n - dct[k]

dct_less = {} #letters which has frequency LESS than n
for k in sorted(dct.keys()):
    if dct[k] > n:
        dct_less[k] = -n + dct[k]

tobe_replaced = "" #collect letters to form a string, from dct_more

for k in dct_more.keys():
    for i in range(dct_more[k]):
        tobe_replaced += k
    
for_replacement = ''  #collect letters to form a string, from dct_less
for k in dct_less.keys():
    for i in range(dct_less[k]):
        for_replacement += k

for i,j in zip(for_replacement,tobe_replaced):
    k = stri.find(i) #find first occurence of a letter to be replaced 
    stri = stri[:k] + j + stri[k+1:]
    
dct_now = Counter(stri) #Find freqency of each letter after replacement.
print("After replacement")

for k in sorted(dct_now.keys()):
    print(k,":",dct_now[k])

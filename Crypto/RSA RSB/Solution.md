# Readme

---

---

### Challenge title: RSA RSB

### 

### Points: 250

> Appropriate point
> 
> ---
> 
> 250
> 
> > why you think this is appropriate point
> > 
> > Need deep understanding of RSA algorithm and number system

### 

### Flag: `buet{RSA_CRAZE}`

### Author:

> overth1nker - Sourov Jajodia

### Challenge Description

---

Do you know how emails are securely encrypted? You should!
You find 2 encrpyted emails and some of their security information which is incomplete, but enough.

Encrypted 1st mail:
`1298844375923722815354017262890739497661050907423966573140039611043896559599615335804486254935432526495097118563377285857307623785482366206237692564911587876038076220400645236962872730359692`

Info related to 1st mail:
n1 = `5510537609253538263795239272357550595639913815262978181392242590461458499161896998889274966499340638595165701148771019262287266917471540483641433017921933491355590956769455165432926040440973`
e1 = `65537`

If you can crack the 1st mail, you will get enough info to crack the 2nd mail.

Encrypted 2nd mail:
`343345009084445163057524426`

Info related to 2nd mail: 
e2 = `1705829`

Your flag is the message sent via the second mail in plaintext, in format: `buet{flag}`

Hint 1: How much information is too much information?
Hint 2: Though the decrypted message of the second mail is a number, the flag is not a number. But you're very close!
Hint 3: Is that an octopus?!?

### Solution of {RSA RSB}

---

#### Skills need to solve this problem

1. Cryptography
2. RSA Algorithm
3. Python
4. to ascii conversion

#### Process

---

1. Basically, a problem using RSA.
2. the second RSA problem has incomplete info, which you will extract by cracking the 1st one.
3. For the 1st problem: n, e, c is given.
4. [cracking] Decompose the n, then you can get phi_n. Use that to find out d, and decrypt the cyphertext c.
5. the decrypted plaintext is the n of the second RSA problem.
6. For the second RSA problem, previously only e, c was given. Now you also have n. So, the problem contains complete information to crack the second RSA.
7. [cracking] similar to 1st one.
8. You get a string of numbers. You notice that none of the digits in that number exceed 8. So, it must be an octal string.
9. convert the octal to ascii, and you get the string: `RSA_CRAZE`
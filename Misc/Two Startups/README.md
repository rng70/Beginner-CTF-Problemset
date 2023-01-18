## Two Startups
### Points
```
50
```
### Author
```
dyn
```
### Challenge Files
```
[+] code.cpp
[+] flag.enc
```
### Description
```
Loop, also known as Loop Freight is one of the rising startups of Bangladesh. Swap is the first re-commerce marketplace in Bangladesh.

Anyway, you do not need to know much about them except their name. The source code given here performs some steps on the original flag and obfuscates it.

Can you retrieve it?

Flag format: buet{flag_here}

Author: dyn
```
### Flag
```
buet{3_t4_L00p_k0rl4m_T4rpor_5w4p_k0rL4m}
```

### Solution
```py

def decrypt(text):
    plaintext = list(text)
    for i in range(len(text)-1, -1, -1):
        for j in range(len(text)-2, i-1, -1):
            for k in range(len(text)-3, j-1, -1):
                plaintext[k], plaintext[k+1] = plaintext[k+1], plaintext[k]
    return "".join(plaintext)

if __name__ == "__main__":
    enc_flag = open("ciphertext.txt", "r").read()
    open("dec_flag.txt", "w").write(decrypt(enc_flag))
```


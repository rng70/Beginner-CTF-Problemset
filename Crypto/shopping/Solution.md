# # Readme

---

---

### Challenge title: Shopping

### 

### Points: 150

> Appropriate point
> 
> ---
>
> 150
> 
> > why you think this is appropriate point
> >
> > Need to understand hints, use vigenere cipher

### 

### Flag: `buet{r3turn_th3_extr4_m0ney}`

### Author:

> overth1nker - Sourov Jajodia

### Challenge Description

---

Your mom gave you a list and some TaKa, and sent you shopping. After reaching the shop, you find out that the list reads `k3dnbg_da3_oqdk4_w0gor`, but you're pretty sure that last night she mentioned something about buying vinegar to make some aachar. 

Do you love your mom enough to understand what she tried to say?

Put the flag in the correct format: `buet{flag}`
 

### Solution of {Shopping}

---

#### Skills need to solve this problem

1. Cryptography
2. Vigenere Cipher

#### Process

---

1. Vignere cipher.
2. The key is TK.
3. Decrpyting it reads: `r3turn_th3_extr4_m0ney`

Alternative:
1. You can also bruteforce for different key sizes. For example, bruteforcing for keysize = 2 is enough to break the code.
# # Readme

---

---

### Challenge title: Inception 2

### 

### Points: 125

> Appropriate point
> 
> ---
> 
> 125
> 
> > why you think this is appropriate point
> > 
> > Magic tool does the trick

### 

### Flag: `buet{n0_pat1shapta_f0r_y0u_overth1nker}`

### Author:

> amepagle - Shafayat Hossain Majumder

### Challenge Description

---

"PAGLEEEEEEEEEY", screamed overth1nker on the top of his lungs in his lair. He had been shocked and extremely angry to see that Pagle had decrypted the invite and attended the BBQ party. He had been so close to getting that extra chicken leg, but now he would have to wait for another opportunity.

But overth1nker was nothing if not determined, and he knew that there would be another chance for him to succeed. The next event on the horizon was the Pitha Utshob, a festival celebrating the delicious Bengali delicacies called pithas, especially patishapta, which was overth1nker's personal favorite.

This time, he was determined to send Pagle an encrypted message so complicated that he wouldn't be able to decrypt it. To make things tough, he also changed his favorite number to 8562586432, a much higher number than 8.

"Why doesn't he just change the actual time and place in the invite instead of encrypting it?", you asked Pagle. "Idk, he is a bigshot cryptographer or something", Pagle replied with a shrug.

Please help pagle have his patishapta.

Put the flag in the format: `BUET{flag}`

Hint 1: Isn't his favorite number too big?

### Solution of {Inception 2}

---

#### Skills need to solve this problem

1. Cryptography
2. BaseXX encode/decode

#### Process

---

1. 5 levels of decoding in the following order: Base85, Base62, Base58, Base64, Base32.
2. Can be easily done in cyberchef
3. The text returned is: n0_pat1shapta_f0r_y0u_overth1nker
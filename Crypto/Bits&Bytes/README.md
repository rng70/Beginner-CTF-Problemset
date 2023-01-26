# Solution

---

---

### Challenge title: Bits&Bytes

### Flag: BUET{y0u_ar333_r3g1st3r_b00ss}

### Author:

> Al Arafat Tanin | rng70

### Challenge Description

---

> Do you know how number system and registers are related to each other? One of the most wanted hacker modified his computer and now using register of size 135 and using the full potential of registers. Our DFIR team found a crypted file with content "89AKAL3RF4O7ANR1E8PJ6CQVE8PMECBJEGPN4NR260O76SRT" but our team is busy with other hackers too. Can you help our team to decrypt it?

### Solution of Bits&Bytes

---

#### Skills need to solve this problem

* Need to know "Base32"

* Need to know how to use "CyberChef"

#### Process

* As the description says, the register size is 85 which is divisible by 5 so it will be easier for this computer to represent everything in ***2<sup>5</sup> = 32*** base

* Now dropping the encoded string to CyberChef and changing the character set to `0-9A-V` will reveal our flag ***BUET{y0u_ar333_r3g1st3r_b00ss}***   

---

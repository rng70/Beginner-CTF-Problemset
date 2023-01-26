# Solution

---

---

### Challenge title: Easy Reverse

### Flag:

> BUET{Security_is_like_a_dragon}

### Author:

> Fahmid Al Rifat

### Challenge Description

---

> The CTF (Capture the Flag) challenge that the community of skilled hackers stumbled upon was an easy problem, designed to be solvable by using reverse engineering techniques. The hackers, being curious individuals, were excited to take on the task and see if they could uncover the flag quickly. As they delved deeper into the problem, they realized that it was indeed a simple task and they were able to successfully capture the flag and claim victory with minimal effort. The challenge had been a breeze for them and it provided an opportunity for the new users to practice and improve their reverse engineering skills. The problem file is provided below for analysis and easy flag capturing.

### Solution

---

#### Skills need to solve this problem
+ IDA_PRO
+ Patching
+ Assembly
#### Process
Source code contains a flag variable and two else statements. The first word of the flag is given in the flag variable, and the rest of the flag is concatenated from the two else statements.
other two words will be concated from else part of the loop .
To solve the problem, you want to change the code so that the patch goes down the else path in both conditions and apply the modified patch.

I would suggest the following steps:

+ Understand the code logic and how the flag variable is being used.
+ Identify the two else statements that are concatenating the rest of the flag.
+ Change the conditions of the loops so that the path goes down the else path in both conditions.
+ Test the code to ensure that the flag is being concatenated correctly.
+ Apply the patch to the code.

Similar Solve Link : https://www.youtube.com/watch?v=nA6fZFjfqTA
---

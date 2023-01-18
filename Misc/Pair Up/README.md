## Pair Up
### Points
```
75
```
### Author
```
dyn
```
### Challenge Files
```
[+] encrypt.py
[+] flag.enc
```
### Description
```
One of my classmate is into loops and basic bitwise operations. Interestingly, he thought he could create an encryption algorithm and use it to protect his files.

Can you bypass his encryption to get the flag?

Flag format: buet{flag_here}
```
### Flag
```
buet{x0r_4mon6_p41r5}
```

### Solution
```py
#! /usr/bin/python3


def decrypt(enc_flag):
	
	flag = list(enc_flag)
	l = len(flag)

	for i in range(1, len(flag)):
		flag[l-i-1] = chr(ord(flag[l-i-1]) ^ ord(enc_flag[l-i]))
	
	return "".join(flag)


def main():

	flag = open("flag.txt", "r").read()

	enc_flag = open("encrypted.txt", "r").read()
	dec_flag = decrypt(enc_flag)

	if flag != dec_flag:
		raise BaseException("Original flag and decrypted flag don't match!")
	else:
		print("Flag matches!")


if __name__ == "__main__":
	main()
```


#! /usr/bin/python3


def decrypt(enc_flag):
	
	flag = list(enc_flag)
	l = len(flag)

	for i in range(1, len(flag)):
		flag[l-i-1] = chr(ord(flag[l-i-1]) ^ ord(enc_flag[l-i]))
	
	return "".join(flag)


def main():

	flag = open("flag.txt", "r").read()

	enc_flag = open("flag.enc", "r").read()
	dec_flag = decrypt(enc_flag)

	if flag != dec_flag:
		raise BaseException("Original flag and decrypted flag don't match!")
	else:
		print("Flag matches!")
		print(f"Flag: {dec_flag}")


if __name__ == "__main__":
	main()
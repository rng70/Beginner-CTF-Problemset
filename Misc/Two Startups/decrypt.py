def decrypt(text):
    plaintext = list(text)
    for i in range(len(text)-1, -1, -1):
        for j in range(len(text)-2, i-1, -1):
            for k in range(len(text)-3, j-1, -1):
                plaintext[k], plaintext[k+1] = plaintext[k+1], plaintext[k]
    return "".join(plaintext)

if __name__ == "__main__":
    enc_flag = open("flag.enc", "r").read()
    open("flag.dec.txt", "w").write(decrypt(enc_flag))
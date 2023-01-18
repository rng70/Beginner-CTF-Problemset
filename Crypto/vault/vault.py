import hashlib

print("Welcome to your vault!")
password = input("Enter the password: ")

hash = hashlib.md5(password.encode("utf-8")).hexdigest()

if hash == "45ea37a8b034ece4d08639d18d913ad0":
    print("\nThe flag is: buet{" + password + "}")
else:
    print("\nSorry. Bad luck!")

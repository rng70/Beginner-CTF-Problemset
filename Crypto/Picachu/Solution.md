# Readme

---

---

### Challenge title: Pikachu

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
> > Need to know a lot of basic about image analysis, binaries, XXX to ascii conversion etc.

### 

### Flag: `buet{b1n4ry_1s_fun}`

### Author:

> overth1nker - Sourov Jajodia

### Challenge Description

---

Picachu takes lots of random pics. He sends you all the photos in his gallery, which are repititive images, to say the least. You doubt that there might be a message hidden in plain sight. Can you find it, UwU?

All the images of his gallery is given in the zip file, please download it. Submit the flag in the format: buet{flag}

Hint 1: What do computers understand?
Hint 2: Magic 🪄

### Solution of {Pikachu}

---

#### Skills need to solve this problem

1. Cryptography
2. Base64 detection, Base64 to ascii.
3. Python image analysis/file analysis

#### Process

---

1. Inspect the images carefully. They could be differentiated by color or size difference. There are in total two classes of images here. Map each class to a 0 or 1. Traverse the whole directory, and map each image sequencially and concatenate. Finally, you'll get a binary string. 
2. Then convert the binary to ascii, which will be a base64 string.
3. Again, convert the base64 to ascii.
4. Text returned: b1n4ry_1s_fun
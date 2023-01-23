# Solution

---

---

### Challenge title: RevLLVM

### Flag: BUET{ch4r_by_ch4r_X0r_in_11vm}

### Author:

> S. M. Zuhair Zaki

### Challenge Description

---

> We found a scary looking file. Could you tell us what it does?

### Solution of {Problem name here}

---

#### Skills need to solve this problem

#### Process

* Open the file in any editor and try to understand what instructions it is executing.

* First we can see a constant variable, `bytes` which is an array of 30 bytes. This will be used for comparing with the input later.
  
  ```llvm
  @__const._Z11check_inputRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERS4_.bytes = private unnamed_addr constant [30 x i8] c"\1D\1B\1D\22\16\04LW?.\0F3*\1CD_7\1Ct_3)'\10L#c>6Z"
  ```

* Next we see a function called ` @_Z11check_input` which takes two arguments of type `string` and stores them in `%0` and `%1` respectively. Here `%0` acts as the input which will be compared with `bytes` later.
  
  ```llvm
  define dso_local noundef i32 @_Z11check_inputRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERS4_(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %0, %"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %1) #4 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %3 = alloca i32, align 4
  %4 = alloca %"class.std::__cxx11::basic_string"*, align 8
  %5 = alloca %"class.std::__cxx11::basic_string"*, align 8
  %6 = alloca [30 x i8], align 16
  %7 = alloca %"class.std::__cxx11::basic_string", align 8
  %8 = alloca %"class.std::allocator", align 1
  %9 = alloca i8*, align 8
  %10 = alloca i32, align 4
  %11 = alloca %"class.std::__cxx11::basic_string", align 8
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i8, align 1
  %16 = alloca i32, align 4
  store %"class.std::__cxx11::basic_string"* %0, %"class.std::__cxx11::basic_string"** %4, align 8
  store %"class.std::__cxx11::basic_string"* %1, %"class.std::__cxx11::basic_string"** %5, align 8
  %17 = bitcast [30 x i8]* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %17, i8* align 16 getelementptr inbounds ([30 x i8], [30 x i8]* @__const._Z11check_inputRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERS4_.bytes, i32 0, i32 0), i64 30, i1 false)
  %18 = getelementptr inbounds [30 x i8], [30 x i8]* %6, i64 0, i64 0
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* noundef nonnull align 1 dereferenceable(1) %8) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %7, i8* noundef %18, i64 noundef 30, %"class.std::allocator"* noundef nonnull align 1 dereferenceable(1) %8)
        to label %19 unwind label %49
  
  19:                                               
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* noundef nonnull align 1 dereferenceable(1) %8) #3
  call void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %11) #3
  %20 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %4, align 8
  %21 = invoke noundef nonnull align 8 dereferenceable(32) %"class.std::__cxx11::basic_string"* @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %11, %"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %20)
        to label %22 unwind label %53
  ```
  
    After defining many local variables (`%3` to `%21`) the function branches to label `%22`. There is so many redundant variables because LLVM IR variables are immutable (can't be changes once declared).

* ```llvm
  22:                                               
  store i32 0, i32* %12, align 4
  br label %23
  
  23:                                               
  %24 = load i32, i32* %12, align 4
  %25 = sext i32 %24 to i64
  %26 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %4, align 8
  %27 = call noundef i64 @_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %26) #3
  %28 = sub i64 %27, 1
  %29 = icmp ult i64 %25, %28
  br i1 %29, label %30, label %57
  
  30:                                               
  %31 = load i32, i32* %12, align 4
  %32 = add nsw i32 %31, 1
  %33 = sext i32 %32 to i64
  %34 = invoke noundef nonnull align 1 dereferenceable(1) i8* @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %11, i64 noundef %33)
          to label %35 unwind label %53
  
  35:                                               
  %36 = load i8, i8* %34, align 1
  %37 = sext i8 %36 to i32
  %38 = load i32, i32* %12, align 4
  %39 = sext i32 %38 to i64
  %40 = invoke noundef nonnull align 1 dereferenceable(1) i8* @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %11, i64 noundef %39)
          to label %41 unwind label %53
  
  41:                                               
  %42 = load i8, i8* %40, align 1
  %43 = sext i8 %42 to i32
  %44 = xor i32 %43, %37
  %45 = trunc i32 %44 to i8
  store i8 %45, i8* %40, align 1
  br label %46
  
  46:                                               
  %47 = load i32, i32* %12, align 4
  %48 = add nsw i32 %47, 1
  store i32 %48, i32* %12, align 4
  br label %23
  ```
  
  The above piece of code loops through the input stored at `%26` with index stored at `%12`. At each iteration, it gets the characters stored at `input[i]` and `input[i+1]`, and XORs them. Then stores the result in `input[i]`.
  
  Basically it does the following:
  
  ```cpp
  for (int i = 0; i < input.size()-1; ++i) {
      input[i] ^= input[i+1];
  }
  ```

* We next see another loop that iterates through the input string (now stored at `%64`).
  
  ```llvm
  61:                                               
  %62 = load i32, i32* %14, align 4
  %63 = sext i32 %62 to i64
  %64 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %4, align 8
  %65 = call noundef i64 @_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %64) #3
  %66 = icmp ult i64 %63, %65
  br i1 %66, label %67, label %85
  
  67:                                               
  %68 = load i32, i32* %14, align 4
  %69 = add nsw i32 %68, 10
  %70 = srem i32 %69, 256
  %71 = trunc i32 %70 to i8
  store i8 %71, i8* %15, align 1
  %72 = load i8, i8* %15, align 1
  %73 = zext i8 %72 to i32
  %74 = load i32, i32* %14, align 4
  %75 = sext i32 %74 to i64
  %76 = invoke noundef nonnull align 1 dereferenceable(1) i8* @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm(%"class.std::__cxx11::basic_string"* noundef nonnull align 8 dereferenceable(32) %11, i64 noundef %75)
          to label %77 unwind label %53
  
  77:                                               
  %78 = load i8, i8* %76, align 1
  %79 = sext i8 %78 to i32
  %80 = xor i32 %79, %73
  %81 = trunc i32 %80 to i8
  store i8 %81, i8* %76, align 1
  br label %82
  
  82:                                               
  %83 = load i32, i32* %14, align 4
  %84 = add nsw i32 %83, 1
  store i32 %84, i32* %14, align 4
  br label %61
  ```
  
    The index is stored in `%14`. At each iteration, it adds 10 to the index and gets the remainder when divided by 256.
  
  * ```llvm
    %68 = load i32, i32* %14, align 4
    %69 = add nsw i32 %68, 10
    %70 = srem i32 %69, 256
    ```
    
    Then it XORs the character at `input[index]` with the remainder and stores it back in `input[index]`.
    
    * ```llvm
      %80 = xor i32 %79, %73
      %81 = trunc i32 %80 to i8
      store i8 %81, i8* %76, align 1
      ```
      
      The C++ equivalent for this loop is:
      
      ```cpp
      for (int i = 0; i < input.size(); ++i) {
      input[i] ^= (i+10) % 256;
      }
      ```

* The remainder of the function just compares the modified input with `bytes` to check for equality.

* Now that we understand the what it is doing we can reverse it and get the flag.
  
  ```py
  def decrypt(input):
      for i in range(len(input)):
          input[i] ^= (i+10) % 256
      for i in range(len(input)-1, 0, -1):
          input[i-1] ^= input[i]
      return "".join([chr(i) for i in input])
  
  check = "\x1D\x1B\x1D\x22\x16\x04LW?.\x0F3*\x1CD_7\x1Ct_3)'\x10L#c>6Z"
  s = [ord(i) for i in check]
  
  print(decrypt(s))
  ```
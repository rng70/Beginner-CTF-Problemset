# # Readme

---

---

### Challenge title: Illusion

> Naming reason
> 
> ---
> 
> > this problem ask for a password and it does not matter which password you give as input it always print a flag with some additional message saying `Sometimes what you see is not the truth and what you doesn't see is the truth` but only for the correct password `tRy69tim3sToHackm3` it gives the correct flag so it was named `Illusion`

### 

### Points: 200

> Appropriate point
> 
> ---
> 
> > The provided binary is a stripped binary which is pretty much difficult to decompile & understand for a beginner. 

### Flag: BUET{:tRy69tim3sToHackm3}

### Author:

> Al Arafat Tanin | rng70

### Challenge Description

---

> Sometimes what you see is not the truth and what you doesn't see is the truth. So trust but verify.

### Solution of Illusion

---

#### Skills need to solve this problem

* Need to know how to decompile and read stripped binary.

* Difficult fo beginner but easy for intermediate.

#### Process

* Just drop the file in Ghidra and analyze the file

* The first function call from the `entry` function is `FUN_0010195d`

* after analyzing the function the first logic we see that
  
  ```cpp
    lVar1 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::size();
    if (lVar1 == 18) {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
                (local_38);
                      /* try { // try from 001019e6 to 001019ea has its CatchHandler @ 00101a0c */
      FUN_00101731(local_38);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)local_38);
    }
    else {
      FUN_001012bb();
      FUN_00101265();
    }
  ```

* `lvar1 == 18` check the string lenght is 18 or not. If not then `FUN_001012bb` and `FUN_00101265` are called but we are not interested in this two function because this two function does not gives the correct flag

* We are interested in function `FUN_00101731` 
  
  ```cpp
  void FUN_00101731(ulong param_1)
  
  {
    char cVar1;
    char *pcVar2;
    basic_string<char,std::char_traits<char>,std::allocator<char>> local_3a8 [32];
    basic_stringstream<char,std::char_traits<char>,std::allocator<char>> local_388 [16];
    basic_ostream<char,std::char_traits<char>> abStack888 [384];
    basic_string<char,std::char_traits<char>,std::allocator<char>> local_1f8 [32];
    basic_stringstream<char,std::char_traits<char>,std::allocator<char>> local_1d8 [16];
    basic_ostream<char,std::char_traits<char>> abStack456 [384];
    basic_string local_48 [36];
    int local_24;
    int local_20;
    undefined local_19;
  
    local_19 = 0;
    pcVar2 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                     operator[](param_1);
    cVar1 = *pcVar2;
    pcVar2 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                     operator[](param_1);
    local_20 = *pcVar2 + -0x30 + (cVar1 + -0x30) * 10;
    local_24 = local_20 * local_20;
    std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::
    basic_stringstream();
                      /* try { // try from 001017bd to 001017da has its CatchHandler @ 0010193a */
    std::basic_ostream<char,std::char_traits<char>>::operator<<(abStack456,local_24);
    std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::str();
                      /* try { // try from 001017e5 to 001017e9 has its CatchHandler @ 00101926 */
    std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::
    basic_stringstream();
    local_24 = local_24 * local_20;
                      /* try { // try from 00101807 to 00101824 has its CatchHandler @ 00101912 */
    std::basic_ostream<char,std::char_traits<char>>::operator<<(abStack888,local_24);
    std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::str();
    cVar1 = FUN_00101a9b(local_1f8,&DAT_00102131);
    if (cVar1 != '\0') {
      local_19 = 1;
    }
    cVar1 = FUN_00101a9b(local_3a8,"328509");
    local_19 = cVar1 != '\0';
    if ((bool)local_19) {
                      /* try { // try from 0010187e to 00101882 has its CatchHandler @ 001018fe */
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string
                (local_48);
                      /* try { // try from 0010188a to 0010188e has its CatchHandler @ 001018ed */
      FUN_001012fc(local_48);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                ((basic_string<char,std::char_traits<char>,std::allocator<char>> *)local_48);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                (local_3a8);
      std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::
      ~basic_stringstream(local_388);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string
                (local_1f8);
      std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::
      ~basic_stringstream(local_1d8);
      return;
    }
                      /* try { // try from 001018d9 to 001018e2 has its CatchHandler @ 001018fe */
    FUN_001012bb();
    FUN_00101265();
                      /* WARNING: Subroutine does not return */
    exit(0);
  }
  ```

* in this function the follwoing line converts the passed `param_1` to `char*` thus it is clear that `param_1` is a `char*` or `string`
  
  ```cpp
  pcVar2 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                     operator[](param_1);
  ```

* we can convert the function signature but that does not help too much

* by looking this line
  
  ```cpp
  pcVar2 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                     operator[](param_1);
  ```

        it is clear that `pcVar2` contains a specific characters of the `param_1` strings. Now         which index it accessing can be found by looking at the registers specially `ESI`         register in our case. Now looking at the register value it is clear that it is accessing         index ` 3 and 4` and doing some calculation which is 

```cpp
local_20 = *pcVar2 + -0x30 + (cVar1 + -0x30) * 10;
local_24 = local_20 * local_20;
```

        now `-0x30` is equal to `-48` in decimal and `-'0'` so the that line actually do in         code is 

```cpp
local_20 = *pcVar2 - '0' + (cVar1 - '0') * 10;
```

        and `local_24` contains square of `local_20` which is 4761 whose square root is         69 now interestingly 4761 is not present in the code but present is the address of         `&DAT_00102131`

* at this point we know that our password string is of size 18 and it's 3-rd & 4-th index is `69`

* now lookig at the function `FUN_001012fc` which was called inside the if block 
  
  ```cpp
  void FUN_001012fc(basic_string *param_1)
  
  {
    char cVar1;
    char cVar2;
    char cVar3;
    char cVar4;
    char cVar5;
    char cVar6;
    char cVar7;
    char cVar8;
    char cVar9;
    char cVar10;
    char cVar11;
    char cVar12;
    char cVar13;
    char cVar14;
    char cVar15;
    char cVar16;
    char cVar17;
    bool bVar18;
    bool bVar19;
    bool bVar20;
    bool bVar21;
    bool bVar22;
    bool bVar23;
    char *pcVar24;
    basic_ostream *pbVar25;
    basic_ostream<char,std::char_traits<char>> *this;
  
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar1 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar2 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar3 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar4 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar5 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar6 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar7 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar8 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar9 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar10 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar11 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar12 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar13 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar14 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar15 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar16 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    cVar17 = *pcVar24;
    pcVar24 = (char *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::
                      operator[]((ulong)param_1);
    bVar18 = false;
    bVar19 = false;
    bVar20 = false;
    bVar21 = false;
    bVar22 = false;
    bVar23 = false;
    if (((cVar12 == 't') && (cVar1 == 'R')) && (cVar2 == 'y')) {
      bVar18 = true;
    }
    if (((cVar10 == '6') && (cVar6 == '9')) && (cVar7 == 't')) {
      bVar19 = true;
    }
    if (((cVar8 == 'i') && (cVar9 == 'm')) && (cVar4 == '3')) {
      bVar20 = true;
    }
    if (((cVar14 == 's') && (cVar15 == 'T')) && (cVar16 == 'o')) {
      bVar21 = true;
    }
    if (((cVar11 == 'H') && (cVar3 == 'a')) && (cVar17 == 'c')) {
      bVar22 = true;
    }
    if (((*pcVar24 == 'k') && (cVar5 == 'm')) && (cVar13 == '3')) {
      bVar23 = true;
    }
    if (((((bVar18) && (bVar19)) && (bVar20)) && ((bVar21 && (bVar22)))) && (bVar23)) {
      pbVar25 = (basic_ostream *)
                std::basic_ostream<char,std::char_traits<char>>::operator<<
                          ((basic_ostream<char,std::char_traits<char>> *)std::cout,
                           std::endl<char,std::char_traits<char>>);
      pbVar25 = std::operator<<(pbVar25,'B');
      pbVar25 = std::operator<<(pbVar25,'U');
      pbVar25 = std::operator<<(pbVar25,'E');
      pbVar25 = std::operator<<(pbVar25,'T');
      pbVar25 = std::operator<<(pbVar25,'{');
      pbVar25 = std::operator<<(pbVar25,":");
      pbVar25 = std::operator<<(pbVar25,param_1);
      pbVar25 = std::operator<<(pbVar25,'}');
      this = (basic_ostream<char,std::char_traits<char>> *)
             std::basic_ostream<char,std::char_traits<char>>::operator<<
                       ((basic_ostream<char,std::char_traits<char>> *)pbVar25,
                        std::endl<char,std::char_traits<char>>);
      std::basic_ostream<char,std::char_traits<char>>::operator<<
                (this,std::endl<char,std::char_traits<char>>);
      return;
    }
    FUN_001012bb();
    FUN_00101265();
                      /* WARNING: Subroutine does not return */
    exit(0);
  }
  ```
  
  the only tricky part here is the string is not in correct order but easily order can be tracked down looking at the `ESI` value

* Finally our password can be found and it is **`tRy69tim3sToHackm3`**

* now running the binary file with this password reveals the flag which is
  
                                       ***`BUET{:tRy69tim3sToHackm}`***

---

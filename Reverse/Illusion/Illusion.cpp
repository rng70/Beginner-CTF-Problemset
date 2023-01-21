#include <bits/stdc++.h>

using namespace std;

void illusion()
{
    cout << endl << "Sometimes what you see is not the truth and what you doesn't see is the truth" << endl << endl;
}

void flag2()
{
    cout << endl << "BUET{R3v3rs3_1s_fun_and_s33_h0w_gooD_yOu_aR3!}" << endl;
}

void check1(string n)
{
    int b = n[1] - '0';
    int c = n[2] - '0';
    int t = n[13] - '0';
    int i = n[8] - '0';
    int q = n[16] - '0';
    int e = n[4] - '0';
    int f = n[5] - '0';
    int g = n[6] - '0';
    int h = n[7] - '0';
    int d = n[3] - '0';
    int m = n[12] - '0';
    int a = n[0] - '0';
    int r = n[17] - '0';
    int j = n[9] - '0';
    int k = n[10] - '0';
    int l = n[11] - '0';
    int o = n[14] - '0';
    int p = n[15] - '0';

    int x = 48;
    int y = 18;

    bool first = false;
    bool second = false;
    bool third = false;
    bool fourth = false;
    bool fifth = false, sixth = false;

    int z = 37;
    int w = 21;
    int zz = 36;
    int yy = 75;
    int xx = 77;

    if(a==68 && b==34 && c==73){
        first = true;
    }
    if(d==6 && e==9 && f==68){
        second = true;
    }
    if(g==57 && h==61 && i==3){
        third = true;
    }
    if(j==67 && k==36 && l==63){
        fourth = true;
    }
    if(m==24 && t==49 && o==51){
        fifth = true;
    }if(p==59 && q==61 && r==3){
        sixth = true;
    }
    
    if(first && second && third && fourth && fifth && sixth){
        cout << endl << (char)(x+y) << (char)(x+z) << (char)(x+w) << (char)(x+zz) << (char)(x+yy) << ":" << n << (char)(x+xx) << endl << endl;
    }else{
        flag2();
        illusion();
        exit(0);
    }
}

void check(string n)
{
    bool pat=false;

    int number = 10*(n[3]-'0')+(n[4]-'0');
    int sq = number*number;
    stringstream ss;
    ss << sq;
    string sss = ss.str();
    stringstream ssw;
    sq = sq*number;
    ssw << sq;
    string ssss = ssw.str();

    if(sss=="4761")
    {
        pat = true;
    }
    if(ssss=="328509"){
        pat = true;
    }else{
        pat = false;
    }
    if(pat){
        check1(n);
    }else{
        flag2();
        illusion();
        exit(0);
    }
    
}

int main()
{
    string n;
    cout << "Give me the password and I will tell you the secret: ";
    cout.flush();
    cin >> n;

    if(n.size() != 18)
    {
        flag2();
        illusion();
        return 0;
    }else{
        check(n);
    }
    return 0;
}

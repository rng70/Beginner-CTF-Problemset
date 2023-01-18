#include <iostream>
#include <fstream>

using namespace std;


string foobar(string text)
{
    int n = text.length();
    string ret(n, '.');

    for (int i=0; i < n; i++)
    {
        for (int j=i; j < n - 1; j++)
        {
            for (int k=j; k < n - 2; k++)
            {
                char ch;
                ch = text[k];
                text[k] = text[k+1];
                text[k+1] = ch;
            }
        }
    }
    return text;
}


int main()
{
    string flag;
    
    ifstream infile;
    ofstream outfile;

    infile.open("flag.txt");
    outfile.open("flag.enc");

    infile >> flag;
    outfile << foobar(flag);

    infile.close();
    outfile.close();
    return 0;
}




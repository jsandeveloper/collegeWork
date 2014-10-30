#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 21;

struct clnData
{
    int     clnNum;
    string  name;
    char    sex;
    string  loc;
    double  balance;
    double  creditLimit;
    double  ytdSales;
    int     slsNum;
};

    fstream clnFile;
    int     rcdSize;
int main (void)
{
    clnData clnRcd ={0, "", '', "", 0.00, 0.00, 0.00, 0};
    
    int rcdCount = 0;
    int i;
    
    rcdSize = sizeof(clnData);
    clnFile.open("clnfile.ran", ios::out);
    
    if (!clnFile)
    {
        cerr << "Couldn't open output file!\n";
        exit (-1);
    }
    
    cout << "Begin formatting of file: \n";
    for (i = 0; i < MAX; i++)
    {
        rcdCount += 1;
        clnFile.write((char*)&clnRcd, rcdSize);
        cout << "Record No: " << rcdCount << endl;
    }
    cout << "\nThe record size is: " << rcdSize << endl;
    cout << "\nFormatting is complete!\n";
    clnFile.close();
    system("pause");
    return(0);
}

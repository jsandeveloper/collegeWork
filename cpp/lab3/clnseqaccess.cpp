#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

ifstream   clnFile;

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

long rcdSize = sizeof(clnData);
int main(void)
{
    cout << fixed << showpoint << setprecision(2) << right;
    
    clnData clnRcd;
    fstream clnFile("clnfile.ran", ios::in);
    
    if (!clnFile)
    {
        cerr << "\nCannot open input file \n";
        exit(-1);
    }
    rcdSize = sizeof(clnData);
    clnFile.read((char*)&clnRcd, rcdSize);
    while (!clnFile.eof())
    {
        if (clnRcd.clnNum !=0)
        {
            cout << clnRcd.clnNum << ' '
                 << clnRcd.balance << endl;
        }
        clnFile.read((char*)&clnRcd, rcdSize);
    }
    clnFile.close();
    cout << "\nClient balance list complete! \n";
    system("pause");
    return(0);
}

// Output
/*
   100 7255.00
   101 596.00
   102 813.00
   103 12576.00
   104 500.00
   105 11500.00
   106 100.00
   107 0.00
   108 125.00
   109 12678.00
   110 269.00
   111 9978.00
   112 0.00
   113 4678.00

   Client balance list complete!
*/

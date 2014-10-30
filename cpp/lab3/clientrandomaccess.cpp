#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

fstream clnFile;

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
    clnData clnRcd;
    long    rcdNum;
    long    byteNum;
    long    rcdSize = sizeof(clnData);
    
int main (void)
{
    int clientNum;
    clnFile.open("clnfile.ran", ios::in);
    if(!clnFile)
    {
        cerr << "\nCannot open input file\n";
        exit(-1);
    }
    cout << "Please enter client account number: ";
    cin >> clientNum;
    
    rcdNum = clientNum - 100;
    byteNum = rcdNum * rcdSize;
    clnFile.seekg(byteNum, ios::beg);
    clnFile.read((char*)&clnRcd, rcdSize);
    
    cout << "account: " << clnRcd.clnNum << "    "
         << "balance is: " << clnRcd.balance << endl;
         
    clnFile.close();
    cout << "\nFile test complete! ";
    cout << endl;
    
    system("pause");
    return(0);
}
    
//Output
/*
 Please enter client account number: 101
 account: 101    balance is: 596

 File test complete!
*/

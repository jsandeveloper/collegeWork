#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

void writeToDisk(long);
void readInput(void);
long getRcdNum(int);
long getByteNum(long);

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
    ifstream inclnFile("clnfile.txt");
    fstream otclnFile("clnfile.ran", ios::in | ios::out);
    int rcdSize = sizeof(clnData);
    
int main (void)
{
    int     inCount = 0;
    int     outCount = 0;
    long    rcdNum;
    long    byteNum;
    
    if (!inclnFile)
    {
        cerr << "\nCannot open input file";
        exit (-1);
    }
    if (!otclnFile)
    { 
        cerr << "\nCannot open output file";
        exit(-2);
    }
    readInput();
    while(!inclnFile.eof())
    {
        inCount++;
        rcdNum = getRcdNum(clnRcd.clnNum);
        cout << "Client: " << clnRcd.clnNum << endl;
        byteNum = getByteNum(rcdNum);
        outCount++;
        readInput();
    }
    cout << "\nInput record count: " << inCount << endl;
    cout << "Output record count: " << outCount << endl;
    
    inclnFile.close();
    otclnFile.close();
    system("pause");
    return(0);
}

void readInput(void)
{
    inclnFile >> clnRcd.clnNum
              >> clnRcd.name
              >> clnRcd.sex
              >> clnRcd.loc
              >> clnRcd.balance
              >> clnRcd.creditLimit
              >> clnRcd.ytdSales
              >> clnRcd.slsNum;
    return;
}

void writeToDisk(long p_byteNum)
{
    otclnFile.seekp(p_byteNum, ios::beg);
    otclnFile.write((char*)&clnRcd, rcdSize);
    return;
}

long getRcdNum(int p_rcdKey)
{
    long v_rcdNum;
    
    v_rcdNum = p_rcdKey - 100;
    return(v_rcdNum);
}

long getByteNum(long p_rcdNum)
{
    long v_byteNum;
    
    v_byteNum = p_rcdNum * rcdSize;
    return(v_byteNum);
}

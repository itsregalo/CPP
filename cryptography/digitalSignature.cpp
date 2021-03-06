#include <iostream>
#include<cstring>
#include <math.h>
#include<string>
#include<sstream>
using namespace std;
unsigned long long int publicKey(
    unsigned long long int phi,
    unsigned long long int n,unsigned long long int e
    );

unsigned long long int privateKey(
    unsigned long long int e,
    unsigned long long int d,
    unsigned long long int phi
    );

unsigned long long int getPrimeNumber(
    unsigned long long int num);
unsigned long long int encryptionFun(unsigned long long int e,unsigned long long int message,unsigned long long int cipher,unsigned long long int n);
void decryptionFun(unsigned long long int d,unsigned long long int cipher,unsigned long long int n);
int main()
{
    unsigned long long int num1;
    unsigned long long int num2;
    unsigned long long int n;//multiplication of the two prime numbers
    unsigned long long int phi;
    unsigned long long int e=2;
    unsigned long long int track;
    unsigned long long int d=2;
    unsigned long long int message;
    unsigned long long int cipher=0;
    string message;
    stringstream digest;
    string digestHex;
    unsigned long int hashtext[100];
    string hashHex[100];
    cout << "ENTER YOUR TEST TO PRODUCE IT'S DIGEST" << endl;
    getline(cin,message);
    hashFun(message,hashtext);
    for(unsigned int i=0;i<message.length();i++)

  cout << "ENTER YOUR TEST TO PRODUCE IT'S DIGEST" << endl;
    getline(cin,message);
    hashFun(message,hashtext);
    for(unsigned int i=0;i<message.length();i++)
    {
        digest<<hex<<hashtext[i];
        hashHex[i] = digest.str();
    }
    cout<<".........DIGEST IS........."<<endl;
    for(unsigned int i=0;i<message.length();i++)
    {
        cout<<hashHex[i];
    }
    cout << "ENTER YOU FIRST PRIME NUMBER" << endl;
    cin>>num1;
    num1= getPrimeNumber(num1);
    cout<<"ENTER YOUR SECOND NUMBER"<<endl;
    cin>>num2;
    num2 = getPrimeNumber(num2);
    cout<<"ENTER message digest TO ENCRYPT"<<endl;
    cin>>message;
    n = num1*num2;
    phi = (num1-1)*(num2-1);
    while(1)
    {
        track =publicKey(phi,n,e);
        if(track == 1)
        {
            break;
        }
        else
        {
            e++;
        }
    }
    cout<<"public key is "<<e<<endl;
    d = privateKey(e,d,phi);
    cout<<"private key is "<<d<<endl;
    cipher = encryptionFun(e,message,cipher,n);
    cout<<"cipher"<<cipher;
    cout<<endl;
    decryptionFun(d,cipher,n);
    return 0;
}
unsigned long int hashFun(string message,unsigned long int hashtext[])
{
    int magic = 100;
    for(unsigned int i=0;i<message.length();i++)
    {
            hashtext[i] = message[i]^magic;
            hashtext[i] = hashtext[i]*magic;

    }

    return 0;
}
//function to verify the number entered is prime
unsigned long long int getPrimeNumber(unsigned long long int num)
{
    while(num%2==0)
    {
        cout<<"enter a prime number"<<endl;
        cin>>num;
    }
    return num;
}
//function to generate public key
unsigned long long int publicKey(unsigned long long int phi, unsigned long long int n,unsigned long long int e)
{
    int mod;
    while(e<phi&&e>1)
    {
        mod = phi%e;
        if (mod==0)
        {
            return e;
        }
        else
        {
            phi=e;
            e=mod;
        }
    }
}
unsigned long long int privateKey(unsigned long long int e,unsigned long long int d,unsigned long long int phi)
{
    while(d<phi)
    {
        if((e*d)%phi==1)
        {
            return d;
        }
        else
        {
            d++;
        }
    }
}

unsigned long long int encryptionFun(unsigned long long int e,unsigned long long int message,unsigned long long int cipher,unsigned long long int n)
{
    cipher = pow(message,e);
    cipher = cipher%n;
    cout<<"ciphered hash digest is : "<<cipher;
    return cipher;

}

void decryptionFun(unsigned long long int d,unsigned long long int cipher,unsigned long long int n)
{
    cipher = pow(cipher,d);
    cipher = cipher%n;
    cout<<"deciphered hash digest is : "<<cipher;
}
#include<stdio.h> 
#include<iostream> 
#include<math.h> 
#include<bitset>
  
using namespace std; 
  

string toBin(long long int num){ 
    string bin = bitset<24>(num).to_string();
    return bin;
} 
  

long long int toDec(string bin){ 
    long long int num = 0; 
    for (int i=0; i<bin.length(); i++){ 
        if (bin.at(i)=='1') 
            num += 1 << (bin.length() - i - 1); 
    } 
    return num; 
} 
  

void CRC(string dataword, string generator){ 
    int l_gen = generator.length(); 
    long long int gen = toDec(generator); 
  
    long long int dword = toDec(dataword); 
  
    
    long long int dividend = dword << (l_gen-1);        

    int shft = (int) ceill(log2l(dividend+1)) - l_gen;   
    long long int rem; 
  
    while ((dividend >= gen) || (shft >= 0)){ 
        rem = (dividend >> shft) ^ gen;                 
        dividend = (dividend & ((1 << shft) - 1)) | (rem << shft); 
        shft = (int) ceill(log2l(dividend + 1)) - l_gen; 
    }  
    long long int codeword = (dword << (l_gen - 1)) | dividend; 
    cout << "Remainder: " << toBin(dividend) << endl; 
    cout << "Codeword : " << toBin(codeword) << endl; 
} 
  
int main(){ 
    string dataword, generator;
    int ch;
    cout << "Enter dataword" << endl;
    cin >> dataword;
    cout << "Enter generator" << endl;
    cin >> generator;
    cout << "Test for error Detection?" << endl;
    cout << "1. yes" << endl;
    cout << "2. no" << endl;
    cout << "Enter choice" << endl;
    cin >> ch;
    switch(ch){
      case 1:
        CRC(dataword, generator);
      break;
      case 2:
        cout << "No error detected" << endl;
      break;
    }
    return 0; 
} 


#include "HugeInt.h"

using namespace std;

HugeInt::HugeInt(int h){
    number.resize(100);
    if(h<0) exit(-1);
    int i = 0; 
    while(h){ // h:12345 -->  number[0]=5  number[1]=4    
        number[i] = h%10;
        h/=10;
        i++;
    }
}

HugeInt::HugeInt(string str){  // str:1234  -->  number[0]=4 , ... , number[3]=1
    number.resize(100);
    for (int i=0;i<number.size();i++){
        if (str.size() != 0){            
            number[i] = str.back() - '0';
            str.pop_back();
        }
    }
}

HugeInt HugeInt::operator+(const HugeInt& addend){ 
    HugeInt res = *this;
    int carry = 0;
    for (int i=0 ; i<number.size() ; i++){
        if ( (addend.number[i] + res.number[i])  > 9 ){
            res.number[i] = (addend.number[i] + res.number[i])%10+carry;
            carry = 1;
        }
        else{
            res.number[i] = (addend.number[i] + res.number[i]) + carry;
            carry = 0;
        }
    }
    if ( res.number[99] > 9 )
        exit(-1);
    return res;     
}

HugeInt HugeInt::operator-(const HugeInt& subtrahend){
    HugeInt res = *this;
    int carry = 0;
    bool check=false;

    // if res is bigger than subtrahend , check = true 
    for(int i=number.size()-1;i>=0;i--){  //  00000001233333 00000004566666
        if(res.number[i]==0 && subtrahend.number[i]==0)
            continue;
        else
        {
            if(res.number[i]>subtrahend.number[i])
                check = true;
            else
                check = false;
        }
    }

    if (check){ // res > subtrahend
        for (int i=0;i<number.size();i++){
            if ( (res.number[i] - subtrahend.number[i] - carry)  < 0  ){
                res.number[i] = res.number[i] - subtrahend.number[i]- carry + 10;
                carry = 1;
            }
            else{
                res.number[i] = res.number[i] - subtrahend.number[i] - carry;
                carry = 0;
            }
        }
        return res;
    }
    else{ // res < subtrahend
        for (int i=0;i<number.size();i++){
            if ((subtrahend.number[i] - carry - res.number[i])< 0){
                res.number[i] = subtrahend.number[i] - res.number[i] - carry + 10;
                carry = 1;
            }
            else{
                res.number[i] = subtrahend.number[i]  - res.number[i] - carry;
                carry = 0;
            }
        }
        cout <<"-";
        return res;
    }
}

HugeInt& HugeInt::operator=(const HugeInt& right){
    if (&right != this){
        for (int i=0;i<number.size();i++)
            this -> number[i] = right.number[i];  
    }
    return *this;
}

istream& operator>>(istream& in ,HugeInt& h ){
    string input_buffer;
    in >> input_buffer;
    h = HugeInt(input_buffer);
    return in;
} 

ostream& operator << (ostream& out ,HugeInt& n){
    int i ;
    for (i=n.number.size()-1;i>0;i--) // 000000123  123
        if (n.number[i] != 0)
            break;
    for (;i>=0;i--)
        out <<  n.number[i];
    return out;
}
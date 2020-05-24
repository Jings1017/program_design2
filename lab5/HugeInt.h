#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class HugeInt{

    public:
        HugeInt(int h=0);
        HugeInt(string);

        HugeInt  operator+(const HugeInt&);
        HugeInt  operator-(const HugeInt&); 
        HugeInt &operator=(const HugeInt&);

        friend ostream & operator<<(ostream&,HugeInt&); 
        friend istream & operator>>(istream&,HugeInt&); 

    private:
        vector<int> number;
};
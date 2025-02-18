// test program of recursive bitwise shift counter for determining number of bits in a heavenlyText 'character'
// will implement the rest tomorrow. i'm getting sleepy.

#include <iostream>
#include <cstdint>
using namespace std;

// example bytes to showcase functionality
uint8_t a{0b01100100};
uint8_t b{0b11101110};
uint8_t c{0b01100101};

uint8_t bytes[] {a, b, c};

// global count variables (this will break so make it not global plz)
int count{0};
int globalx{0};

// returns bit in counter byte
int checkBit(int x, int y)
{
    if (x & (1 << y)) { return 1; }
    else { return 0; }
}

// uUGHH
// pass in the target byte, current 'value' to reference if shift occurred, and the bit being referenced
void shift(int target, int shiftval, int spot)
{       
    if (spot < 8) 
    {
        int x = checkBit(target, spot);
        if (shiftval ^ x) // okay IF THERE IS A CHANGE -> print how many bits were in a row and move on
        {
            shiftval = x; 
            cout << "switched after " << count << " bit(s)\n"; 
            count = 1;
            shift(target, shiftval, ++spot);
        }
        else { // IF THERE IS NO CHANGE: move it along
            count++; 
            shift(target, shiftval, ++spot);
        }
    } else {
		globalx = shiftval;
	}
}

// checkByte() is just to print the whole byte so you can see it OHHH THAT's WHY checkBit() IS SEPARATE
void checkByte(int z) 
{
    for (int i{}; i < 8; i++) {
        cout << checkBit(z, i);
        "/n";
    }
}

int main() 
{
	for (int i : bytes)
	{
		shift(i, globalx, 0);
		cout << "reached end of byte with " << count << " remaining bit(s) (value " << globalx << ")\n";
	}
    return 0;
}

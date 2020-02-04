#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char number[15];
    int time = 0;
    cin >> number;
    
    for(int i=0, n=strlen(number); i<n; i++) {
        switch(number[i]) {
            case 'A':
            case 'B':
            case 'C':
                time += 3;
                break;
            case 'D':
            case 'E':
            case 'F':
                time += 4;
                break;
            case 'G':
            case 'H':
            case 'I':
                time += 5;
                break;
            case 'J':
            case 'K':
            case 'L':
                time += 6;
                break;
            case 'M':
            case 'N':
            case 'O':
                time += 7;
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                time += 8;
                break;
            case 'T':
            case 'U':
            case 'V':
                time += 9;
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                time += 10;
                break;
            default:
                time += 0;
        }
    }
    
    cout << time << endl;
    
    return 0;
}

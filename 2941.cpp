#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[100];
    int cnt = 0;
    cin >> s;
    
    for(int i=0, n=strlen(s); i<n; i++) {
        switch(s[i]) {
            case 'c':
                if((s[i+1]=='=' || s[i+1]=='-') && i < n-1)
                    i += 1;
                break;
            case 'd':
                if((s[i+1]=='z' && s[i+2]=='=') && i < n-2)
                   i += 2;
                else if((s[i+1] == '-') && i < n-1)
                    i += 1;
                break;
            case 'l':
                if((s[i+1] == 'j') && i < n-1)
                    i += 1;
                break;
            case 'n':
                if((s[i+1] == 'j') && i < n-1)
                    i += 1;
                break;
            case 's':
                if((s[i+1] == '=') && i < n-1)
                    i += 1;
                break;
            case 'z':
                if((s[i+1] == '=') && i < n-1)
                    i += 1;
                break;
            default:
                break;
        }
        cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}

/*
č	c=
ć	c-
dž	dz=
đ	d-
lj	lj
nj	nj
š	s=
ž	z=
*/

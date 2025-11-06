#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cout << "  BUFFER OVERFLOW  PROG II" <<endl;
    
    
    struct {
        char buffer[8];
        int isAdmin;
    } data;
    
    data.isAdmin = 0;  
    memset(data.buffer, 0, 8);  
    
    cout << "Memory Layout:" <<endl;
    cout << "buffer  starts at: " << (void*)data.buffer <<endl;
    cout << "isAdmin is at:     " << (void*)&data.isAdmin <<endl;
    cout << "Distance: " << ((char*)&data.isAdmin - data.buffer) << " bytes" <<endl;
    
    cout << "Before overflow:" <<endl;
    cout << "isAdmin = " <<data.isAdmin<<endl;
    
    char userInput[100];
    cout<<"Enter your name (try 9+ characters): ";
    cin.getline(userInput, 100);
    
    cout << "You entered " << strlen(userInput) << " characters" <<endl;
    
    
    strcpy(data.buffer, userInput);
    
    cout << "After overflow:" <<endl;
    cout << "buffer = " << data.buffer<<endl;
    cout << "isAdmin = " << data.isAdmin<<endl;
    
    if (data.isAdmin != 0) {
        cout << "================================" <<endl;
        cout << "================================" << endl;
        cout << "ADMIN ACCESS GRANTED!" <<endl;
        cout << "SYSTEM HACKED!" <<endl;
    } else {
        cout << "No admin access yet." <<endl;
        cout << "Try entering MORE characters (at least 9)!"<<endl;
    }
    
    return 0;
}
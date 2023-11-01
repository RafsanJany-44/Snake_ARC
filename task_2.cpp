#include <iostream>
using namespace std;
int main() {
 string userId;
 string userPass;
 int attempt = 0;
 while (attempt < 3) {
 cout << "Enter your user ID: ";
 cin >> userId;
 cout << "Enter your user password: ";
 cin >> userPass;
 if (userId == "eazzy" && userPass == "heyu") {
 cout << "Welcome back to ... well, whatever this is!" << 
endl;
 break;
 } else {
 cout << "Incorrect user ID or password. Please try 
again." << endl;
 attempt++;
 }
 }

 if (attempt == 3) {
 cout << "You blind, 3 wrong attempts. Access denied." << 
endl;
 }
 return 0;
}
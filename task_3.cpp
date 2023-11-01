#include <iostream>
using namespace std;
int main() {
 int choice;
 double quiz, performance, labTask, attendance, 
finalExam;
 while (true) {
 cout << "Teacher Menu:" << endl;
 cout << "1. View Grading Policy" << endl;
 cout << "2. Calculate Grade" << endl;
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
11
 cout << "Grading Policy:" << endl;
 cout << "Quiz: 20%" << endl;
 cout << "Performance: 20%" << endl;
 cout << "Lab Task: 20%" << endl;
 cout << "Attendance: 10%" << endl;
 cout << "Final Term Exam: 30%" << endl;
 break;
 case 2:
 cout << "Enter marks for the following 
components:" << endl;
 cout << "Quiz: ";
 cin >> quiz;
 cout << "Performance: ";
 cin >> performance;
 cout << "Lab Task: ";
12
 cin >> labTask;
 cout << "Attendance: ";
 cin >> attendance;
 cout << "Final Term Exam: ";
 cin >> finalExam;
 double overallMarks = (quiz * 0.20) + 
(performance * 0.20) + (labTask * 0.20) + (attendance * 0.10) + 
(finalExam * 0.30);
 char grade;
 if (overallMarks >= 90) {
 grade = 'A';
 } else if (overallMarks >= 80) {
 grade = 'B';
 } else if (overallMarks >= 70) {
 grade = 'C';
13
 } else if (overallMarks >= 60) {
 grade = 'D';
 } else {
 grade = 'F';
 }
 cout << "Overall Marks (out of 100): " << 
overallMarks << endl;
 cout << "Equivalent Grade: " << grade << endl;
 break;
 }
 }
 return 0;
}

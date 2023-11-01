#include <iostream>
using namespace std;
int main()
{
 int choice;
 char continueChoice;
 do {
 cout << "Teacher's Menu: " <<endl;
 cout << "1. View Grading Policy" << endl;
 cout << "2. Calculate Grade" << endl;
 cout << "Enter your choice: ";
 cin >> choice;
 cout<<endl;
 if (choice == 1)
 {
 cout << "Grading Policy:" << endl;
 cout << "Quizzes: 30 marks" << endl;
 cout << "Performance: 10 marks" << endl;
 cout << "Lab Tasks: 10 marks" << endl;
 cout << "Attendance: 10 marks" << endl;
 cout << "Final Term Exam: 40 marks" << endl;
 }
 else if (choice == 2)
 {
 int quizMarks, performanceMarks, labTaskMarks, attendanceMarks, finalTermExamMarks;
 float totalMarks;
 string grade;
 cout << "Enter quiz marks out of 30: ";
 cin >> quizMarks;
 cout << "Enter performance marks out of 10: ";
 cin >> performanceMarks;
 cout << "Enter lab task marks out of 10: ";
 cin >> labTaskMarks;
 cout << "Enter attendance marks out of 10: ";
 cin >> attendanceMarks;
 cout << "Enter final term exam marks out of 40: ";
 cin >> finalTermExamMarks;
 totalMarks = (quizMarks) + (performanceMarks) + (labTaskMarks) + (attendanceMarks ) + 
(finalTermExamMarks);
 if(totalMarks > 100)
 {
 grade="Invalid Grade";
 }
 else if (totalMarks < 0)
 {
 grade="Invalid Grade";
 }
 else if (totalMarks >= 80)
 {
 grade = "A";
 }
 else if (totalMarks >= 70)
 {
 grade = "B";
 }
 else if (totalMarks >= 60)
 {
 grade = "C";
 }
 else if (totalMarks >= 50)
 {
 grade = "D";
 }
 else
 {
 grade = "F";
 }
 cout << "Obtained Marks: " << totalMarks << endl;
 cout << "Grade: " << grade << endl;
 }
 else
 {
 cout << "Invalid choice" << endl;
 }
 cout<<endl;
 cout << "Do you want to continue? (y/n): ";
 cin >> continueChoice;
 }
 while (continueChoice == 'y' || continueChoice == 'Y');
 if (continueChoice == 'n' || continueChoice == 'N' )
 {
 cout<<"Thank you for your cooperation!"<<endl;
 }
 r
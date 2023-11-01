#include <iostream>
using namespace std;
int main()
{
int english;
int physics;
int biology;
int programming;
int history;

double englishCGPA;
double physicsCGPA;
double biologyCGPA;
double programmingCGPA;
double historyCGPA;


cout<<"Mark of English: ";
cin>>english;
if(english>=80)
{
cout<<"English Grade: A"<<endl<<endl;
englishCGPA = 4.00;
}
else if(english>=70)
{
cout<<"English Grade: B"<<endl<<endl;
englishCGPA = 3.75;
}
else if (english>=60)
{
cout<<"English Grade: C"<<endl<<endl;
englishCGPA = 3.50;
}
else if(english>=50)
{
cout<<"English Grade: D"<<endl<<endl;
englishCGPA = 3.00;
}
else
{
cout<<"English Grade: F"<<endl<<endl;
englishCGPA = 2.00;
}



cout<<"Mark of Physics: ";
if(physics>=80)
{
cout<<"Physics Grade: A"<<endl<<endl;
physicsCGPA = 4.00;
}
else if(physics>=70)
{
cout<<"Physics Grade: B"<<endl<<endl;
physicsCGPA = 3.75;
}
else if (physics>=60)
{
cout<<"Physics Grade: C"<<endl<<endl;
physicsCGPA = 3.50;
}
else if(physics>=50)
{
cout<<"Physics Grade: D"<<endl<<endl;
physicsCGPA = 3.00;
}
else
{
cout<<"Physics Grade: F"<<endl<<endl;
physicsCGPA = 2.00;
}


cout<<"Mark of Biology: ";
cin>>biology;
if(biology>=80)
{
cout<<"Biology Grade: A"<<endl<<endl;
biologyCGPA  = 4.00;
}
else if(biology>=70)
{
cout<<"Biology Grade: B"<<endl<<endl;
biologyCGPA = 3.75;
}
else if (biology>=60)
{
cout<<"Biology Grade: C"<<endl<<endl;
biologyCGPA  = 3.50;
}
else if(biology>=50)
{
cout<<"Biology Grade: D"<<endl<<endl;
biologyCGPA  = 3.00;
}
}
else
{
cout<<"Biology Grade: F"<<endl<<endl;
biologyCGPA= 2.00;
}


cout<<"Mark of Programming: ";
cin>>programming;
if(programming>=80)
{
cout<<"Programming Grade: A"<<endl<<endl;
programmingCGPA= 4.00;
}
else if(programming>=70)
{
cout<<"Programming Grade: B"<<endl<<endl;
programmingCGPA = 3.75;
}
else if (programming>=60)
{
cout<<"Programming Grade: C"<<endl<<endl;
programmingCGPA  = 3.50;
}
else if(programming>=50)
{
cout<<"Programming Grade: D"<<endl<<endl;
programmingCGPA = 3.00;
}
else
{
cout<<"Programming Grade: F"<<endl<<endl;
programmingCGPA= 2.00;
}


cout<<"Mark of History: ";
cin>>history;
if(history>=80)
{
cout<<"History Grade: A"<<endl<<endl;
historyCGPA= 4.00;
}
else if(history>=70)
{
cout<<"History Grade: B"<<endl<<endl;
historyCGPA = 3.75;
}
else if(history>=60)
{
cout<<"History Grade: C"<<endl<<endl;
historyCGPA= 3.00;
}
else if(programming>=50)
{
cout<<"History Grade: D"<<endl<<endl;
historyCGPA= 3.00;
}
else
{
cout<<"History Grade: F"<<endl<<endl;
historyCGPA= 2.00;
}


//Overall CGPA
double CGPA;
CGPA=(engCGPA+phyCGPA+bioCGPA+proCGPA+histCGPA)/5;
cout<<"Your average CGPA is= "<<CGPA<<endl<<endl;
cout<<"Believe in yourself and keep pushing!";
return 0;
}
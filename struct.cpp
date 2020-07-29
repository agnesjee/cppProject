#include <iostream>
#include <string>
using namespace std;

struct student {
string name;
int age;
student *what;
};

void display1(student s) {
cout << "Student Name " << s.name << endl;
cout << "Student Age " << s.age << endl;
}

void display2(student *s) {
cout << "Student Name " << s->name << endl;
cout << "Student Age " << s->age << endl;
}

int main() {
student s1, s2, *s3;
s3 = new student;
s1.name ="Mamat";
s1.age = 22;
s2.name ="Minah";
s2.age = 33;
s3->name ="Joyah";
s3->age = 44;
display1(s1);
display1(s2);
display2(s3);
s1.what = &s2;
s3->what = &s1;
display2(s1.what);
display2(s3->what);

return 0;
}

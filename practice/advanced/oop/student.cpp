#include <iostream>
using namespace std;

// class is a template/blueprint that defines the 
// properties and functionalities of an object

// default access modifier is private

class Student {
    public:
    int roll_no;

    // class funcs can access private vars
    void display() {
        cout << age << " " << roll_no << endl;
    }

    // setters for private props
    void set_age(int a) {
        age = a;
    }

    // getters for private props
    int get_age() {
        return age;
    }
    
    private:
    int age;
};

int main () {
    // static allocation
    Student ss1, ss2;

    // dynamic allocation
    Student *s1 = new Student;
    Student *s2 = new Student;

    // accessing object props and funcs
    (*s1).roll_no = 34;
    (*s2).roll_no = 35;

    s1->roll_no = 23;
    s2->roll_no = 43;

    s1->set_age(19);
    s1->display();
}
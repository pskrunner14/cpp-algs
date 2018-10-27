#include <iostream>

using namespace std;

// class is a template/blueprint that defines the
// properties and functionalities of an object

// default access modifier is private

class Student {
  public:
    int roll_no;

    // default constructor
    Student() {
        cout << "Called Student defualt constructor!" << endl;
    }

    // paramaterized constructor
    // default constructor override
    Student(int roll_no, int age) {
        cout << "Called Student parameterized constructor!" << endl;
        // this is a pointer that holds the
        // address of the current object
        this->roll_no = roll_no;
        set_age(age);
    }

    // class funcs can access private vars
    void display() {
        cout << age << " " << roll_no << endl;
    }

    // setters for private props
    void set_age(int age) {
        // custom constraints
        if (age < 0) {
            cout << "age argument is invalid" << endl;
            return;
        }
        this->age = age;
    }

    // getters for private props
    int get_age() {
        return this->age;
    }

  private:
    int age;
};

int main() {
    // static allocation
    Student ss1, ss2 = Student(12, 23);

    // dynamic allocation
    Student *s1 = new Student; // or Student()
    Student *s2 = new Student(32, 43);

    // accessing object props and funcs
    (*s1).roll_no = 34;
    (*s2).roll_no = 35;

    s1->roll_no = 23;
    s2->roll_no = 43;

    s1->set_age(19);
    s1->display();

    // call copy constructor (default)
    Student *s1_copy = new Student(*s1);
    s1_copy->display();
}
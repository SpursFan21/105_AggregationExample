#include <iostream>
#include <string>
#include <vector>

// Forward declaration of the Student class
class Student;

// Teacher class
class Teacher {
private:
    std::string name;
    int teacherID;
    std::vector<Student*> students; // Aggregation: Teacher contains a collection of Student objects

public:
    Teacher(const std::string& name, int id) : name(name), teacherID(id) {}

    // Add a student to the teacher's list
    void addStudent(Student* student) {
        students.push_back(student);
    }

    // Display teacher details along with the list of students
    void displayDetails() {
        std::cout << "Teacher: " << name << " (ID: " << teacherID << ")" << std::endl;
        std::cout << "Students under this teacher:" << std::endl;
        for (const auto& student : students) {
            std::cout << "- " << student->getName() << " (ID: " << student->getStudentID() << ")" << std::endl;
        }
    }
};

// Student class
class Student {
private:
    std::string name;
    int studentID;

public:
    Student(const std::string& name, int id) : name(name), studentID(id) {}

    // Getter methods for student name and ID
    std::string getName() const {
        return name;
    }

    int getStudentID() const {
        return studentID;
    }
};

int main() {
    // Create instances of students
    Student student1("Alice", 101);
    Student student2("Bob", 102);

    // Create an instance of a teacher
    Teacher teacher("Mr. Smith", 201);

    // Associate students with the teacher
    teacher.addStudent(&student1);
    teacher.addStudent(&student2);

    // Display teacher and student details
    teacher.displayDetails();

    return 0;
}
/*
In this example:

We have a Teacher class and a Student class.

The Teacher class contains a collection of Student objects, which demonstrates aggregation. This means that a Teacher object is associated with one or more Student objects.

The addStudent method in the Teacher class allows adding students to the teacher's list.

In the main function, we create instances of students and a teacher, and then associate the students with the teacher using the addStudent method.

Finally, we display the teacher's details along with the list of students under that teacher.

This example illustrates aggregation by showing how a Teacher class aggregates Student objects as part of its composition.
*/
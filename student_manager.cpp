#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students] = Student(name, id, midterm, final);
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if(idx > -1)
    {
        for(int i = idx; i < num_of_students - 1; i++)
        {
            students[i] = students[i + 1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());

    students[idx].updateRecord
    (
        student.getName().c_str(), 
        student.getRecord().getMidterm(),
        student.getRecord().getFinal()
    );
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for(int idx = 0; idx < num_of_students; idx++)
    {
        if(students[idx].getID() == id)
        {
            return idx;
        }
    }

    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    int idx = 0;
    float best = students[idx].getRecord().getMidterm();

    for(int i = 1; i < num_of_students; i++)
    {
        if(best < students[i].getRecord().getMidterm())
        {
            best = students[i].getRecord().getMidterm();
            idx = i;
        }
    }

    return idx;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    int idx = 0;
    float best = students[idx].getRecord().getFinal();

    for(int i = 1; i < num_of_students; i++)
    {
        if(best < students[i].getRecord().getFinal())
        {
            best = students[i].getRecord().getFinal();
            idx = i;
        }
    }

    return idx;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    int idx = 0;
    float best = students[idx].getRecord().getTotal();

    for(int i = 1; i < num_of_students; i++)
    {
        if(best < students[i].getRecord().getTotal())
        {
            best = students[i].getRecord().getTotal();
            idx = i;
        }
    }

    return students[idx].getID();
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum = 0.0f;

    for(int i = 0; i < num_of_students; i++)
    {
        sum += students[i].getRecord().getMidterm();
    }

    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float sum = 0.0f;

    for(int i = 0; i < num_of_students; i++)
    {
        sum += students[i].getRecord().getFinal();
    }

    return sum / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float sum = 0.0f;

    for(int i = 0; i < num_of_students; i++)
    {
        sum += students[i].getRecord().getTotal();
    }

    return sum / num_of_students;
}
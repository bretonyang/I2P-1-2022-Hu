#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

//create a student list size n
Student* Create_(int n) {
    Student* students = (Student*)malloc(sizeof(Student) * n);
    for (int i = 0; i < n; i++) {
        students[i].name = (char*)malloc(sizeof(char) * 51);
    }
    return students;
}

// set value of the student's grade and name
void SetVal_(Student* students, int index, int grade, char name[]) {
    students[index].grade = grade;
    strcpy(students[index].name, name);
}

//compare the grades of the student, return 1 if id2 has higher priority than id1
int Compare_(Student* students, int id1, int id2) {
    if (students[id1].grade == students[id2].grade) {
        // compare name
        return strcmp(students[id2].name, students[id1].name);
    }
    else {
        // compare grade
        return students[id2].grade - students[id1].grade;
    }
}

//swap student
void Swap_(Student* students, int index_1, int index_2) {
    Student tmp = students[index_1];
    students[index_1] = students[index_2];
    students[index_2] = tmp;
}

//free the student list
void Free_(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        free(students[i].name);
    }
    free(students);
}

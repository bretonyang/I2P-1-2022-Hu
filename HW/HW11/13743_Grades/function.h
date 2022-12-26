typedef struct {
	int grade; 
	char* name;
} Student;

//create a student list size n
Student* Create_(int);
//set value of the student's grade and name
void SetVal_(Student*, int, int, char[]);
//compare the grades of the student, return 1 if id2 has higher priority than id1
int Compare_(Student*, int id1, int id2);
//swap student 
void Swap_(Student*, int, int);
//free the student list 
void Free_(Student*, int);




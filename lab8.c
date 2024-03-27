#include <stdio.h>
#include <string.h>

struct student {
    int id;          // student ID
    char name[20];   // first name of student
};


// find_name(name, arr, n, ids) searches for student(s) with given name in arr;
//   returns the number of students found and the array ids is updated to
//   contain the id numbers of those students
// requires: arr contains n students
//           students in arr have unique ids
//           ids points to enough memory to hold the found student ids
int find_name(char * name, struct student arr[], int n, int ids[]);


int main(void) {

    
    char command[5];
    int id;
    char name[20];
    int find_id;
    int student_ids[1001];
    struct student students[1001];
    int len_students = 0;
    while(1) {
        scanf("%s", &command);
        if (!strcmp(command, "add")) {
            scanf("%d %s", &id, name);
            struct student s = {id};
            strcpy(s.name, name);
            students[len_students] = s;
            
            len_students++;
        } else if (!strcmp(command, "find")) {
            scanf("%s", &name);
            find_id = find_name(name, students, len_students, student_ids);
            if (find_id == 0) {
                printf("Not found\n");
                return 0;
            }
            for (int i = 0; i < find_id; i++) {
                printf("%d\n", student_ids[i]);
            }
            return 0;
        }
    }
}


int find_name(char * name, struct student arr[], int n, int ids[]) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (!strcmp(name, arr[i].name)) {
            ids[index] = arr[i].id;
            index++;
        }
    }
    return index;
}
 
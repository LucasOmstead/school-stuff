#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct student {
    int id;          // student ID
    char * name;     // first name of student
};

// create_student(id, name) creates a new student record with given id and name;
//   allocates memory to store structure and name (caller must free with
//   free_student); returns a pointer to the structure, or NULL if memory
//   allocation fails
// requires: name points to a valid string
struct student * create_student(const int id, const char * name);

// change_name(s, new_name) renames the student s to have the name given by
//   new_name; returns true when the name was successfully changed
// requires: s points to a valid student and new_name points to a valid string
bool change_name(struct student * s, const char * new_name);

// free_student(s) frees the memory associated with the student record s
// requires: s is a student record created using dynamic memory allocation
void free_student(struct student * s);

// print_student() prints the ID and then the name of the given student s
//   the ID and name are separated by a single space and end with a newline
void print_student(const struct student * s);

int main(void) {
    // ====================================
    // Add Your Own Tests Using Assert Here
    // ====================================

    // ====================================================
    // Automatic Testing on Codeforces (DO NOT CHANGE THIS)
    // If the tests don't pass, update your functions
    // ====================================================
    struct student * lucas = create_student(110137402, "Lucas Omstead");
    assert(lucas->id == 110137402);
    assert(strcmp(lucas->name, "Lucas Omstead") ==  0);
    change_name(lucas, "Omstead");
    assert(strcmp(lucas->name, "Omstead") == 0);


    
    int id, namelen;
    scanf("%d", &id);
    scanf("%d", &namelen);
    char * sname = malloc(sizeof(char) * (namelen + 1));
    scanf("%s", sname);
    struct student * s = create_student(id, sname);
    free(sname);
    print_student(s);
    sname = malloc(sizeof(char) * (namelen + 1));
    scanf("%s", sname);
    change_name(s, sname);
    free(sname);
    print_student(s);
    free_student(s);
}


// create_student(id, name) creates a new student record with given id and name;
//   allocates memory to store structure and name (caller must free with
//   free_student); returns a pointer to the structure, or NULL if memory
//   allocation fails
// requires: name points to a valid string
struct student * create_student(const int id, const char * name) {
    struct student * s = (struct student *)malloc(sizeof(struct student));
    if (s == NULL) {
        return s;
    }
    s->id = id;
    s->name = malloc(sizeof(char) * (strlen(name)+1));
    if (s->name == NULL) {
        free(s);
        return NULL;
    }
    strcpy(s->name, name);
    return s; 
}

// change_name(s, new_name) renames the student s to have the name given by
//   new_name; returns true when the name was successfully changed
// requires: s points to a valid student and new_name points to a valid string
bool change_name(struct student * s, const char * new_name) {
    free(s->name);
    s->name = malloc(sizeof(char) * (strlen(new_name)+1));
    strcpy(s->name, new_name);
}

// free_student(s) frees the memory associated with the student record s
// requires: s is a student record created using dynamic memory allocation
void free_student(struct student * s) {
    free(s->name);
    free(s);
}

// print_student() prints the ID and then the name of the given student s
//   the ID and name are separated by a single space and end with a newline
void print_student(const struct student * s) {
    printf("%d %s\n", s->id, s->name);
}

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct snode {
  int id;
  char * name;
  struct snode * next;
};

struct slist {
  struct snode * front;
};

// create_list() returns an empty newly-created list of students
// note: caller must free using free_list
struct slist * create_list();

// insert_student(id, name, lst) attempts to add a student with given id and
//   name into the given list lst; if a student with that id is already in the
//   list then return false, otherwise lst is modified and true is returned
bool insert_student(int id, char name[], struct slist * lst);

// remove_student(id, lst) attempts to remove a student with given id from the
//   given list and free the memory allocated to that student; true is returned
//   if successful and false otherwise
bool remove_student(int id, struct slist * lst);

// find_student(id, lst) returns the name of the student with given id in the
//   given list lst in a dynamically-allocated string (that the caller must
//   free) or NULL if no student has that id
char * find_student(int id, struct slist * lst);

// free_list (lst) deallocates all memory associated with the given list lst
//   including the memory used by the student records in the list
void free_list(struct slist * lst);

// is_sorted(lst) returns true if a list is sorted or false if it isn't
bool is_sorted(struct slist * lst);

int main(void) {
    
    //first list, vacuously sorted
    struct slist * s1 = create_list();
    assert(is_sorted(s1));
    //second list, sorted
    struct slist * s2 = create_list();
    insert_student(1, "John", s2);
    insert_student(2, "Joe", s2);
    insert_student(3, "Jacob", s2); 
    assert(is_sorted(s2));
    //third list, unsorted
    struct slist * s3 = create_list();
    struct snode n3 = {2, "Joseph", NULL};
    struct snode n2 = {3, "Johnny", &n3};
    struct snode n1 =  {1, "Josephine", &n2};
    s3->front = &n1;
    assert(!is_sorted(s3));
    free_list(s1);
    free_list(s2);
    free(s3);
    

   struct slist * head = create_list();
   char command[20];
   int id;
   char name[30];
   bool success;
   scanf("%s", command);
   while (strcmp(command, "free") != 0) {
        if (!strcmp(command, "insert")) {
            scanf("%d %s", &id, name);
            success = insert_student(id, name, head);
            assert(is_sorted(head));
            printf(success ? "success\n" : "failure\n");
        } else if (!strcmp(command, "remove")) {
            scanf("%d", &id);
            success = remove_student(id, head);
            assert(is_sorted(head));
            printf(success ? "success\n" : "failure\n");
        } else if (!strcmp(command, "find")) {
            scanf("%d", &id);
            if (find_student(id, head) == NULL) {
                printf("failure\n");
            } else {
                printf("%s\n", find_student(id, head));
            }
            assert(is_sorted(head));
        } else {
            continue;
        }
        
        scanf("%s", command);
   }
   
   free_list(head);
   



}

struct slist * create_list() {
    struct slist * returnList = malloc(sizeof(struct slist));
    returnList->front = NULL;
    return returnList;
}

bool insert_student(int id, char name[], struct slist * lst) {
    
    int nameSize = strlen(name);
    
    struct snode * curNode = lst->front;
    if (lst->front && lst->front->id > id) {
        
        struct snode * s = malloc(sizeof(struct snode));
        s->id = id;
        s->name = malloc(sizeof(char) * (nameSize + 1));
        strcpy(s->name, name);
        s->next = NULL;
        lst->front = s;
        s->next = curNode;
        return true;
    }
    while (curNode) { 
        if (curNode->id == id) {
            return false;
        }
        
        if (!curNode->next || curNode->next->id > id) {
            
            struct snode * s = malloc(sizeof(struct snode));
            s->id = id;
            s->name = malloc(sizeof(char) * (nameSize + 1));
            strcpy(s->name, name);
            s->next = NULL;
            if (curNode->next) {
                struct snode * tmpNode = curNode->next;
                curNode->next = s;
                s->next = tmpNode;
            } else {
                curNode->next = s;
                s->next = NULL;
            }
            return true;
        }
        curNode = curNode->next;
    }
    struct snode * s = malloc(sizeof(struct snode));
    s->id = id;
    s->name = malloc(sizeof(char) * (nameSize + 1));
    strcpy(s->name, name);
    s->next = NULL;
    lst->front = s;
    
    return true;
    
   
}

bool remove_student(int id, struct slist * lst) {
    if (!lst->front) {
        return false;
    }
    struct snode * s = lst->front;
    struct snode * lastNode = NULL;
    struct snode * tmpNode = s;
    while (s) {
        
        if (s->id == id) {
            
            if (lastNode) {
                lastNode->next = s->next;
            } else {
                lst->front = s->next;
            }
            free(s->name);
            free(s);
            return true;
        }
        lastNode = s;
        s = s->next;
    }
    return false;
}

char * find_student(int id, struct slist * lst) {
    if (lst->front) { 
        struct snode * s = lst->front;
        while (s) {
            
            if (s->id == id) {
                char * returnName = malloc((strlen(s->name)+1) * sizeof(char));
                strcpy(returnName, s->name);
                return returnName;
            }
            s = s->next;
        }
    } else {
        return NULL;
    }
}

void free_list(struct slist * lst) {

    struct snode * s = lst->front;
    struct snode * tempnode = s;
    
    while (s) {
        tempnode = s->next;
        free(s->name);
        free(s);
        s = tempnode;
    }
    free(lst);
}

bool is_sorted(struct slist * lst) {
    if (!lst->front) {
        return true;
    } 
    struct snode * s = lst->front;
    int lastid = 0;
    while (s) {
        if (s->id < lastid) {
            return false;
        }
        lastid = s->id;
        s = s->next;
    }
    return true;
}
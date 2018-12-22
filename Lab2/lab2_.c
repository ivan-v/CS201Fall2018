#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// structs
struct node2d {
    struct node1d *first;
    char *name;
    struct node2d *down;
};
struct node1d {
    struct node1d *next;
    char *name;
};

// funs in this file
struct node1d *mk1dNode(char *name, struct node1d *next);
struct node2d *mk2dNode(struct node1d *first, char *name, struct node2d *down);
struct node2d *mkExConfig ();

void printConfig(struct node2d *p2d) {
    int count2d = 0;
    int count1d = 0;
    for (; p2d; p2d = p2d->down) {
        count2d++;
        printf("2d node name=%s\n", p2d->name);
        struct node1d *p1d = p2d->first;
        if (p1d) {
            do {
                count1d++;
                printf("\t1d node name=%s", p1d->name);
            } while ((p1d = p1d->next));
            printf("\n");
            printf("The number of 2d nodes is %d \n", count2d);
            printf("The number of 1d nodes is %d \n", count1d);
        }
    }
}

void print1d(struct node1d *p1d) {
    int count1d = 0;
    for (struct node1d *p = p1d; p; p = p->next) {
        count1d++;
        printf("\tThe %s 1d node has name %s",
                p == p1d ? "first" : "next",
                p->name);
    }
    printf("\n The number of 1d nodes is %d \n", count1d);
}

void print2d(struct node2d *p2d) {
    int count2d = 0;
    for (struct node2d *p = p2d; p; p = p->down) {
        count2d++;
        printf("The %s 2d node has name %s\n",
                p == p2d ? "first" : "next",
                p->name);
        if (p->first) {
            print1d(p->first);
            printf("\n");
        }
    }
    printf("The number of 2d nodes is %d \n", count2d);
}

void freeNode1d(struct node1d *p1d) {
    while (p1d) {
        struct node1d *next = p1d->next;
        free(p1d);
        p1d = next;
    }
}

void freeNode2d(struct node2d *p2d) {
    while (p2d) {
        struct node2d *down = p2d->down;
        freeNode1d(p2d->first);
        free(p2d);
        p2d = down;
    }
}

// memory for strings

#define STRING_ARENA_CAPACITY (1 << 20)
char string_arena[STRING_ARENA_CAPACITY];
char *string_arena_end = string_arena;

void string_arena_push(char c) {
    if (string_arena_end == string_arena + STRING_ARENA_CAPACITY) {
        fputs("error: no more room in statically allocated buffer", stderr);
        exit(1);
    }
    *string_arena_end++ = c;
}

// input

struct command {
    char *name2d;
    char *name1d;
};

int readIns() {
    int c = getchar();
    if (c                == 'I'
            && getchar() == 'n'
            && getchar() == 's'
            && getchar() == ' ') {
        return 0;
    } else if (c == EOF) {
        return 1;
    } else {
        fputs("error: first command must be \"Ins \"", stderr);
        exit(1);
    }
}

char *readName(int sentinel) {
    char *name = string_arena_end;
    for (int c = getchar(); c != sentinel; c = getchar()) {
        if (!isalnum(c)) {
            fputs("error: alphanumeric character expected", stderr);
            exit(1);
        }
        string_arena_push((char)c);
    }
    string_arena_push('\0');
    return name;
}

int readCommand(struct command *result) {
    if (readIns()) {
        return 1;
    }
    result->name2d = readName(' ');
    result->name1d = readName('\n');
    return 0;
}

// insertion
struct node2d *findNode2d(struct node2d *p2d, char *name) {
    while (p2d && strcmp(name, p2d->name) != 0) {
        p2d = p2d->down;
    }
    return p2d;
}

//returns 1 if the first name comes alphabetically before the second
//meaning that the newnode should NOT be inserted before oldnode
int nodecmp1d(char *oldnode1d, char *newnode1d) {
    if (strcmp(oldnode1d, newnode1d) > 0)
        return 1;
    else 
        return 0;
}

struct node2d *insertNode1d(struct node2d *p2d, char *name2d, char *name1d) {
    struct node2d *found = findNode2d(p2d, name2d);
    if (found) {
        if (found->first) {
            struct node1d *temp = found->first;
            struct node1d *q = NULL;
            //printf("Comparing %s to %s \n", temp->name, name1d);
             if (!nodecmp1d(temp->name, name1d)) {
                while (temp) {
                    //printf("Comparing %s to %s \n", temp->name, name1d);
                    if (!nodecmp1d(temp->name, name1d)) {
                        q = temp;
                        if (!(temp->next)) {
                            //printf("Inserting at end. \n");
                            q->next = mk1dNode(name1d, NULL);
                            return p2d;
                        } else {
                            temp = temp->next;
                            //printf("Cycling to %s \n", temp->name);
                        } 
                    } else {
                        //printf("Inserting at middle or end. \n");
                        q->next = mk1dNode(name1d, temp->next);
                        q->next->next = temp;
                        return p2d;
                    }
                }
                //printf("Inserting at end. \n");
                q->next = mk1dNode(name1d, temp->next);
                q->next->next = temp;
                return p2d; 
            } else {
                //printf("Inserting at beginning. \n");
                found->first = mk1dNode(name1d, found->first);
                return p2d;
            }
        } else {
            //printf("Inserting first 1dnode. \n");
            found->first = mk1dNode(name1d, NULL);
            return p2d;
        }
    } else {
        //printf("Have to create new 2dnode for the new 1dnode. \n");
        struct node1d *p1d = mk1dNode(name1d, NULL);
        return mk2dNode(p1d, name2d, p2d);
    }
}

// main
int main (int argc, char *argv[]) {
    struct node2d *p2d;
    p2d = mkExConfig();
    print2d(p2d);
    printf("%s \n", "Inserting the 1d nodes for part 4.");
    insertNode1d(p2d, "R2D2", "c3p0");
    insertNode1d(p2d, "R2D2", "cso");
    insertNode1d(p2d, "joe", "xy2");
    insertNode1d(p2d, "joe", "e342");
    insertNode1d(p2d, "joe", "sally");
    print2d(p2d);
    for (struct command names; readCommand(&names) == 0;) {
        p2d = insertNode1d(p2d, names.name2d, names.name1d);
    }
    print2d(p2d);
    freeNode2d(p2d);
    return 0;
}

struct node2d *mkExConfig() {
    struct node1d *p1d;
    struct node2d *p2d;
    
    // create rows from bottom to top
    
    // create bottom row from right to left
    //p1d = mk1dNode("c3pO", NULL);
    //p1d = mk1dNode("cso", p1d);
    p2d = mk2dNode(NULL, "R2D2", NULL);

    // create middle row
    p2d = mk2dNode(NULL, "alice", p2d);

    // create top row from right to left
    //p1d = mk1dNode("e342", NULL);
    //p1d = mk1dNode("sally", p1d);
    //p1d = mk1dNode("xy2", p1d);
    p2d = mk2dNode(NULL, "joe", p2d);

    return p2d;
}

struct node1d *mk1dNode(char *name, struct node1d *next) {
    struct node1d *p1d;
    p1d = (struct node1d *)malloc(sizeof(struct node1d));
    (*p1d).next = next;   // (*p1d). is long form
    p1d->next = next;     // common abbreviation
    p1d->name = name;
    //printf("Node inserted! \n");
    return p1d;
}

struct node2d *mk2dNode(struct node1d *first, char *name, struct node2d *down) {
    struct node2d *p2d;
    p2d = (struct node2d *)malloc(sizeof(struct node2d));
    p2d->first = first;
    p2d->name  = name;
    p2d->down  = down;
    return p2d;
}
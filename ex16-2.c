#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person Person_create(char *name, int age, int height, int weight) {

    struct Person p;

    p.name = strdup(name);
    p.age = age;
    p.height = height;
    p.weight = weight;

    return p;
}


void Person_print(struct Person p) {

    printf("Name: %s\n", p.name);
    printf("\tAge: %d\n", p.age);
    printf("\tHeight: %d\n", p.height);
    printf("\tWeight: %d\n", p.weight);
}

int main(int argc, char *argv[]) {

    //make two people structures
    struct Person joe = Person_create(
        "Joe Alex", 32, 64, 140);
    
    struct Person frank = Person_create(
        "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", &joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", &frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe.height += 20;
    joe.height -= 2;
    joe.weight += 40;
    Person_print(joe);

    frank.age += 20;
    frank.weight += 20;
    Person_print(frank);
    
    free(joe.name);
    free(frank.name);


    return 0;
}

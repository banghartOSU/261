 /*CS261- Assignment 1 - Q.1
 * Name: Thomas Banghart
 * Date: 06/29/2019
 * Solution description: Experimenting with memory allocation and structures
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_OF_STUDENTS 10

struct student{
    int id;
    int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* std = (struct student*)malloc(NUM_OF_STUDENTS*sizeof(struct student));
     
     /*Return the pointer*/
    return std;
}

int checkID(struct student* students, int idToCheck){
    int i;
    for(i = 0; i < NUM_OF_STUDENTS; i++){
        if(students[i].id == idToCheck){
            return 1;
        }
    }
    return 0;
}
void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/
    int i, id;
    for(i = 0; i < NUM_OF_STUDENTS; i++){
        do {
            id = (rand() % 10) + 1;
        } while (checkID(students, id));
        
        students[i].id = id;
        students[i].score = rand() % (100 + 1);
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;
    for(i = 0; i < NUM_OF_STUDENTS; i++){
        printf("ID:%d score:%d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i;
    int sum = 0;
    double avg;

    int min = students[0].score;
    int max = min;
    for(i = 0; i < NUM_OF_STUDENTS; i++){
        if (students[i].score <= min) {
            min = students[i].score;
        }
        else if (students[i].score >= max) {
            max = students[i].score;
        }
    sum += students[i].score;
    }
    
    avg = ((sum*1.0)/NUM_OF_STUDENTS);
    
    printf("Minimum  score: %d\n", min);
    printf("Max score: %d\n", max);
    printf("Average score: %.1f\n", avg);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    srand(time(NULL));
    struct student* stud = NULL;
    
    /*Call allocate*/
    stud = allocate();
    
    /*Call generate*/
    generate(stud);
    
    /*Call output*/
    output(stud);
    
    /*Call summary*/
    summary(stud);
    
    /*Call deallocate*/
    deallocate(stud);

    return 0;
}


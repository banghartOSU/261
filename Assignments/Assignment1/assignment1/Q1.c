 /*CS261- Assignment 1 - Q.1
 * Name: Thomas Banghart
 * Date: 06/29/2019
 * Solution description: Experimenting with memory allocation and structures
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define num_of_students 10

struct student{
    int id;
    int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* std = (struct student*)malloc(num_of_students*sizeof(struct student));
     
     /*Return the pointer*/
    return std;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/
    int i;
    for(i = 0; i < num_of_students; i++){
        students[i].id = ( rand() % 10) + 1;
        students[i].score = (rand() % 100) + 1;
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
    for(i = 0; i < num_of_students; i++){
        printf("ID:%d score:%d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i;
    int sum = 0;
    double avg;
    //Get minimum
    int min = students[0].score;
    for(i = 1; i < num_of_students; i++){
        if (students[i].score <= min) {
            min = students[i].score;
        }
    }
    printf("Minimum  score: %d\n", min);
    //Get maximum
    int max = min;
    for(i = 0; i < num_of_students; i++){
        if (students[i].score >= max) {
            max = students[i].score;
        }
    }
    printf("Max score: %d\n", max);
    //Get average
    for(i = 0; i < num_of_students; i++){
        sum += students[i].score;
    }
    avg = ((sum*1.0)/num_of_students);
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


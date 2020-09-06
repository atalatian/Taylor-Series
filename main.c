#include <stdio.h>
#include <string.h>

int factorial(int number){
    int num = 1;
    int *num_pnt = &num;
    if (number == 0){
        return 0;
    } else if(number == 1){
        return 1;
    }
    for (int i = number; i > 1; --i) {
        *num_pnt = *num_pnt * i;
    }
    return *num_pnt;
}


int * makeFactorialArray(int **amount){
    int ans;
    static int factorial_answers[50];
    for (int i = 1; i <= **amount; ++i) {
        ans = factorial(i);
        factorial_answers[i-1] = ans;
    }
    return factorial_answers;
}


void taylor_series(int *amount,int answers[],int *roundPoint,char first_answer[50]){
    int *fac_ans_arr;
    char part[50];
    char final_answer[1000] = "";
    if(first_answer != "0"){
        strcat(final_answer,first_answer);
    }
    fac_ans_arr = makeFactorialArray(&amount);
    for (int i = 0; i < *amount; ++i) {
        if (answers[i] != 0){
            strcat(final_answer," + ");
            sprintf(part,"%i.(x-%i)^%i/%i!{%i}",answers[i],*roundPoint,i+1,i+1,fac_ans_arr[i]);
            strcat(final_answer,part);
        }
    }
    printf("%s",final_answer);
}



int main() {
    int amount = 0;
    int *amount_pnt = &amount;
    int point = 0;
    int *point_pnt = &point;
    char input_answer[50];
    char answer_round_point[50];
    int derivative_answers[] = {0,-1,0,1}; //for cos

    *amount_pnt = sizeof(derivative_answers)/sizeof(derivative_answers[0]);

    printf("Round which point? ");
    scanf("%i",point_pnt);

    printf("Enter The answer round %i: ",*point_pnt);
    scanf("%s",answer_round_point);

    taylor_series(&amount,derivative_answers,&point,answer_round_point);
    return 0;
}





















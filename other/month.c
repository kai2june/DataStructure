#include<stdio.h>

enum months {
    JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

int main(int argc, char* argv[]){
    enum months month;
    const char* monthName[] = {"", "January", "February", "March", "April", "May", 
    "June", "July", "August", "September", "October", "November", "December"};

    for( month = JAN; month <= DEC; month++){
        printf("%d means %s\n", month, monthName[month]);
    }  
    
    return 0;
}
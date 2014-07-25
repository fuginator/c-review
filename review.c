#include <stdio.h>

// Structs
struct employee {
  int idNum;
  float salary;
  char fName[20];
  char lName[20];
};

// Prototypes
int returnFive();
int findTextInQuotes(char* input, char* output, char* output2);
int increaseEmployeePay(struct employee* e, float percent);
void printEmployee(struct employee* e);

// Functions

int main() {
  printf("Andrew's C code review...\n");
  printf("This should read the number five: %d\n", returnFive());

  char str[50] = "I \"don't\" want a beer!";
  char str2[50];
  char str3[50];
  findTextInQuotes(str, str2, str3);

  printf("\nString: %s\nIn  Q: %s\nOut Q: %s\n", str, str2, str3);


  char str4[50] = "I left a \"quote open!";
  findTextInQuotes(str4, str2, str3);
  printf("\nString: %s\nIn  Q: %s\nOut Q: %s\n", str4, str2, str3);

  struct employee e1;
  e1.idNum = 12345;
  e1.salary = 3.14;
  printf("\ne1 Before Changes:\n");
  printEmployee(&e1);

  increaseEmployeePay(&e1, 10.0);
  printf("\ne1 After Changes:\n");
  printEmployee(&e1);

  return 0;
}

/* Print an employee */
void printEmployee(struct employee* e){
  printf("Employee ID: %d\n", e->idNum);
  printf("Employee Salery: %f\n", e->salary);
}

/* Modify data in a struct */
int increaseEmployeePay(struct employee* e, float percent){
  e->salary = (e->salary * (percent + 100) / 100);
  return 1;
}


/* Some basic string operations */
int findTextInQuotes(char* input, char* output, char* output2){
  int i = 0; // input pointer
  int j = 0; // output pointer
  int k = 0; // output2 pointer
  int q = 0; // in quotes

  while(input[i] != 0){
    if(input[i] == '"'){
      q = !q;  // flip 'in quotes'
    }
    if(q && input[i] != '"'){
      output[j++] = input[i];
    }
    else if(!q && input[i] != '"'){
      output2[k++] = input[i];
    }
    i++;
  }
  output[j] = 0;
  output2[k] = 0;

  return -q;   // if in quotes still, return an error
}

int returnFive(){
  return 5;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[100];
    float salary;
} Employee;

Employee payroll[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Payroll is full, cannot add more employees.\n");
        return;
    }
    
    Employee newEmployee;
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);
    getchar(); // consume newline
    printf("Enter employee name: ");
    fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = 0; // remove newline
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);
    
    payroll[employeeCount++] = newEmployee;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (employeeCount == 0) {
        printf("No employees in the payroll.\n");
        return;
    }
    printf("\nEmployees in the payroll:\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", payroll[i].id, payroll[i].name, payroll[i].salary);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEmployee Payroll Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
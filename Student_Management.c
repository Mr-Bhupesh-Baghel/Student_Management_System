#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    int id;
    char name[50];
    float marks;
};

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void modifyStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();

// Global variables
struct Student students[100];
int count = 0;

int main() {
    int choice;
    loadFromFile(); // Load data from file at the start

    while (1) {
        // Menu-driven program
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student\n");
        printf("5. Delete Student\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: saveToFile(); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to add a student
void addStudent() {
    if (count < 100) {
        printf("Enter Student ID: ");
        scanf("%d", &students[count].id);
        printf("Enter Name: ");
        scanf("%s", students[count].name);
        printf("Enter Marks: ");
        scanf("%f", &students[count].marks);
        count++;
        printf("Student Added Successfully!\n");
    } else {
        printf("Database Full!\n");
    }
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        printf("No Records Found!\n");
        return;
    }
    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

// Function to search a student by ID
void searchStudent() {
    int id, found = 0;
    printf("Enter Student ID to Search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student Not Found!\n");
}

// Function to modify student details
void modifyStudent() {
    int id, found = 0;
    printf("Enter Student ID to Modify: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter New Name: ");
            scanf("%s", students[i].name);
            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);
            printf("Student Updated Successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Student Not Found!\n");
}

// Function to delete a student
void deleteStudent() {
    int id, found = 0;
    printf("Enter Student ID to Delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student Deleted Successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Student Not Found!\n");
}

// Function to save data to file
void saveToFile() {
    FILE *file = fopen("students.dat", "wb");
    if (file) {
        fwrite(&count, sizeof(int), 1, file);
        fwrite(students, sizeof(struct Student), count, file);
        fclose(file);
        printf("Data Saved Successfully!\n");
    } else {
        printf("Error Saving Data!\n");
    }
}

// Function to load data from file
void loadFromFile() {
    FILE *file = fopen("students.dat", "rb");
    if (file) {
        fread(&count, sizeof(int), 1, file);
        fread(students, sizeof(struct Student), count, file);
        fclose(file);
    }
}

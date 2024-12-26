#include <stdio.h>
#include <string.h

struct Student{
    int id;
    char name[100];
    int age;
};
typedef struct Student Student;

void displayStudent(Student students[], int count);
void addStudent(Student students[], int *count);
void editStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);
void findStudent(Student students[], int count);
void sortStudent(Student students[], int count);

int main() {
    Student students[100];
    int count = 0;
    FILE *file = fopen(studentList.BIN, "rb");
        while (fread(&students[count], sizeof(Student), 1, file)) {
            count++;
        }
        fclose(file);
    }
    int choice;
    do {
        printf("\t Menu\n");
        printf("1. In danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                displayStudent(students, count);
                break;
            case 2:
                addStudent(students, &count);
                break;
            case 3:
                editStudent(students, count);
                break;
            case 4:
                deleteStudent(students, &count);
                break;
            case 5:
                findStudent(students, count);
                break;
            case 6:
                sortStudent(students, count);
                break;
            case 7:
                break;
        }
    } while (choice != 7);
    FILE *fileOut = fopen(studentList.BIN, "wb");
    if (fileOut != NULL) {
        fwrite(students, sizeof(Student), count, fileOut);
        fclose(fileOut);
    }
    return 0;
}

void displayStudent(Student students[], int count) {
        printf("Danh sach sinh vien:\n");
        for (int i = 0; i < count; i++) {
            printf("ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
}

void addStudent(Student students[], int *count) {
    Student newStudent;
    printf("Nhap ID sinh vien: ");
    scanf("%d", &newStudent.id);
    getchar();
    printf("Nhap ten sinh vien: ");
    fgets(newStudent.name, 100, stdin);
    fflush(stdin);
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &newStudent.age);
    students[*count] = newStudent;
    (*count)++;
    FILE *file = fopen(studentList.BIN, "wb");
    fwrite(students, sizeof(Student), *count, file);
    fclose(file);
}

void editStudent(Student students[], int count) {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Nhap ten moi cho sinh vien (ten cu: %s): ", students[i].name);
            getchar();
            fgets(students[i].name, 100_NAME_LENGTH, stdin);
            fflush(stdin);
            printf("Nhap tuoi moi cho sinh vien (tuoi cu: %d): ", students[i].age);
            scanf("%d", &students[i].age);
            FILE *file = fopen(studentList.BIN, "wb");
            fwrite(students, sizeof(Student), count, file);
            fclose(file);
            return;
        }
    }
    printf("Khong tim thay sinh vien ");
}

void deleteStudent(Student students[], int *count) {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            FILE *file = fopen(studentList.BIN, "wb");
            fwrite(students, sizeof(Student), *count, file);
            fclose(file);
            return;
        }
    }
    printf("Khong tim thay sinh vien ");
}

void findStudent(Student students[], int count) {
    int id;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Sinh vien tim thay: ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
            return;
        }
    }
    printf("Khong tim thay sinh vien ");
}

void sortStudent(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].id > students[j].id) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

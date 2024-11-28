#include <stdio.h>
#include<string.h>

#define MAX_ENTRIES 70
#define MAX_NAME_LENGTH 40

typedef struct {

char firstname[MAX_NAME_LENGTH];
char surname[MAX_NAME_LENGTH];
int age;

} Person;

void addEntry(Person list[], int *count) {
    if(*count>=MAX_ENTRIES ) {
    printf("Error the list can't add anymore");
    ;return ;
    }

printf("Enter first name :");
scanf("%39s", list[*count].firstname);
printf("Enter surname :");
scanf("%39s", list[*count].surname);
printf("Enter age :");
scanf("%lf",list[*count].age);
(*count)++;
printf("Entered sucessfully");

}

void findOldestPerson (Person list[], int count){
    // first check if the list is empty

    if(count==0){
        printf("The set is empty");
        return;
    }
int oldestIndex=0;
for(int i=1;i< count; i++){
    if(list[i].age > list[oldestIndex].age) {
        oldestIndex=i;
    }
}
printf("The oldest person is %s %s, Age: %d\n",
        list[oldestIndex].firstname,
        list[oldestIndex].surname,
        list[oldestIndex].age);
}

void printList(Person list[], int count) {
    if (count == 0) {
        printf("The list is empty.\n");
        return;
    }
    printf("Complete List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s %s, Age: %d\n",
               i + 1,
               list[i].firstname,
               list[i].surname,
               list[i].age);
    }
}

int main() {
    Person list[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1) Add new entry in the list\n");
        printf("2) Find the oldest person\n");
        printf("3) Print complete list\n");
        printf("0) Exit the program\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(list, &count);
                break;
            case 2:
                findOldestPerson(list, count);
                break;
            case 3:
                printList(list, count);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
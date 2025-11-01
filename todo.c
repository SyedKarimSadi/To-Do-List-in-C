#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    char name[100];
    int completed;
};

int main() {
    struct Task tasks[MAX_TASKS];
    int choice, count = 0, i;

    while (1) {
        printf("\n==== TO-DO LIST ====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        if (choice == 1) {
            if (count < MAX_TASKS) {
                printf("Enter task name: ");
                fgets(tasks[count].name, sizeof(tasks[count].name), stdin);
                tasks[count].name[strcspn(tasks[count].name, "\n")] = '\0';
                tasks[count].completed = 0;
                count++;
                printf("Task added!\n");
            } else {
                printf("Task list is full!\n");
            }
        } 
        else if (choice == 2) {
            printf("\nYour Tasks:\n");
            for (i = 0; i < count; i++) {
                printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? '?' : ' ', tasks[i].name);
            }
        } 
        else if (choice == 3) {
            int num;
            printf("Enter task number to mark completed: ");
            scanf("%d", &num);
            if (num > 0 && num <= count) {
                tasks[num - 1].completed = 1;
                printf("Task marked as completed!\n");
            } else {
                printf("Invalid task number!\n");
            }
        } 
        else if (choice == 4) {
            int num;
            printf("Enter task number to delete: ");
            scanf("%d", &num);
            if (num > 0 && num <= count) {
                for (i = num - 1; i < count - 1; i++) {
                    tasks[i] = tasks[i + 1];
                }
                count--;
                printf("Task deleted!\n");
            } else {
                printf("Invalid task number!\n");
            }
        } 
        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


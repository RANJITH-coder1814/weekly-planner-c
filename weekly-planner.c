#include <stdio.h>

char days[7][12] = {
    "Monday", "Tuesday", "Wednesday", "Thursday",
    "Friday", "Saturday", "Sunday"
};

typedef struct {
    int dd, mm, yy;
} Date;

struct Day {
    char day[12];
    Date date;       // Nested structure
    char activity[50];
} planner[7];

void readSchedule() {
    printf("\n--- Enter Weekly Schedule ---\n");

    for (int i = 0; i < 7; i++) {
        printf("\n%s - Enter date (dd/mm/yyyy): ", days[i]);
        scanf("%d/%d/%d",
              &planner[i].date.dd,
              &planner[i].date.mm,
              &planner[i].date.yy);

        printf("Activity: ");
        scanf(" %[^\n]", planner[i].activity);
    }

    printf("\nSchedule saved successfully!\n");
}

void displaySchedule() {
    printf("\n========== WEEKLY REPORT ==========\n");
    printf("%-12s %-12s %s\n", "Day", "Date", "Activity");
    printf("===========================================\n");

    for (int i = 0; i < 7; i++) {
        printf("%-12s %02d/%02d/%04d %s\n",
               days[i],
               planner[i].date.dd,
               planner[i].date.mm,
               planner[i].date.yy,
               planner[i].activity);
    }

    printf("===========================================\n");
}

int main() {
    int choice;

    printf("=== WEEKLY PLANNER ===\n");

    while (1) {
        printf("\n1. Enter Schedule\n2. Display Report\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readSchedule();
                break;
            case 2:
                displaySchedule();
                break;
            case 3:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

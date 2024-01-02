#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMINDERS 50

typedef struct Date {
    int dayNr;
    int month;
    int year;
    char reminder[20];
} Date;

Date reminders[MAX_REMINDERS];
int reminderCount = 0;

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 2: return isLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

void addReminder(int day, int month, int year, const char *rem) {
    if (reminderCount < MAX_REMINDERS) {
        reminders[reminderCount].dayNr = day;
        reminders[reminderCount].month = month;
        reminders[reminderCount].year = year;
        strncpy(reminders[reminderCount].reminder, rem, 19);
        reminderCount++;
    }
}

char *getReminder(int day, int month, int year) {
    for (int i = 0; i < reminderCount; i++) {
        if (reminders[i].dayNr == day && reminders[i].month == month && reminders[i].year == year) {
            return reminders[i].reminder;
        }
    }
    return NULL;
}

void printMonth(int month, int year) {
    int days = daysInMonth(month, year);
    printf("Month: %d, Year: %d\n", month, year);
    for (int day = 1; day <= days; day++) {
        char *rem = getReminder(day, month, year);
        if (day == 10 || day == 20) printf("\n");
        if (rem) {
            printf("%d*\t", day);
        } else {
            printf("%d\t", day);
        }
    }
    printf("\n");
}

int main() {
    addReminder(15, 1, 2024, "Doctor's Appointment");
    addReminder(20, 1, 2024, "Team Meeting");

    printMonth(1, 2024);

    return 0;
}

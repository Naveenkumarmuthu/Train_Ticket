#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define booking structure as a linked list node
struct BookingNode
{
    char name[50];
    int age;
    int trainN;
    int seat_no;
    char date[20];
    char time[20];
    struct BookingNode *next;
};
typedef struct BookingNode *Book;
Book head = NULL; 
int nexts = 1;    // global seat counter

// Fun to show available trains
void displayTrains()
{
    printf("\nAvailable Trains:\n");
    printf("1. 1001 - Chennai to Bangalore - 07:00 AM\n");
    printf("2. 1002 - Chennai to Delhi     - 10:00 AM\n");
    printf("3. 1003 - Chennai to Mumbai    - 01:00 PM\n");
}

// Fun to get current date and time
void getCurrentDateTime(char *date, char *time_str)
{
    time_t t = time(NULL);
    struct tm *dt = localtime(&t);
    strftime(date, 20, "%Y-%m-%d", dt);
    strftime(time_str, 20, "%H:%M:%S", dt);
}

// Fun to book a ticket
void bookTicket()
{
    Book newn = (Book)malloc(sizeof(struct BookingNode));
    if (!newn)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    getchar(); // clear newline
    printf("Enter your name: ");
    fgets(newn->name, sizeof(newn->name), stdin);
    newn->name[strcspn(newn->name, "\n")] = '\0'; // remove newline

    printf("Enter your age: ");
    scanf("%d", &newn->age);
    do
    {
        printf("Enter Train Number (1001, 1002, or 1003): ");
        scanf("%d", &newn->trainN);
        if (newn->trainN != 1001 && newn->trainN != 1002 && newn->trainN != 1003)
        {
            printf("Invalid Train Number. Please select a train from the list.\n");
        }
    } while (newn->trainN != 1001 && newn->trainN != 1002 && newn->trainN != 1003);

    newn->seat_no = nexts++;
    getCurrentDateTime(newn->date, newn->time);
    newn->next = NULL;

    // Add to the linked list
    if (head == NULL)
    {
        head = newn;
    }
    else
    {
        Book temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }

    printf("\nTicket booked successfully!\n");
    printf("Name     : %s\n", newn->name);
    printf("Age      : %d\n", newn->age);
    printf("Train No : %d\n", newn->trainN);
    printf("Seat No  : %d\n", newn->seat_no);
    printf("Date     : %s\n", newn->date);
    printf("Time     : %s\n", newn->time);
}

// Fun to view all booked tickets
void viewBookings()
{
    if (head == NULL)
    {
        printf("\nNo bookings found.\n");
        return;
    }

    Book temp = head;
    printf("\nBooked Tickets:\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Name\t\tAge\tTrain No\tSeat No\t\tDate\t\tTime\n");
    printf("----------------------------------------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%-15s\t%d\t%d\t\t%d\t\t%s\t%s\n",
               temp->name, temp->age, temp->trainN,
               temp->seat_no, temp->date, temp->time);
        temp = temp->next;
    }
}

// Fun to cancel a ticket by seat number
void cancelTicket()
{
    if (head == NULL)
    {
        printf("No tickets to cancel.\n");
        return;
    }

    int seat;
    printf("Enter seat number to cancel: ");
    scanf("%d", &seat);

    Book temp = head;
    Book prev = NULL;
    while (temp != NULL && temp->seat_no != seat)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Ticket with seat number %d not found.\n", seat);
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("Ticket with seat number %d has been canceled.\n", seat);
}

// Main menu
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Train Booking System ---\n");
        printf("1. View Available Trains\n");
        printf("2. Book Ticket\n");
        printf("3. View Booked Tickets\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayTrains();
            break;
        case 2:
            bookTicket();
            break;
        case 3:
            viewBookings();
            break;
        case 4:
            cancelTicket();
            break;
        case 5:
            printf("Thank you for using the system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

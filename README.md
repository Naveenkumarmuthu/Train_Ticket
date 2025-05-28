# Train Ticket Reservation System in C

This is a simple command-line based Train Ticket Reservation System written in C, using a singly linked list to manage ticket bookings.

## Features

- View list of available trains
- Book a train ticket
- View all booked tickets
- Cancel a ticket by seat number
- Real-time date and time recording for bookings

## Technologies Used

- C programming language
- Linked Lists (for managing bookings)
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `time.h`)

## How It Works

- When a user books a ticket, the system stores the passenger's name, age, selected train, and automatically generates a seat number and booking timestamp.
- All booking entries are stored dynamically using linked list nodes.
- Users can cancel bookings by entering the seat number.

## Usage

### Compile the Code

Make sure you have GCC installed. Then, compile using:

```bash
gcc train_p.c -o train_booking

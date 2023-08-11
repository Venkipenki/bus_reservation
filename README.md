# Bus Reservation System

This is a simple Bus Reservation System implemented in C++ using Object-Oriented Programming concepts. The program allows passengers to book seats in luxury and economy buses, preventing double bookings and displaying seat availability.

## Features

- Booking seats in luxury and economy buses
- Displaying available seats using a seat map
- Preventing double booking of seats
- User-friendly interface for passenger interaction

## How to Use

1. Clone the repository or download the code files.

2. Compile the code using a C++ compiler.

3. Run the compiled executable.

4. Follow the prompts to enter passenger details, choose a bus type, select a seat, and continue booking.

5. The program will display seat availability, prevent double bookings, and provide a user-friendly experience.

## Implementation Details

The system uses C++ classes to represent buses, passengers, tickets, and reservations. The program showcases inheritance and polymorphism by creating subclasses for different bus types (luxury, economy) and treating them as instances of a common superclass.

The `Bus` class contains methods to check seat availability, book seats, and display seat maps. The system also prevents double booking by keeping track of booked seats in a vector.

## Example Screenshots

Luxury Bus Seat Map:
1 2 3 4
5 6 7 8
...

javascript
Copy code

Economy Bus Seat Map:
1 2 3 4
5 6 7 8
...

csharp

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to use, modify, and distribute the code as per the terms of the license.

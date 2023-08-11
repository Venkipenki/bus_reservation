#include <iostream>
#include <vector>

class Passenger {
public:
    Passenger(const std::string& name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
};

class Ticket {
public:
    Ticket(const Passenger& passenger, int seatNumber)
        : passenger(passenger), seatNumber(seatNumber) {}

    const Passenger& getPassenger() const {
        return passenger;
    }

    int getSeatNumber() const {
        return seatNumber;
    }

private:
    Passenger passenger;
    int seatNumber;
};

class Bus {
public:
    Bus(int totalSeats) : totalSeats(totalSeats), availableSeats(totalSeats) {
        seats.reserve(totalSeats);
        for (int i = 0; i < totalSeats; ++i) {
            seats.push_back(false);
        }
    }

    bool checkAvailability() const {
        return availableSeats > 0;
    }

    bool bookSeat(const Passenger& passenger, int seatNumber) {
        if (seatNumber >= 1 && seatNumber <= totalSeats && !seats[seatNumber - 1]) {
            seats[seatNumber - 1] = true;
            availableSeats--;
            tickets.push_back(Ticket(passenger, seatNumber));
            return true;
        }
        return false;
    }

    bool isSeatBooked(int seatNumber) const {
        return seats[seatNumber - 1];
    }

    void displaySeats() const {
        for (int i = 0; i < totalSeats; ++i) {
            if (seats[i]) {
                std::cout << "X ";
            } else {
                std::cout << (i + 1) << " ";
            }
            if ((i + 1) % 4 == 0) {
                std::cout << "\n";
            }
        }
    }

protected:
    int totalSeats;
    int availableSeats;
    std::vector<bool> seats;
    std::vector<Ticket> tickets;
};

class LuxuryBus : public Bus {
public:
    LuxuryBus(int totalSeats) : Bus(totalSeats) {}
};

class EconomyBus : public Bus {
public:
    EconomyBus(int totalSeats) : Bus(totalSeats) {}
};

int main() {
    LuxuryBus luxuryBus(20);
    EconomyBus economyBus(40);

    while (true) {
        std::string passengerName;
        std::cout << "Enter passenger name: ";
        std::cin >> passengerName;

        Passenger passenger(passengerName);

        std::cout << "Select bus type: (1) Luxury, (2) Economy: ";
        int busType;
        std::cin >> busType;

        int selectedSeat;

        if (busType == 1) {
            if (luxuryBus.checkAvailability()) {
                std::cout << "Available seats in Luxury Bus:\n";
                luxuryBus.displaySeats();
                std::cout << "Enter seat number: ";
                std::cin >> selectedSeat;
                if (luxuryBus.isSeatBooked(selectedSeat)) {
                    std::cout << "Seat " << selectedSeat << " is already booked.\n";
                } else if (luxuryBus.bookSeat(passenger, selectedSeat)) {
                    std::cout << "Seat " << selectedSeat << " booked for " << passenger.getName() << " in Luxury Bus.\n";
                } else {
                    std::cout << "Invalid seat number.\n";
                }
            } else {
                std::cout << "No available seats in Luxury Bus.\n";
            }
        } else if (busType == 2) {
            if (economyBus.checkAvailability()) {
                std::cout << "Available seats in Economy Bus:\n";
                economyBus.displaySeats();
                std::cout << "Enter seat number: ";
                std::cin >> selectedSeat;
                if (economyBus.isSeatBooked(selectedSeat)) {
                    std::cout << "Seat " << selectedSeat << " is already booked.\n";
                } else if (economyBus.bookSeat(passenger, selectedSeat)) {
                    std::cout << "Seat " << selectedSeat << " booked for " << passenger.getName() << " in Economy Bus.\n";
                } else {
                    std::cout << "Invalid seat number.\n";
                }
            } else {
                std::cout << "No available seats in Economy Bus.\n";
            }
        } else {
            std::cout << "Invalid bus type selection.\n";
        }

        char continueBooking;
        std::cout << "Do you want to continue booking? (y/n): ";
        std::cin >> continueBooking;

        if (continueBooking != 'y' && continueBooking != 'Y') {
            break;
        }
    }

    return 0;
}

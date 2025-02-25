# FlightSync Management System

![FlightSync Logo](https://via.placeholder.com/150) <!-- You can replace this with an actual image or remove it -->

## Overview
Welcome to the **FlightSync Management System**, a C++ project developed as part of a Data Structures and Algorithms (DSA) course. This system is designed to manage flight schedules, passenger information, and booking records efficiently using advanced data structures and object-oriented programming (OOP) principles. It’s a practical demonstration of software engineering skills, including optimization, memory management, and error handling—skills relevant to a DevOps Intern role in automotive software development.

## Features
- Manage flight schedules, including adding, deleting, and searching flights.
- Handle passenger data, including registration and booking management.
- Optimize search operations using data structures like Binary Search Trees (BST), linked lists, and queues.
- Provide robust input validation and error handling for a user-friendly experience.
- Modular design using C++ classes for scalability and maintainability.

## Technologies Used
- **Programming Language**: C++ (C++11 or higher)
- **Data Structures**: Linked Lists, Stacks, Queues, Binary Search Trees (BST)
- **Tools**: Git (version control), CMake (optional for building), Valgrind (for memory debugging)
- **Development Environment**: Any C++-compatible IDE (e.g., Visual Studio Code, CLion)

## Installation and Usage

### Prerequisites
- C++ compiler (e.g., g++ on Linux/Mac, MSVC on Windows)
- CMake (optional, for building the project)
- Git (for cloning the repository)

### Steps to Run
1. **Clone the Repository**
   ```bash
   git clone https://github.com/ngophong010/FlightSync-Management-System.git
   cd FlightSync-Management-System
   ```

2. Build the Project
- If using CMake:
```bash
mkdir build
cd build
cmake ..
make
```
- Or, compile manually with g++:
```bash
g++ -o FlightSync src/*.cpp
```

3. Run the Program
```bash
./FlightSync
```
Follow the on-screen prompts to manage flights, passengers, and bookings.

### Notes
- Sample data files (e.g., data/flights.txt, data/passengers.txt) are included in the data/ folder for testing.
- Ensure you have read/write permissions for the data/ folder to save or load data.

## Folder Structure
```
FlightSync-Management-System/
├── src/                    # Source code (.cpp and .h files)
├── include/                # Header files
├── tests/                  # Unit tests (optional)
├── data/                   # Data files (.txt for flights, passengers, bookings)
├── docs/                   # Documentation (README, design docs)
├── build/                  # Build artifacts
├── .gitignore              # Git ignore file
├── CMakeLists.txt          # Build configuration
└── LICENSE                 # MIT License
```

## Contributing
This project is open-source under the MIT License. If you’d like to contribute, feel free to fork the repository, make improvements, and submit a pull request. I welcome suggestions for enhancing the system’s performance, adding new features, or improving the code structure.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Contact
- Author: Ngo Phong
- GitHub: ngophong010
- Email: [ngophong010@gmail.com]

If you have any questions or feedback, feel free to reach out or open an issue on GitHub!
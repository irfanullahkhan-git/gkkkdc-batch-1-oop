# Object-Oriented Programming in C++ - Part 1

This repository contains C++ code examples demonstrating fundamental Object-Oriented Programming (OOP) concepts. Part 1 covers basic class structures, constructors, pointers, references, and destructors.

---

## Table of Contents

1. [Basic Class Structure](#1-basic-class-structure)
2. [Default Constructor](#2-default-constructor)
3. [Parameterized Constructor](#3-parameterized-constructor)
4. [Pointers and References](#4-pointers-and-references)
5. [Copy Constructor](#5-copy-constructor)
6. [Destructor](#6-destructor)

---

## 1. Basic Class Structure
**File:** `1-basic.cpp`

### Definition
A **class** is a user-defined data type that encapsulates data members (attributes) and member functions (methods) into a single unit. It serves as a blueprint for creating objects.

### Key Concepts
- **Data Members:** Variables that store the state of an object
- **Member Functions:** Functions that define the behavior of an object
- **Object:** An instance of a class

### Example from Code
```cpp
class Student{
    public:
        // Data Members
        int rollNumber;
        string name;
        
        // Member functions
        void printDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rollNumber<<endl;
        }
};
```

### Usage
```cpp
Student s1;
s1.name = "Ali";
s1.rollNumber = 20;
s1.printDetails();
```

---

## 2. Default Constructor
**File:** `2-constructors.cpp`

### Definition
A **constructor** is a special member function that is automatically called when an object is created. A **default constructor** is one that takes no parameters and initializes object members with default values.

### Characteristics
- Same name as the class
- No return type (not even `void`)
- Automatically called when an object is created
- Used to initialize data members with default values

### Example from Code
```cpp
class Student{
    public:
        int rollNumber;
        string name;
        
        // Default Constructor
        Student(){
            rollNumber = 0;
            name = "Not Set";    
        }
        
        void printDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rollNumber<<endl;
        }
};
```

### Usage
```cpp
Student s1;  // Constructor automatically called
s1.printDetails();  // Output: Name: Not Set, Roll Number: 0
```

---

## 3. Parameterized Constructor
**File:** `3-parameterized-constructor.cpp`

### Definition
A **parameterized constructor** is a constructor that accepts parameters to initialize object members with specific values at the time of object creation.

### Types of Constructors
1. **Default Constructor** - No parameters
2. **Parameterized Constructor** - Takes parameters
3. **Copy Constructor** - Creates object from another object

### Key Features
- Allows initialization of objects with custom values
- Multiple parameterized constructors can exist (constructor overloading)
- Different parameter types and orders create different constructors

### Example from Code
```cpp
class Student{
    public:
        int rollNumber;
        string name;
        
        // Default Constructor
        Student(){
            rollNumber = 0;
            name = "Not Set";    
        }
        
        // Parameterized Constructor (string, int)
        Student(string n, int r){
            name = n;
            rollNumber = r;
        }
        
        // Parameterized Constructor (int, string)
        Student(int roll_no, string temp_name){
            name = temp_name;
            rollNumber = roll_no;
        }
};
```

### Usage
```cpp
Student s1;                    // Default Constructor
Student s2("Aslam", 22);      // Parameterized Constructor (string, int)
Student s3(30, "Ayaz");       // Parameterized Constructor (int, string)
```

---

## 4. Pointers and References
**File:** `4-pointers-reference.cpp`

### Definitions

#### Pointer
A **pointer** is a variable that stores the memory address of another variable. It can be reassigned to point to different variables.

#### Reference
A **reference** is an alias (alternative name) for an existing variable. Once initialized, it cannot be changed to refer to another variable.

### Key Differences

| Feature | Pointer | Reference |
|---------|---------|-----------|
| Syntax | `int *ptr = &a;` | `int &ref = num;` |
| Reassignment | Can point to different variables | Cannot be reassigned |
| Null value | Can be NULL | Must be initialized |
| Dereferencing | Uses `*` operator | Direct access |

### Example from Code

**Pointers:**
```cpp
int a = 10;
int *ptr = &a;
cout<<"Value of a: "<< *ptr<<endl;      // Output: 10
cout<<"Address: " << ptr<<endl;         // Output: Address of a

int b = 20;
ptr = &b;  // Pointer can be reassigned
cout<<"Value of b: "<< *ptr<<endl;      // Output: 20
```

**References:**
```cpp
int num = 15;
int &ref = num;  // ref is an alias for num
cout<<"The value of Num: "<< num << endl;  // Output: 15
cout<<"The value of Ref: "<< ref << endl;  // Output: 15

ref++;  // Modifying ref also modifies num
cout<<"The value of Num: "<< num << endl;  // Output: 16

int num2 = 20;
ref = num2;  // This assigns value, doesn't change reference
cout<<"The value of Num: "<< num << endl;  // Output: 20
```

---

## 5. Copy Constructor
**File:** `5-copy-constructor.cpp`

### Definition
A **copy constructor** is a special constructor that creates a new object as a copy of an existing object. It takes a reference to an object of the same class as its parameter.

### Characteristics
- Used to initialize an object from another object
- First parameter must be a reference to an object of the same class
- If not defined, compiler provides a default copy constructor (shallow copy)
- Syntax: `ClassName(ClassName &ref)`

### Why Use Reference Parameter?
The parameter must be passed by reference (`&`) to avoid infinite recursion. If passed by value, it would require copying the object, which would call the copy constructor again, leading to infinite recursion.

### Example from Code
```cpp
class Student{
    public:
        int rollNumber;
        string name;
        
        // Default Constructor
        Student(){
            rollNumber = 0;
            name = "Not Set";    
        }
        
        // Parameterized Constructor
        Student(string n, int r){
            name = n;
            rollNumber = r;
        }
        
        // Copy Constructor
        Student(Student &ref){
            name = ref.name;
            rollNumber = ref.rollNumber;
        }
        
        void printDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rollNumber<<endl;
        }
};
```

### Usage
```cpp
Student s1;
s1.name = "Ali";
s1.rollNumber = 20;

Student s4 = s1;  // Copy constructor called
s4.rollNumber = 31;
s4.printDetails();  // Output: Name: Ali, Roll Number: 31
```

---

## 6. Destructor
**File:** `6-oop-destructor.cpp`

### Definition
A **destructor** is a special member function that is automatically called when an object goes out of scope or is explicitly deleted. It is used to release resources and perform cleanup operations.

### Characteristics
- Same name as the class, prefixed with tilde (`~`)
- No return type and no parameters
- Only one destructor per class (cannot be overloaded)
- Automatically called when object is destroyed
- Called in reverse order of object creation
- Used for cleanup: releasing memory, closing files, etc.

### Example from Code
```cpp
class Student{
    public:
        int rollNumber;
        string name;
        int *marks;
        
        Student(string n, int r){
            name = n;
            rollNumber = r;
        }
        
        // Destructor
        ~Student(){
            cout<<"Object with name: "<<name
                <<" and Roll Number: "<<rollNumber
                <<" is destroyed\n";    
        }
        
        void printDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rollNumber<<endl;
        }
};
```

### Usage and Output
```cpp
int main(){
    Student s1("Ali", 20); 
    s1.printDetails();

    Student s2("Aslam", 22); 
    s2.printDetails();
    
    cout<<"\nMain function ends here\n";    
}
```

**Output:**
```
Name: Ali
Roll Number: 20
Name: Aslam
Roll Number: 22

Main function ends here
Object with name: Aslam and Roll Number: 22 is destroyed
Object with name: Ali and Roll Number: 20 is destroyed
```

Note: Destructors are called in reverse order - `s2` is destroyed before `s1`.

---

## Compilation Instructions

To compile any of the C++ files, use the following command:

```bash
g++ filename.cpp -o filename
```

For example:
```bash
g++ 1-basic.cpp -o 1-basic
g++ 2-constructors.cpp -o 2-constructors
```

To run the compiled program:
```bash
./filename        # On Linux/Mac
filename.exe      # On Windows
```

---

## Learning Path

Follow the files in numerical order for a progressive learning experience:

1. Start with basic class structure (`1-basic.cpp`)
2. Learn about constructors (`2-constructors.cpp`)
3. Explore parameterized constructors (`3-parameterized-constructor.cpp`)
4. Understand pointers and references (`4-pointers-reference.cpp`)
5. Master copy constructors (`5-copy-constructor.cpp`)
6. Learn about destructors (`6-oop-destructor.cpp`)

---

## Key Takeaways

### Constructor vs Destructor

| Feature | Constructor | Destructor |
|---------|-------------|------------|
| Purpose | Initialize objects | Cleanup resources |
| Name | Same as class | `~` + class name |
| Parameters | Can have parameters | No parameters |
| Overloading | Yes | No |
| When called | Object creation | Object destruction |
| Call order | Creation order | Reverse creation order |

### Constructor Types Summary

1. **Default Constructor:** No parameters, provides default initialization
2. **Parameterized Constructor:** Takes parameters for custom initialization
3. **Copy Constructor:** Creates copy from existing object

---

## License

This project is open source and available under the MIT License.

---

## Author

Created for educational purposes to teach fundamental OOP concepts in C++.


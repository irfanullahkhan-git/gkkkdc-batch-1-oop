# Object-Oriented Programming in C++ - Part 1

This repository contains C++ code examples demonstrating fundamental Object-Oriented Programming (OOP) concepts. Part 1 covers basic class structures, constructors, pointers, references, destructors, access specifiers, const functions, composition, aggregation, and inheritance.

---

## Table of Contents

1. [Basic Class Structure](#1-basic-class-structure)
2. [Default Constructor](#2-default-constructor)
3. [Parameterized Constructor](#3-parameterized-constructor)
4. [Pointers and References](#4-pointers-and-references)
5. [Copy Constructor](#5-copy-constructor)
6. [Destructor](#6-destructor)
7. [Access Specifiers](#7-access-specifiers)
8. [Const Functions](#8-const-functions)
9. [Composition](#9-composition)
10. [Aggregation](#10-aggregation)
11. [Inheritance](#11-inheritance)

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

## 7. Access Specifiers
**File:** `7-access-specifier.cpp`

### Definition
**Access specifiers** define the accessibility of class members (data members and member functions). They control how the members can be accessed from outside the class.

### Types of Access Specifiers

#### 1. Public
- Members are accessible from anywhere in the program
- Can be accessed using the object directly

#### 2. Private
- Members are only accessible within the class
- Cannot be accessed directly from outside the class
- Default access specifier for class members

#### 3. Protected (covered later)
- Members are accessible within the class and by derived classes

### Encapsulation
Encapsulation is the principle of bundling data and methods that operate on that data within a single unit (class), and restricting direct access to some components. This is achieved using access specifiers.

### Getters and Setters
- **Setters (Mutators):** Public methods used to modify private data members with validation
- **Getters (Accessors):** Public methods used to retrieve private data member values

### Example from Code
```cpp
class Student{
    private:
        int rollNumber;    // Private data members
        string name;
        
    public:
        Student(string n, int r){
            setName(n);
            setRollNo(r);
        }
        
        // Setter with validation
        void setName(string n){
            if(n == ""){
                cout<<"Error: The given name is invalid.\n";
            }else{
                name = n;
            }
        }
        
        void setRollNo(int r){
            if(r < 0){
                cout<<"Error: the given roll number is invalid\n";
            }else{
                rollNumber = r;
            }
        }
        
        // Getters
        int getRollNumber(){
            return rollNumber;
        }
        
        string getName(){
            return name;
        }
};
```

### Usage
```cpp
Student s1("", -20);      // Validation errors triggered
Student s2("Aslam", 22);  // Valid object creation
// s2.rollNumber = 50;    // ERROR: Cannot access private member
int roll = s2.getRollNumber();  // Correct way using getter
```

### Benefits
- **Data Hiding:** Protects data from unauthorized access
- **Validation:** Ensures data integrity through setter validation
- **Flexibility:** Can change internal implementation without affecting external code
- **Maintainability:** Easier to debug and maintain

---

## 8. Const Functions
**File:** `8-const-functions.cpp`

### Definition
A **const member function** is a function that promises not to modify any data members of the class. It is declared by placing the `const` keyword after the function signature.

### Characteristics
- Declared with `const` keyword after parameter list
- Cannot modify any data members of the class
- Can be called on both const and non-const objects
- Const objects can ONLY call const member functions
- Provides safety and clarity about function behavior

### Why Use Const Functions?
1. **Safety:** Prevents accidental modification of data
2. **Const Object Compatibility:** Allows const objects to use the function
3. **Code Clarity:** Indicates that the function is read-only
4. **Compiler Enforcement:** Compiler ensures no modifications occur

### Example from Code
```cpp
class Student{
    private:
        int rollNumber;
        string name;
        
    public:
        Student(string n, int r){
            setName(n);
            setRollNo(r);
        }
        
        // Non-const function - can modify data
        void setName(string n){
            if(n == ""){
                cout<<"Error: The given name is invalid.\n";
            }else{
                name = n;
            }
        }
        
        // Const function - cannot modify data
        void printDetails() const{
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rollNumber<<endl;
            // name = "Test";  // ERROR: Cannot modify in const function
        }
};
```

### Usage
```cpp
Student s1("Ali", 20);
s1.setName("Ali Khan");    // OK: Non-const object can call any function
s1.printDetails();         // OK: Can call const function

const Student s2("Aslam", 22);
// s2.setName("Test");     // ERROR: Const object cannot call non-const function
s2.printDetails();         // OK: Const object can call const function
```

### Key Rules

| Situation | Can Call Non-Const Function? | Can Call Const Function? |
|-----------|------------------------------|-------------------------|
| Non-const object | ✓ Yes | ✓ Yes |
| Const object | ✗ No | ✓ Yes |

---

## 9. Composition
**File:** `9-composition.cpp`

### Definition
**Composition** is a "has-a" relationship where one class contains objects of another class as data members. It represents a strong ownership relationship where the contained object cannot exist independently of the container.

### Characteristics
- Strong "has-a" relationship
- Lifetime dependency: Contained object is created when container is created
- Contained object is destroyed when container is destroyed
- Represents a "part-of" relationship
- Uses object as a data member (not pointer)

### Member Initializer List
A special syntax used to initialize data members and base class constructors before the constructor body executes.

**Syntax:**
```cpp
Constructor(parameters) : member1(value1), member2(value2) {
    // Constructor body
}
```

### Example from Code
```cpp
class Engine{
    int horsePower;
    string type;
    
    public: 
        Engine(int hp, string t) : horsePower(hp), type(t){
            cout<<"\nEngine object is being created\n";
        }
        
        ~Engine(){
            cout<<"\nEngine destroyed\n";
        }
        
        void displayEngineInfo(){
            cout<<"\nHorse Power: "<<horsePower<<"\nType: "<<type;
        }
};

class Car{
    string name;
    string company;
    string model;
    Engine engine;  // Composition: Car "has-a" Engine
    
    public:
        Car(string n, string c, string m, int hp, string t): 
            name(n), company(c), model(m), engine(hp, t){
            cout<<"\nCar object is being created\n";
        }
        
        ~Car(){
            cout<<"\nCar destroyed\n";
        }
        
        void displayCarinfo(){
            cout<<"\nCar Name: "<<name<<"\n";
            cout<<"\nCar Company: "<<company<<"\n";
            cout<<"\nCar Model: "<<model<<"\n";
            engine.displayEngineInfo();
        }
};
```

### Usage and Output
```cpp
Car c("Xyz", "Toyota", "2024", 1000, "petrol");
c.displayCarinfo();
```

**Output Order:**
```
Engine object is being created
Car object is being created
// ... display info ...
Car destroyed
Engine destroyed
```

**Note:** Engine is created first (before Car), and destroyed last (after Car).

### Key Points
- Engine cannot exist without Car in this design
- When Car is destroyed, Engine is automatically destroyed
- Member initializer list is used to initialize the Engine object
- Constructor and destructor order: Contained objects are constructed first, destroyed last

---

## 10. Aggregation
**File:** `10-aggregation.cpp`

### Definition
**Aggregation** is a "has-a" relationship where one class contains a reference or pointer to another class, but both objects can exist independently. It represents a weak ownership relationship.

### Characteristics
- Weak "has-a" relationship
- Objects have independent lifetimes
- Container holds a pointer/reference to the contained object
- Contained object can exist without the container
- Contained object is typically created outside the container

### Composition vs Aggregation

| Feature | Composition | Aggregation |
|---------|-------------|-------------|
| Relationship Type | Strong "has-a" | Weak "has-a" |
| Lifetime | Dependent | Independent |
| Ownership | Owned by container | Shared or external |
| Implementation | Object member | Pointer/reference member |
| Example | Car has Engine | Department has Teacher |

### Example from Code
```cpp
class Teacher{
    string name;
    string qualification;
    
    public:
        Teacher(string n, string q): name(n), qualification(q){
        }
        
        string getTeacherName(){
            return name;
        }
        
        string getTeacherQualification(){
            return qualification;
        }
        
        ~Teacher(){
            cout<<"Teacher object destroyed";
        }
};

class Department{
    string deptName;
    Teacher * teacher;  // Aggregation: Pointer to Teacher
    
    public:
        Department(string dn, Teacher * t): deptName(dn), teacher(t){
        }
        
        ~Department(){
            cout<<"Department object destroyed\n";
        }
        
        void displayDepartment(){
            cout<<"Department Name: "<<deptName<<endl;
            cout<<"Teacher Name: "<<teacher->getTeacherName()<<endl;
            cout<<"Teacher Qualificaiton: "<<teacher->getTeacherQualification()<<endl;
        }
};
```

### Usage
```cpp
Teacher t("Ali", "MS");           // Teacher created independently
Department d1("CS", &t);          // Department uses existing Teacher
Department * d2 = new Department("Physics", &t);  // Multiple departments share teacher

d2->displayDepartment();
delete d2;                        // Department destroyed, Teacher still exists

d1.displayDepartment();           // Teacher still accessible
```

### Key Points
- Teacher exists independently of Department
- Same Teacher can be associated with multiple Departments
- Destroying Department doesn't destroy Teacher
- Department doesn't own Teacher, just references it
- More flexible than composition

---

## 11. Inheritance
**File:** `11-inheritance.cpp`

### Definition
**Inheritance** is an "is-a" relationship where a class (derived/child class) inherits properties and behaviors from another class (base/parent class). It enables code reuse and establishes a hierarchical relationship between classes.

### Terminology
- **Base Class / Parent Class / Super Class:** The class being inherited from
- **Derived Class / Child Class / Sub Class:** The class that inherits

### Types of Inheritance Access

```cpp
class Derived : public Base      // Public inheritance (most common)
class Derived : private Base     // Private inheritance
class Derived : protected Base   // Protected inheritance
```

### Characteristics
- Promotes code reusability
- Establishes "is-a" relationship
- Derived class inherits all members except constructors and destructors
- Derived class can add new members specific to its needs
- Base class methods are automatically available in derived classes
- Supports polymorphism (covered in advanced topics)

### Constructor in Inheritance
- Base class constructor is called before derived class constructor
- Derived class must explicitly call base class constructor
- Use member initializer list to call base class constructor

### Example from Code
```cpp
class Person{
    string name;
    int age;
    
    public:
        Person(string n, int a): name(n), age(a){
        }
        
        void introduce(){
            cout<<"Name: "<<name<<" Age: "<<age<<endl;
        }
};

class Teacher : public Person{
    string subject;
    
    public: 
        Teacher(string n, int a, string s): Person(n, a), subject(s){
        }
        
        void teach(){
            cout<<"Subject: "<<subject<<endl;
        }
};

class Student: public Person{
    int rollNumber;
    
    public:
        Student(string n, int a, int r): Person(n, a), rollNumber(r){
        }
        
        void study(){
            cout<<"Roll No: "<<rollNumber<<endl;
        }
};
```

### Usage
```cpp
Teacher t("Ali", 35, "C++");
t.introduce();  // Inherited from Person
t.teach();      // Teacher-specific function

Student s("Aslam", 20, 101);
s.introduce();  // Inherited from Person
s.study();      // Student-specific function
```

### Inheritance Hierarchy

```
        Person
       /      \
   Teacher   Student
```

- Teacher "is-a" Person
- Student "is-a" Person
- Both inherit name and age from Person
- Both add their own specific members

### Benefits
- **Code Reusability:** Avoid duplicating common code
- **Extensibility:** Easy to add new derived classes
- **Maintainability:** Changes in base class reflect in all derived classes
- **Logical Hierarchy:** Models real-world relationships

### Key Points
- Derived class has all base class members plus its own
- Use `:` to specify inheritance
- Use member initializer list to call base class constructor
- Both Teacher and Student inherit `introduce()` method from Person
- Each derived class adds its own specific functionality (`teach()` and `study()`)

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
7. Understand access specifiers and encapsulation (`7-access-specifier.cpp`)
8. Learn about const functions (`8-const-functions.cpp`)
9. Explore composition relationships (`9-composition.cpp`)
10. Understand aggregation relationships (`10-aggregation.cpp`)
11. Master inheritance concepts (`11-inheritance.cpp`)

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

### Access Specifiers Summary

| Specifier | Class Members | Derived Class | Outside Class |
|-----------|--------------|---------------|---------------|
| Public | ✓ | ✓ | ✓ |
| Private | ✓ | ✗ | ✗ |
| Protected | ✓ | ✓ | ✗ |

### Relationships in OOP

| Relationship | Type | Syntax | Lifetime | Example |
|--------------|------|--------|----------|---------|
| Composition | "has-a" (strong) | Object member | Dependent | Car has Engine |
| Aggregation | "has-a" (weak) | Pointer/reference | Independent | Department has Teacher |
| Inheritance | "is-a" | Class derivation | N/A | Teacher is-a Person |

### OOP Principles Covered

1. **Encapsulation:** Data hiding using access specifiers
2. **Abstraction:** Hiding implementation details, exposing interface
3. **Inheritance:** Code reuse through class hierarchies
4. **Composition/Aggregation:** Building complex objects from simpler ones

---

## License

This project is open source and available under the MIT License.

---

## Author

Created for educational purposes to teach fundamental OOP concepts in C++.


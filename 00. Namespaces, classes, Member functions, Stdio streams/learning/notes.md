References: cplusplus.com/doc
### Words and Terms:
OOP: inheritance, polyphomism, encapsulation, abstraction
- Member functions, classes
- Stdio streams - std cin, std cout.
- static, const, namespaces
- virtual
- Constructors, copy a
- C++ keywords: const, class, delete, int, new, operator, return, private, protected, public, static, typedef
- Operator overload
- endl
- referencing and the &
- Compound types and fundamental types
- rhs?? lhs??
- 


#### Questions:
Initial Questions:
- How do l  create a class?
- How do l create an object?
- How do l add and create functions for a class?
- What does a C++ header file look like

cplusplus: Streams
 A stream is an entity where a program can either insert or extract characters to/from
 streams are a source/destination of characters, and that these characters are provided/accepted sequentially (i.e., one after another).
 Streams -- https://cplusplus.com/doc/tutorial/basic_io/
 Check what you have been given: Only very simple programs should rely on values extracted directly from cin without further checking.
 we separate the process of getting user input from its interpretation as data, allowing the input process to be what the user expects, and at the same time gaining more control over the transformation of its content into useful data by the program.

Can l use getline();


### OOP notes from Intra: Only way to master OOP is to build using OOP

Methods are actually member functions
Static attributes in functions in C++

Namespaces: Group together symbols and functions in the same file;
Scope resolution operator: 
Magical objects - cin and cout --> character input and output
Operators -- << >>
<iosstream> and C++98
Class and Instance -- new syntax and new keywords
There is the constructor and a destructor -- name of the class for constructor and destructor but with ~ at the start -- instance of the class is constructed and the destructor is destroyed
Between classes and namespaces there are a few similarites
When we declare an instance of a function a constructor function is called
Terms: Class, Instance, Declaration and Definition; Member functions
Member attributes and member functions
this keyword or self in other programming languages --> pointer on the current instance
Initialisation List -- set variables in the constructor at the start. We can do more. We can initialise a constant in class;
Const -- functional programming, guarantee program will work fine in the end; Make my code as constant as possible. 
You are telling the compiler this member function wont alter the current instance. Wont have this keyword; 
Visibility -- Encapsulation. Public and Private. Hide what you want and only give access to what is useful to the user. Use underscore for all the private members. Know when you are looking that the code, you are looking at a private or public keyword
Keep private as much as possible. When designing a class think what should you expose?
Difference between the class and the struct: Scope of a class is private by default. 
Accessors and getters in C: All attributes are private in a class. Interface between user and private attributes. To set and get the values; Use Naming convention to make it easy to get an idea of your class.
Getter can only read so we use const to make it read only object
Comparisons in C++;
Non-member functions and non attributes: static keyword. This means some functions and variables exist at a class level and not an instance level. This pointer is used for instances that are member functions but not available for non member functions
Pointers to members: .* operator??
Really understand the initialisation list and have const code as much as possible. 
Must understand all these notions to complete these assignments;

OOP Articles Notes:
Two characteristics of objects -- State and Behaviour;
Encapsulation: Hiding internal state and requiring all interaction to be performed through an object's methods is known as data encapsulation — a fundamental principle of object-oriented programming. The object remains in control of how the outside world is allowed to use it
https://docs.oracle.com/javase/tutorial/java/concepts/index.html
Allows classes to inherit commonly used state and behavior
Interface:  Methods form the object's interface with the outside world;
Packages:  There are literally thousands of classes to choose from. This allows you, the programmer, to focus on the design of your particular application, rather than the infrastructure required to make it work.

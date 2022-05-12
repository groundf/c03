A Tour of C++
Chapter 1

compiled language
statically typed (u proměnné či parametru nutno uvádět typ)


Core language features
built-in types (char, int)
loops (for, while)

Standard-library components
containers (vector, map)
I/O operations (<<, getline())
efektivní i pro náročnější úlohy



Hello, World!


int main() { }			// the minimal C++ program



funkce main: nebere a nevrací nic
{ } : grouping (začátek a konec těla funkce)
// : komentář
každý C++ program musí mít přesně jednu globální funkci main()


#include <iostream>

int main()
{
	std::cout << “Hello, World!\n”;
}


iostream: instructs the compiler to include (“import”) the declarations of the standard stream I/O facilities as found in iostream
<< : put to, the string literal "Hello, World!\n" is written onto the standard output stream std::cout
std:: specifies that the name cout is to be found in the standard-library namespace
void: return type, nevrací žádnou hodnotu

Funkce

nemůže být volána, pokud nebyla deklarována (jméno funkce, typ)
v deklaraci funkce je návratový typ a typy argumentů uzavřeny v závorkách
the type of a function consists of the return type and the argument types
pokud jsou dvě funkce definovány stejným názvem, ale mají jiné typy argumentů, kompilátor vybere nejvhodnější funkci, případně vyhodí error
class member functions: the name of the class is also part of the function type

double s2 = sqrt(2); 		// call sqrt() with the argument double{2}
double s3 = sqrt(“three”);	// error: sqrt() requires an argument of type double
double sqrt(double d);	// return the square root of d
double square(double);	// return the square of the argument


Typy, proměnné
každý název a výraz má typ, který určuje, jaká operace může být provedena
např.:      int inch;
inch je typu int
deklarace
statement that introduces a name into the program
it specifies a type for the named entity

type:
definuje množinu možných hodnot a operací
object:
paměť, která má hodnotu podle typu (?)
value:
sada bitů interpretovaná dle určitého typu
variable:
pojmenovaný objekt

Základní typy
each type corresponds directly to hardware facilities and has a fixed size
např.: sizeof(char)  = 1  a sizeof(int) = 4

bool (true, false)
char (character: ‘a’, ‘9’)
int (celé číslo)
double (desetiná čísla)
insigned (non-negative int)

Operators

arithmetic operators
x+y    // plus
+x      // unary plus
x–y     // minus
–x       // unary minus
x*y      // multiply
x/y      // divide
x%y    // remainder (modulus) for integers
comparison operators
x==y   // equal
x!=y    // not equal
x<y     // less than
x<=y   // less than or equal
logical operators
x&y    // bitwise and
x|y      // bitwise or
x^y     // bitwise exclusive or
~x       // bitwise complement
x&&y  // logical and
x||y      // logical or
operations for modifying a variable
x+=y    // x = x+y
++x      // increment: x = x+1
x–=y    // x = x-y
– –x    // decrement: x = x-1
x*=y    // scaling: x = x*y
x/=y    // scaling: x = x/y
x%=y   // x = x%y



Pointers, Arrays and References

array of elements of type char
char v[6];
pointer to character
char* p;
[ ] = array of, první je 0 (index)
* = pointer to, “contents of”
the size of an array must be constant expression
char* p = &v[3];
p points to v’s fourth element
char x = *p;
*p is the object that p points to
& = adress of, reference to (specifying function arguments
++x = increment: x = x+1

void copy_fct()
{
	int v1[10] = {0,1,2,3,4,5,6,7,8,9};
	int v2[10];			// to become a copy of v1

	for (auto i=0; i!=10; ++i)	// copy elements
		v2[i]=v1[i];
	// …
}

for = set i to zero; while i is not 10, copy the ith element and increment i


void print()
{
	int v[] = {0,1,2,3,4,5,6,7,8,9};

	for (auto x : v)		// for each x in v
		cout << x << ‘\n’;

	for (auto x : {10,21,32,43,54,65})
		cout << x << ‘\n’;
	// …
}

for every element of v, from the first to the last, place a copy in x and print it
- when we don’t want to modify an argument, but still don’t want the cost of copying, we use a const reference
double sum(const vector<double>&)


T a[n];		// T[n]: array of n Ts
T* p;		// T*: pointer to T
T& r;		// T&: reference to T
T f(A);		// T(A): function taking an argument of type A returning result of type

null pointer: nullptr (if we need to represent the notion of “no object available”)



Scope and Lifetime

a declaration introduces its name into a scope
Local scope:
a name declared in a function or lambda is called a local name
its scope extends from its point of declaration to the end of the block in which its declaration occurs
a block is delimited by a { } pair
function argument names are considered local names
Class scope:
a name is called a member name (or a class member name) if it is defines in a class, outside any function, lambda, or enum class
its scope extends from the opening  { of its enclosing declaration to the end of that declaration
Namespace scope:
a name is called a namespace member name if it is defined in a namespace outside any function, lambda, class, or enum class
its scope extends from the point of declaration to the ends of its namespace

we can have objects without names, such as temporaries and objects created using new
an object created by new “lives” until destroyed by delete
an object must be initialized before it is used and will be destroyed at the end of its scope



Constants

const:
“I promise not to change this value”
primarily used to specify interfaces
constexpr:
“to be evaluated at compile time”
primarily used to specify constants
to allow placement of data in read-only memory
a function must be rather simple, just a return statement computing a value
for non-constant arguments, but than the result is not a constant expression

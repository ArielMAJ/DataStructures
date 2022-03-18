# Basic C & C++

1. Monolithic Programming;
	- The code is written completely in main function;
	- No function calls, no structs, much less classes;
	- If you make changes to how something is done (e.g. how the perimeter is calculated) you may end up having to change the same thing a lot of times in a lot of places;

2. Modular Programming;
	- Makes use of functions;
	- If you change the behavior of your function you might have to change it only in one place;

3. Programming with "Structures and Functions";
	- With structures we start to walk into the direction of OOP:
		- Now we have an object in which we define its properties;
		- We have functions that are made specifically for acting on objects of that type;
	- This is the nearest of OOP that C alone can get.

4. OOP w/ all in one place;
	- In C++ we get OOP;
	- Classes can be defined either as "class" or as "struct":
		- "class" have everything private by default;
		- "struct" have everything public by default;
		- In addition, if you create a class as "struct", they can be initialized the way structs normally are. If you create as "class" they must have a constructor to be initialized (and will be initialized with parenthesis instead of curly brackets);
	- Classes can have constructors and destructors;
		- Constructors are used upon creating an object;
		- Destructors are automatically called when the program ends;
	- A lot of things here resemble C#;

5. OOP defining functions outside the class;
	- Maybe this can help make the code a little bit cleaner (?);
	- Looks similar to some HTML sintax (eg. "div:hover{...}" $\rightarrow$ "int Rectangle::area(){...}");

6. OOP with template class;
	- Making the class a template can facilitate reusing it with different types (eg. int/long/float/double) according to the necessity.
	- Uses a header to indicate it's a template and indicates which variable&functions are templates.

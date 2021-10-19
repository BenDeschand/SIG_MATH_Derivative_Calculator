Instructions to working with derivative calculator program
	create a function within the derivative.cpp file 
		should be written as the *return value* derivCal::*name of function" {*code*};
		please COMMENT
			it will help everyone invloved if we can clearly understand yuor method
	update the .h file to include your method
	update the README.txt file to say what you completed
	create a test file to test said function
		name it test*some number*.cpp (like test01.cpp)
		make sure to test for edge cases, anything you can think of
	run using the following commands
		make test (will run every test)
		./test
		program set up to be able to use gdb to parse through program if needed
			gdb ./test
		NOTE: after running use the command "make clean" to remove all .o files and executables 
			if you don't and make a pull request I will deny it becuase it will also push those files 
	when making pull request detail what you did so I know what you did 

:)

Class deriv
	private:
		String equation          // done (Ben) 
		Vector parse equation    // done (Ben)
		Variable to solve        // done (Ben)
		Variable vector
		Nested variable vector
		Nested tree
	
	public:
		constructors             // done (Ben)
		accessors                // done (Ben)
		Parse equation
		Look for variable
		Look for constant
		Look for exponent
		Order of operation 
		Negative check method
		Trigonmetric check 
		Power rule method
		What type method
		Create answer
		Solve method
		Power rule
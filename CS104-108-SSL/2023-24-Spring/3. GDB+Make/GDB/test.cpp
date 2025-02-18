#include <iostream>

void myFunction(int x, double y) {
    int a = 5;
    double b = 3.14;

    // Perform some simple calculations
    double result = x + y + a + b;
    std::cout << "Result: " << result << std::endl;
}

int main() {
    int num1 = 10;
    {
	    int num1 = 12;
	    std::cout<<"num1 = "<<num1<<std::endl;
    }
    double num2 = 20.5;

    myFunction(num1, num2);  // Call the function with arguments
    return 0;
}

//Passing a function as a pointer:
//#include <iostream>
//using namespace std;
//
//typedef int (*funcType) (int x); //The list of parameters for the function pointer
//int multiply(int x) { return x * 2; }
//int divide(int x) { return (x / 2); }
//
//class A {
//public:
//	A(funcType function) { m_function = function; }
//	void set(funcType function) { m_function = function; }
//	int calc(int x) { return m_function(x); } //returns the return of m_function(x) *m_function is a function, not just a variable*
//private:
//	funcType m_function;
//};
//
//int main() {
//	A obj(multiply);
//	cout << "Calling multiply() => " << obj.calc(20) << "\n";
//	obj.set(divide);
//	cout << "Calling divide() => " << obj.calc(20) << "\n";
//
//	return 0;
//}
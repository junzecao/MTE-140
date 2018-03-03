#include "a1_polynomial_test.hpp"
#include<cstdlib>
#include<iostream>

std::string get_status_str(bool status)
{
    return status ? "TEST PASSED" : "TEST FAILED";
}

int main()
{
	Polynomial_test polynomial_test;
	
	std::string polynomial_test_descriptions[8] = {
      "Test1: constructor",
      "Test2: add function",
      "Test3: sub function",      
	  "Test4: mul function",
	  "Test5: isGreaterDegree function",
	  "Test6: isOddDegree function",
	  "Test7: addLastTerm function",
	  "Test8: replaceTerm function"
	};
	
	bool polynomial_test_results[8];
    polynomial_test_results[0] = polynomial_test.test1();
    polynomial_test_results[1] = polynomial_test.test2();
    polynomial_test_results[2] = polynomial_test.test3();
    polynomial_test_results[3] = polynomial_test.test4();
    polynomial_test_results[4] = polynomial_test.test5();
    polynomial_test_results[5] = polynomial_test.test6();
    polynomial_test_results[6] = polynomial_test.test7();
    polynomial_test_results[7] = polynomial_test.test8();

	std::cout << "POLYNOMIAL TESTING RESULTS \n";
	std::cout << "******************************* \n";
	for (int i = 0; i < 8; ++i) {
    	std::cout << polynomial_test_descriptions[i] << std::endl << get_status_str(polynomial_test_results[i]) << std::endl;
	}
	system("pause");
	return 0;
}


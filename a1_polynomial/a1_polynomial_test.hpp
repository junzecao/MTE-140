#ifndef POLYNOMIAL_TEST_HPP
#define POLYNOMIAL_TEST_HPP

#include "a1_polynomial.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class Polynomial_test
{
public:
	// Test constructor
    bool test1()
    {
		int a1[0] = {};
    	int a2[5] = {0,1,2,3,4};
    	int a3[1] = {100};
		Polynomial* p1 = new Polynomial(a1, 0);
    	Polynomial* p2 = new Polynomial(a2, 5);
    	Polynomial* p3 = new Polynomial(a3, 1);
        ASSERT_TRUE(p1->isEmpty() && p2->isEmpty() == false && p3->isEmpty() == false)
        ASSERT_TRUE(p2->getArraySize() == 5 && p3->getArraySize() == 1)
        ASSERT_TRUE(p2->getValue(100) == -1000)
        for(int i = 0; i < 5; i++)
        {
        	ASSERT_TRUE(p2->getValue(i) == i)
		}
        ASSERT_TRUE(p3->getValue(0) == 100)
        return true;
    }

	// Test add function
    bool test2()
    {
    	int a1[5] = {0,1,2,3,4};
    	int a2[5] = {5,4,3,2,1};
    	int a3[1] = {100};
    	Polynomial* p1 = new Polynomial(a1, 5);
    	Polynomial* p2 = new Polynomial(a2, 5);
    	Polynomial* p3 = new Polynomial(a3, 1);
        Polynomial* temp = p1->add(p2);
        for(int i = 0; i < 5; i++)
        	ASSERT_TRUE(temp->getValue(i) == 5)
        temp = p1->add(p3);
        ASSERT_TRUE(temp->getValue(0) == 100 && temp->getValue(1) == 1)
        temp = p3->add(p3);
        ASSERT_TRUE(temp->getValue(0) == 200)
        return true;
    }

	// Test sub function
    bool test3()
    {
    	int a1[5] = {0,1,2,3,4};
    	int a2[5] = {5,4,3,2,1};
    	int a3[1] = {100};
    	Polynomial* p1 = new Polynomial(a1, 5);
    	Polynomial* p2 = new Polynomial(a2, 5);
    	Polynomial* p3 = new Polynomial(a3, 1);
        Polynomial* temp = p1->sub(p2);
        for(int i = 0; i < 5; i++)
        	ASSERT_TRUE(temp->getValue(i) == (2*i - 5))
        temp = p1->sub(p3);
        ASSERT_TRUE(temp->getValue(0) == -100 && temp->getValue(1) == 1)
        temp = p3->sub(p3);
        ASSERT_TRUE(temp->getValue(0) == 0)
        return true;
    }
    
    // Test mul function
    bool test4()
    {
    	int a1[5] = {0,1,2,3,4};
    	int a2[5] = {5,4,3,2,1};
    	int a3[1] = {100};
    	Polynomial* p1 = new Polynomial(a1, 5);
    	Polynomial* p2 = new Polynomial(a2, 5);
    	Polynomial* p3 = new Polynomial(a3, 1);
	    Polynomial* temp = p1->mul(p2);
	    
        ASSERT_TRUE(temp->getValue(0) == 0)
        ASSERT_TRUE(temp->getValue(8) == 4)
        ASSERT_TRUE(temp->getValue(7) == 11)
        
        temp = p1->mul(p3);
        for(int i = 0; i < 5; i++)
        	ASSERT_TRUE(temp->getValue(i) == i*100)
        return true;
    }
    
    // Test isGreaterDegree function 
    bool test5()
    {
    	int a1[0] = {};
    	int a2[5] = {5,4,3,2,1};
    	int a3[1] = {100};
    	Polynomial* p1 = new Polynomial(a1, 0);
    	Polynomial* p2 = new Polynomial(a2, 5);
    	Polynomial* p3 = new Polynomial(a3, 1);
	    
        ASSERT_FALSE(p1->isGreaterDegree(p2))
        ASSERT_TRUE(p2->isGreaterDegree(p1))
        ASSERT_FALSE(p1->isGreaterDegree(p3))
        ASSERT_TRUE(p3->isGreaterDegree(p1))
        ASSERT_TRUE(p2->isGreaterDegree(p3))
        ASSERT_FALSE(p3->isGreaterDegree(p2))
        
        return true;
    }
    
    // Test isOddDegree function
    bool test6()
    {
    	int a1[2] = {0,1};
    	int a2[5] = {5,4,3,2,1};
    	int a3[1] = {100};
    	Polynomial* p1 = new Polynomial(a1, 2);
    	Polynomial* p2 = new Polynomial(a2, 5);
    	Polynomial* p3 = new Polynomial(a3, 1);
	    
        ASSERT_TRUE(p1->isOddDegree())
        ASSERT_FALSE(p2->isOddDegree())
        ASSERT_FALSE(p3->isOddDegree())
        
        return true;
    }
    
    // Test addLastTerm function
    bool test7()
    {
    	int a1[0] = {};
    	int a2[5] = {5,4,3,2,1};
    	Polynomial* p1 = new Polynomial(a1, 0);
    	Polynomial* p2 = new Polynomial(a2, 5);
	    p1->addLastTerm(100);
	    p2->addLastTerm(100);
        ASSERT_TRUE(p1->getValue(0) == 100)
        ASSERT_TRUE(p2->getValue(5) == 100)
        
        return true;
    }
    
    // Test replaceTerm function
    bool test8()
    {
    	int a1[5] = {5,4,3,2,1};
    	Polynomial* p1 = new Polynomial(a1, 5);
	    p1->replaceTerm(0,100);
	    p1->replaceTerm(4,200);
        ASSERT_TRUE(p1->getValue(0) == 100)
        ASSERT_TRUE(p1->getValue(4) == 200)
        
        return true;
    }
};

#endif


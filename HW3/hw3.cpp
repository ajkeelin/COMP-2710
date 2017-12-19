/*
*Austin Keelin
*ajk0033
*hw3.cpp
*Compiled using g++ compiler
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
using namespace std;

//Prototypes 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/* Input: A_alive indicates whether Aaron is alive */
/*        B_alive indicates whether Bob is alive */
/*        C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/*         otherwise return false */

void Aaron_shoots1(bool& B_alive, bool& C_alive);
/* Strategy 1: Use call by reference
 * Input: B_alive indicates whether Bob alive or dead
 * 		 C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 * 		  Change C_alive into false if Charlie is killed.	
 */

void Bob_shoots(bool& A_alive, bool& C_alive);
/* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 * 		 C_alive indicates if Charlie is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 * 		  Change C_alive into false if Charlie is killed.
 */

void Charlie_shoots(bool& A_alive, bool& B_alive);
/* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 *        B_alive indicates whether Bob is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 * 		  Change B_alive into false if Bob is killed.       
 */

void Aaron_shoots2(bool& B_alive, bool& C_alive);
/* Strategy 2: Use call by reference
 * Input: B_alive indicates whether Bob is alive or dead
 * 		 C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 * 		  Change C_alive into false if Charlie is killed.		  
 */

void test_at_least_two_alive(void);
/* This is a test driver for at_least_two_alive() */

void test_Aaron_shoots1(void);
/* This is a test driver for Aaron_shoots1() */

void test_Bob_shoots(void);
/* This is a test driver for Bob_shoots() */

void test_Charlie_shoots(void);
/* This is a test driver for Charlie_shoots() */

void test_Aaron_shoots2(void);
/* This is a test driver for Aaron_shoots2() */

//Main Function
int main() {
	const int number_of_runs = 10000;
   const int Aaron_hit_rate = 33;
   const int Bob_hit_rate = 50;
   const int Charlie_hit_rate = 100;
   int A_win_count_s1, B_win_count_s1, C_win_count_s1;
   int A_win_count_s2, B_win_count_s2, C_win_count_s2;
   srand(time(0));
   
   cout << "*** Welcome to Austin's Duel Simulator ***\n";
    
   test_at_least_two_alive(); 
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   test_Aaron_shoots1();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   test_Bob_shoots();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   test_Charlie_shoots();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   test_Aaron_shoots2();
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   //Strategy 1
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   cout << "press any key to continue...";
   cin.ignore().get();   
   
   int A_count_s1 = 0; 
   int B_count_s1 = 0; 
   int C_count_s1 = 0;
   
   for (int x = 0; x < number_of_runs; x++) {
      bool A_alive = true;
      bool B_alive = true;
      bool C_alive = true;
      
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive == true) {
            Aaron_shoots1(B_alive, C_alive);
         }
         if (B_alive == true) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive == true) {
            Charlie_shoots(A_alive, B_alive);
         }
         cout << endl;
      }
      
      if (A_alive == true) {
         A_count_s1++;
      }
      else if (B_alive == true) {
         B_count_s1++;
      }
      else if (C_alive == true) {
         C_count_s1++;
      }
   }
   
   double Aaron_wins1 = A_count_s1 * 1.0 / number_of_runs;
   double Bob_wins1 = B_count_s1 * 1.0 / number_of_runs;
   double Charlie_wins1 = C_count_s1 * 1.0 / number_of_runs;                        
    
   cout << "Aaron won " << A_count_s1 << "/10000 duels or " << Aaron_wins1 * 100 << "%\n"; 
   cout << "Bob won " << B_count_s1 << "/10000 duels or " << Bob_wins1 * 100 << "%\n";
   cout << "Charlie won " << C_count_s1 << "/10000 duels or " << Charlie_wins1 * 100 << "%\n\n";    
   
   //Strategy 2
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   cout << "Press any key to continue...";
   cin.ignore().get();
   
   int A_count_s2 = 0;
   int B_count_s2 = 0;
   int C_count_s2 = 0;
   
   for (int x = 0; x < number_of_runs; x++) {
      bool A_alive = true;
      bool B_alive = true;
      bool C_alive = true;
      
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive == true) {
            Aaron_shoots2(B_alive, C_alive);
         }
         if (B_alive == true) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive == true) {
            Charlie_shoots(A_alive, B_alive);
         }
         cout << endl;
      }
      
      if (A_alive == true) {
         A_count_s2++;
      }
      else if (B_alive == true) {
         B_count_s2++;
      }
      else if (C_alive == true) {
         C_count_s2++;
      }
   }
   
   double Aaron_wins2 = A_count_s2 * 1.0 / number_of_runs;
   double Bob_wins2 = B_count_s2 * 1.0 / number_of_runs;
   double Charlie_wins2 = C_count_s2 * 1.0 / number_of_runs;                        
    
   cout << "Aaron won " << A_count_s2 << "/10000 duels or " << Aaron_wins2 * 100 << "%\n"; 
   cout << "Bob won " << B_count_s2 << "/10000 duels or " << Bob_wins2 * 100 << "%\n";
   cout << "Charlie won " << C_count_s2 << "/10000 duels or " << Charlie_wins2 * 100 << "%\n\n";
   
   if (A_count_s2 > A_count_s1) {
      cout << "Strategy 2 is better than strategy 1.\n";
   }
   else {
      cout << "Strategy 1 is better than strategy 2.\n";
   }      
   
	return 0;
}

//Function Implementations
bool at_least_two_alive(bool a_alive, bool b_alive, bool c_alive) {
	if (a_alive == true && b_alive == true) {
		return true;
	}
	if (a_alive == true && c_alive == true) {
		return true;
	}
	if (b_alive == true && c_alive == true) {
		return true;
	}
	else {
		return false;
	}
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   int shoot_target_result;
   shoot_target_result = rand()%100;   
   
   assert(B_alive || C_alive);
   
   if (C_alive == true) {   
      cout << "\t\tAaron is shooting at Charlie\n";
      if (shoot_target_result <= 33) {
         C_alive = false;
         cout << "\t\tCharlie is dead\n";
      }
      else {
         cout << "\t\tAaron misses\n";
      }
   }   
   else if (B_alive == true) {
      cout << "\t\tAaron is shooting at Bob\n";
      if (shoot_target_result <= 33) {
         B_alive = false;
         cout << "\t\tBob is dead\n";
      }
      else {
         cout << "\t\tAaron misses\n";
      }
   }   
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
	int shoot_target_result;
   shoot_target_result = rand() % 100;
   
   assert(A_alive || C_alive);
   
   if (C_alive == true) {
      cout << "\t\tBob is shooting at Charlie\n";
      if (shoot_target_result <= 50) {
         C_alive = false;
         cout << "\t\tCharlie is dead\n";
      }
      else {
         cout << "\t\tBob misses\n";
      }
   }
   else if (A_alive == true) {
      cout << "\t\tBob is shooting at Aaron\n";
      if (shoot_target_result <= 50) {
         A_alive = false;
         cout << "\t\tAaron is dead\n";
      }
      else {
         cout << "\t\tBob misses\n";
      }
   }                 

}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
   assert(A_alive || B_alive);
   
	if (B_alive == true) {
      cout << "\t\tCharlie is shooting at Bob\n";
      B_alive = false;
      cout << "\t\tBob is dead\n";
   }
   else if (A_alive == true) {
      cout << "\t\tCharlie is shooting at Aaron\n";
      A_alive = false;
      cout << "\t\tAaron is dead\n";
   }      
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
	int shoot_target_result;
   shoot_target_result = rand() % 100;
   
   assert(B_alive || C_alive);
   int count = 0;
   if (B_alive == true && C_alive == true && count == 0) {
      cout << "\t\tAaron intentionally misses his first shot\n";
      cout << "\t\tBoth Bob and Charlie are alive.\n";
      count++;
   }
   else if (C_alive == true) {
      cout << "\t\tAaron is shooting at Charlie\n";
      if (shoot_target_result <= 33) {
         C_alive = false;
         cout << "\t\tCharlie is dead\n";
      }
      else {
         cout << "\t\tAaron misses\n";
      }
   }
   else if (B_alive == true) {
      cout << "\t\tAaron is shooting at Bob\n";
      if (shoot_target_result <= 33) {
         B_alive = false;
         cout << "\t\tBob is dead\n";
      }
      else {
         cout << "\t\tAaron misses\n";
      }
   }                        
}

//Test Drivers
void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	
	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 5: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";
	
	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";
   
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
}

void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   bool B_alive;
   bool C_alive;

   cout << "\tCase 1: Bob alive, Charlie alive\n";
   B_alive = true;
   C_alive = true;
   Aaron_shoots1(B_alive, C_alive);
   
   cout << "\tCase 2: Bob dead, Charlie alive\n";
   B_alive = false;
   C_alive = true;
   Aaron_shoots1(B_alive, C_alive);
   
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   B_alive = true;
   C_alive = false;
   Aaron_shoots1(B_alive, C_alive);
   
} 

void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   bool A_alive;
   bool C_alive;
   
   cout << "\tCase 1: Aaron alive, Charlie alive\n";
   A_alive = true;
   C_alive = true;
   Bob_shoots(A_alive, C_alive);
   
   cout << "\tCase 2: Aaron dead, Charlie alive\n";
   A_alive = false;
   C_alive = true;
   Bob_shoots(A_alive, C_alive);
   
   cout << "\tCase 3: Aaron alive, Charlie dead\n";
   A_alive = true;
   C_alive = false;
   Bob_shoots(A_alive, C_alive);
}  

void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   bool A_alive;
   bool B_alive;
   
   cout << "\tCase 1: Aaron alive, Bob alive\n";
   A_alive = true;
   B_alive = true;
   Charlie_shoots(A_alive, B_alive); 
   
   cout << "\tCase 2: Aaron dead, Bob alive\n";
   A_alive = false;
   B_alive = true;
   Charlie_shoots(A_alive, B_alive);
   
   cout << "\tCase 3: Aaron alive, Bob dead\n";
   A_alive = true;
   B_alive = false;
   Charlie_shoots(A_alive, B_alive);
}  

void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   bool B_alive;
   bool C_alive;
   
   cout << "\tCase 1: Bob alive, Charlie alive\n";
   B_alive = true;
   C_alive = true;
   Aaron_shoots2(B_alive, C_alive); 
   
   cout << "\tCase 2: Bob dead, Charlie alive\n";
   B_alive = false;
   C_alive = true;
   Aaron_shoots2(B_alive, C_alive);
   
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   B_alive = true;
   C_alive = false;
   Aaron_shoots2(B_alive, C_alive);
}   
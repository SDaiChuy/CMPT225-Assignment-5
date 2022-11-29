/*
 * Member.cpp
 * 
 * Class Description: Models a member belonging to a Hash Table.
 *                    This member has the following characteristics:
 *                    name, cell phone number, email address and a credit card number.
 *                    Each member has a unique cell phone number.
 * Class Invariant: This cell phone number must have 12 digits.
 *                  This cell phone number must have the following format: XXX-XXX-XXXX.
 *                  This cell phone number cannot be modified. 
 *
 * Author: AL + Sd
 * Last modified: Nov. 2022
 */

#include <iostream>
#include "Member.h"

using std::cout;
using std::endl;

// Default Constructor
// Description: Create a member with a cell phone number of "000-000-0000". 
// Postcondition: All data members set to an empty string, 
//                except the cell phone number which is set to "000-000-0000".
Member::Member() : name(""), phone("000-000-0000"), email(""), creditCard("") {

   //cout << "Member::default constructor" << endl;   // For testing purposes ... and curiosity
}

// Parameterized Constructor
// Description: Create a member with the given cell phone number.
// Postcondition: If aPhone does not have 12 digits, then aPhone is set to "000-000-0000".
//                All other data members set to an empty string.
Member::Member(string aPhone) : name(""), email(""), creditCard("")  {

   setPhone(aPhone);
}

// Parameterized Constructor
// Description: Create a member with the given name, cell phone number, email and credit card number.
// Postcondition: If aPhone does not have 12 digits, then aPhone is set to "000-000-0000".
Member::Member(string aName, string aPhone, string anEmail, string aCreditCard) : 
                 name(aName), email(anEmail), creditCard(aCreditCard) {
                 	
   setPhone(aPhone);
}

// Getters and setters
// Description: Returns member's name.
string Member::getName() const {
   return name;
}

// Description: Returns member's phone number.
string Member::getPhone() const {
   return phone;
}

// Description: Returns member's email.
string Member::getEmail() const {
   return email;
}

// Description: Returns member's credit card number.
string Member::getCreditCard() const {
   return creditCard;
}

// Description: Sets the member's name.
void Member::setName(const string aName) {
   name.assign(aName);
}

// Description: Sets the member's email.
void Member::setEmail(const string anEmail) {
   email.assign(anEmail);
}

// Description: Sets the member's credit card number.
void Member::setCreditCard(const string aCreditCard) {
   creditCard.assign(aCreditCard);
}

// Description: Sets the member's cell phone number - Private method
// Why is this method private? 
void Member::setPhone(const string aPhone){

   bool badPhone = false;
   unsigned int i = 0;

   phone.assign("000-000-0000");
	
   if ( aPhone.length() != SIZE_OF_PHONE_NUMBER ) badPhone = true; // size = 12
   else {
      for ( ; i < 3; i++ ) {
         if ( !isdigit( aPhone[i] ) ) badPhone = true; // digits at indices 0,1,2
      }
      if ( aPhone[i++] != '-' ) badPhone = true; // '-' at index 3
      for ( ; i < 7; i++) {
         if ( !isdigit( aPhone[i] ) ) badPhone = true; // digits at indices 4,5,6
      }
      if ( aPhone[i++] != '-' ) badPhone = true; // '-' at index 7
      for ( ; i < 12; i++) {
         if ( !isdigit( aPhone[i] ) ) badPhone = true; // digits at indices 8,9,10,11
      }
   }

   if ( !badPhone ) phone = aPhone;
   return;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if both Member objects have the same cell phone number.
bool Member::operator == (const Member & rhs) {

   return this->phone == rhs.getPhone();
}
	
// Description: Greater than operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if the cell phone number of "this" Member object is > the 
//              cell phone number of "rhs" Member object.
bool Member::operator > (const Member & rhs) {

   return this->phone > rhs.getPhone();
} 

// Description: Less than operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if the cell phone number of "this" Member object is < the 
//              cell phone number of "rhs" Member object.
bool Member::operator < (const Member & rhs) {
	
   return this->phone < rhs.getPhone();
} 
 
// For testing purposes!
// Description: Prints the content of "this".
// Example: Louis Pace, 604-853-1423, louis@nowhere.com, 1234 5678 9098 7654 
ostream & operator<<(ostream & os, const Member & p) {
	
   os << p.name << ", " << p.phone << ", " << p.email << ", " << p.creditCard << endl;  
	     
   return os;
} 

// end of Member.cpp

#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference): reference(reference), the_entry("") {}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  the_entry = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{

  int ref_len = reference.length();     //helper variables for length of strings
  int entry_len = the_entry.length();
  int total = ref_len - entry_len;
  
  if(ref_len > entry_len || ref_len < entry_len)  //case if reference is bigger or smaller than entry
    return abs(total);

  else
    return 0;

}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  tappity temp(reference);
  temp.entry(the_entry);
  double acc; //accuracy of the two strings
  double match; //count of matching characters

  double ref_len = reference.length();
  double entry_len = the_entry.length();

/* SAME LENGTH STRINGS */
  if(temp.length_difference() == 0){ 
    for(double i = 0; i < ref_len; i++){               //iterate through either word (since same length)
      if(reference[i] == the_entry[i]){             //if char at index matches, add to match variable
        match++;
      }
    }
    if(match == 0){
      acc = 0;
    }
    else{
    acc = (match/ref_len) * 100;                    //divide total matches by length of either word (since same length)
    }
  }//end if


/* DIFFERENT LENGTH STRINGS */
  if(temp.length_difference() != 0){
    if(ref_len > entry_len){                        //if reference string is longer
      for(double i = 0; i < entry_len; i++){           //iterate through entry string
        if(the_entry[i] == reference[i]){           //find matches
          match++;
        }
      }
    acc = (match/ref_len) * 100;                    //divide total matches by length of longer string
    }
    else if(ref_len < entry_len){                   //if entry string is longer
      for(double i = 0; i < ref_len; i++){             //iterate through reference string
        if(reference[i] == the_entry[i]){           //find matches
          match++;
        }
      }
    acc = (match/entry_len) * 100;                  //divide total matches by length of longer string
    }
  }//end if

  if(reference == "" && the_entry == ""){           //empty-strings are identical, so accuracy should equal 100
    acc = 100;
  }

  return acc;


  return 0;
}

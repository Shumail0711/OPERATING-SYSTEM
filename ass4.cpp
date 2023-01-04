

#include <iostream>
#include <thread>
#include <string>
using namespace std;

void input_thread(string& st)          //creating four threads
{
 
    cout << "Enter a string: "; //taking input from user
    getline(cin, st);        // storing input in 
}

void reverse_thread(const string& st)
{
   
    string reversed_s(st.rbegin(), st.rend());   //reversing the input string
    cout << "Reversed string is: " << reversed_s <<endl;
}
void capital_thread(const string& st)
{
    
    
    string capital_str; //declaring a variable capital string
    for (char ch : st)
        capital_str += toupper(ch);   // capitalizing the characters of the string by using "toupper"
    cout << "Capitalized string is: " << capital_str << endl;
}

void shift_thread(const string& st)
{
   
    string shift_ch; 
    for (char ch : st)
        shift_ch += (ch + 2); //shifting character by 2 times in a string
    cout << "Shifted string is: " << shift_ch <<endl;
}

int main()
{
    string st;

   
    thread t1(input_thread, ref(st));  // Create the first thread and taking input
    t1.join();
    thread t2(reverse_thread, cref(st)); // Create the second thread 
    thread t3(capital_thread, cref(st));  // Create the third thread 
    thread t4(shift_thread, cref(st));    // Create the fourth thread 

    t2.join();  //taking output of thread 2,3 and 4
    t3.join();
    t4.join();
     
    return 0;
}

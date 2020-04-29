//Name:Orlando Valdez
//Teacher: Dr_T
//School: Tarrant County College
//Date:4-15-2020
//Purpose: A Restaruant struct file convereted to class 
//Skills: update code, output results to text file, convert to class 


#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include <fstream> // write to a file
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 


//**********Class Style ************//
class MenuItemList
{
  private:
    string name;
    double itemCost;
    string desc;
    char addLetter;
    char removeLetter;
    int count;
  public:
    void setName(string n) { name = n;}
    void setItemCost( double iT) { itemCost = iT;}
    void setDesc(string d) {desc = d;}
    void setAddLetter(char aL) { addLetter = aL;}
    void setRemoveLetter(char rL) { removeLetter = rL;}
    void setCount(int c) { count = c;}
    string getName() const { return name;}
    double getItemCost() const { return itemCost;}
    string getDesc() const { return desc;}
    char getAddLetter() const { return addLetter;}
    char getRemoveLetter() const { return removeLetter;}
    int getCount() const { return count;}
    //void print() {} // print menu item data on demand}

};


//************Class Style*****/
//function definitions
void populateObjectMenu(vector<MenuItemList> &entireMenu)
{

  //put some default values in our Menu
  const int numItems = 7; 
  MenuItemList Item1; //Item1 is an object 
  MenuItemList Item2;
  MenuItemList Item3; 
  MenuItemList Item4;
  MenuItemList Item5;
  MenuItemList Item6;
  MenuItemList Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Tortas", "Tacos", "Horchata", "Elote", "Boba Tea"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost(3.00 + i); //set a random starter cost for each item
    entireMenu[i].setCount(0); //initialze all counts to 0
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
  }

}



//**********Classs Style**********/
void showobjectMenu(vector<MenuItemList> &m)
{
  string color;
  string colorR = "\x1b[31;15m";
  string colorG = "\x1b[32;4m";
  string colorT = "\x1b[36;15m";
  string colorMenu = "\x1b[34;4m";
  string reset = "\x1b[0m";
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << colorG << "DrT's Effcient Object Menu" << reset << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].getAddLetter() << ")" << setw(10) << m[i].getName() 
    << setw(5) << "$" << m[i].getItemCost() << setw(5) << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc() 
    <<endl; 
  }

}



//********Class Style**********
void acceptobjectOrder(vector<MenuItemList> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0;
  double total = 0.0;
  double tipRate = 0.20;
  double taxRate = 0.0825;
  double tipInput = 0.20;
  double tip = 0.0;
  double tax = 0.0;
  double cash, change = 0.0;
  char paymentMethod;
  string color;
  string colorR = "\x1b[31;15m";
  string colorG = "\x1b[32;4m";
  string colorT = "\x1b[36;15m";
  string colorMenu = "\x1b[40;93m";
  string reset = "\x1b[0m";

  do
  {
    cout << colorG<< "\nPlease choose an item (x to Exit): " << reset ;
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
        m[i].setCount(m[i].getCount()+1) ;//increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showobjectMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          m[i].setCount(m[i].getCount()-1); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showobjectMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getAddLetter() && 
                option != m[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  
  cout << colorMenu << "\nWhat Percent Would You Like To Tip? \n(20% is the preffered amount): " << reset;
  validateDouble(tipInput);
  tipRate = (tipInput * (0.010));
  total = subtotal;
  tip = (subtotal * tipRate);
  tax = (subtotal * taxRate);
  cout << "\nTotal " << setw(13) <<"$"<< total << endl;
  cout << "Tip " << setw(15) << "$"<<tip << endl;
  cout << "Tax " << setw(15) << "$"<<tax << endl;
  subtotal = (subtotal + tip + tax);
  cout << colorR <<"\nSubtotal "  << setw(10)<< "$"<< subtotal << reset;
  cout << colorMenu <<"\n\nHow Would you like to pay?"<< reset << endl;
  cout << "A. Cash " << endl;
  cout << "B. Credit Card" << endl;
  //cout << "X. Cancel" << endl;
  cin >> paymentMethod;

 
  if(paymentMethod == 'A' || paymentMethod == 'a')
    {
      cout << colorMenu <<"What Is Your Cash Payment Amount? " << reset ;
      validateDouble(cash);
      change = (cash - subtotal);
      cout << colorMenu <<"\nTotal "<< reset << setw(13) << total << endl;
      cout << colorMenu <<"Tip "<< reset << setw(15) << tip << endl;
      cout << colorMenu <<"Tax "<< reset << setw(15) << tax << endl;      
      cout << colorMenu <<"\nSubtotal "<< reset  << setw(10)<< subtotal;
      cout << colorMenu <<"\nPayment"<< reset << setw(12) << cash << endl;
      cout << colorMenu <<"\nChange "<< reset << setw(12) << change << endl;
    }
  else if (paymentMethod == 'B' || paymentMethod == 'b')
    {
      cout << colorMenu;
      cout << "|Please Insert Card Into Reader|\n" << endl;
      sleep(1);
      cout << "|Reading Card Info.............|\n" << endl;
      sleep(2);
      cout << "|PROCESSING PAYMENT............|\n" << endl;
      cout << "|DO NOT REMOVE CARD............|\n" << endl;
      sleep(3);
      cout << "\n\n\t\tPayment Successful! " << endl;
      cout << "V V V-- Your Reciept Displayed Below --V V V\n";
      cout << reset;
    }
  cout << colorT <<"*********************************************"<< reset;    
  cout << colorG << "\n1 UP on Green Tea Receipt"<< reset << endl;
  cout << "    ITEM \t  COST \t QUANTITY" << endl;
  for(int i=0 ; i < m.size(); i++)
  {
  cout << setw(10) << m[i].getName() << setw(5) << "$" << m[i].getItemCost() << setw(5) << setw(7) << m[i].getCount() << setw(13)  <<endl;  
  }
  cout << "\nTotal " << setw(9) <<"$"<< total << endl;
  cout << "Tip " << setw(11) << "$"<<tip << endl;
  cout << "Tax " << setw(11) << "$"<<tax << endl;      
  cout << colorR << "\nSubtotal "  << setw(6)<< "$"<< subtotal << reset;
  cout << "\nPayment" << setw(8) << "$"<<cash << endl;
  cout << "\nChange " << setw(8) << "$"<<change << endl;




  
  cout << colorT <<"*********************************************"<< reset;    
  cout << "\nThank you for placing your order." << endl; 
//below this line the output to print to the reciept is done with slelected output varibles
  fstream reciept; 
  reciept.open("reciept.txt",ios::out);

  reciept <<"*********************************************";    
  reciept << "\n1 UP on Green Tea Receipt"<< endl;
  reciept << "    ITEM \t  COST \t QUANTITY" << endl;
  reciept << fixed << setprecision(2);
  for(int i=0 ; i < m.size(); i++)
  {
  reciept << setw(10) << m[i].getName() << setw(5) << "$" << m[i].getItemCost() << setw(5) << setw(7) << m[i].getCount() << setw(13)  <<endl;  
  }

  
  reciept << "\nTotal " << setw(9) << "$"<<total << endl;
  reciept << "Tip " << setw(11) << "$"<<tip << endl;
  reciept << "Tax " << setw(11) << "$"<<tax << endl;      
  reciept << "\nSubtotal "  << setw(6)<< "$"<<subtotal;
  reciept << "\nPayment" << setw(8) << "$"<<cash << endl;
  reciept << "\nChange " << setw(8) << "$"<<change << endl;

  reciept << "\nThank You Come Again!" << endl;



  
  reciept <<"*********************************************";



  reciept.close(); 
  //handle the tip process here
  //callculate total due + tax + tip//accept payment type
  //handle cash vs. credit
  //handle on screen reciept generation here
  //handle the text file reciept generation here
  //loop the program, reset over and
}

void printTextReciept(vector<MenuItemList> &m)
{
  /**double total, tip, tax, subtotal, cash, change = 0.0;

  fstream reciept; 
  reciept.open("reciept.txt",ios::out);

  reciept <<"*********************************************";    
  reciept << "\n1 UP on Green Tea Receipt"<< endl;
  reciept << "    ITEM \t  COST \t QUANTITY" << endl;
  reciept << fixed << setprecision(2);
  for(int i=0 ; i < m.size(); i++)
  {
  reciept << setw(10) << m[i].getName() << setw(5) << "$" << m[i].getItemCost() << setw(5) << setw(7) << m[i].getCount() << setw(13)  <<endl;  
  }
  reciept << "\nTotal " << setw(13) << total << endl;
  reciept << "Tip " << setw(15) << tip << endl;
  reciept << "Tax " << setw(15) << tax << endl;      
  reciept << "\nSubtotal "  << setw(10)<< subtotal;
  reciept << "\nPayment" << setw(12) << cash << endl;
  reciept << "\nChange " << setw(12) << change << endl;
  cout <<"*********************************************";
  reciept.close();  
  **/
}

void clrscr()//loop to clear the screen after every loop
{
    system("@cls||clear");
}


int main() 
  {
   char order = 'Y';
    //*******Class Style********/
    while( order == 'Y' || order == 'y')//user selelcts if they want to run menu order again
    {
    clrscr();
    vector<MenuItemList> objectMenu; 
    populateObjectMenu(objectMenu); //put some default values in the menu
    showobjectMenu(objectMenu); //show the inital menu on screen
    acceptobjectOrder(objectMenu);
    //solve and call acceptObjectOrder void function here

    printTextReciept(objectMenu); 
    
    cout << "Order Again? (Y/N)";
    cin >> order;
    }
    cout << "Thank You Come Again!";
  return 0; 
}
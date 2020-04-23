//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include <fstream> // write to a file
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

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7"}; 
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
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Object Menu" << endl; 
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

  double tipRate = 0.20;
  double taxRate = 0.0825;
  double tip = 0.0;
  double tax = 0.0;
  

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
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

  ///**cout << "Would You like To Add A Tip? (20% is the default)" << endl;;
  cin >> tipRate;
  tipRate = tipRate * (0.10);
  tip = subtotal * tipRate ;
  cout << tip << endl;
  subtotal = (subtotal + tip);
  cout << subtotal ;
  //**/
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here
  //callculate total due + tax + tip//accept payment type
  //handle cash vs. credit
  //handle on screen reciept generation here
  //handle the text file reciept generation here
  //loop the program, reset over and
}

void printTextReciept(vector<MenuItemList> &m)
{
  fstream reciept; 
  reciept.open("reciept.txt",ios::out);

  reciept << "\t" <<"Item Name" << "\t\t\t" << "Quantity " << endl;
  reciept << "\t" << m[0].getName() << "\t\t" << m[0].getCount() << endl; 
  
  for(int i=0; i < m.size(); i++)//gets the name and quantity of order and prints to text file accorrdingly
  {
      reciept << "\t" << m[i].getName() << "\t\t" << m[i].getCount() << endl; 
  }


  reciept.close();  

  fstream html; 
  html.open("index.html",ios::out);

  html << "<html><head><title>Cool</title><head>";
  html << "<body style=\"background-color:#000000; color:#FFFFFF;\">";
  html << "<h1>"<< m[0].getName() << "</h1>" << endl;
  html << "</body></html>";  

  html.close(); 


}

int main() 
{
  

//*******Class Style********/
vector<MenuItemList> objectMenu; 
populateObjectMenu(objectMenu); //put some default values in the menu
showobjectMenu(objectMenu); //show the inital menu on screen
acceptobjectOrder(objectMenu);
//solve and call acceptObjectOrder void function here

printTextReciept(objectMenu); 
  return 0; 
}
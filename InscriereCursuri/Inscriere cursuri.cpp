#include"ControlBook.h"

int main()
{
   
    ControlBook* cb = new ControlBook;
    
    Book* b1 = cb->GetBookByName("Data Science Part 1");
    cout<<b1->describe();
    



    
  


}



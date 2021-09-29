#include"ControlDirector.h"

int main()
{
   
    ControlEnrolment* ce = new ControlEnrolment;

    ControlDirector* cd = new ControlDirector;
    
    Director * d = cd->GetDirectorByName("Paul Vlad");
    Admin* a = dynamic_cast<Admin*>(d);
    a->erase_invest(50.3);
    a->traverse();


    
  


}



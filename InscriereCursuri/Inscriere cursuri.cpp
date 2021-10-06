#include"ViewDirector.h"

int main()
{
   

    /*ControlDirector* cd = new ControlDirector;
    
    Director * d = cd->GetDirectorByName("Paul Vlad");
    Admin* a = dynamic_cast<Admin*>(d);*/

    ViewDirector* vd = new ViewDirector;
    ControlPerson* cp = new ControlPerson;
    ControlStudentIDCard* cs = new ControlStudentIDCard;


 
    vd->play();
  









    
  


}



#include"ControlEnrolment.h"

int main()
{
   
    ControlEnrolment* ce = new ControlEnrolment;

    Enrolment* e1 = ce->GetEnrolmentByIDs(33, 6);
    cout<<e1->describe();
    



    
  


}



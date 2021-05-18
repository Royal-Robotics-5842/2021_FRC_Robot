#include "subsystems/delete.h"

Turret *twist;
Feeder *pass;
Spindexer *spin;
Shooter *FIREEEEE;

easyshot::easyshot()
{
    twist = new Turret();
    pass = new Feeder();
    spin = new Spindexer();
    FIREEEEE = new Shooter();

}

void easyshot::everything(bool fire, double distance)
{
    if(fire = true)
    {
    
    twist->autoRotate(1);
    spin->runSpindexer(1);//,0);

    }
    

}
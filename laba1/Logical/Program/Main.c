#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_motor1.dt = 0.01;
	fb_motor1.ke = 0.24;
	fb_motor1.Tm = 0.1;
	fb_motor1.u = 0;
	fb_motor1.integrator.dt=0.01;
 
	fb_motor2.dt = 0.01;
	fb_motor2.ke = 0.24;
	fb_motor2.Tm = 0.1;
	fb_motor2.u = 0;
	fb_motor2.integrator.dt=0.01;
 
	fb_controller.dt = 0.01;
	fb_controller.integrator.dt = 0.01;
	fb_controller.k_i = 0.2;
	fb_controller.k_p = 0.78;
	fb_controller.max_abs_value = 24.0;
 
	Speed = 0;
	counter = 0;
	Enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	if (Enable)
	{
		if(counter == 200)
		{
			Speed = 0;
			counter = 0;
		}
		else if (counter == 50)
		{
			Speed = 50;
		}
		counter++;
  
		fb_controller.e = Speed - fb_motor1.w;
		FB_Regulator(&fb_controller);
		
		fb_motor1.u = fb_controller.u;
		FB_Motor(&fb_motor1);
  
		fb_motor2.u = Speed * fb_motor2.ke;
		FB_Motor(&fb_motor2);
	}
}

void _EXIT ProgramExit(void)
{

}
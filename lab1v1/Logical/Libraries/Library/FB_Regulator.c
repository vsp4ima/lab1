
#include <bur/plctypes.h>
#ifdef __cplusplus
  extern "C"
  {
#endif
#include "Library.h"
#ifdef __cplusplus
  };
#endif

void FB_Regulator(struct FB_Regulator* inst)
{
	//vremennye peremennye
	REAL a = inst->e * inst ->k_p;
	REAL b = inst->e * inst ->k_i;
  	//ogranichenie napryazeniya
	
	a = a > inst->max_abs_value ? inst ->max_abs_value : a;
	a = a < -inst ->max_abs_value ? -inst ->max_abs_value : a;
  	
	inst->integrator.in = b + inst->iyOld;
  
	FB_Integrator(&inst->integrator);
  
	REAL sum = a + inst->integrator.out;
	inst->u = sum;
	
	//ogranichenie napryazeniya
	inst->u = inst->u > inst->max_abs_value ? inst->max_abs_value : inst->u;
	inst->u = inst->u < -inst->max_abs_value ? inst->max_abs_value : inst->u;
	
	inst->iyOld = inst->u - sum;
}
#include<reg51.h>


#include "..\seg7\seg7.h"

int keyscan(void)
{
	while(1)
	{
		if(P1^5==0)
		{
			delay(10);
			if(P1^5==0)
			return 1;
			else 
			return 0;
		}
		return 0;
	 }
  //  return 1;
}
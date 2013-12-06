#ifndef _ORC_FACTORY
#define _ORC_FACTORY
#include "Orc.h"
#include <string>
class OrcFactory
{
private:
	static OrcFactory* _me;
	OrcFactory(void);
public:
	~OrcFactory(void);
	Orc* CreateOrc(string _name);
	static OrcFactory* GetInstance();
};

#endif


	

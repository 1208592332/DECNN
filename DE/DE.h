#ifndef DE_H
#define DE_H
/* FileName: DE.h */


#include "IDE.h"

class DE : public IDE {

public:

	DE() {}
	DE(int dim, int np, int func_type, double global_opt, double opt_val) :
		IDE( dim, np, func_type, global_opt, opt_val) {}
	
	virtual ~DE() ;
	double _de(int lock);	
	void _mutation(int ind_index);
	void _cross_over(int ind_index);
	void _selection(int ind_index);

};

#endif


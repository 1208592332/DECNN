
/* FileName: MDE.cpp */

#include "MDE.h"


MDE::~MDE() {

}



void MDE::_mutation( int ind_index ) {
	
	// 	find r1, r2, r3 which r1 != r2 != r3 != i
	int r1, r2, r3;
	
	do { r1 = rand() % _np; } while ( r1 == ind_index ) ;
	do { r2 = rand() % _np; } while ( r2 == ind_index || r2 == r1 );
	do { r3 = rand() % _np; } while ( r3 == ind_index || r3 == r2 || r3 == r1 ) ;
	
	for ( int j = 0; j < _dim; j ++) {
		(_mu_pop->_inds[ind_index])._x[j] = _cur_pop->_inds[r1]._x[j] + 
										  (_cur_pop->_inds[r2]._x[j] - _cur_pop->_inds[r3]._x[j]) * F;
		if ( _mu_pop->_inds[ind_index]._x[j] > _func->_x_right_bound[j] || 
				_mu_pop->_inds[ind_index]._x[j] < _func->_x_left_bound[j] ) {
			_mu_pop->_inds[ind_index]._x[j] = _cur_pop->_inds[ind_index]._x[j];
		}
	}

}

void MDE::_cross_over( int ind_index ) {

	int   chose = rand() % _dim;
	for ( int j = 0; j < _dim; j ++) {
		double rate = ( rand() / (double) RAND_MAX );
		if ( rate < CR || j == chose ) {
			_lab_pop->_inds[ind_index]._x[j] = _mu_pop->_inds[ind_index]._x[j];
		} else {
			_lab_pop->_inds[ind_index]._x[j] = _cur_pop->_inds[ind_index]._x[j];
		}
	}

}

void MDE::_selection( int ind_index ) {
		
	double fit_cur_pop = _fitness(_cur_pop->_inds[ind_index]);
	double fit_lab_pop = _fitness(_lab_pop->_inds[ind_index]);
	_cur_pop->_inds[ind_index]._fit_val = fit_cur_pop;
	_lab_pop->_inds[ind_index]._fit_val = fit_lab_pop;
	
	if ( fit_cur_pop > fit_lab_pop ) {
		for ( int j = 0; j < _dim; j ++) {
			_cur_pop->_inds[ind_index]._x[j] = _lab_pop->_inds[ind_index]._x[j];
		}
	}
	
}

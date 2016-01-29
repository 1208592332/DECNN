#ifndef ConvNeuralNetwork_H_
#define ConvNeuralNetwork_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "layer.h"

using namespace std;

#define D 28 * 28
#define ON 10

class ConvNeuralNetwork {


public:
	vector<Layer*> 	_layers;	// ��
	int 			_param_cnt;	// �������� 2204
	double			**_x;
	int				**_y;
	double			**_t_x;
	int				**_t_y;
	
	int				_train_sample_cnt;
	int				_test_sample_cnt;
	
	ConvNeuralNetwork() {}
	
	ConvNeuralNetwork( int param_cnt, int train_sample_cnt, int test_sample_cnt) :
	   	_param_cnt(param_cnt),
   		_train_sample_cnt(train_sample_cnt),
		_test_sample_cnt(test_sample_cnt) {
		
		_x = new double*[_train_sample_cnt];
		if ( NULL == _x ) {
			cerr << "[ERROR] bad alloc for _x in ConvNeuralNetwork !" << endl;
			exit (0);
		}
		
		_y = new int*[_train_sample_cnt];
		if ( NULL == _y ) {
			cerr << "[ERROR] bad alloc for _y in ConvNeuralNetwork !" << endl;
			exit (0);
		}
		
		for ( int i = 0; i < _train_sample_cnt; ++i) {
			_x[i] = new double[D];
			_y[i] = new int[ON];
			
			if ( NULL == _x[i] ) {
				cerr << "[ERROR] bad alloc for _x[i] in ConvNeuralNetwork !" << endl;
				exit (0);
			}
			
			if ( NULL == _y[i] ) {
				cerr << "[ERROR] bad alloc for _y[i] in ConvNeuralNetwork !" << endl;
				exit (0);
			}
			
		}
		
		_t_x = new double*[_test_sample_cnt];
		
		if ( NULL == _t_x ) {
			cerr << "[ERROR] bad alloc for _t_x in ConvNeuralNetwork !" << endl;
			exit (0);
		}
		
		_t_y = new int*[_test_sample_cnt];
		if ( NULL == _t_y ) {
			cerr << "[ERROR] bad alloc for _t_y in ConvNeuralNetwork !" << endl;
			exit (0);
		}
		
		for ( int i = 0; i < _test_sample_cnt; ++i) {
			_t_x[i] = new double[D];
			_t_y[i] = new int[ON];
			
			if ( NULL == _t_x[i] ) {
				cerr << "[ERROR] bad alloc for _t_x[i] in ConvNeuralNetwork !" << endl;
				exit (0);
			}
			
			if ( NULL == _t_y[i] ) {
				cerr << "[ERROR] bad alloc for _t_y[i] in ConvNeuralNetwork !" << endl;
				exit (0);
			}
			
		}
		
	}	
	// �����������ľ���ˡ�ƫ�á�ȫ���Ӳ�Ȩֵת
	// ��Ϊ����ݻ��㷨����ı���ֵ����Ҫ�Ǿ��
	void 	_transfer_to_dev(double *a);
	// ������Ϊlen�ĸ���ı���ֵ����Ϊ����������
	// ����ˡ�ƫ���Լ�ȫ���Ӳ�Ȩֵ
	void 	_get_from_dev(const double *a);
	// ���Ӳ�
	void 	_add_layer(Layer* &layer);
	// ����һ������ͼ������(v�������ת��һά��ͼ������),�������
	double*	_calculate(double *v);
	// ����һ������ͼ�������Լ����ǩ(�����Ӧ�����ֵı���)����������ļ������
	double	_cost_val_sig(double *v, int *y);
	// ����ѵ������
	void	_load_train_data();
	// ���ز�������
	void	_load_test_data();
	// �����ʼ��
	void	_init_net();
	// ����
	void	_test();
	
	// ʹ��BP����ѵ��
	// void train();
};

#endif

//----------------------------------------------------------------------//
// 	   ����� ����������: ����� �����-����� 4-�� �������					//
//��� ������� ����������������� ��������� 2-�� ������� ����				//
//				x'' = f(t, x, x')										//
//																		//
// ����������� �����: RungeKutta_method.cpp ; RungeKutta_method.h		//
//																		//
// �������� ������:														//
// 0) ����������������� �������: x'' = f(t, x, x')						//
// double funkX(double t,double x,double v)								//
// return  (x>0 ? -(1./2) : +(1./2)) - (0.2/2.)*v - (9.8/2.) * sin(x);	//
// 1)���������� ����� � ���� ������										//
//		#include "RungeKutta_method.h"									//
// 2) ������� ������ ������ � ��������� ���������� �����������	(2 ���.)//
// 2.1) RungeKutta_method pendulum (0,		//���. ����������,			//
//									0,		//���. ���������,			//
//									0,		//����� ���. �������,		//
//									funkX								//
//									);									//
// 2.2) RungeKutta_method pendulum;										//
//		pendulum.resetAll (			0,		//���. ����������,			//
//									0,		//���. ���������,			//
//									0,		//����� ���. �������,		//
//									funkX	);							//
// 3)������� ����� getNextPosition,										//
//��� ��������� ��������� ���������� ����� ����� ������ t				//
//		double xNewPosition = pendulum.getNextPosition(					//
//									0.1		//����� ����				//
//									);									//
// *��� ������ � ��������� �������,										//
//��������������� �������� resetToBeginning								//
//----------------------------------------------------------------------//

#pragma once

struct state_system {
	double x, v, t;
};

class RungeKutta_method
{
private:
	//------------------����:-------------------//
	
	//������� �� ��������� ����
	bool _initialization_status;

	//���������� ������							x
	double _x;

	//�������� ������/������ ����������� �����.	x'
	double _x_1degree;

	//����� ������								t
	double _t;

	//������� �������� ���������,
	//���-��� ��-��� 2-��� �������				x'' = f(t, x, x')
	double (*_move_function)(double t, double x, double x_1degree);

	//-----------------������:------------------//

	//k1
	double _k1(double& delta_t);

	//k2
	double _k2(double& k1, double& delta_t);

	//k3
	double _k3(double& k1, double& k2, double& delta_t);

	//k4
	double _k4(double& k2, double& k3, double& delta_t);

	//x_(k+1)
	double _x_kPlusOne(double& k1, double& k2, double& k3, double& delta_t);

	//x_(k+1)
	double _x_kPlusOne_1degree(double& k1, double& k2, double& k3, double& k4, double& delta_t);

public:

	//--------------������������:---------------//

	RungeKutta_method();

	//������� ��������� ������� � ������� ��������
	RungeKutta_method(
		double& x0, double& x0_1degree, double& t0,
		double (*move_function)(double t, double x, double x_1degree)
	);
	//-----------------������:------------------//

	//����� �����
	void resetAll(
		double& x0, double& x0_1degree, double& t0,
		double (*move_function)(double t, double x, double x_1degree)
	);

	//����� � ��������� ����������
	void resetToBeginning(double& x0, double& x0_1degree, double& t0);

	//������� ��������� ��������� �������
	state_system getNextPosition(double& delta_t);
};


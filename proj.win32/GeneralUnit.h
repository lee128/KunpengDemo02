#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GeneralUnit :public Sprite
{
public:

	//Ѫ��
	int health;


	//��Ӫ��ͬһ����Ӫ�ĵ�λ���������˴ˣ���ͬ��Ӫ�ĵ�λ�˴�Ϊ�С��ݶ�������Ӫ��1��С����Ӫ��2��
	int camp;


	//�������ӿ�����Ҫ��¶������
	void wanderAbout();//AI������д����ÿ֡�������������
	void getHurt();//����������
	void die();//����������

	static GeneralUnit * create(const std::string & filename);

	GeneralUnit();
	~GeneralUnit();
};


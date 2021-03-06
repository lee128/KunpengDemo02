#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GeneralUnit :public Sprite
{
public:

	//血量
	int health;


	//阵营。同一个阵营的单位攻击不到彼此，不同阵营的单位彼此为敌。暂定主角阵营是1，小怪阵营是2。
	int camp;


	//这三个接口是需要暴露出来的
	void wanderAbout();//AI由你们写。我每帧都调用这个方法
	void getHurt();//由我来调用
	void die();//由我来调用

	static GeneralUnit * create(const std::string & filename);

	GeneralUnit();
	~GeneralUnit();
};


#include "HeroSprite.h"


HeroSprite::HeroSprite()
{
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_00.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_01.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_02.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_03.jpg");
	this->hoveringAnimation->setDelayPerUnit(0.5f);
	this->hoveringAnimation->setRestoreOriginalFrame(true);


	//�������ڵ�3֡�͵�1֡�ϼ��¼������ӣ����лص�������lambda��������ʽ����
	ValueMap hoveringAnimationFrame03info;
	ValueMap hoveringAnimationFrame01info;
	hoveringAnimationFrame03info["1"] = Value(1);//�����ø�infoָ��һ���µ�ַ��û�б���ô�
	hoveringAnimationFrame01info["2"] = Value(2);//�����ø�infoָ��һ���µ�ַ��û�б���ô�
	//log("here three = %s,", hoveringAnimationFrame04info["FrameId"].asString());//��֪Ϊʲô�������string��string���ɣ�����ֻ����ȷ������֡�

	hoveringAnimation->getFrames().at(3)->setUserInfo(hoveringAnimationFrame03info);
	hoveringAnimation->getFrames().at(1)->setUserInfo(hoveringAnimationFrame01info);


	EventListenerCustom * hoveringAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringAnimationFrame03info, hoveringAnimationFrame01info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		log("Target %p with data %s , if this frame added 03 = %d. ", userData->target, Value(userData->userInfo).getDescription().c_str(), *userData->userInfo == hoveringAnimationFrame03info);
		//log("Value(userData->userInfo).asString = %s",Value(userData->userInfo).asString());
		if (*userData->userInfo == hoveringAnimationFrame03info){
			this->setPositionY(this->getPositionY() + 33);
		}
		if (*userData->userInfo == hoveringAnimationFrame01info){
			this->setPositionY(this->getPositionY() - 33);
		}
	});

	//�����¼���ӵ��¼��ַ���
	_eventDispatcher->addEventListenerWithFixedPriority(hoveringAnimationFrameEventListener, -1);
	//֡�¼����ӽ�����


	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
	this->hoveringAnimation->retain();

	



	this->movingUpAnimation = Animation::create();
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpAnimation->setDelayPerUnit(0.5f);
	this->movingUpAnimation->setRestoreOriginalFrame(true);
	this->movingUpAnimation->retain();

	this->movingDownAnimation = Animation::create();
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownAnimation->setDelayPerUnit(0.5f);
	this->movingDownAnimation->setRestoreOriginalFrame(true);
	this->movingDownAnimation->retain();

	this->movingRightAnimation = Animation::create();
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingRightAnimation->setDelayPerUnit(0.5f);
	this->movingRightAnimation->setRestoreOriginalFrame(true);
	this->movingRightAnimation->retain();

	this->movingUpRightAnimation = Animation::create();
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpRightAnimation->setDelayPerUnit(0.5f);
	this->movingUpRightAnimation->setRestoreOriginalFrame(true);
	this->movingUpRightAnimation->retain();

	this->movingDownRightAnimation = Animation::create();
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownRightAnimation->setDelayPerUnit(0.5f);
	this->movingDownRightAnimation->setRestoreOriginalFrame(true);
	this->movingDownRightAnimation->retain();

	this->movingLeftAnimation = Animation::create();
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingLeftAnimation->setDelayPerUnit(0.5f);
	this->movingLeftAnimation->setRestoreOriginalFrame(true);
	this->movingLeftAnimation->retain();

	this->movingDownLeftAnimation = Animation::create();
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownLeftAnimation->setDelayPerUnit(0.5f);
	this->movingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->movingDownLeftAnimation->retain();

	this->movingUpLeftAnimation = Animation::create();
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpLeftAnimation->setDelayPerUnit(0.5f);
	this->movingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->movingUpLeftAnimation->retain();

	this->blowingWindAnimation = Animation::create();
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_00.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_01.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_02.jpg");
	this->blowingWindAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_03.jpg");
	this->blowingWindAnimation->setDelayPerUnit(0.2f);
	this->blowingWindAnimation->setRestoreOriginalFrame(true);
	this->blowingWindAnimation->retain();


	this->windBulletFlyingAnimation = Animation::create();
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_00.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_01.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_02.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_03.jpg");
	this->windBulletFlyingAnimation->setDelayPerUnit(0.2f);
	this->windBulletFlyingAnimation->setRestoreOriginalFrame(true);
	this->windBulletFlyingAnimation->retain();


	//dashing animations would need frame events.
	this->dashingRightAnimation = Animation::create();
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_00.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_01.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_02.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_03.jpg");
	this->dashingRightAnimation->setDelayPerUnit(0.4f);
	this->dashingRightAnimation->setRestoreOriginalFrame(true);
	this->dashingRightAnimation->retain();

	this->dashingDownRightAnimation = Animation::create();
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_00.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_01.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_02.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_03.jpg");
	this->dashingDownRightAnimation->setDelayPerUnit(0.4f);
	this->dashingDownRightAnimation->setRestoreOriginalFrame(true);
	this->dashingDownRightAnimation->retain();

	this->dashingUpRightAnimation = Animation::create();
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_00.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_01.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_02.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_03.jpg");
	this->dashingUpRightAnimation->setDelayPerUnit(0.4f);
	this->dashingUpRightAnimation->setRestoreOriginalFrame(true);
	this->dashingUpRightAnimation->retain();

	this->dashingLeftAnimation = Animation::create();
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_00.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_01.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_02.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_03.jpg");
	this->dashingLeftAnimation->setDelayPerUnit(0.4f);
	this->dashingLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingLeftAnimation->retain();

	this->dashingUpLeftAnimation = Animation::create();
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_00.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_01.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_02.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_03.jpg");
	this->dashingUpLeftAnimation->setDelayPerUnit(0.4f);
	this->dashingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingUpLeftAnimation->retain();

	this->dashingDownLeftAnimation = Animation::create();
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_00.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_03.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_03.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_03.jpg");
	this->dashingDownLeftAnimation->setDelayPerUnit(0.4f);
	this->dashingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingDownLeftAnimation->retain();



}


HeroSprite::~HeroSprite()
{
}


HeroSprite * HeroSprite::create(const std::string &filename){
	HeroSprite *mySprite = new HeroSprite();
	if (mySprite &&mySprite->initWithFile(filename)){
		mySprite->autorelease();
		return mySprite;
	}
	CC_SAFE_DELETE(mySprite);
	return nullptr;
}
void HeroSprite::windAttack(){
	this->stopAllActions();
	this->move();
	this->runAction(Animate::create(this->blowingWindAnimation));
	Sprite * windBullet = Sprite::create();
	windBullet->setPosition(this->getPosition());
	this->getParent()->addChild(windBullet);
	windBullet->runAction(Spawn::create(MoveBy::create(0.4f,Vec2(300,0)),Repeat::create(Animate::create(this->windBulletFlyingAnimation),2),nullptr));
}

//���move���⿪�ţ����ǵ���ͨ�ƶ�ֻ��������Ϊ�˵��Է��㣬����ϸ��Ŀǰ����public���˷����ƶ�������ʱ��public�����Ӧ��Ϊprivate��
//�ڴ���֤�������ڵ���move����ʱ�Ŀ��ƶ��ԡ�
//one more �ϻ���move��˵����ť��ɵ�λ�ƣ�dash��˵��̼�����ɵ�λ�ơ�
void HeroSprite::move(){
	if (this->moveable){
		if (this->directionToMoveRight) {
			moveRight();
		}
		if (this->directionToMoveLeft){
			moveLeft();
		}
		if (this->directionToMoveUp){
			moveUp();
		}
		if (this->directionToMoveDown){
			moveDown();
		}

		if (this->directionToMoveUpRight){
			moveUpRight();
		}
		if (this->directionToMoveUpLeft){
			moveUpLeft();
		}
		if (this->directionToMoveDownRight){
			moveDownRight();
		}
		if (this->directionToMoveDownLeft){
			moveDownLeft();
		}
		if (this->directionToMoveUpRight == false &&
			this->directionToMoveRight == false &&
			this->directionToMoveDownRight == false &&
			this->directionToMoveDown == false &&
			this->directionToMoveDownLeft == false &&
			this->directionToMoveLeft == false &&
			this->directionToMoveUpLeft == false &&
			this->directionToMoveUp == false){
			moveBrake();
		}
	}
}
//moving in 8 directions
//�����������ƶ��Ͳ����ƶ�����һ��runһ�£�û���Ƿ���ƶ�����֤��ʣ�µ��߸�������Ȼ���Ժ�Ҫ�����˴��������
void HeroSprite::moveRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();

	//this->runAction(Spawn::create(RepeatForever::create(MoveBy::create(2.0f,Vec2(33,0))),RepeatForever::create(Animate::create(this->movingRightAnimation)),nullptr));//��֪Ϊ�Σ������ò��ˣ���ʾ[Action update] override me
	/*
	Sequence��Spawn���ǲ��ܺ�RepeatForeverһ���õġ����ɼ�Դ�룬RepeatForever��interval = 0��������������������һ���̡�
	*/
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingRightAnimation)));
}
void HeroSprite::moveLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingLeftAnimation)));
}
void HeroSprite::moveUp(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->speed_flying_pixel_per_second))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpAnimation)));
}
void HeroSprite::moveDown(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->speed_flying_pixel_per_second))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownAnimation)));
}
void HeroSprite::moveUpRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.4142, this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));
}
void HeroSprite::moveUpLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.4142, this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation)));
}
void HeroSprite::moveDownRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.4142, -this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
}
void HeroSprite::moveDownLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.4142, -this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation)));
}


//brakes after moving����Ȼ��ʱû���꣬����һ��Ҫ���ġ����ϵ������������
void HeroSprite::moveRightBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
void HeroSprite::moveLeftBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
void HeroSprite::moveDownBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
void HeroSprite::moveUpBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
void HeroSprite::moveBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringAnimation)));
}
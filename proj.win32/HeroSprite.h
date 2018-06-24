#pragma once
#include "cocos2d.h"
USING_NS_CC;
class HeroSprite :	public Sprite
{

public:

	int speed_flying_pixel_per_second = 266;
	int speed_swimming_pixel_per_second = 200;

	//��ͣ����
	Animation * hoveringAnimation;

	//��ͨ�ƶ��Ķ���
	Animation * movingUpAnimation;	
	Animation * movingUpRightAnimation;
	Animation * movingRightAnimation;
	Animation * movingDownRightAnimation;
	Animation * movingDownAnimation;
	Animation * movingDownLeftAnimation;
	Animation * movingLeftAnimation;
	Animation * movingUpLeftAnimation;




	//��̶���
	Animation * dashingUpAnimation;
	Animation * dashingUpRightAnimation;
	Animation * dashingRightAnimation;
	Animation * dashingDownRightAnimation;
	Animation * dashingDownAnimation;
	Animation * dashingDownLeftAnimation;
	Animation * dashingLeftAnimation;
	Animation * dashingUpLeftAnimation;

	//���ܶ���
	Animation * blowingWindAnimation;
	Animation * scratchingAnimation;

	Animation * tryCatchAnimation;//��ͼʹ��һ��Ͷ��
	Animation * holdingObjectAnimation;//ץס��Ʒ���ŵĶ���
	Animation * holdingEnemyAnimation;//ץס���˲��ŵĶ���
	Animation * throwingObjectAnimation;//�ӳ���Ʒ�Ķ���
	Animation * throwingEnemyAnimationi;//��С��ʹ��Ͷ���Ķ���

	Animation * throwingBossAnimation;//��Bossʹ��Ͷ���Ķ���

	Animation * windBulletFlyingAnimation;


	//���ǲ���������㣬û�е�����������
	bool isBird = true;
	bool isFish = false;

	//���ǵ��˶�״̬����Щ״̬�뼼��ʩ���йء����磬ֻ���ڷ���ʱ����ʩ�ŷ絯
	bool facingRight = true;
	bool facingLeft = false;
	bool flying = true;
	//bool walking = false;//�������ǽ����ڵ��沢���챼�ܵĹ���
	bool swimming = false;

	//�������ڸ��
	bool moving = false;
	bool windAttacking = false;
	bool pawAttacking = false;
	bool pawTryingCatch = false;
	bool pawHolding = false;
	bool pawThrowing = false;
	bool pawThrowingBoss = false;

	//���ǵ�ǰ�ܸ����״̬��
	bool moveable = true;//�������ƶ�
	bool longRangeAttackable = true;//���δ��ռ�ã��ܷ���絯
	bool pawAttackable = true;//צ��δ��ռ�ã���˺����������ʹ��צ��������Ʒ�����ʱ������Ϊfalse������Ϊfalseʱ��ʹ���˽���Ҳ�޷�������սצ�ӹ���
	bool dashable = true;//�ܷ��̡�
	bool catchable = true;//צ���ܷ�ץ�������������鰲�Ż�����˺��ʱ����Ϊfalse��
	bool throwable = true;//�ܷ�צ���ϵĶ����ӳ����������ǲ���һ�Ķ��á������ǰ����ʹ�ó����絯�������Ϊfalse������Ϊfalseʱ����throw���������ᴥ�����˱����µĶ��������������˴�צ������˳ë���·��������Ķ�����

	bool invincible = false;//�Ƿ��޵С�Ϊ����������峡���������µ��������������޵У�Ϊ�������ˬ������Ͷbossʱ����������Ϊ�޵С�



	bool directionToMoveRight = false;
	bool directionToMoveLeft = false;
	bool directionToMoveUp = false;
	bool directionToMoveDown = false;
	bool directionToMoveUpRight = false;
	bool directionToMoveUpLeft = false;
	bool directionToMoveDownRight = false;
	bool directionToMoveDownLeft = false;

	int lastDirection = 0;//0����1�J��2����3�K��4����5�L��6����7�I

	bool DirectionToPawhold = false;

	static HeroSprite * create(const std::string & filename);

	void move();//������ء�����**����һ����ʱ����**����
	void move(double direction);
	void moveBrake();


	void moveRight();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveUpRight();
	void moveUpLeft();
	void moveDownRight();
	void moveDownLeft();


	void moveRightBrake();
	void moveUpBrake();
	void moveDownBrake();
	void moveLeftBrake();
	void moveUpRightBrake();
	void moveUpLeftBrake();
	void moveDownRightBrake();
	void moveDownLeftBrake();

	


	void windAttack();//�������
	void pawAttack();
	void pawHold();//����**����һ����ʱ����**����
	void pawThrowObject();
	void pawThrowEnemy();
	void pawThrowBoss();//�������

	void getHurt();//�������
	void getHurtByThunder();
	void getHurtByFire();
	void getHurtByWater();
	void getHurtByHammer();//������������
	void getHurtByHammer(double direction);//���ɷ���Ϊdirection��0�������ϴ��ɣ�90�������Ҵ��ɣ�180�������´��ɣ�270�������󴵷ɡ�
	void getHurtByWind();

	HeroSprite();
	~HeroSprite();
};


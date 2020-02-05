#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

HRESULT Player::Init()
{
	//player.playerHeadImage = IMAGEMANAGER->findImage(imageName);								//�Ӹ� �̹���
	//player.playerBodyImage = IMAGEMANAGER->findImage(imageName);								//�� �̹���
	player.playerHeadRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 64, 62);					//�Ӹ� ����
	player.playerBodyRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 - 62, 64, 62);			//�� ����
	player.playerSpeed = 6.0f;																	//�̵��ӵ�
	player.playerSlideSpeed = 3.0f;																//�����̵� �ӵ�

	//�÷��̾� ���� ���� �ʱ�ȭ
	isLeft = false;
	isRight = false;
	isUp = false;
	isDown = false;
	//�÷��̾� �����̵� ���� �ʱ�ȭ
	slideLeft = false;
	slideRight = false;
	slideUp = false;
	slideDown = false;
	//�÷��̾� �밢 �����̵� ���� �ʱ�ȭ
	slideLeftUp = false;
	slideLeftDown = false;
	slideRightUp = false;
	slideRightDown = false;

	return S_OK;
}

void Player::Release()
{
}

void Player::Update()
{
	PlayerMove();
	PlayerSilde();
}

void Player::Render(HDC hdc)
{
	Rectangle(hdc, player.playerHeadRect.left, player.playerHeadRect.top, player.playerHeadRect.right, player.playerHeadRect.bottom);
	Rectangle(hdc, player.playerBodyRect.left, player.playerBodyRect.top, player.playerBodyRect.right, player.playerBodyRect.bottom);
}

void Player::PlayerMove()
{
	//����
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		isLeft = true;
		player.playerHeadRect.left -= player.playerSpeed;
		player.playerHeadRect.right -= player.playerSpeed;
		player.playerBodyRect.left -= player.playerSpeed;
		player.playerBodyRect.right -= player.playerSpeed;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		if (isUp) slideLeftUp = true;
		else if (isDown) slideLeftDown = true;
		else slideLeft = true;
	}

	//������
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		isRight = true;
		player.playerHeadRect.left += player.playerSpeed;
		player.playerHeadRect.right += player.playerSpeed;
		player.playerBodyRect.left += player.playerSpeed;
		player.playerBodyRect.right += player.playerSpeed;
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		if (isUp) slideRightUp = true;
		else if (isDown) slideRightDown = true;
		else slideRight = true;
	}

	//��
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		isUp = true;
		player.playerHeadRect.top -= player.playerSpeed;
		player.playerHeadRect.bottom -= player.playerSpeed;
		player.playerBodyRect.top -= player.playerSpeed;
		player.playerBodyRect.bottom -= player.playerSpeed;
	}
	if (KEYMANAGER->isOnceKeyUp('W'))
	{
		if (isLeft) slideLeftUp = true;
		else if (isRight) slideRightUp = true;
		else slideUp = true;
	}

	//�Ʒ�
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		isDown = true;
		player.playerHeadRect.top += player.playerSpeed;
		player.playerHeadRect.bottom += player.playerSpeed;
		player.playerBodyRect.top += player.playerSpeed;
		player.playerBodyRect.bottom += player.playerSpeed;
	}
	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		if (isLeft) slideLeftDown = true;
		else if (isRight) slideRightDown = true;
		else slideDown = true;
	}
}

void Player::PlayerSilde()
{
	//���� �����̵�
	if (slideLeft)
	{
		player.playerSlideSpeed = player.playerSlideSpeed * 0.9f;
		player.playerHeadRect.left -= player.playerSlideSpeed;
		player.playerHeadRect.right -= player.playerSlideSpeed;
		player.playerBodyRect.left -= player.playerSlideSpeed;
		player.playerBodyRect.right -= player.playerSlideSpeed;
		if (player.playerSlideSpeed < 1.2f)
		{
			player.playerSlideSpeed = 3.0f;
			isLeft = false;
			slideLeft = false;
		}
	}
	//������ �����̵�
	if (slideRight)
	{
		player.playerSlideSpeed = player.playerSlideSpeed * 0.9f;
		player.playerHeadRect.left += player.playerSlideSpeed;
		player.playerHeadRect.right += player.playerSlideSpeed;
		player.playerBodyRect.left += player.playerSlideSpeed;
		player.playerBodyRect.right += player.playerSlideSpeed;
		if (player.playerSlideSpeed < 1.2f)
		{
			player.playerSlideSpeed = 3.0f;
			isRight = false;
			slideRight = false;
		}
	}
	//���� �����̵�
	if (slideUp)
	{
		player.playerSlideSpeed = player.playerSlideSpeed * 0.9f;
		player.playerHeadRect.top -= player.playerSlideSpeed;
		player.playerHeadRect.bottom -= player.playerSlideSpeed;
		player.playerBodyRect.top -= player.playerSlideSpeed;
		player.playerBodyRect.bottom -= player.playerSlideSpeed;
		if (player.playerSlideSpeed < 1.2f)
		{
			player.playerSlideSpeed = 3.0f;
			isUp = false;
			slideUp = false;
		}
	}
	//�Ʒ��� �����̵�
	if (slideDown)
	{
		player.playerSlideSpeed = player.playerSlideSpeed * 0.9f;
		player.playerHeadRect.top += player.playerSlideSpeed;
		player.playerHeadRect.bottom += player.playerSlideSpeed;
		player.playerBodyRect.top += player.playerSlideSpeed;
		player.playerBodyRect.bottom += player.playerSlideSpeed;
		if (player.playerSlideSpeed < 1.2f)
		{
			player.playerSlideSpeed = 3.0f;
			isDown = false;
			slideDown = false;
		}
	}

	//������ �����̵�
	if (slideLeftUp)
	{
		player.playerSlideSpeed = player.playerSlideSpeed * 0.9f;
		player.playerHeadRect.left -= player.playerSlideSpeed;
		player.playerHeadRect.right -= player.playerSlideSpeed;
		player.playerBodyRect.left -= player.playerSlideSpeed;
		player.playerBodyRect.right -= player.playerSlideSpeed;
		player.playerHeadRect.top -= player.playerSlideSpeed;
		player.playerHeadRect.bottom -= player.playerSlideSpeed;
		player.playerBodyRect.top -= player.playerSlideSpeed;
		player.playerBodyRect.bottom -= player.playerSlideSpeed;
		if (player.playerSlideSpeed < 1.2f)
		{
			player.playerSlideSpeed = 3.0f;
			isLeft = false;
			isUp = false;
			slideLeftUp = false;
		}
	}
	//���ʾƷ� �����̵�
	if (slideLeftDown)
	{
		player.playerSlideSpeed = player.playerSlideSpeed * 0.9f;
		player.playerHeadRect.left -= player.playerSlideSpeed;
		player.playerHeadRect.right -= player.playerSlideSpeed;
		player.playerBodyRect.left -= player.playerSlideSpeed;
		player.playerBodyRect.right -= player.playerSlideSpeed;
		player.playerHeadRect.top += player.playerSlideSpeed;
		player.playerHeadRect.bottom += player.playerSlideSpeed;
		player.playerBodyRect.top += player.playerSlideSpeed;
		player.playerBodyRect.bottom += player.playerSlideSpeed;
		if (player.playerSlideSpeed < 1.2f)
		{
			player.playerSlideSpeed = 3.0f;
			isLeft = false;
			isDown = false;
			slideLeftDown = false;
		}
	}
	//�������� �����̵�
	if (slideRightUp)
	{
		player.playerSlideSpeed = player.playerSlideSpeed * 0.9f;
		player.playerHeadRect.left += player.playerSlideSpeed;
		player.playerHeadRect.right += player.playerSlideSpeed;
		player.playerBodyRect.left += player.playerSlideSpeed;
		player.playerBodyRect.right += player.playerSlideSpeed;
		player.playerHeadRect.top -= player.playerSlideSpeed;
		player.playerHeadRect.bottom -= player.playerSlideSpeed;
		player.playerBodyRect.top -= player.playerSlideSpeed;
		player.playerBodyRect.bottom -= player.playerSlideSpeed;
		if (player.playerSlideSpeed < 1.2f)
		{
			player.playerSlideSpeed = 3.0f;
			isRight = false;
			isUp = false;
			slideRightUp = false;
		}
	}
	//�����ʾƷ� �����̵�
	if (slideRightDown)
	{
		player.playerSlideSpeed = player.playerSlideSpeed * 0.9f;
		player.playerHeadRect.left += player.playerSlideSpeed;
		player.playerHeadRect.right += player.playerSlideSpeed;
		player.playerBodyRect.left += player.playerSlideSpeed;
		player.playerBodyRect.right += player.playerSlideSpeed;
		player.playerHeadRect.top += player.playerSlideSpeed;
		player.playerHeadRect.bottom += player.playerSlideSpeed;
		player.playerBodyRect.top += player.playerSlideSpeed;
		player.playerBodyRect.bottom += player.playerSlideSpeed;
		if (player.playerSlideSpeed < 1.2f)
		{
			player.playerSlideSpeed = 3.0f;
			isRight = false;
			isDown = false;
			slideRightDown = false;
		}
	}
}
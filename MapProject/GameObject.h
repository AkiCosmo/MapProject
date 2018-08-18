#pragma once
class GameObject
{
protected:
	bool clickable;

public:
	GameObject();
	virtual ~GameObject();

	bool isClickable(void);
};


#pragma once
class VisObjects
{

protected:
	vector <GameObject*> objectList;

public:
	VisObjects();
	~VisObjects();

	int init(GameData* gameData);
	void draw(GameData* gameData);

};


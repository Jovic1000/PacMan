#pragma once
#include "B_BaseEntity.h"
class Ghost : public B_BaseEntity
{
public:

	void Update() override;
	void Render() override;

	Ghost();
	~Ghost();

private:
};


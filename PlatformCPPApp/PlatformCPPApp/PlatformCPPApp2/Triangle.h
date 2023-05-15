#include "IShape.h"

class Triangle : public IShape
{
public:
	Triangle();
	~Triangle();
	void ShowShapeInfo() override;
};
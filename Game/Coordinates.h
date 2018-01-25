#ifndef COORDINATES_H
#define COORDINATES_H
class Coordinates
{
	public:
		Coordinates();
		~Coordinates();
		Coordinates(int x, int y);
		int get_x();
		int get_y();

	private:
		int m_x;
		int m_y;

};
#endif

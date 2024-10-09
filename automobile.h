#pragma once
using namespace std;
class wheel {
protected:
	float radius;
	float width;
	string color;
public:
	wheel() :radius(0), width(0), color("") {}
	wheel(float radius, float width, string color) :radius(radius), width(width), color(color) {}
};
class engine {
protected:
	int count_cylinders;
	float power, volume;
public:
	engine() :count_cylinders(0), power(0), volume(0) {}
	engine(int count_cylinders, float power, float volume) :count_cylinders(count_cylinders), power(power), volume(volume) {}


};
class corps {
protected:
	string color;
	string type;
	float weight;
public:
	corps() :color(""), type(""), weight(0) {}
	corps(string color, string type, float weight) :color(color), type(type), weight(weight) {}
};
class automobile :public wheel, public engine, public corps
{
protected:
	int max_velocity;
	float max_accelerate;
public:
	automobile() :max_velocity(0), max_accelerate(0), corps(), engine(), wheel() {}
	automobile(float radius,
		float width,
		string color_w, int count_cylinders,
		float power, float volume, string color_c,
		string type,
		float weight, int max_velocity, float max_accelerate) :max_velocity(max_velocity), max_accelerate(max_accelerate),
		wheel(radius, width, color_w), engine(count_cylinders, power, volume), corps(color_c, type, weight) {}
	void print() {
		cout << radius << " " << width << " " << wheel::color << " " << count_cylinders << " " << power << " " << volume << " "
			<< corps::color << " \n" << type << " " << weight << " " << max_velocity << " " << max_accelerate << " "
			<< endl;
	}
};


using namespace std;
extern "C" _declspec(dllexport) void ChangeStack();
extern "C" _declspec(dllexport) void PlusOperater();
extern "C" _declspec(dllexport) void MinusOperater();
extern "C" _declspec(dllexport) void TimeOperater();
extern "C" _declspec(dllexport) void DivideOperater();
extern "C" _declspec(dllexport) void NumberPush(std::string tmp);
extern "C" _declspec(dllexport) string Calcutest();
extern "C" _declspec(dllexport) void ButtonCE();
extern "C" _declspec(dllexport) void getMaxFenMu();
extern "C" _declspec(dllexport) void fenZiChange();
extern "C" _declspec(dllexport) void ButtonBack(int NumberFlag);
extern "C" _declspec(dllexport) unsigned long gcd(unsigned long x, unsigned long y);


class  _declspec(dllexport) numerator
{
public:
	int numberOver;
	numerator(int number1)
	{
		numberOver = number1;
	}
};
class _declspec(dllexport) denominator :public numerator
{
public:
	int numberBelow;
	denominator(int number1, int number2) : numerator(number1)
	{
		numberBelow = number2;
	}
};

class _declspec(dllexport) calculator :public denominator
{
public:
	friend void ChangeStack();
	friend void PlusOperater();
	friend void MinusOperater();
	friend void TimeOperater();
	friend void DivideOperater();
	friend void NumberPush(std::string tmp);
	friend string Calcutest();
	friend void ButtonCE();
	friend void getMaxFenMu();
	friend void fenZiChange();
	friend void ButtonBack(int NumberFlag);
	friend unsigned long gcd(unsigned long x, unsigned long y);
	calculator(int x, int y) :denominator(x, y)
	{

	}
};



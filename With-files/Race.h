#ifndef Race_h
#define Race_h

const int N = 20;
const int M = 5;

class Race
{
public:
	Race();
	~Race();
	void Model(char*);
	void LicensePlate(char*);
	void Carrying(char*);
	void SetUniÑosts(int*);
	void SetRace(char*, char*, char*, int*);
	double GetTotalÑost();
	char* GetcarModel();
	char* GetlicensePlate();
	char* Getcarrying();
	void DisplayRace();
	void EnterRace();
private:
	char carModel[N], licensePlate[N], carrying[N];
	int UniÑosts[M];
	double totalÑost;
	void SetTotalÑost();
};

#endif

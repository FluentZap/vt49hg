#ifndef DICEROLLER_H
#define DICEROLLER_H

#include <stdio.h>
typedef unsigned char byte;


struct dieResult {
	byte success = 0, fail = 0, advantage = 0, threat = 0, triumph = 0, dispare = 0, darkForce = 0, lightForce = 0;

	dieResult operator+=(const dieResult& other)
	{
		this->success += other.success;
		this->fail += other.fail;
		this->advantage += other.advantage;
		this->threat += other.threat;
		this->triumph += other.triumph;
		this->dispare += other.dispare;
		this->darkForce += other.darkForce;
		this->lightForce += other.lightForce;
		return *this;
	}
};


struct diceResult {
	byte success = 0, fail = 0, advantage = 0, threat = 0, triumph = 0, dispare = 0, darkForce = 0, lightForce = 0;
	byte totalSuccess = 0, totalFail = 0, totalAdvantage = 0, totalThreat = 0;
	bool succeededRoll = false;
	bool advantageousRoll = false;
	dieResult *rolledResult;
};

class DiceRoller
{
public:
	static diceResult diceRoll(byte statistic, byte skill, byte difficulty, byte difficultyUpgrade, byte blue, byte black, byte white);
};

dieResult rollGreen();
dieResult rollYellow();
dieResult rollPurple();
dieResult rollRed();
dieResult rollBlack();
dieResult rollBlue();
dieResult rollWhite();

#endif // DICEROLLER_H


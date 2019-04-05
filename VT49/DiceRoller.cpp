#include <stdio.h>
#include <stdlib.h>
#include "DiceRoller.h"

using namespace std;

diceResult DiceRoller::diceRoll(byte statistic, byte skill, byte difficulty, byte difficultyUpgrade, byte blue, byte black, byte white) {
	byte green, yellow, purple, red;
	//byte success, fail, advantage, threat, triumph, dispare, darkForce, lightForce;
	diceResult finalResult;
	dieResult faceTotal;
	
	if (statistic >= skill){
		green = statistic - skill;
		yellow = skill;
	} else {
		green = skill - statistic;
		yellow = statistic;
	}
	if (difficulty >= difficultyUpgrade){
		purple = difficulty - difficultyUpgrade;
		red = difficultyUpgrade;
	} else {
		purple = difficultyUpgrade - difficulty;
		red = difficulty;
	}
	int diceToRoll = green + yellow + purple + red + blue + black + white;
	dieResult rolledResult[diceToRoll];
	
	int rolledDice = 0;
	while(rolledDice < diceToRoll) {
		if (green > 0) { rolledResult[rolledDice] = rollGreen(); rolledDice++; green--;}
		if (yellow > 0) { rolledResult[rolledDice] = rollYellow(); rolledDice++; yellow--;}
		if (purple > 0) { rolledResult[rolledDice] = rollPurple(); rolledDice++; purple--;}
		if (red > 0) { rolledResult[rolledDice] = rollRed(); rolledDice++; red--;}
		if (blue > 0) { rolledResult[rolledDice] = rollBlue(); rolledDice++; blue--;}
		if (black > 0) { rolledResult[rolledDice] = rollBlack(); rolledDice++; black--;}
		if (white > 0) { rolledResult[rolledDice] = rollWhite(); rolledDice++; white--;}
	}
	for (int x = 0; x < diceToRoll; x++) {
		//faceTotal += rolledResult[x];
	}
	//Success
	if (faceTotal.success > faceTotal.fail) {
		finalResult.success = faceTotal.success - faceTotal.fail;
		finalResult.succeededRoll = true;
	} else {
		finalResult.fail = faceTotal.fail - faceTotal.success;
		finalResult.succeededRoll = false;
	}
	//Advantage
	if (faceTotal.advantage > faceTotal.threat) {
		finalResult.advantage = faceTotal.advantage - faceTotal.threat;
		finalResult.advantageousRoll = true;
	} else {
		finalResult.threat = faceTotal.threat - faceTotal.advantage;
		finalResult.advantageousRoll = false;
	}
	finalResult.totalSuccess = faceTotal.success;
	finalResult.totalFail = faceTotal.fail;
	
	finalResult.totalAdvantage = faceTotal.advantage;
	finalResult.totalThreat = faceTotal.threat;
	
	finalResult.triumph = faceTotal.triumph;
	finalResult.dispare = faceTotal.dispare;
	
	finalResult.lightForce = faceTotal.lightForce;
	finalResult.darkForce = faceTotal.darkForce;
	
	finalResult.rolledResult = rolledResult;
	return finalResult;
}

dieResult rollGreen() {
	byte roll = rand() % 8;
	dieResult rolled;
	switch(roll) {
		case 0: break;
		case 1: rolled.success++; break;
		case 2: rolled.success++; break;
		
		case 3: rolled.advantage++; break;
		case 4: rolled.advantage++; break;
		
		case 5: rolled.success++; rolled.advantage++; break;
		case 6: rolled.success++; rolled.success++; break;
		case 7: rolled.advantage++; rolled.advantage++; break;
	}
	return rolled;
}

dieResult rollYellow() {
	byte roll = rand() % 12;
	dieResult rolled;
	switch(roll) {
		case 0: break;
		case 1: rolled.success++; break;
		case 2: rolled.success++; break;
		
		case 3: rolled.advantage++; break;
		
		case 4: rolled.success++; rolled.advantage++; break;
		case 5: rolled.success++; rolled.advantage++; break;
		case 6: rolled.success++; rolled.advantage++; break;
		
		case 7: rolled.success++; rolled.success++; break;
		case 8: rolled.success++; rolled.success++; break;
		
		case 9: rolled.advantage++; rolled.advantage++; break;
		case 10: rolled.advantage++; rolled.advantage++; break;

		case 11: rolled.success++; rolled.triumph++; break;
	}
	return rolled;
}

dieResult rollPurple() {
	byte roll = rand() % 8;
	dieResult rolled;
	switch(roll) {
		case 0: break;
		case 1: rolled.fail++; break;
		
		case 2: rolled.threat++; break;
		case 3: rolled.threat++; break;
		case 4: rolled.threat++; break;
		
		case 5: rolled.fail++; rolled.threat++; break;
				
		case 6: rolled.threat++; rolled.threat++; break;
		case 7: rolled.fail++; rolled.fail++; break;
	}
	return rolled;
}

dieResult rollRed() {
	byte roll = rand() % 12;
	dieResult rolled;
	switch(roll) {
		case 0: break;
		case 1: rolled.fail++; break;
		case 2: rolled.fail++; break;
		
		case 3: rolled.threat++; break;
		case 4: rolled.threat++; break;
		
		case 5: rolled.fail++; rolled.threat++; break;
		case 6: rolled.fail++; rolled.threat++; break;
		
		case 7: rolled.fail++; rolled.fail++; break;
		case 8: rolled.fail++; rolled.fail++; break;
		
		case 9: rolled.threat++; rolled.threat++; break;
		case 10: rolled.threat++; rolled.threat++; break;
		
		case 11: rolled.fail++; rolled.dispare++; break;
	}
	return rolled;
}

dieResult rollBlack() {
	byte roll = rand() % 6;
	dieResult rolled;
	switch(roll) {
		case 0: break;
		case 1: break;
		
		case 2: rolled.threat++; break;
		case 3: rolled.threat++; break;
		
		case 4: rolled.fail++; break;
		case 5: rolled.fail++; break;
	}
	return rolled;
}

dieResult rollBlue() {
	byte roll = rand() % 6;
	dieResult rolled;
	switch(roll) {
		case 0: break;
		case 1: break;
		
		case 2: rolled.success++; break;
		case 3: rolled.advantage++; break;
		
		case 4: rolled.success++; rolled.advantage++; break;
		case 5: rolled.advantage++; rolled.advantage++; break;
	}
	return rolled;
}

dieResult rollWhite() {
	byte roll = rand() % 12;
	dieResult rolled;
	switch(roll) {
		case 0: rolled.lightForce++; break;
		case 1: rolled.lightForce++; break;
		
		case 2: rolled.darkForce++; break;
		case 3: rolled.darkForce++; break;
		case 4: rolled.darkForce++; break;
		case 5: rolled.darkForce++; break;
		case 6: rolled.darkForce++; break;
		case 7: rolled.darkForce++; break;
		
		case 8: rolled.lightForce++; rolled.lightForce++; break;
		case 9: rolled.lightForce++; rolled.lightForce++; break;
		case 10: rolled.lightForce++; rolled.lightForce++; break;
		
		case 11: rolled.darkForce++; rolled.darkForce++; break;
	}
	return rolled;
}
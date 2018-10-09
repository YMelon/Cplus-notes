
#include <iostream>
#include <vector>
#include <map>
using namesapce std;

class Warrior {
public:
    Warrior(int id, int strength, int attack)
	:id(id), strength(strength), attack(attack) { }

protected:
    int id;
    int strength;
    int attack;
};


class Lion: public Warrior {
public:
    Lion(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    { cout << "lion " << id << " born with strength " << strength; }
};


class Iceman: public Warrior {
public:
    Iceman(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    { cout << "iceman " << id << " born with strength " << strength; }
};


class Dragon: public Warrior {
public:
    Dragon(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    { cout << "dragon " << id << " born with strength " << strength; }
};



class Ninja: public Warrior {
public:
    Ninja(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    { cout << "ninja " << id << " born with strength " << strength; }
};


class Wolf: public Warrior {
public:
    Wolf(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    { cout << "wolf " << id << " born with strength " << strength; }
};


class RedHeadquarter {
public:
    RedHeadquarter(int energy);
    void produceWarr(int order, int life);
    
    friend bool isProduce(const RedHeadquarter& red, map<string,int> warrStrength);
private:
    int energy;
    int time;
    int totalCount;
    int nextWarr;

    vector<string> produceWarrSeq;
    map<string, int> eachWarrCount;
};

RedHeadquarter::RedHeadquarter(int energy) 
    :energy(energy)
{
    produceWarrSeq.push_back("iceman");
    produceWarrSeq.push_back("lion");
    produceWarrSeq.push_back("wolf");
    produceWarrSeq.push_back("ninja");
    produceWarrSeq.push_back("dragon");

    time = 0;
    totalCount = 0;
    nextWarr = 0;
}

void RedHeadquarter::produceWarr(int order, int life) {
    cout << setw(3) << setfill('0') << time 
	 << " red ";

    if(produceWarrSeq[order] == "iceman") {
	Iceman ice(++totalCount, life);
	cout << "," << ++ eachWarrCount["iceman"] 
	     << " iceman in red headquarter" << endl;
    }
    else if(produceWarrSeq[order] == "lion") {
	Lion lion(++totalCount, life);
	cout << "," << ++ eachWarrCount["lion"] 
	     << " lion in red headquarter" << endl;
    }
    else if(produceWarrSeq[order] == "wolf") {
	Wolf wolf(++totalCount, life);
	cout << "," << ++ eachWarrCount["wolf"] 
	     << " wolf in red headquarter" << endl;
    }
    else if(produceWarrSeq[order] == "ninja") {
	Ninja nin(++totalCount, life);
	cout << "," << ++ eachWarrCount["ninja"] 
	     << " ninja in red headquarter" << endl;
    }
    else if(produceWarrSeq[order] == "dragon") {
	Dragon dragon(++totalCount, life);
	cout << "," << ++ eachWarrCount["dragon"] 
	     << " dragon in red headquarter" << endl;
    }

    energy -= life;
    time ++;
    nextWarr = (order+1) % 5;
}


class BlueHeadquarter {
public:
    BlueHeadquarter(int energy);
    void produceWarr(int order, int life);
    
    friend bool isProduce(const BlueHeadquarter& blue, map<string,int> warrStrength);
private:
    int energy;
    int time;
    int totalCount;
    int nextWarr;

    vector<string> produceWarrSeq;
    map<string, int> eachWarrCount;
};

BlueHeadquarter::BlueHeadquarter(int energy) 
    :energy(energy)
{
    produceWarrSeq.push_back("lion");
    produceWarrSeq.push_back("dragon");
    produceWarrSeq.push_back("ninja");
    produceWarrSeq.push_back("iceman");
    produceWarrSeq.push_back("wolf");

    time = 0;
    totalCount = 0;
    nextWarr = 0;
}

void BlueHeadquarter::produceWarr(int order, int life) {
    cout << setw(3) << setfill('0') << time 
	 << " blue ";

    if(produceWarrSeq[order] == "iceman") {
	Iceman ice(++totalCount, life);
	cout << "," << ++ eachWarrCount["iceman"] 
	     << " iceman in blue headquarter" << endl;
    }
    else if(produceWarrSeq[order] == "lion") {
	Lion lion(++totalCount, life);
	cout << "," << ++ eachWarrCount["lion"] 
	     << " lion in blue headquarter" << endl;
    }
    else if(produceWarrSeq[order] == "wolf") {
	Wolf wolf(++totalCount, life);
	cout << "," << ++ eachWarrCount["wolf"] 
	     << " wolf in blue headquarter" << endl;
    }
    else if(produceWarrSeq[order] == "ninja") {
	Ninja nin(++totalCount, life);
	cout << "," << ++ eachWarrCount["ninja"] 
	     << " ninja in blue headquarter" << endl;
    }
    else if(produceWarrSeq[order] == "dragon") {
	Dragon dragon(++totalCount, life);
	cout << "," << ++ eachWarrCount["dragon"] 
	     << " dragon in blue headquarter" << endl;
    }

    energy -= life;
    time ++;
    nextWarr = (order+1) % 5;
}


bool isProduce(const RedHeadquarter& red, map<string,int> warrStrength) {
    int lastWarr = red.nextWrr;

    while(red.energy < warrStrength[red.produceWarrSeq[red.nextWarr]]) {
	red.nextWarr = (red.nextWarr+1) % 5;
	if(red.nextWarr == lastWarr)
	    return false;
    }

    int life = warrStrength[red.produceWarrSeq[red.nextWarr]];
    red.produceWarr(red.nextWarr, life);
    
    return true;
}



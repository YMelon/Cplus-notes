
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

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
    int getTime() const { return time; }
    
    friend bool isProduce(RedHeadquarter& red, vector<pair<string,int> > warrStrength);
private:
    int energy;
    int time;
    int totalCount;
    int nextWarr;

    vector<string> produceWarrSeq;
    //unordered_map<string,int> eachWarrCount;
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
    int getTime() const { return time; }
    
    friend bool isProduce(BlueHeadquarter& blue, vector<pair<string,int> > warrStrength);
private:
    int energy;
    int time;
    int totalCount;
    int nextWarr;

    vector<string> produceWarrSeq;
    //使用map会自动按key排序 造成武士生命值初始化错误
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



bool isProduce(RedHeadquarter& red, vector<pair<string,int> > warrStrength) {
    int lastWarr = red.nextWarr;
    vector<pair<string,int> >::iterator it = warrStrength.begin();
    while(it != warrStrength.end() 
	    && red.produceWarrSeq[red.nextWarr] != it->first)
	it ++;

    while(red.energy < it -> second) {
	red.nextWarr = (red.nextWarr+1) % 5;
	if(red.nextWarr == lastWarr)
	    return false;

	if(++ it == warrStrength.end()) {
	    it = warrStrength.begin();
	}
    }

    red.produceWarr(red.nextWarr, it->second);
    
    return true;
}

bool isProduce(BlueHeadquarter& blue, vector<pair<string,int> > warrStrength) {
    int lastWarr = blue.nextWarr;
    vector<pair<string,int> >::iterator it = warrStrength.begin();
    while(it != warrStrength.end() 
	    && blue.produceWarrSeq[blue.nextWarr] != it->first)
	it ++;

    while(blue.energy < it -> second) {
	blue.nextWarr = (blue.nextWarr+1) % 5;
	if(blue.nextWarr == lastWarr)
	    return false;

	if(++ it == warrStrength.end()) {
	    it = warrStrength.begin();
	}
    }

    blue.produceWarr(blue.nextWarr, it->second);
    
    return true;
}


int main() {
    //使用map会初始化武士发生错误
    //unordered_map 编译有错 不知道为啥
    //unordered_map<string,int> warrStrength;
    vector<pair<string,int> > warrStrength;
    warrStrength.push_back(make_pair<string,int>("dragon",0));
    warrStrength.push_back(make_pair<string,int>("ninja",0));
    warrStrength.push_back(make_pair<string,int>("iceman",0));
    warrStrength.push_back(make_pair<string,int>("lion",0));
    warrStrength.push_back(make_pair<string,int>("wolf",0));

    int n, energy;
    int tmp;
    cin >> n;
    for(int i = 0; i < n; ++ i) {
	cin >> energy;
	vector<pair<string,int> >::iterator it = warrStrength.begin();
	for(int j = 0; j < 5; ++ j) {
	    cin >> tmp;
	    it -> second = tmp;
	    cout << it->second << endl;
	    it ++;
	}

	RedHeadquarter red(energy);
	BlueHeadquarter blue(energy);
	cout << "case:" << i+1 << endl;
	while(1) {
	    if(!isProduce(red, warrStrength)) {
		cout << setw(3) << setfill('0');
		cout << red.getTime() << " red headquarter stops making warriors" << endl;
		while(isProduce(blue, warrStrength)) 
			;
		cout << setw(3) << setfill('0');
		cout << blue.getTime() << " blue headquarter stops making warriors" << endl;
		break;
	    }
	    if(!isProduce(blue, warrStrength)) {
		cout << setw(3) << setfill('0');
		cout << blue.getTime() << " blue headquarter stops making warriors" << endl;
		while(isProduce(red, warrStrength)) 
			;
		cout << setw(3) << setfill('0');
		cout << red.getTime() << " red headquarter stops making warriors" << endl;
		break;
	    }
	}
    }

    return 0;
}



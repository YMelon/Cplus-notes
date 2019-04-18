//魔兽世界二：装备
//AC版本，就是代码量比别人提交的大，运行时间5ms比较好，在优化下设计

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
    vector<int> weapon;
};


class Lion: public Warrior {
public:
    Lion(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    { cout << "lion " << id << " born with strength " << strength; }
    
    void setLoyalty(int val) { loyalty = val; }
    int getLoyalty() { return loyalty; }


private:
    int loyalty;
};


class Iceman: public Warrior {
public:
    Iceman(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    { 
        weapon.push_back(id%3);

        cout << "iceman " << id << " born with strength " << strength; 
    }

    vector<int> getWeapon() { return weapon; }

};


class Dragon: public Warrior {
public:
    Dragon(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    {
        weapon.push_back(id%3);

        cout << "dragon " << id << " born with strength " << strength; 
    }

    vector<int> getWeapon() { return weapon; }
    void setMorale(float val) { morale = val; }
    float getMorale() { return morale; }
private:
    float morale;//士气
};



class Ninja: public Warrior {
public:
    Ninja(int id, int strength, int attack=0)
	:Warrior(id, strength, attack)
    { 
        weapon.push_back(id%3);
        weapon.push_back((id+1)%3);

        cout << "ninja " << id << " born with strength " << strength; 
    }

    vector<int> getWeapon() { return weapon; }
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
    void produceWarr(int order, int life, vector<pair<string,int> > Weapon);
    int getTime() const { return time; }
    
    friend bool isProduce(RedHeadquarter& red, 
                          vector<pair<string,int> > warrStrength,
                          vector<pair<string,int> > Weapon);
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

void RedHeadquarter::produceWarr(int order, int life, vector<pair<string,int> > Weapon) {
    energy -= life;

    cout << setw(3) << setfill('0') << time 
	 << " red ";

    if(produceWarrSeq[order] == "iceman") {
	Iceman ice(++totalCount, life);
	cout << "," << ++ eachWarrCount["iceman"] 
	     << " iceman in red headquarter" << endl;

    cout << "It has a " << Weapon[ice.getWeapon()[0]].first << endl;
    }
    else if(produceWarrSeq[order] == "lion") {
	Lion lion(++totalCount, life);
	cout << "," << ++ eachWarrCount["lion"] 
	     << " lion in red headquarter" << endl;
    
    lion.setLoyalty(energy);
    cout << "It's loyalty is " << lion.getLoyalty() << endl;
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

    cout << "It has a " << Weapon[nin.getWeapon()[0]].first 
         << " and a " << Weapon[nin.getWeapon()[1]].first << endl;
    }
    else if(produceWarrSeq[order] == "dragon") {
	Dragon dragon(++totalCount, life);
	cout << "," << ++ eachWarrCount["dragon"] 
	     << " dragon in red headquarter" << endl;
   
    float tmp = (float)energy / life;
    dragon.setMorale(tmp);
    cout << "It has a " << Weapon[dragon.getWeapon()[0]].first
         << ",and it's morale is ";
    cout << setiosflags(ios::fixed) << setprecision(2)
          << dragon.getMorale() << endl;
    }

    //energy -= life;
    time ++;
    nextWarr = (order+1) % 5;
}


class BlueHeadquarter {
public:
    BlueHeadquarter(int energy);
    void produceWarr(int order, int life, vector<pair<string,int> > Weapon);
    int getTime() const { return time; }
    
    friend bool isProduce(BlueHeadquarter& blue, 
                          vector<pair<string,int> > warrStrength,
                          vector<pair<string,int> > Weapon);
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

void BlueHeadquarter::produceWarr(int order, int life, vector<pair<string,int> > Weapon) {
    energy -= life;

    cout << setw(3) << setfill('0') << time 
	 << " blue ";

    if(produceWarrSeq[order] == "iceman") {
	Iceman ice(++totalCount, life);
	cout << "," << ++ eachWarrCount["iceman"] 
	     << " iceman in blue headquarter" << endl;

    cout << "It has a " << Weapon[ice.getWeapon()[0]].first << endl;
    }
    else if(produceWarrSeq[order] == "lion") {
	Lion lion(++totalCount, life);
	cout << "," << ++ eachWarrCount["lion"] 
	     << " lion in blue headquarter" << endl;

    lion.setLoyalty(energy);
    cout << "It's loyalty is " << lion.getLoyalty() << endl;
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

    cout << "It has a " << Weapon[nin.getWeapon()[0]].first
         << " and a " << Weapon[nin.getWeapon()[1]].first << endl;
    }
    else if(produceWarrSeq[order] == "dragon") {
	Dragon dragon(++totalCount, life);
	cout << "," << ++ eachWarrCount["dragon"] 
	     << " dragon in blue headquarter" << endl;

    float tmp = (float)energy / life;
    dragon.setMorale(tmp);
    cout << "It has a " << Weapon[dragon.getWeapon()[0]].first
         << ",and it's morale is ";
    cout << setiosflags(ios::fixed) << setprecision(2) << dragon.getMorale() << endl;
    }

    //energy -= life;
    time ++;
    nextWarr = (order+1) % 5;
}



bool isProduce(RedHeadquarter& red, 
               vector<pair<string,int> > warrStrength,
               vector<pair<string,int> > Weapon) {
    int lastWarr = red.nextWarr;
    int index;
    for(index = 0; index < warrStrength.size(); ++ index) {
	if(red.produceWarrSeq[red.nextWarr] == warrStrength[index].first)
	    break;
    }

    while(red.energy < warrStrength[index].second) {
	red.nextWarr = (red.nextWarr+1) % 5;
	if(red.nextWarr == lastWarr)
	    return false;
        
	for(index = 0; index < warrStrength.size(); ++ index) {
	    if(red.produceWarrSeq[red.nextWarr] == warrStrength[index].first)
	        break;
        }
    }

    red.produceWarr(red.nextWarr, warrStrength[index].second, Weapon);
    
    return true;
}

bool isProduce(BlueHeadquarter& blue, 
               vector<pair<string,int> > warrStrength,
               vector<pair<string,int> > Weapon) {
    int lastWarr = blue.nextWarr;
    int index;
    for(index = 0; index < warrStrength.size(); ++ index) {
	if(blue.produceWarrSeq[blue.nextWarr] == warrStrength[index].first)
	    break;
    }

    while(blue.energy < warrStrength[index].second) {
	blue.nextWarr = (blue.nextWarr+1) % 5;
	if(blue.nextWarr == lastWarr)
	    return false;

        for(index = 0; index < warrStrength.size(); ++ index) {
	    if(blue.produceWarrSeq[blue.nextWarr] == warrStrength[index].first)
	        break;
        }
    }

    blue.produceWarr(blue.nextWarr, warrStrength[index].second, Weapon);
    
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

    //武器
    vector<pair<string,int> > Weapon;
    Weapon.push_back(make_pair<string,int>("sword",0));
    Weapon.push_back(make_pair<string,int>("bomb",0));
    Weapon.push_back(make_pair<string,int>("arrow",0));

    int n, energy;
    int tmp;
    cin >> n;
    for(int i = 0; i < n; ++ i) {
	cin >> energy;
	vector<pair<string,int> >::iterator it = warrStrength.begin();
	for(int j = 0; j < 5; ++ j) {
	    cin >> tmp;
	    it -> second = tmp;
	    it ++;
	}

	RedHeadquarter red(energy);
	BlueHeadquarter blue(energy);
	cout << "Case:" << i+1 << endl;
	while(1) {
	    if(!isProduce(red, warrStrength, Weapon)) {
		cout << setw(3) << setfill('0');
		cout << red.getTime() << " red headquarter stops making warriors" << endl;
		while(isProduce(blue, warrStrength, Weapon)) 
			;
		cout << setw(3) << setfill('0');
		cout << blue.getTime() << " blue headquarter stops making warriors" << endl;
		break;
	    }
	    if(!isProduce(blue, warrStrength, Weapon)) {
		cout << setw(3) << setfill('0');
		cout << blue.getTime() << " blue headquarter stops making warriors" << endl;
		while(isProduce(red, warrStrength, Weapon)) 
			;
		cout << setw(3) << setfill('0');
		cout << red.getTime() << " red headquarter stops making warriors" << endl;
		break;
	    }
	}
    }

    return 0;
}



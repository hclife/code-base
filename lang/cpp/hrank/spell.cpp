//Magic Spells
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    string scroll=spell->revealScrollName();
    if (scroll.empty()) {
        Fireball *fire=dynamic_cast<Fireball*>(spell);
        if (fire!=nullptr) {
            fire->revealFirepower();
            return;
        }
        Frostbite *frost=dynamic_cast<Frostbite*>(spell);
        if (frost!=nullptr) {
            frost->revealFrostpower();
            return;
        }
        Thunderstorm *thunder=dynamic_cast<Thunderstorm*>(spell);
        if (thunder!=nullptr) {
            thunder->revealThunderpower();
            return;
        }
        Waterbolt *water=dynamic_cast<Waterbolt*>(spell);
        if (water!=nullptr) {
            water->revealWaterpower();
            return;
        }
        return;
    }
    string journal(SpellJournal::journal);
    int ssize=scroll.size(),jsize=journal.size();
    vector<vector<int>> dp(ssize,vector<int>(jsize));
    for (register int s=0;s<ssize;++s) {
        for (register int j=0;j<jsize;++j) {
            int x=0;if (s>0) x=dp[s-1][j];
            int y=0;if (j>0) y=dp[s][j-1];
            if (x<y) x=y;
            
            int z=(scroll[s]==journal[j]);
            if (s>0 && j>0) z+=dp[s-1][j-1];
            if (x<z) x=z;
            dp[s][j]=x;
        }
    }
    cout<<dp[ssize-1][jsize-1]<<endl;
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}	
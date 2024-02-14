#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cfloat>

using namespace std;


class Timer {
    public:
    void start() {
        origin = rdtsc();
    }
    
    inline double get_time() {
        return (rdtsc() - origin) * SECONDS_PER_CLOCK;
    }
    
    private:
    constexpr static double SECONDS_PER_CLOCK = 1 / 3.0e9;
    unsigned long long origin;
    
    inline static unsigned long long rdtsc() {
        unsigned long long lo, hi;
        __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
        return (hi << 32) | lo;
    }
};

constexpr int MAX_INVEST_LEVEL = 20;
constexpr int END_OF_INITIAL_PHASE = 900;

constexpr long long LINF = 1001001001001001001;

struct Project {
    int64_t h;
    int64_t v;
    double efficiency() {
        return (double)v/(double)h;
    }
};

enum class CardType {
    WORK_SINGLE = 0,
    WORK_ALL = 1,
    CANCEL_SINGLE = 2,
    CANCEL_ALL = 3,
    INVEST = 4,
};

struct Card {
    CardType t;
    int64_t w;
    int64_t p;
    double efficiency() {
        if(p==0) return 0;
        else return (double)w/(double)p;
    }
};

struct Judge {
    const int n;
    const int m;
    const int k;

    Judge(int n, int m, int k): n(n), m(m), k(k) {}

    vector<Card> read_initial_cards() {
        vector<Card> cards;
        for (int i = 0; i < n; i++) {
            int64_t t, w;
            cin >> t >> w;
            cards.push_back(Card{(CardType)t, w, 0ll});
        }
        return cards;
    }

    vector<Project> read_projects() {
        vector<Project> projects;
        for (int i = 0; i < m; i++) {
            int64_t h, v;
            cin >> h >> v;
            projects.push_back(Project{h, v});
        }
        return projects;
    }

    void use_card(int c, int m) {
        cout << c << " " << m << endl;
    }

    int64_t read_money() {
        int64_t money;
        cin >> money;
        return money;
    }

    vector<Card> read_next_cards() {
        vector<Card> cards;
        for (int i = 0; i < k; i++) {
            int64_t t, w, p;
            cin >> t >> w >> p;
            cards.push_back(Card{(CardType)t, w, p});
        }
        return cards;
    }

    void select_card(int r) {
        cout << r << endl;
    }

};

struct Solver {
    const int n;
    const int m;
    const int k;
    const int t;
    Judge judge;
    int turn;
    int invest_level;
    int64_t money;
    vector<Project> projects;
    vector<Card> cards;


    Solver(int n, int m, int k, int t) : 
        n(n), m(m), k(k), t(t), judge(n, m, k), turn(0), invest_level(0), money(0) {
    }

    int64_t solve() {
        cards = judge.read_initial_cards();
        projects = judge.read_projects();
        for (turn = 0; turn < t; ++turn) {
            auto [use_card_i, use_target] = select_action();
            const Card& use_card = cards[use_card_i];
            if (use_card.t == CardType::INVEST) {
                invest_level++;
            }
            
            judge.use_card(use_card_i, use_target);
            assert(invest_level <= MAX_INVEST_LEVEL);

            projects = judge.read_projects();
            money = judge.read_money();

            vector<Card> next_cards = judge.read_next_cards();
            int select_card_i;
            if(turn < END_OF_INITIAL_PHASE) {
                select_card_i = initial_phase_next_card(next_cards);
            } else {
                select_card_i = final_phase_next_card(next_cards);
            }
            cards[use_card_i] = next_cards[select_card_i];
            judge.select_card(select_card_i);
            
            money -= next_cards[select_card_i].p;
            assert(money >= 0);
        }
        return money;
    }

    pair<int, int> select_action() {
        // TODO: implement your strategy
        int p_i = -1;
        if(p_i==-1) p_i = most_efficient_project();
        
        int c_i = -1;
        if(c_i==-1 && is_investable()) c_i = select_invest();
        if(c_i==-1) c_i = 0;
        
        CardType type = cards.at(c_i).t;
        if(type==CardType::WORK_ALL || type==CardType::CANCEL_ALL || type==CardType::INVEST) {
            p_i = 0;
        }
        return {c_i, p_i};
    }
    
    int most_efficient_project() {
        int idx = 0;
        double eff = 0;
        for(int i=0;i<m;i++) {
            auto p = projects.at(i);
            if(p.efficiency()>eff) {
                eff = p.efficiency();
                idx = i;
            }
        }
        return idx;
    }
    
    int least_efficient_project() {
        int idx = 0;
        double eff = DBL_MAX;
        for(int i=0;i<m;i++) {
            auto p = projects.at(i);
            if(p.efficiency()<eff) {
                eff = p.efficiency();
                idx = i;
            }
        }
        return idx;
    }

    int select_invest() {
        for(int i=0;i<n;i++) {
            if(cards.at(i).t==CardType::INVEST) return i;
        }
        return -1;
    }
    
    int initial_phase_next_card(const vector<Card>& next_cards) {
        // TODO: implement your strategy
        int idx = -1;
        
        if(idx==-1 && is_investable()) idx = select_affordable_invest(next_cards);
        if(idx==-1) idx = select_reasonable_work_all(next_cards);
        if(idx==-1) idx = select_reasonable_work_single(next_cards);
        if(idx==-1) idx = 0;
        return idx;
    }
    
    int final_phase_next_card(const vector<Card>& next_cards) {
        // TODO: implement your strategy
        int idx = -1;
        
        if(idx==-1) idx = select_reasonable_work_all(next_cards);
        if(idx==-1) idx = select_reasonable_work_single(next_cards);
        if(idx==-1) idx = 0;
        return idx;
    }
    
    int select_affordable_invest(const vector<Card>& next_cards) {
        int idx = -1;
        long long mi = LINF;
        for(int i=0;i<k;i++) {
            auto c = next_cards.at(i);
            if(c.t != CardType::INVEST) continue;
            if(!is_affordable(c)) continue;
            if(mi > c.p) {
                mi = c.p;
                idx = i;
            }
        }
        return idx;
    }

    int select_reasonable_work_all(const vector<Card>& next_cards) {
        int idx = -1;
        long long mi = LINF;
        for(int i=0;i<k;i++) {
            auto c = next_cards.at(i);
            if(c.t != CardType::WORK_ALL) continue;
            if(!is_affordable(c)) continue;
            int cnt = 0;
            for(auto p : projects) {
                if(c.w >= p.h) cnt++;
            }
            if(cnt > (m+1)/2 && mi > c.p && c.w*m/3 >= c.p) {
                mi = c.p;
                idx = i;
            }
        }
        return idx;
    }
    
    int select_reasonable_work_single(const vector<Card>& next_cards) {
        int idx = -1;
        long long mi = LINF;
        for(int i=0;i<k;i++) {
            auto c = next_cards.at(i);
            if(c.t != CardType::WORK_SINGLE) continue;
            if(!is_affordable(c)) continue;
            if(projects.at(most_efficient_project()).h <= c.w && c.p < mi && c.w/3 >= c.p) {
                mi = c.p;
                idx = i;
            }
        }
        if(idx!=-1) return idx;
        double ma = 1;
        for(int i=0;i<k;i++) {
            auto c = next_cards.at(i);
            if(c.t != CardType::WORK_SINGLE) continue;
            if(!is_affordable(c)) continue;
            if(ma < c.efficiency() && c.w/3 >= c.p) {
                ma = c.efficiency();
                idx = i;
            }
        }
        return idx;
    }
    
    bool is_investable() {
        return invest_level < MAX_INVEST_LEVEL;
    }
    
    bool is_affordable(const Card& card) {
        return card.p <= money;
    }
    
};

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    Solver solver(n, m, k, t);
    solver.solve();
}

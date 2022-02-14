#include "word.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <time.h>
#define NDEBUG
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
const int WORD_LEN = 5;
const int MAX_GUESS = 5;
const int NUMC = 26;
const int NUM_SCRAMBLE = 8869;
char scramble[NUM_SCRAMBLE][WORD_LEN + 1];

const char FIRST_GUESS[NUMC][WORD_LEN + 1] = {"tries","teals","tares","tires","darns","tiles","tales","lares","snare","toles","naris","tines","nates","aides","arles","lares","suite","nates","plate","pares","snare","roles","tares","reoil","nares","aeons"};
int first_guess[NUMC];

const int NUM_S_G = 243;  // 3^WORD_LEN
const int NUM_HARD = 2;
const char HARD_SECOND_GUESS[NUM_HARD][NUM_S_G][WORD_LEN + 1] = {{"myoid","","runic","yclad","","windy","riyal","","rowan","rotch","","rutin","ratty","","ratan","","","","rowth","","runty","rabat","","","rhyta","","riant","bipod","","vodun","kedge","","raven","","","","retem","","","rater","","","","","","velum","","","ramet","","","","","","oldie","","rewin","ramie","","rance","hemal","","rewan","retro","","","rathe","","","retax","","","folic","","rente","","","","reata","","","filum","","rings","cigar","","ranis","roars","","roans","rotls","","","ratos","","","rotas","","","riots","","runts","rafts","","rants","","","","build","","runes","pluck","","","","","","rites","","","rates","","rates","rites","","","","","","pluck","","","","","","feued","","reins","","","","pearl","","","","","","ratos","","","","","","rests","","rents","","","","","","","roshi","","rosin","raspy","","","","","","","","","","","","","","","roust","","","","","","roast","","","resew","","risen","rased","","","","","","","","","rater","","","","","","reset","","","","","","","","","resod","","resin","raise","","","resaw","","","","","","","","","","","","reest","","","","","","resat","",""}, {"conus","","yourn","biogs","","slops","kills","","spill","hymns","","morns","swigs","","slaps","chill","","spall","naris","","spray","","","","fillo","","salpa","fohns","","spits","slots","","","silts","","","wicks","","spats","slats","","","","","","sorta","","sputa","","","","salts","","","knout","","strop","","","slipt","still","","spilt","grins","","staph","slant","","","stall","","","ottar","","strap","","","","sault","","splat","rhino","","cornu","slime","","slipe","solve","","spile","mohur","","dreck","slake","","","swale","","spale","sarge","","","","","","sable","","","hilum","","spite","","","","","","","skate","","spate","slate","","slate","skate","","spate","saute","","","","","","","","","krone","","stupe","","","","style","","","grind","","","slake","","","stale","","spale","setae","","","","","","","","","heder","","spies","sleds","","sleep","molls","","spiel","seams","","spaed","","","","seals","","","waker","","spean","","","","selah","","salep","setts","","septs","","","","","","","seats","","","slats","","","","","","","","septa","","","","","","","stern","","steps","sleet","","slept","smelt","","spelt","","","","","","","","","","steam","","","","","","steal","",""}};

int hard_second_guess[NUM_HARD][NUM_S_G];

// states of |c|
const char UNKNOWN = 0;
// the bits 1, 2, 4, 8, 16 show the silver (wrong) positions
const char RED = 31;  // no occurences other than gold
const char UNSATISFIED_SILVER = 32;  // has occurences other than gold (real silver)

int win_points[MAX_GUESS] = {85, 90, 100, 120, 150};  // win_points[i] = extra points for a correct guess with i remaining guesses
double lose_penalty = 0;

const int MAP_SIZE_THRESHOLD = 600 * 1024 * 1024 / 72;  // 600M

// temp buffers
int visit[NUMC], vn = 0;
int visit_big[NUM_SCRAMBLE], vn_big = 0;

int letter_count[NUMC][WORD_LEN];
int letter_counts[NUMC];
int sum_letter_count;

int init_letter = 0;  // ranging [0, NUMC)

class State {
public:
	char gold[WORD_LEN];  // correct letters
	char remaining_guesses;
	char c[NUMC];
	size_t hash_value;
	State() {
		memset(gold, 0, sizeof(gold));
		remaining_guesses = 0;
		memset(c, UNKNOWN, sizeof(c));
		hash_value = 0;
	}
	void compute_hash() {
		hash_value = remaining_guesses;
		for (int i = 0; i < WORD_LEN; i++)
			hash_value = hash_value * 26 + gold[i];
		for (int i = 0; i < NUMC; i++)
			hash_value = hash_value * 65 + c[i];
	}
	int get_heuristics(int guess, bool is_possible_answer, int num_possible_answers) const {
		vn++;
		int ret = 0;
		if (is_possible_answer) {
			ret += sum_letter_count * (3 + (1 << (5 - remaining_guesses)) + 150.0 / num_possible_answers) / 2;  // possible answer: (3+(1-16)+(0-150))0.5x
		}
		for (int i = 0; i < WORD_LEN; i++) {
			if (scramble[guess][i] != gold[i] && gold[i]) {
				visit[gold[i] - 'a'] = vn;
			}
		}
		for (int i = 0; i < WORD_LEN; i++) {
			// possible gold or new silver: (1.5 + 0.1875)x
			// possible given silver at a different place: 0.75x
			// possible silver: 0.1875x
			if (c[scramble[guess][i] - 'a'] == RED) {
				continue;
			}
			if (scramble[guess][i] != gold[i] && !(c[scramble[guess][i] - 'a'] & UNSATISFIED_SILVER) && visit[scramble[guess][i] - 'a'] != vn) {
				ret += letter_counts[scramble[guess][i] - 'a'] * 52;
				ret += sum_letter_count;
				visit[scramble[guess][i] - 'a'] = vn;
			}
			if (i > 0 && scramble[guess][i] != gold[i] && !(c[scramble[guess][i] - 'a'] & (1 << i))) {
				if (c[scramble[guess][i] - 'a'] & UNSATISFIED_SILVER) {
					ret += letter_count[scramble[guess][i] - 'a'][i] * 104;
					ret += sum_letter_count / 2;
				} else {
					ret += letter_count[scramble[guess][i] - 'a'][i] * 26;
					ret += sum_letter_count / 4;
				}
			}
		}
		return ret;
	}
	bool promote_silver_to_gold(int &golden_mask, int letter) {
		// return true iff successfully promoted
		int tmp = golden_mask | (c[letter] & RED);
		tmp = RED ^ tmp;
		assert(tmp);  // at least 1 possible place
		if (tmp == (tmp & (-tmp))) {
			// tmp == lowbit(tmp): only 1 possible place left
			// promote to gold
			for (int k = 0; k < WORD_LEN; k++) {
				if (tmp == (1 << k)) {
					gold[k] = letter + 'a';
					break;
				}
			}
			if (c[letter] & UNSATISFIED_SILVER)
				c[letter] ^= UNSATISFIED_SILVER;
			golden_mask ^= tmp;
			return true;
		}
		return false;
	}
	void apply_guess(int guess, int answer) {
		vn += 2;
		remaining_guesses--;
		int golden_mask = 0;
		for (int i = 0; i < WORD_LEN; i++) {
			if (scramble[guess][i] == scramble[answer][i]) {
				gold[i] = scramble[guess][i];
				if (c[scramble[guess][i] - 'a'] & UNSATISFIED_SILVER)
					c[scramble[guess][i] - 'a'] ^= UNSATISFIED_SILVER;  // clear previous silver
			} else {
				// silver only applies to letters that is not gold
				visit[scramble[answer][i] - 'a'] = vn;
			}
			if (gold[i])
				golden_mask ^= (1 << i);
		}
		for (int i = 0; i < WORD_LEN; i++) {
			if (gold[i] && scramble[guess][i] != gold[i]) {
				// the silver is not unsatisfied here
				visit[gold[i] - 'a']--;
			}
		}
		for (int i = 0; i < WORD_LEN; i++) {
			if (scramble[guess][i] != scramble[answer][i]) {
				// not gold -- check silvers
				if (visit[scramble[guess][i] - 'a'] == vn) {
					c[scramble[guess][i] - 'a'] |= (1 << i) | UNSATISFIED_SILVER;
				} else if (visit[scramble[guess][i] - 'a'] == vn - 1) {
					c[scramble[guess][i] - 'a'] |= (1 << i);
				} else {
					// no occurences other than gold
					c[scramble[guess][i] - 'a'] = RED;
				}
			}
		}
		/* do not do this to make it faster
		while (true) {
			bool has_silver_promoted = false;
			for (int i = 0; i < NUMC; i++) {
				if ((c[i] & UNSATISFIED_SILVER) && promote_silver_to_gold(golden_mask, i)) {
					has_silver_promoted = true;
				}
			}
			if (!has_silver_promoted)
				break;
		}*/
	}
	void apply_guess(int guess, bool *result_gold, bool *silver) {
		vn++;
		remaining_guesses--;
		int golden_mask = 0;
		for (int i = 0; i < WORD_LEN; i++) {
			if (result_gold[i]) {
				gold[i] = scramble[guess][i];
				if (c[scramble[guess][i] - 'a'] & UNSATISFIED_SILVER)
					c[scramble[guess][i] - 'a'] ^= UNSATISFIED_SILVER;  // clear previous silver
			}
			if (gold[i])
				golden_mask ^= (1 << i);
		}
		for (int i = 0; i < WORD_LEN; i++) {
			if (gold[i] && scramble[guess][i] != gold[i]) {
				// the silver is not unsatisfiable here
				visit[gold[i] - 'a'] = vn;
			}
		}
		for (int i = 0; i < WORD_LEN; i++) {
			if (silver[i]) {
				if (visit[scramble[guess][i] - 'a'] != vn) {
					c[scramble[guess][i] - 'a'] |= (1 << i) | UNSATISFIED_SILVER;
				} else {
					c[scramble[guess][i] - 'a'] |= (1 << i);
				}
			} else if (!result_gold[i]) {
				// red
				// no occurences other than gold
				c[scramble[guess][i] - 'a'] = RED;
			}
		}
		while (true) {
			bool has_silver_promoted = false;
			for (int i = 0; i < NUMC; i++) {
				if ((c[i] & UNSATISFIED_SILVER) && promote_silver_to_gold(golden_mask, i)) {
					has_silver_promoted = true;
				}
			}
			if (!has_silver_promoted)
				break;
		}
	}
	bool possible_answer(int answer) const {
		vn++;
		// check gold, red or silver
		for (int i = 0; i < WORD_LEN; i++) {
			if (gold[i]) {
				if (gold[i] != scramble[answer][i]) {
					return false;
				}
			} else {
				if (c[scramble[answer][i] - 'a'] & (1 << i)) {
					return false;
				}
				// can satisfy silver here
				visit[scramble[answer][i] - 'a'] = vn;
			}
		}
		// check unsatisfied silver
		for (int i = 0; i < NUMC; i++) {
			if ((c[i] & UNSATISFIED_SILVER) && visit[i] != vn) {
				return false;
			}
		}
		return true;
	}
	void print() const {
		printf("%d ", (int) remaining_guesses);
		for (int i = 0; i < WORD_LEN; i++)
			printf("%c", gold[i] ? gold[i] : '*');
		bool has_red = false;
		for (int i = 0; i < NUMC; i++) {
			if (c[i] && !(c[i] & UNSATISFIED_SILVER)) {
				if (!has_red) {
					printf(", no ");
					has_red = true;
				}
				printf("%c", i + 'a');
				if (c[i] != RED) {
					for (int j = 0; j < WORD_LEN; j++) {
						if (c[i] & (1 << j))
							printf("%d", j);
					}
				}
			}
		}
		bool has_silver = false;
		for (int i = 0; i < NUMC; i++)
			if (c[i] & UNSATISFIED_SILVER) {
				if (!has_silver) {
					printf(", silver ");
					has_silver = true;
				}
				printf("%c", i + 'a');
				for (int j = 0; j < WORD_LEN; j++) {
					if (c[i] & (1 << j))
						printf("%d", j + 1);
				}
			}
	}
	bool operator==(const State &other) const {
		if (remaining_guesses != other.remaining_guesses)
			return false;
		for (int i = 0; i < WORD_LEN; i++)
			if (gold[i] != other.gold[i])
				return false;
		for (int i = 0; i < NUMC; i++)
			if (c[i] != other.c[i])
				return false;
		return true;
	}
};
class StateHash {
public:
	size_t operator()(const State &s) const noexcept {
		return s.hash_value;
	}
};

unordered_map<State, double, StateHash> f;

inline bool hard_case(char initial_letter) {
	return initial_letter == 'r' || initial_letter == 's';
}

void count_letters(const State &s, const vector<int> &possible_answers) {
	memset(letter_count, 0, sizeof(letter_count));
	memset(letter_counts, 0, sizeof(letter_counts));
	sum_letter_count = 0;
	for (auto i : possible_answers) {
		// the first letter is given so we don't count it
		for (int j = 1; j < WORD_LEN; j++) {
			if (!s.gold[j]) {
				letter_count[scramble[i][j] - 'a'][j]++;
				letter_counts[scramble[i][j] - 'a']++;
				sum_letter_count++;
			}
		}
	}
}

void init(int num_scramble, const char *SCRAMBLE_PURE) {
	assert(num_scramble == NUM_SCRAMBLE);
	memset(hard_second_guess, -1, sizeof(hard_second_guess));
	for (int i = 0; i < NUM_SCRAMBLE; i++) {
		memcpy(scramble[i], SCRAMBLE_PURE + i * WORD_LEN, WORD_LEN);
		const string scramble_str = string(scramble[i]);
		for (int j = 0; j < NUMC; j++) {
			if (scramble_str == string(FIRST_GUESS[j])) {
				first_guess[j] = i;
			}
		}
		for (int j = 0; j < NUM_HARD; j++) {
			for (int k = 0; k < NUM_S_G; k++) {
				if (scramble_str == string(HARD_SECOND_GUESS[j][k])) {
					hard_second_guess[j][k] = i;
				}
			}
		}
	}
}

int search_max_remaining_guesses;
int search_result;  // the word to guess

double search(const State &s, const vector<int> &possible_answers) {
	/*printf("search ");
	s.print();
	printf(", %d possible answers\n", (int) possible_answers.size());*/
	if (f.count(s) > 0 && s.remaining_guesses != search_max_remaining_guesses)
		return f[s];
	assert(s.remaining_guesses > 0);
	assert(!possible_answers.empty());
	if (s.remaining_guesses == 1) {
		int ret = possible_answers.size();
		if (s.remaining_guesses == search_max_remaining_guesses) {
			search_result = possible_answers[0];
		}
		return f[s] = win_points[0] * (1.0 / ret) + lose_penalty * (1 - 1.0 / ret);
	}
	if (possible_answers.size() == 1) {
		if (s.remaining_guesses == search_max_remaining_guesses) {
			search_result = possible_answers[0];
		}
		return f[s] = win_points[s.remaining_guesses - 1];
	}
	if (possible_answers.size() == 2) {
		if (s.remaining_guesses == search_max_remaining_guesses) {
			search_result = possible_answers[0];
		}
		return f[s] = (win_points[s.remaining_guesses - 1] + win_points[s.remaining_guesses - 2]) / 2.0;
	}
	double result = (win_points[0] - 1e-3) * possible_answers.size();  // assume we must win...
	if (hard_case(s.gold[0])) {
		// unless the hard cases
		result = lose_penalty * possible_answers.size();
	}
	int best_guess = -1;
	vector<pair<int, int>> guesses;
	const int SEARCH_NUM = 30;
	/*if (s.remaining_guesses == search_max_remaining_guesses && possible_answers.size() <= 1000) {
		for (auto i : possible_answers) {
			printf("%s: %d\n", scramble[i], s.get_heuristics(i, true, possible_answers.size()));
		}
	}*/
	count_letters(s, possible_answers);
	if ((int) possible_answers.size() <= s.remaining_guesses) {
		// only guess possible answers
		for (auto i : possible_answers) {
			guesses.emplace_back(s.get_heuristics(i, true, possible_answers.size()), i);
		}
		if (possible_answers.size() <= SEARCH_NUM) {
			sort(guesses.begin(), guesses.end(), greater<pair<int, int>>());
		} else {
			partial_sort(guesses.begin(), guesses.begin() + SEARCH_NUM, guesses.end(), greater<pair<int, int>>());
			guesses.resize(SEARCH_NUM);
		}
	} else {
		guesses.reserve(NUM_SCRAMBLE);
		vn_big++;
		for (auto i : possible_answers) {
			guesses.emplace_back(s.get_heuristics(i, true, possible_answers.size()), i);
			visit_big[i] = vn_big;
		}
		for (int i = 0; i < NUM_SCRAMBLE; i++) {
			if (visit_big[i] != vn_big) {
				guesses.emplace_back(s.get_heuristics(i, false, possible_answers.size()), i);
			}
		}
		if (hard_case(s.gold[0]) && s.remaining_guesses >= search_max_remaining_guesses - 1) {
			// worst-case analysis
			for (int ii = 0; ii < NUM_SCRAMBLE; ii++) {
				int i = guesses[ii].second;
				unordered_map<State, int, StateHash> new_answers;
				for (int j : possible_answers) {
					// suppose the answer is j
					State new_s = s;
					new_s.apply_guess(i, j);
					new_s.compute_hash();
					new_answers[new_s]++;
				}
				int mx = 0;
				for (auto &it : new_answers) {
					if (it.second > mx)
						mx = it.second;
				}
				guesses[ii].first -= mx * 200;
			}
		}
		partial_sort(guesses.begin(), guesses.begin() + SEARCH_NUM, guesses.end(), greater<pair<int, int>>());
		guesses.resize(SEARCH_NUM);
	}
	for (int ii = 0; ii < (int) guesses.size(); ii++) {
		int i = guesses[ii].second;
		// guess word i
		unordered_map<State, vector<int>, StateHash> new_answers;
		bool has_correct_one = false;
		for (int j : possible_answers) {
			if (i == j) {
				has_correct_one = true;
				continue;
			}
			// suppose the answer is j
			State new_s = s;
			new_s.apply_guess(i, j);
			new_s.compute_hash();
			new_answers[new_s].push_back(j);
		}
		if (new_answers.size() == 1 && s == new_answers.begin()->first) {
			// useless guess, prune it
			continue;
		}
		double current_result = 0;
		int remaining_candidates = possible_answers.size();
		if (has_correct_one) {
			current_result += (double) win_points[s.remaining_guesses - 1];
			remaining_candidates--;
		}
		bool pruned = false;
		for (auto &it : new_answers) {
			double new_result = search(it.first, it.second);
			current_result += new_result * it.second.size();
			remaining_candidates -= it.second.size();
			if (current_result + win_points[s.remaining_guesses - 2] * remaining_candidates < result) {
				// pruning
				pruned = true;
				break;
			}
		}
		/*if (s.remaining_guesses == search_max_remaining_guesses) {
			printf("searched %d(%d) %s %f %.2f\n", ii, guesses[ii].first, scramble[i], pruned ? lose_penalty + current_result / possible_answers.size() : current_result / possible_answers.size(), clock() / 1000.0);
		}*/
		if (pruned) {
			continue;
		}
		assert(remaining_candidates == 0);
		if (current_result > result) {
			best_guess = i;
			result = current_result;
		}
		if (result >= (win_points[s.remaining_guesses - 1] + (possible_answers.size() - 1) * win_points[s.remaining_guesses - 2])) {
			// max possible result
			break;
		}
	}
	result /= possible_answers.size();
	if (s.remaining_guesses == search_max_remaining_guesses) {
		if (!hard_case(s.gold[0])) {
			assert(best_guess != -1);
		}
		if (best_guess == -1) {
			// fall back
			best_guess = possible_answers[0];
		}
		search_result = best_guess;
	}
	if (result < win_points[0] && !hard_case(s.gold[0]))
		result = lose_penalty;  // assume we must win
	return f[s] = result;
}

State current_state;
vector<int> possible_answers;

const char *guess(int num_testcase, int remaining_guesses, char initial_letter, bool *gold, bool *silver) {
	if (remaining_guesses == MAX_GUESS) {
		if (f.size() > MAP_SIZE_THRESHOLD)
			f.clear();
		current_state = State();
		current_state.gold[0] = initial_letter;
		current_state.remaining_guesses = MAX_GUESS;
		current_state.compute_hash();
		possible_answers.clear();
		for (int i = 0; i < NUM_SCRAMBLE; i++) {
			if (scramble[i][0] == initial_letter) {
				possible_answers.push_back(i);
			}
		}
		search_result = first_guess[initial_letter - 'a'];
		return scramble[search_result];
	} else {
		State backup_state = current_state;
		current_state.apply_guess(search_result, gold, silver);
		vector<int> new_possible_answers;
		new_possible_answers.reserve(possible_answers.size());
		for (auto i : possible_answers) {
			if (current_state.possible_answer(i)) {
				new_possible_answers.emplace_back(i);
			}
		}
		if (new_possible_answers.empty()) {
			current_state = backup_state;  // restore current_state
			return "invalid";
		}
		swap(possible_answers, new_possible_answers);
	}
	if (hard_case(initial_letter) && remaining_guesses == MAX_GUESS - 1) {
		// hard second guess, lookup table
		int index = 0;
		for (int i = WORD_LEN - 1; i >= 0; i--) {
			index *= 3;
			if (gold[i])
				index++;
			else if (silver[i])
				index += 2;
		}
		search_result = hard_second_guess[initial_letter == 's'][index];
		return scramble[search_result];
	}
	count_letters(current_state, possible_answers);
	
	search_max_remaining_guesses = current_state.remaining_guesses;
	search_result = -1;
	//current_state.print();
	// double result_val = 
	search(current_state, possible_answers);
	//printf(" %f %d possible answers\n", result_val, (int) possible_answers.size());
	assert(search_result != -1);
	return scramble[search_result];
}

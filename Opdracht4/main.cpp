#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::pair;
using std::string;
using std::vector;

int main() {
  string alphabet = "abcdefghijklomnopqrstuvwxyz";

  // 1
  ifstream input_file;
  input_file.open("JamesBible.txt");
  if (!input_file.is_open()) {  // If open failed show error
    std::cerr << "Error: " << std::strerror(errno) << endl;
  }
  input_file >> std::noskipws;  // Make sure not to skip the whitespaces (spaces, tabs, \n)
  vector<char> characters{istream_iterator<char>(input_file), istream_iterator<char>()};

  // 2
  unsigned int size_characters = characters.size();
  cout << "Characters in James bible: " << size_characters << endl;
  // 3
  auto count_newlines = std::count(characters.begin(), characters.end(), '\n');
  cout << "New lines in James bible: " << count_newlines << endl;
  // 4
  unsigned int count = 0;
  std::for_each(alphabet.begin(), alphabet.end(),
                [&count, &characters](char& c) { count += std::count(characters.begin(), characters.end(), c); });
  cout << "Amount of alphabetical character: " << count << endl;
  // 5
  std::for_each(characters.begin(), characters.end(), [](char& c) {
    if (isupper(c)) {
      c = tolower(c);
    }
  });
  // 6
  std::map<char, int> dict_char_sorted;
  std::for_each(alphabet.begin(), alphabet.end(), [&dict_char_sorted, &characters](char& c) {
    int c_count = std::count(characters.begin(), characters.end(), c);
    auto n_pair = pair<char, int>(c, c_count);
    dict_char_sorted.insert(n_pair);
  });
  // 7.1
  for (auto& pair : dict_char_sorted) {  // Started with a in alphabet so is in correct order already
    cout << "Char: " << pair.first << " amount: " << pair.second << endl;
  }
  // 7.2
  std::map<int, char> dict_value_sorted;
  std::for_each(dict_char_sorted.begin(), dict_char_sorted.end(), [&dict_value_sorted](pair<char, int> o_pair) {
    auto n_pair = pair<int, char>(o_pair.second, o_pair.first);
    dict_value_sorted.insert(n_pair);
  });
  for (auto& pair : dict_value_sorted) {
    cout << "Char: " << pair.first << " amount: " << pair.second << endl;
  }
  // 8
  std::map<string, int> dict_words;
  bool active_word = false;
  string current_word = "";
  std::for_each(characters.begin(), characters.end(), [&](char& c) {
    if (c >= 'a' && c <= 'z') {
      active_word = true;
      current_word += c;
    } else if (active_word) {
      if (dict_words.count(current_word)) {  // If word is NOT key in dict than count is 0!
        dict_words[current_word]++;
      } else {
        dict_words[current_word] = 1;
      }
      active_word = false;
      current_word = "";
    }
  });

	std::map<int, string> dict_amount;
	std::for_each(dict_words.begin(), dict_words.end(), [&dict_amount](pair<string, int> o_pair) {
    auto n_pair = pair<int, string>(o_pair.second, o_pair.first);
    dict_amount.insert(n_pair);
  });
	auto iterator = dict_amount.rbegin();
	int print_words = 10;
	while(print_words > 0){
		print_words--;
		cout << "Word: " << iterator->second << " amount: " << iterator->first << endl;
		iterator++;
	}
}
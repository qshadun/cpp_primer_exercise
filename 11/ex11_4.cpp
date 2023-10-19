/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include <unordered_map>
using std::unordered_map;

#include <unordered_set>
using std::unordered_set; using std::unordered_multiset;

#include <string>
using std::string; 

using std::hash;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cstddef>
using std::size_t;


// unordered_map version of the word count program
int main() 
{
	// count occurrences, but the words won't be in alphabetical order
    unordered_map<string, size_t> word_count;  
    string word;
    while (cin >> word) {
        if (word[word.size() - 1] == '.' || word[word.size() - 1] == ',') {
            word = word.substr(0, word.size() - 1);
        }
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		++word_count[word]; // fetch and increment the counter for word
    }
        

	for (const auto &w : word_count) // for each element in the map
		// print the results
		cout <<  w.first << " occurs " << w.second 
		     << ((w.second > 1) ? " times" : " time") << endl;

	return 0;
}



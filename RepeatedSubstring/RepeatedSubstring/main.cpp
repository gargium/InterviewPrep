//
//  main.cpp
//  RepeatedSubstring
//
//  Created by Gargium on 12/10/16.
//  Copyright © 2016 Rakshit Garg. All rights reserved.
//

/*
 Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 
 Example 1:
 Input: "abab"
 
 Output: True
 
 Explanation: It's the substring "ab" twice.
 Example 2:
 Input: "aba"
 
 Output: False
 Example 3:
 Input: "abcabcabcabc"
 
 Output: True
 
 Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 */



#include <iostream>
#include <string>


using namespace std;



//O(n^2) implementation
bool repeatedSubstringPattern(string str) {
    size_t size = str.size();
    int window = 1;
    bool ret = false;
    
    while (window != (size/2)+1) {
        string substring = str.substr(0,window);
        string appendedSub = substring+substring;
        size_t appendedSize = appendedSub.size();
        if (appendedSub != str.substr(0,appendedSize)) {
            window++;
            ret = false;
            continue;
        } else {
            int n = appendedSize;
            string appendedSubTest = appendedSub;
            while (n != size) {
                appendedSubTest += substring;
                n += substring.size();
            }
            if (appendedSubTest == str) {
                return true;
            } else {
                return false;
            }
        }
    }
    return ret;
}






int main(int argc, const char * argv[]) {
    // insert code here...
    string str =  "aa";
    std::cout << (repeatedSubstringPattern(str) ? "true" : "false");
    return 0;
}

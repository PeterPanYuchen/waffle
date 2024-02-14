//
// Created by beich on 2/14/2024.
//

#ifndef WAFFLE_TS_GET_OLDEST_KEY_H
#define WAFFLE_TS_GET_OLDEST_KEY_H

#include <string>
#include <iostream>
#include "FrequencySmoother.hpp"

class TS_get_oldest_key {
public:
    static std::pair<std::string,int> get_oldest_key(FrequencySmoother &frequencySmoother,std::vector<std::string> keys_to_be_deleted) {
        std::string oldest_key;
        std::set<std::pair<std::string, int>, decltype(&freqCmp)>::iterator it = frequencySmoother.getIterator();
        //initialize oldest_timestamp to the maximum possible value
        long oldest_timestamp= std::numeric_limits<long>::max();
        while (it != frequencySmoother.accessTree.end()) {
            if (std::find(keys_to_be_deleted.begin(), keys_to_be_deleted.end(), it->first) != keys_to_be_deleted.end()) {
                it++;
                continue;
            }
            if (get_timestamp(it->first)<oldest_timestamp) {
                oldest_key = it->first;
                oldest_timestamp = get_timestamp(it->first);
            }
            it++;
        }
        frequencySmoother.removeKey(oldest_key);
        return std::pair<std::string,int>(oldest_key,oldest_timestamp);
    }

    static long get_timestamp(std::string key){
        size_t firstAmp = key.find('&');
        if (firstAmp == std::string::npos) {
            std::cout<<"WARNING: No timestamp found in key: "<<key<<std::endl;
            return -1;
        }
        size_t secondAmp = key.find('&', firstAmp + 1);
        if (secondAmp == std::string::npos) {
            std::cout<<"WARNING: No timestamp found in key: "<<key<<std::endl;
            return -1;
        }
        //return the int between the two ampersands
        return std::stol(key.substr(firstAmp + 1, secondAmp - firstAmp - 1));

    }

};
#endif //WAFFLE_TS_GET_OLDEST_KEY_H

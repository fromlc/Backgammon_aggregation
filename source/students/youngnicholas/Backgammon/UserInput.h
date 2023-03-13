//
// Created by nicholas on 11/1/21.
//

#pragma once

#include <iostream>
#include <string>

namespace str2num {
    template<typename T>
    T convert(const std::string &str) {
        return {str};
    }

    template<>
    double convert<double>(const std::string &str) {
        return std::stod(str);
    }

    template<>
    int convert<int>(const std::string &str) {
        return std::stoi(str);
    }

    template<>
    unsigned int convert<unsigned int>(const std::string &str) {
        unsigned long tempULong = std::stoul(str);
        if (tempULong > UINT32_MAX) {
            throw std::invalid_argument("");
        }
        return tempULong;
    }

    template<>
    float convert<float>(const std::string &str) {
        return std::stof(str);
    }

    template<>
    long convert<long>(const std::string &str) {
        return std::stol(str);
    }

    template<>
    char convert<char>(const std::string &str) {
        if (str.length() != 1) {
            throw std::invalid_argument("");
        }
        return str[0];
    }
}

/**
 * template<typename T>
 * T readInput(std::string prompt)
 *
 * Reads in user input as a string and then attempts to return
 * it as type T, throwing an execution and prompting if an
 * invalid input.
 */

template<typename T>
T getUserInput(std::string prompt = "") { // NOLINT(performance-unnecessary-value-param)

    // loop until a valid value is input
    while (true) {
        std::cout << prompt << std::endl;
        try {
            // read in string
            std::string tempStr;
            std::getline(std::cin, tempStr);
            // try to return the string converted to type T
            return str2num::convert<T>(tempStr);
        } catch (std::invalid_argument &ignored) {
        } catch (std::out_of_range &ignored) {
        }
        std::cout << "\nInvalid input, Please Try again" << std::endl;
    }
}




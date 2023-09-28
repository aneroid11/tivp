#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

std::vector<std::string> find_files_with_ext(const std::string& dir, const std::string& ext);
std::string get_extension(const std::string& file);
std::vector<std::string> get_all_files_recursive(const std::string& dir);
bool has_extension(const std::string& file, const std::string& ext);
void print_files(const std::vector<std::string>& files, std::ostream& out = std::cout);
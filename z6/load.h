#pragma once

#include <iostream>
#include <string>

enum class LoadResult
{
    SUCCESS = 0,
    OPEN_FILE_FAILED,
    DOWNLOAD_FILE_FAILED,
    INITIALIZE_CURL_FAILED,
};

LoadResult load(const std::string& url, const std::string& path);
bool is_path_exist(const std::string& path_str);
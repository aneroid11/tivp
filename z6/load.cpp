#include "load.h"

#include <cstdio>
#include <filesystem>
#include <curl/curl.h>

LoadResult load(const std::string& url, const std::string& path)
{
    FILE *fp;
    CURLcode res;
    CURL *curl = curl_easy_init();

    if (curl)
    {
        fp = fopen(path.c_str(),"wb");
        if (!fp)
        {
            return LoadResult::OPEN_FILE_FAILED;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);

        res = curl_easy_perform(curl);
        if (res)
        {
            return LoadResult::DOWNLOAD_FILE_FAILED;;
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }
    else
    {
        return LoadResult::INITIALIZE_CURL_FAILED;
    }

    return LoadResult::SUCCESS;
}

bool is_path_exist(const std::string& path_str)
{
    std::filesystem::path path(path_str);
    return std::filesystem::exists(path);
}
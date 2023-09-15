#include <iostream>
#include <string>
#include <cstdio>
#include <curl/curl.h>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "you must specify exactly two arguments: url and path!\n";
        exit(EXIT_FAILURE);
    }

    const std::string url = argv[1];
    const std::string path = argv[2];

    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();

    if (curl)
    {
        fp = fopen(path.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if (res)
        {
            std::cerr << "cannot download file from url!\n";
            exit(EXIT_FAILURE);
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }
    else
    {
        std::cerr << "failed to initialize CURL!\n";
    }

    return 0;
}

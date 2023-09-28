#include "find_files.h"
#include <algorithm>

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

std::string get_extension(const std::string& file)
{
    std::filesystem::path path(file);
    return path.extension();
}

bool has_extension(const std::string& file, const std::string& ext)
{
    return get_extension(file) == ext;
}

std::vector<std::string> get_all_files_recursive(const std::string& dir)
{
    std::vector<std::string> result;
    try
    {
        const auto& iter = recursive_directory_iterator(dir);

        for (const auto& dir_entry : iter)
        {
            const std::string entry_str = dir_entry.path().string();
            result.push_back(entry_str);
        }
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        return {};
    }

    return result;
}

std::vector<std::string> find_files_with_ext(const std::string& dir, const std::string& ext)
{
    auto all_files = get_all_files_recursive(dir);
    std::vector<std::string> files_with_ext;

    std::copy_if(all_files.cbegin(), all_files.cend(), std::back_inserter(files_with_ext),
                 [&ext](const std::string& file)
                 {
                    return has_extension(file, ext);
                 });
    return files_with_ext;
}

void print_files(const std::vector<std::string>& files, std::ostream& out)
{
    for(const auto& f : files)
    {
        out << f << '\n';
    }
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

// write a simple copy application that takes command line arguments
// the first argument is the source file
// the second argument is the destination file e.g.
// mycopy source destination
// the application is only intended to copy files, not folders
// todo:
// 1. check command line arguments
// 2. if we have a number of arguments that's different to 2, then we print an error message and quit
// 3. if we have two command line arguments, then we 
// 4. attempt to create a file named like the destination argument
// 5. attempt to open the source file
// 6. read the contents of the source file until eof and write it to the destination file
// 7. close both files




int main(int argc, const char * argv[])
{
    std::cout << " Running in " << argv[0] << '\n';
    if (argc != 3 && argc != 4)
    {
        std::cerr << "Invalid argument count.\nusage: mycopy.exe <source_file> <destination_file>";
        return 1;
    }

    bool binary = true;
    if (argc == 4)
    {
        std::string lastArg = argv[3];
        binary = lastArg == "binary";
    }
    if (binary)
    {
        std::cout << "Using binary copy.\n";
    }
    else
    {
        std::cout << "Using getline copy.\n";
    }

    std::cout << "Copying from " << argv[1] << " to " << argv[2] << " ...\n";
    
    std::ifstream source(argv[1], std::ios::in | std::ios::binary);

    if (!source.is_open() )
    {
        std::cerr << "Could not open source file.\n";
        return 1;
    }

    std::ofstream destination(argv[2], std::ios::out | std::ios::binary);

    if (!destination.is_open())
    {
        std::cerr << "Could not open destination file.\n";
        source.close();
        return 1;
    }

    auto  before = std::chrono::steady_clock::now();

    if (binary)
    {
        constexpr const int32_t readchunk = 255;
        std::vector<char> line(readchunk);

        while (!source.eof())
        {

            source.read(line.data(), readchunk);
            int64_t read = source.gcount();
            destination.write(line.data(), read);
        }
    }
    else
    {
        std::string line;
        while (!source.eof())
        {

            std::getline(source, line);
            destination << line << '\n';
        }
    }

    auto after = std::chrono::steady_clock::now();

    int64_t msec = std::chrono::duration_cast<std::chrono::milliseconds>((after - before)).count();

    std::cout << "Took " << msec << "ms to copy file.\n";
    source.close();
    destination.close();
    std::cout << "Success!\n";


    return 0;
}

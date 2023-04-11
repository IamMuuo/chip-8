#include "chip8.hpp"
#include <fstream>

#define START_ADDRESS 0x200
// contains implementation of various fuctions
// to be used by the chip8 class

void Chip8::loadROM(const char* filename)
{
    // open the file and navigate to end
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if(file.is_open())
    {
        // get the size of the file
        std::streampos size = file.tellg();

        char* buffer = new char[size];


        // get to the beginning of the file filling the memory buffer
        file.seekg(0,std::ios::beg);
        file.read(buffer, size);
        file.close();

        // Load the instructions read to the CHIP's memory
        for(auto i =0;i<size; i++)
        {
            memory[START_ADDRESS + i] = buffer[i];
        }

        // delete the buffer
        delete[] buffer;

    }
}

/**
 * This file is part of CHIP8
 * 
 * Developed By Erick Muuo
 * Email: hearteric57@gmail.com
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
*/

#include "chip8.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>

#define START_ADDRESS 0x200
#define FONTSET_START_ADDRESS 0x50

/**
 * Initializes the CHIP8 simulator
 * Sets the program counter to 0x200
 * Loads fonts to memory
 * Initializes the randByte
 */
Chip8::Chip8() {

  programCounter = START_ADDRESS;

  // initialize the fonts
  const unsigned int FONTSET_SIZE = 80;

  uint8_t fontset[FONTSET_SIZE] = {
      0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
      0x20, 0x60, 0x20, 0x20, 0x70, // 1
      0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
      0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
      0x90, 0x90, 0xF0, 0x10, 0x10, // 4
      0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
      0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
      0xF0, 0x10, 0x20, 0x40, 0x40, // 7
      0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
      0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
      0xF0, 0x90, 0xF0, 0x90, 0x90, // A
      0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
      0xF0, 0x80, 0x80, 0x80, 0xF0, // C
      0xE0, 0x90, 0x90, 0x90, 0xE0, // D
      0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
      0xF0, 0x80, 0xF0, 0x80, 0x80  // F
  };
  // Load fonts into memory
  for (unsigned int i = 0; i < FONTSET_SIZE; ++i) {
    memory[FONTSET_START_ADDRESS + i] = fontset[i];
  }

  // set a random value to randbyte
  srand(time(nullptr));
  randByte = rand() % 255;
}

/**
 * Loads a ROM into memory
 * @param filename a valid path to the ROM to be loaded
 */
void Chip8::loadROM(const char *filename) {
  // open the file and navigate to end
  std::ifstream file(filename, std::ios::binary | std::ios::ate);

  if (file.is_open()) {
    // get the size of the file
    std::streampos size = file.tellg();

    char *buffer = new char[size];

    // get to the beginning of the file filling the memory buffer
    file.seekg(0, std::ios::beg);
    file.read(buffer, size);
    file.close();

    // Load the instructions read to the CHIP's memory
    for (auto i = 0; i < size; i++) {
      memory[START_ADDRESS + i] = buffer[i];
    }

    // delete the buffer
    delete[] buffer;
  }
}

// the instruction sets

/**
 * Clears the video buffer setting each pixel to zero
 */
void Chip8::OP_00E0() { memset(video, 0, sizeof(video)); }

/**
 * RET
 * Returns from a subroutine
 */
void Chip8::OP_00EE() {
  --stackPointer;
  programCounter = stack[stackPointer];
}

/**
 * JUMP ADDR
 * Jumpts to the location nnn
 */
void Chip8::OP_1nnn() {
  // A jump does not remember its origin so no stack interaction is
  // not required

  uint16_t address = opcode & 0x0FFFu;
  programCounter = address;
}

/**
 * CALL ADDR
 * Calls the subroutine at nnn
 */
void Chip8::OP_2nnn() {
  uint16_t address = opcode & 0x0FFFu;

  stack[stackPointer] = programCounter;
  ++stackPointer;
  programCounter = address;
}
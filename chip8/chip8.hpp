/**********************************************************************
 * (C) Copyright 2023
 * All rights reserved
 *
 * Author: Erick Muuo
 *
 * Project Chip8
 *
 * *******************************************************************/
#include <cstdint>
// A class to represent the chip8 core architecture

struct Chip8 {
public:
  uint8_t registers[16]; // The 16 8-bit registers 0-F
  uint8_t memory[4096];  // 4KB of RAM
  uint16_t index;        // A single 16-bit register to store memory
                         // used in various operations

  uint16_t programCounter; // stores the memory address of the statement
                           // to be executed

  uint16_t stack[16];   // the 16 level stack
  uint8_t stackPointer; // 8-bit stack pointer

  uint8_t delayTimer; // Used for various timings
  uint8_t soundTimer; // Used for sound timing
  uint8_t keypad[16]; // 16 input keys that match the first 16 hex
                      // values: 0 - F

  uint32_t video[64 * 32]; // screen
  uint16_t opcode;

  uint8_t randByte;

  // Member functions
  Chip8();
  void loadROM(const char *);
};

// *********************************************************
//
//			 CHIP 8 CLASS FUNCTION DECLARATIONS
//
// *********************************************************

// header inclusion
#include "chip8.h"

using namespace std;

// MEMORY RANGES:
// Total: 0x000 to 0xFFF
// Beginning: 0x000-0x1FF - reserved for the CHIP-8 interpreter
// Middle: 0x050-0x0A0 - storage space for the 16 built-in characters
// Ending: 0x200-0xFFF - instructions from the ROM

const unsigned int START_ADDRESS = 0x200;	// starting memory location for any Chip8 object
const unsigned int FONT_SIZE = 80;			// 5 bytes per character, 16 characters
const unsigned int FONT_START_ADDRESS = 0x50;

// array of fontset (characters created in terms of bytes in hexadecimal)
// Example of the letter 'F'
// 11110000 = (0x)F0
// 10000000 = (0x)80
// 11110000 = (0x)F0
// 10000000 = (0x)80
// 10000000 = (0x)80

uint8_t fontset[FONT_SIZE] = {
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

// Chip8 constructor declaration
Chip8::Chip8() {
	// Sets the program counter to the starting address in memory
	program_counter = START_ADDRESS;

	// loads in fontset into memory
	for (unsigned int i = 0; i < FONT_SIZE; i++) {
		memory[FONT_START_ADDRESS + i] = fontset[i];
	}
}

// Rom loading function declaration
void Chip8::LoadROM(char const* filename) {

	// creation of input file with name filename, and reading in binary at the end of the file
	ifstream rom_file(filename, ios::binary | ios::ate);

	if (rom_file.is_open()) {
		// allocates size and gets current character in stream
		streampos size = rom_file.tellg();

		// creates a pointer to a dynamic array of characters with size 
		char* buffer = new char[size];

		// goes back to beginning of file
		rom_file.seekg(0, ios::beg);
		
		// fills buffer array with the size of the rom file and closes 
		rom_file.read(buffer, size);
		rom_file.close();

		// loads the ROM into the respective memory slot in Chip8 interpreter
		for (long i = 0; i < size; i++) {

			// iterates as long as size and goes storing into memory 
			memory[START_ADDRESS + i] = buffer[i];

		}

		// delets dynamically allocated buffer array
		delete[] buffer;
	}
}

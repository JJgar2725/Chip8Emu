#include <cstdint>

// Chip8 class
class Chip8 {
	public:
		// some functions here later

	private:
		// Chip-8 emulator specfications as listed here: https://austinmorlan.com/posts/chip8_emulator/
		uint8_t memory[4096]{};			// creates memory array composed of 8-bit elements
		uint8_t registers[16]{};		// creates 16 8-bit registers for the emulator
		uint8_t stack_pointer{};		// 8-bit variable for stack pointer
		uint8_t keys[16];				// 8-bit array for key inputs
		uint8_t delayTimer{};			// 8-bit delay timer
		uint8_t soundTimer{};			// 8-bit sound timer
		uint16_t index{};				// 16-bit index variable
		uint16_t program_counter{};		// 16-bit program_counter variable
		uint16_t stack[16]{};			// creates 16-bit memory stack array
		uint16_t opcode;				// 16-bit opcode instruction
		uint32_t display[64 * 32]{};	// 32-bit display for output

};
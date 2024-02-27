#pragma once
#include <cstdint>
#include "olc6502.h"
#include <array>
class Bus
{
public:
	Bus();
	~Bus();


public: // Devices on bus
	olc6502 cpu;

	// Fake Ram to this part of series
	std::array<uint8_t, 64 * 1024> ram;
public: //Bus read & Write
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr, bool bReadOnly = false);
};


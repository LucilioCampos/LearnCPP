﻿#pragma once
#include <memory>
#include "Cartridge.h"
class olc2C02
{
public:
	olc2C02();
	~olc2C02();

private:
	uint8_t		tblName[2][2024];
	uint8_t		tblPalette[32];
	uint8_t		tblPattern[2][4096];

public:
	// Communications with Main Bus
	uint8_t cpuRead(uint16_t addr, bool rdonly = false);
	void    cpuWrite(uint16_t addr, uint8_t  data);

	// Communications with PPU Bus
	uint8_t ppuRead(uint16_t addr, bool rdonly = false);
	void    ppuWrite(uint16_t addr, uint8_t data);

private:
	// The Cartridge or "GamePak"
	std::shared_ptr<Cartridge> cart;

public:
	// Interface
	void ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void clock();
};


#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "common_defines.hpp"

namespace mips
{

    /* =============================================================================== Decoder */
    class Decoder
    {
    public:
        /**
         * @brief Get current OP type
         */
        op_mode_t get_opmode(void)
        {
            return _mode;
        }

        unified_t &get_ops(void)
        {
            return _ops;
        }

        /**
         * @brief Default Constructor
         *
         * This will decode the given instruction and store it in the unified data type
         */
        Decoder(std::bitset<32> instruction)
        {
            /* parse opcode */
            _opcode = (instruction.to_ulong() >> 26u);
            std::cout << "Opcode:" << _opcode;

            switch ((op_t)_opcode.to_ulong())
            {
            case R_TYP: // R-Type Instruction
                _mode = R_TYPE;
                _ops.rt.rs = (instruction.to_ulong() >> 21u);
                _ops.rt.rt = (instruction.to_ulong() >> 16u);
                _ops.rt.rd = (instruction.to_ulong() >> 11u);
                _ops.rt.shamt = (instruction.to_ulong() >> 6u);
                _ops.rt.funct = (instruction.to_ulong() >> 0u);
                std::cout << " Rs: " << _ops.rt.rs << " Rt: " << _ops.rt.rs << " Rd: " << _ops.rt.rd << " Shamt: " << _ops.rt.shamt << " Funct: " << _ops.rt.funct << std::endl;
                break;
            case J_TYP: // J-Type Instruction
                _mode = J_TYPE;
                _ops.jt.addr = (instruction.to_ulong() >> 0u);
                std::cout << " addr: " << _ops.jt.addr << std::endl;
                break;
            case HALT: // HALT
                std::cout << "\n[HALT] End of instruction memory.\n";
                exit(0);
                break;
            default:
                std::cout << std::endl;
                break;
            }
        }

    private:
        std::bitset<6> _opcode{};
        unified_t _ops{};
        op_mode_t _mode = OP_NONE;
    };

}
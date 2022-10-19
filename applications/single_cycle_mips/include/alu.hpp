#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "common_defines.hpp"

namespace mips
{

    /* =============================================================================== ALU */
    class ALU
    {
    public:
        std::bitset<32> ALUresult;

        std::bitset<32> ALUOperation(std::bitset<3> ALUOP, std::bitset<32> oprand1, std::bitset<32> oprand2)
        {
            /* reset the ALU result */
            ALUresult.reset();
            
            /* parse ALU op */
            funct_t alu_op = static_cast<funct_t>(ALUOP.to_ulong());
            std::cout << "AluOp = " << alu_op << std::endl;
            bool check = false;

            /* perform ALU operation */
            switch (alu_op)
            {
            case ADDU:
                check = ((oprand1.to_ullong() + oprand2.to_ullong()) < UINT32_MAX);
                if (check)
                {
                    ALUresult = oprand1.to_ulong() + oprand2.to_ulong();
                }
                break;
            case SUBU:
                check = (((int)oprand1.to_ullong() - (int)oprand2.to_ullong()) >= 0);
                if (check) {
                    ALUresult = oprand1.to_ulong() - oprand2.to_ulong();
                }
                break;
            case AND:
                ALUresult = oprand1.to_ulong() & oprand2.to_ulong();
                break;
            case OR:
                ALUresult = oprand1.to_ulong() | oprand2.to_ulong();
                break;
            case NOR:
                ALUresult = ~(oprand1.to_ulong() | oprand2.to_ulong());
                break;
            default:
                break;
            }

            std::cout << "ALU Result : " << ALUresult << std::endl;

            return ALUresult;
        }
    };
}
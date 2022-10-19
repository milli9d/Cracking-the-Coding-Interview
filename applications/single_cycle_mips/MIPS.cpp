#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "include/common_defines.hpp"
#include "include/register_file.hpp"
#include "include/alu.hpp"
#include "include/decoder.hpp"
#include "include/imem.hpp"
#include "include/dmem.hpp"

int main()
{
    mips::RF myRF;
    mips::ALU myALU;
    mips::INSMem myInsMem;
    mips::DataMem myDataMem;

    uint32_t myPC = 0u;
    uint32_t iteration = 0u;

    while (1)
    {
        /* log for debug */
        std::cout << "==============================\nCPU Cycle : " << iteration++ << std::endl;

        /* fetch instruction */
        std::bitset<32> instruction = myInsMem.ReadMemory(myPC);

        /* decode */
        mips::Decoder decode(instruction);
        mips::unified_t &ops = decode.get_ops();
        mips::op_mode_t curr_mode = decode.get_opmode();

        /* read RF */
        switch (curr_mode)
        {
        case mips::R_TYPE:
        case mips::I_TYPE:
            /* read RF contents */
            myRF.ReadWrite(ops.rt.rs, ops.rt.rt, 0u, 0u, 0u);
            std::cout << "RTYPE\nRdData1: " << myRF.ReadData1 << "\nRdData2: " << myRF.ReadData2 << std::endl;
            break;
        case mips::J_TYPE:
            break;
        default:
            break;
        }

        /* Execute */
        switch (curr_mode)
        {
        case mips::R_TYPE:
            myALU.ALUOperation(ops.rt.funct.to_ulong(), myRF.ReadData1, myRF.ReadData2);
            break;
        default:
            break;
        }

        /* Read/Write Mem */

        /* Write back to RF */
        switch (curr_mode)
        {
        case mips::R_TYPE:
            /* write back ALU result */
            myRF.ReadWrite(0u, 0u, ops.rt.rd, myALU.ALUresult, 1u);
            break;
        default:
            break;
        }

        /* dump RF */
        myRF.OutputRF();

        /* increment PC */
        myPC += WORD_LEN;
    }

    /* dump data mem */
    myDataMem.OutputDataMem();

    return 0;
}

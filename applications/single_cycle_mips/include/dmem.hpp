#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

#include "common_defines.hpp"

namespace mips
{

    /* =============================================================================== Data Memory */

    class DataMem
    {
    public:
        std::bitset<32> readdata;

        /**
         * @brief Default Constructor
         *
         * Open DMEM file and read contents
         */
        DataMem()
        {
            DMem.resize(MemSize);
            std::ifstream dmem;
            std::string line;
            int i = 0;
            dmem.open("dmem.txt");
            if (dmem.is_open())
            {
                while (getline(dmem, line))
                {
                    DMem[i] = std::bitset<8>(line);
                    i++;
                }
            }
            else
            {
                throw std::runtime_error("DMEM Unable to open file.");
            }
            dmem.close();
        }

        std::bitset<32> MemoryAccess(std::bitset<32> Address, std::bitset<32> WriteData, std::bitset<1> readmem, std::bitset<1> writemem)
        {

            // implement by you.
            return readdata;
        }

        void OutputDataMem() // write dmem results to file
        {
            std::ofstream dmemout;
            dmemout.open("dmemresult.txt");
            if (dmemout.is_open())
            {
                for (int j = 0; j < 1000; j++)
                {
                    dmemout << DMem[j] << std::endl;
                }
            }
            else
            {
                throw std::runtime_error("OUT Unable to open file.");
            }
            dmemout.close();
        }

    private:
        std::vector<std::bitset<8>> DMem;
    };

}
#pragma once
#include <cstdio>
#include <iostream>

namespace CTCI
{
    void BUG_ON(bool assert, const char *cause)
    {
        if (assert) {
            printf("ERROR [BUG]: %s \n", cause);
            exit(1);
        }
    }
}
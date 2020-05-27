#pragma once

int NWD(int lhs, int rhs) {

    if (lhs == 0 || rhs == 0)
        return std::max(lhs, rhs);

    lhs = std::abs(lhs);
    rhs = std::abs(rhs);

    while (lhs != rhs)
    {
        if (lhs > rhs)
        {
            lhs = lhs - rhs;
        }
        else
        {
            rhs = rhs - lhs;
        }
    }

    return lhs;
}

int NWW(int lhs, int rhs) {

    if (lhs == 0 || rhs == 0)
        return 0;

    lhs = std::abs(lhs);
    rhs = std::abs(rhs);

    return (lhs / NWD(lhs, rhs)) * rhs;
}
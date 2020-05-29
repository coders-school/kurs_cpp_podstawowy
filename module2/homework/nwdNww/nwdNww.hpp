#pragma once

int NWD(int lhs, int rhs)
{
    int mod = 0;
    while (rhs != 0)
    {
        mod = lhs % rhs;
        lhs = rhs;
        rhs = mod;
    }
    return std::abs(lhs);
}

int NWW(int lhs, int rhs)
{
    int nwd = NWD(lhs, rhs);
    if (nwd == 0)
        return 0;
    return std::abs((lhs * rhs) / NWD(lhs, rhs));
}

// poddałem się
// {
//     if (lhs == 0 || rhs == 0)
//     {
//         lhs = rhs;
//     }
//     return lhs;
//     if (lhs < 0)
//     {
//         lhs = lhs * (-1);
//     }
//     if (rhs <0){
//         rhs = rhs * (-1);
//     }
//     {
//         while (lhs != rhs)
//             if (lhs > rhs)
//                 lhs -= rhs;
//             else
//                 lhs -= rhs;
//         return lhs;
//     }
// }
// int NWW(int lhs, int rhs)
// {
//     int tmp;
//     while (rhs != 0)
//     {
//         tmp = rhs;
//         rhs = lhs % rhs;
//         lhs = tmp;
//     }
//     return lhs;
// }
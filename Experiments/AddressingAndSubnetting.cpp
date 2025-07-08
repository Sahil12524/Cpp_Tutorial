/*
    File: AddressingAndSubnetting.cpp

    Purpose:
        This program computes both the network address and broadcast address
        of a given IPv4 address using its subnet mask. The computation is done
        using SSE instructions in external Assembly for efficient parallel
        bitwise operations on the 4 octets.

    Inputs:
        - ipAddress     : std::array<int, 4> representing the IPv4 address
        - networkMask   : std::array<int, 4> representing the subnet mask

    Outputs:
        - resultNetwork     : std::array<int, 4> containing the result of (ip & mask)
        - resultBroadcast   : std::array<int, 4> containing the result of (ip | ~mask) masked to 8 bits

    Behavior:
        Calls the external Assembly function `AddressingAndSubnetting`, which:
            - Computes the network address using a bitwise AND
            - Computes the broadcast address using a bitwise NOT and OR
            - Ensures each resulting octet is clamped to 0–255 via masking

    Example:
        ipAddress       = {70, 12, 100, 132}
        networkMask     = {255, 255, 255, 192}
        resultNetwork   = {70, 12, 100, 128}
        resultBroadcast = {70, 12, 100, 191}

    Build Command:
        nasm -f win64 AddressingAndSubnetting.asm -o AddressingAndSubnetting.o ^
        && g++ -O2 -std=c++17 AddressingAndSubnetting.cpp AddressingAndSubnetting.o -o AddressingAndSubnetting.exe ^
        && AddressingAndSubnetting.exe
*/

#include <iostream>
#include <array>
#include <cstdint>

extern "C" int AddressingAndSubnetting(
    int *ipAddress,
    int *networkMask,
    int *resultNetwork,
    int *resultBroadcast);

void printIP(const std::array<int, 4> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << (arr[i] & 0xFF);
        if (i != arr.size() - 1)
        {
            std::cout << ".";
        }
    }

    std::cout << "\n";
}

int main()
{
    std::array<int, 4> ipAddress = {70, 12, 100, 132};
    std::array<int, 4> networkMask = {255, 255, 255, 192};
    std::array<int, 4> resultNetwork = {};
    std::array<int, 4> resultBroadcast = {};

    AddressingAndSubnetting(ipAddress.data(), networkMask.data(), resultNetwork.data(), resultBroadcast.data());

    std::cout << "Network Address:   ";
    printIP(resultNetwork);

    std::cout << "Broadcast Address: ";
    printIP(resultBroadcast);

    return 0;
}
/*
    File: AddressingAndSubnetting.cpp

    Purpose:
        This program calculates both the Network Address and Broadcast Address
        of a given IPv4 address using its subnet mask. It also computes the number
        of host bits and the total number of usable hosts available in that subnet.
        All bitwise computations on the 4 octets are offloaded to an external 
        NASM Assembly routine using SSE instructions for efficient parallel execution.

    Inputs:
        - ipAddress       : std::array<int, 4> — the 32-bit IPv4 address split into 4 octets
        - networkMask     : std::array<int, 4> — the subnet mask in 4-octet format

    Outputs:
        - resultNetwork     : std::array<int, 4> — contains (ipAddress[i] & networkMask[i])
        - resultBroadcast   : std::array<int, 4> — contains (ipAddress[i] | ~networkMask[i]) masked to 8-bit
        - hostBits          : int — total number of bits available for host addressing
        - useableHost       : int — total usable hosts in subnet (2^hostBits - 2)

    Behavior:
        - Calls `AddressingAndSubnetting` (NASM) which:
            → Computes the network address using SIMD bitwise AND
            → Computes the broadcast address using SIMD bitwise OR with inverse mask
            → Masks all results to ensure 8-bit octets (0–255 range)
        - Uses a helper C++ function to count 1s in subnet mask (Hamming weight)
        - Calculates usable hosts as (2^hostBits - 2), excluding network/broadcast

    Example:
        ipAddress         = {70, 12, 100, 132}
        networkMask       = {255, 255, 255, 192}
        resultNetwork     = {70, 12, 100, 128}
        resultBroadcast   = {70, 12, 100, 191}
        hostBits          = 6
        useableHost       = 62

    Build Command:
        nasm -f win64 AddressingAndSubnetting.asm -o AddressingAndSubnetting.o ^
        && g++ -O2 -std=c++17 AddressingAndSubnetting.cpp AddressingAndSubnetting.o -o AddressingAndSubnetting.exe ^
        && AddressingAndSubnetting.exe
*/


#include <iostream>
#include <array>
#include <cstdint>

// Declaration of external NASM function (Win64 ABI)
extern "C" int AddressingAndSubnetting(
    int *ipAddress,
    int *networkMask,
    int *resultNetwork,
    int *resultBroadcast);

// Prints IP address from a 4-element array, formatted as dotted-decimal
void printIP(const std::array<int, 4> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << (arr[i] & 0xFF); // Ensure 8-bit value per octet
        if (i != arr.size() - 1)
        {
            std::cout << ".";
        }
    }

    std::cout << "\n";
}

// Counts number of 1s in an 8-bit byte (Hamming weight)
int countOnes(uint8_t byte)
{
    int count = 0;
    while (byte)
    {
        count += byte & 1; // Increment if LSB is 1
        byte >>= 1; // Shift right to check next bit
    }
    return count;
}

int main()
{
    // IPv4 address and subnet mask (4 octets)
    std::array<int, 4> ipAddress = {70, 12, 100, 132};
    std::array<int, 4> networkMask = {255, 255, 255, 192};

     // Output arrays for results
    std::array<int, 4> resultNetwork = {}; // Network address
    std::array<int, 4> resultBroadcast = {}; // Broadcast address

    int totalNetworkBits = 0;

    // Count how many bits are set to 1 in the subnet mask
    for (int i = 0; i < 4; ++i)
    {
        totalNetworkBits += countOnes(networkMask[i] & 0xFF); // Use only low 8 bits
    }

    // Calculate number of host bits and usable hosts in the subnet
    int hostBits = 32 - totalNetworkBits;
    int useableHost = (hostBits >= 2) ? (1 << hostBits) - 2 : 0; // 2 reserved: network and broadcast

    // Call external Assembly function for network and broadcast computation
    AddressingAndSubnetting(
        ipAddress.data(), 
        networkMask.data(), 
        resultNetwork.data(), 
        resultBroadcast.data());

    // Print results
    std::cout << "Network Address:   ";
    printIP(resultNetwork);

    std::cout << "Broadcast Address: ";
    printIP(resultBroadcast);

    std::cout << "Host bits: " << hostBits << "\n";
    std::cout << "Useable hosts: " << useableHost << "\n";

    return 0;
}
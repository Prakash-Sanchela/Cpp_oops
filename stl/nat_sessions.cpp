#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdlib> // For rand()

// Represents an internal PC with a private IP
class PC {
public:
    PC(const std::string& ip) : privateIP(ip) {}

    std::string getPrivateIP() const {
        return privateIP;
    }

    int generateEphemeralPort() {
        return 10000 + rand() % 50000; // Random port in the range [10000, 60000]
    }

private:
    std::string privateIP;
};

// Represents the router with NAT capability
class Router {
public:
    Router(const std::string& publicIP) : publicIP(publicIP), publicPortCounter(40000) {}

    // Handle a packet from an internal PC to an external server
    void handlePacket(const PC& pc, const std::string& externalIP, int privatePort) {
        int publicPort = getNextPublicPort();
        
        // Add a new entry to the NAT table
        NATEntry entry = {pc.getPrivateIP(), privatePort, publicIP, publicPort, externalIP};
        natTable[publicPort] = entry;

        std::cout << "NAT Table Entry Created: [" 
                  << pc.getPrivateIP() << ":" << privatePort 
                  << " -> " << publicIP << ":" << publicPort 
                  << "] -> " << externalIP << std::endl;
    }

    // Handle a response packet coming back to the public IP/port
    void handleIncomingPacket(int publicPort) {
        if (natTable.find(publicPort) != natTable.end()) {
            NATEntry entry = natTable[publicPort];
            std::cout << "Routing response to internal PC: " 
                      << entry.privateIP << ":" << entry.privatePort 
                      << " (for destination: " << entry.externalIP << ")" << std::endl;
        } else {
            std::cout << "No NAT table entry found for port: " << publicPort << std::endl;
        }
    }

private:
    // Represents a NAT table entry
    struct NATEntry {
        std::string privateIP;
        int privatePort;
        std::string publicIP;
        int publicPort;
        std::string externalIP;
    };

    std::string publicIP;                         // Router's public IP
    int publicPortCounter;                        // Counter to generate unique public ports
    std::unordered_map<int, NATEntry> natTable;   // NAT table mapping public ports to NAT entries

    int getNextPublicPort() {
        return publicPortCounter++;
    }
};

int main() {
    // Initialize 5 PCs with private IPs
    std::vector<PC> pcs = {
        PC("192.168.1.2"),
        PC("192.168.1.3"),
        PC("192.168.1.4"),
        PC("192.168.1.5"),
        PC("192.168.1.6")
    };

    // Initialize the router with a public IP
    Router router("198.51.100.1");

    // Each PC sends a packet to an external server
    std::string externalServerIP = "203.0.113.50";
    for (PC& pc : pcs) {
        int privatePort = pc.generateEphemeralPort();
        router.handlePacket(pc, externalServerIP, privatePort);
    }

    // Simulate a response coming back to one of the public ports
    std::cout << "\nHandling incoming packets..." << std::endl;
    router.handleIncomingPacket(40002); // Simulate response to the 3rd PC
    router.handleIncomingPacket(40005); // Invalid port, should not be in NAT table

    return 0;
}


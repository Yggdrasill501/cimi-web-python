#ifndef WEBSOCKETFRAME_H
#define WEBSOCKETFRAME_H

#include <vector>
#include <cstdint>

class WebSocketFrame {
public:
    // Frame data members
    bool fin;
    uint8_t opcode;
    bool mask;
    uint64_t payloadLength;
    std::vector<uint8_t> maskingKey;
    std::vector<uint8_t> payloadData;

    // Parse a frame from a byte stream
    static WebSocketFrame parse(const std::vector<uint8_t>& buffer);

    // Encode this frame to a byte stream
    std::vector<uint8_t> encode() const;

    // Other utility methods...
};

#endif // WEBSOCKETFRAME_H


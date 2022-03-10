#ifndef OBD_EMULATOR_H
#define OBD_EMULATOR_H

#include <map>
#include "./communication_layer.h"
#include "./obd_service.h"

namespace ObdEmulator
{
    /// @brief A class that routes OBD queries to their corresponding services
    class ObdEmulator
    {
    private:
        CommunicationLayer *mCommunicationLayer;
        std::map<uint8_t, ObdService *> mObdServices;

        bool processQuery(
            std::vector<uint8_t> &&query,
            std::vector<uint8_t> &response);

    public:
        /// @brief Constructor
        /// @param communicationLayer CAN communication medium abstraction layer
        /// @param obdServices Supported OBD-II services during the emulation
        ObdEmulator(
            CommunicationLayer *communicationLayer,
            std::initializer_list<ObdService *> obdServices);
        ~ObdEmulator();

        /// @brief Try to start the emulation
        /// @returns True if the emulation start was successful, otherwise false
        bool TryStart();

        /// @brief Try to stop the emulation
        /// @returns True if the emulation stop was successful, otherwise false
        bool TryStop();
    };
}

#endif
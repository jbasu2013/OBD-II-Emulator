#include <gtest/gtest.h>
#include <obdemulator/communication_layer.h>

namespace ObdEmulator
{
    class CommunicationLayerTest : public testing::Test, public CommunicationLayer
    {
    protected:
        static bool DummyCallback(
            std::vector<uint8_t> &&request,
            std::vector<uint8_t> &response);

    public:
        void Start() override
        {
        }

        void Stop() override
        {
        }
    };

    bool CommunicationLayerTest::DummyCallback(
        std::vector<uint8_t> &&request,
        std::vector<uint8_t> &response)
    {
        return false;
    }

    TEST_F(CommunicationLayerTest, SetCallbackMethod)
    {
        SetCallback(DummyCallback);
        EXPECT_TRUE(Callback);
    }

    TEST_F(CommunicationLayerTest, ResetCallbackMethod)
    {
        SetCallback(DummyCallback);
        ResetCallback();
        EXPECT_FALSE(Callback);
    }
}
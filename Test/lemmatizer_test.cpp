#include "gtest/gtest.h"
#include "lemmatizer.h"
#include <filesystem>

class LemmatizerTest : public ::testing::Test {
protected:

    void SetUp() override {
        lemmatizer = new Lemmatizer();
        std::string path = "../Examples/";
        for (const auto &entry : fs::directory_iterator(path)) {
            std::cout << entry.path << std::endl;
        }
    }

    void TearDown() override {
        delete lemmatizer;
    }

    Lemmatizer* lemmatizer;

    std::vector<std::string> inputs;
    std::vector<Token> outputs;
};

// Use TEST_F for tests that use the fixture
TEST_F(LemmatizerTest, TestMethodReturnsTrue) {
    // Arrange: set up the test conditions
    // The lemmatizer is already initialized by the fixture

    // Act: call the method you're testing
    bool result = lemmatizer->someMethod();

    // Assert: check if the result is as expected
    ASSERT_TRUE(true);
}

// A simple test without a fixture
TEST(SimpleTest, AnotherMethodReturnsCorrectValue) {
    EXPECT_EQ(5, 5);
}

int main(int argc, char** argv) {
    // This line initializes Google Test
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
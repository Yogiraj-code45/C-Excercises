#include "stringimpl.h"

int main()
{
    std::unique_ptr<stringimpl> mInstance_ = std::make_unique<stringimpl>();

    std::unique_ptr<stringimpl> mInstance1_ = std::make_unique<stringimpl>();

    stringimpl firstString;

    stringimpl secondString;

    std::thread strThread = std::thread([&] {
        for (auto x = 'a'; x <= 'z' ;x++)
        {
            mInstance_->setChr(x);
            mInstance1_->setChr(x);
        }
    });

    if (strThread.joinable())
    {
        strThread.join();
    }

    std::cout << mInstance_->getLength() << std::endl;

    mInstance_->printAllLetters();

    firstString = std::move(*mInstance_);

    secondString = std::move(*mInstance1_);

    firstString.append(secondString);

    std::cout << "First string length" << firstString.getLength() << std::endl;

    firstString.printAllLetters();

    return 0;
}
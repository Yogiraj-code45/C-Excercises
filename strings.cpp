#include "stringimpl.h"

int main()
{
    std::unique_ptr<stringimpl> mInstance_ = std::make_unique<stringimpl>();

    /// Reference capturing

    // Lamda function inside thread

    std::thread strThread = std::thread([&] {
        for (auto x = 'a'; x <= 'z' ;x++)
        {
            mInstance_->setChr(x);
        }
    });

    if (strThread.joinable())
    {
        strThread.join();
    }

    std::cout << mInstance_->getLength() << std::endl;

    mInstance_->printAllLetters();

    return 0;
}
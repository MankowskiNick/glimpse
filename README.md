# GlimpseLogger

## Description
GlimpseLogger is a simple logging utility designed to handle OpenGL error logging and general message logging. It supports multiple output targets and can handle fatal errors by terminating the application.

## Installation
To use GlimpseLogger in your project, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/MankowskiNick/glimpse.git
    ```
2. Navigate to the project directory:
    ```sh
    cd glimpse
    ```
3. Build the project using `cmake`:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

## Usage
Here's a brief overview of how to use GlimpseLogger:
### Logging
1. **Create new logger**
    ```cpp
    Glimpse::GlimpseLogger logger();
    ```
1. **Add a new logging output**:
    ```cpp
    GLOut* newOutput = new ConsoleOutput();
    logger.AddLogging(newOutput);

    // Alternatively, you can pass a GLOut to the Glimpse::GlimpseLogger constructor.
    Glimpse::GlimpseLogger newLogger(newOutput);
    ```

2. **Log a message**:
    ```cpp
    logger.Log("This is a warning.", Glimpse::WARNING);
    logger.Log("This is a fatal error." Glimpse::FATAL);
    ```

3. **Log an OpenGL error**:
    ```cpp
    int errorCode = glGetError();
    logger.LogGL(errorCode);
    ```

### Building new outputs
**Building New Outputs Using the GLOut Abstract Class**

To create a new output type for the GlimpseLogger, you need to derive a class from the GLOut abstract class and implement the Output method. This method will define how the log messages are handled and where they are sent.

#### Steps to Create a New Output Class
1. **Include Necessary Headers**: Ensure you include the glout.h header file and any other necessary headers.
2. **Derive from GLOut**: Create a new class that inherits from GLOut.
3. **Implement the Output Method**: Define the behavior of the Output method to handle log messages.

#### Example: Creating a Console Output Class

Here is an example of how to create a console output class that prints log messages to the standard output.

**Creating output class**

Start by creating an output class that inherits from GLOut and implements the Output method.
```cpp
#include "glout.h"
#include <iostream>

namespace Glimpse {
    class ConsoleOutput : public GLOut {
    public:
        // Destructor
        virtual ~ConsoleOutput() {}

        // Implement the Output method
        void Output(const std::string& message, const GLLogStatus status) override {
            std::cout << "Status: " << status << " - Message: " << message << std::endl;
        }
    };
}
```

**Adding the New Output to GlimpseLogger**

Once you have created your new output class, you need to add it to the GlimpseLogger so that it can be used for logging.

```cpp
#include "glimpse.h"
#include "consoleoutput.h"

int main();    Glimpse::GlimpseLogger logger();

    // Create an instance of the new output class
    Glimpse::ConsoleOutput* consoleOutput = new Glimpse::ConsoleOutput();

    // Add logging
g
    logger.AddLogging(consoleOutput);

    // Log a message
    logger.Log("This is a test message", INFO);

    return 0;
}
```

## Contributing
We welcome contributions to GlimpseLogger! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes.
4. Commit your changes (`git commit -am 'Add new feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Open a pull request.
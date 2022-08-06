# Blue2devclass - bluetooth device class parser

**Blue2devclass** is a parser for bluetooth handshakes based on linux API. Blue2devclass displays all available information about the remote bluetooth devices in xml format
## Documents
* [Baseband](https://btprodspecificationrefs.blob.core.windows.net/assigned-numbers/Assigned%20Number%20Types/Baseband.pdf)
## Requirements
* [spdlog](https://github.com/gabime/spdlog)

## Compilation and installation
```
$ sudo apt-get install libspdlog-dev
$ mkdir build; cd build
$ cmake ..
$ make


# A simple UDP broadcaster using Boost.asio.

## Build

Install Boost C++ library on your system.
It sends broadcast on port _2020_.

```shell script
cmake
cd cmake-build-debug
make 
```

## Run

```shell script
./boost_test _message_
```

Example

```shell script
./boost_test my_message_to_be_sent
```

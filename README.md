# SCP-7777
A small C++20 library to convert between plaintext and an instance of SCP-7777. To use in your own project, simply `#include "scp_7777.hxx"`

All functions read a STL string object and return another STL string object. C-strings are not currently supported. Control characters with a value less than 32 will be discarded when decoding. Encoding may optionally pad the output to a specified total length with random output generated from a specified seed value.

The list of instances are taken verbatim from the original SCP-7777.

# Licensing
This code is based on "SCP-7777" by Yossipossi, from the SCP Wiki. Source: https://scp-wiki.wikidot.com/scp-7777. Licensed under CC-BY-SA.

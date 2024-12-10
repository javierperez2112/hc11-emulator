cmake_minimum_required(VERSION 3.0.0)

set(LANGUAGE C_STANDARD)
project("hc11-emulator")

add_executable(main main.c hc11_mem.c hc11_inst.c hc11_search.c)
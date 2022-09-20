# README

## Dependencies

1. ROS2
2. colcon
3. gtest
4. valgrind

## Build & Install

```shell
git clone <branch>
colcon build
```

## Directories

```shell
demo
├── CMakeLists.txt
├── README.md
├── include
│   └── demo.hpp
├── package.xml
├── src
│   ├── demo.cpp
│   └── main.cpp
└── unitest
    └── ut.cpp
```

The `include` and  `src` folder, `package.xml` and `CMakeLists.txt` file are created by the ros2 pkg create command `ros2 pkg create <pkg_name>`.

The unit test source file is located in:
`demo/unitest/`

If built successfully, the directory would be like:

```shell
.
├── build
│   ├── COLCON_IGNORE
│   └── demo
├── demo
│   ├── CMakeLists.txt
│   ├── README.md
│   ├── include
│   ├── package.xml
│   ├── src
│   └── unitest
├── install
│   ├── COLCON_IGNORE
│   ├── _local_setup_util_ps1.py
│   ├── _local_setup_util_sh.py
│   ├── demo
│   ├── local_setup.bash
│   ├── local_setup.ps1
│   ├── local_setup.sh
│   ├── local_setup.zsh
│   ├── setup.bash
│   ├── setup.ps1
│   ├── setup.sh
│   └── setup.zsh
└── log
    ├── COLCON_IGNORE
    ├── build_2022-09-20_23-16-32
    ├── latest -> latest_build
    └── latest_build -> build_2022-09-20_23-16-32
```

The Unit Test executable located in:
`${workspaceFolder/install/demo/unitest/}`

## Run Unit Test

Simplely,

```shell
./install/demo/unitest/demo_test 
```

Terminal outputs:

```shell
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from demo_test
[ RUN      ] demo_test.test1
[       OK ] demo_test.test1 (0 ms)
[----------] 1 test from demo_test (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```

## Run Memory Leak Check

```shell
valgrind --tool=memcheck --leak-check=full ./install/demo/unitest/demo_test 
```

Terminal outputs:

```shell
==68499== Memcheck, a memory error detector
==68499== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==68499== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==68499== Command: ./install/demo/unitest/demo_test
==68499== 
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from demo_test
[ RUN      ] demo_test.test1
[       OK ] demo_test.test1 (11 ms)
[----------] 1 test from demo_test (20 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (62 ms total)
[  PASSED  ] 1 test.
==68499== 
==68499== HEAP SUMMARY:
==68499==     in use at exit: 0 bytes in 0 blocks
==68499==   total heap usage: 164 allocs, 164 frees, 109,089 bytes allocated
==68499== 
==68499== All heap blocks were freed -- no leaks are possible
==68499== 
==68499== For lists of detected and suppressed errors, rerun with: -s
==68499== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## TODO

Use `lcov` to generate coverage stats.

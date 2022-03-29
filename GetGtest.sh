

# 从github上获取googletest的版本
git clone https://github.com/google/googletest.git -b release-1.11.0

# 本地编译, 将googletest编译为动态库
# 生成动态库的目录为googletest/out/lib/,  googltest运行所需的动态库为libgtest.so和libgtest_main.so
# 头文件所在目录为googletest/googletest/include/gtest
cd googletest && mkdir out && cd out && cmake -DBUILD_SHARED_LIBS=ON ../ && make

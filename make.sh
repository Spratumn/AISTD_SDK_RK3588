SDK_ROOT_DIR=$PWD
TOOLCHAIN_NAME=gcc-arm-12.3-x86_64-aarch64-none-linux-gnu

INCLUDE_PATH=${SDK_ROOT_DIR}/include
LIB_PATH=${SDK_ROOT_DIR}/lib
COMPILER_PATH=${SDK_ROOT_DIR}/${TOOLCHAIN_NAME}/bin/aarch64-none-linux-gnu-g++

CFLAGS="-std=gnu++20 -O3 -I${INCLUDE_PATH} -L${LIB_PATH}"
LDFLAGS="-lz -ltbb -lopenjp2 -ljpeg -lpng -lrknn_api -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -laistd"

${COMPILER_PATH} ${CFLAGS} ${LDFLAGS} demo.cpp -o demo.elf
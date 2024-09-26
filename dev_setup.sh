cd ../openmesh-manage/3rd/OpenMesh-11.0.0/

rm -rf build

mkdir build
cd build
cmake ..
make -j

./compile.sh

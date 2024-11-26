ROOT=$PWD

cd ../openmesh-manage/3rd/OpenMesh-11.0.0/

rm -rf build

mkdir build
cd build
cmake -DOPENMESH_DOCS=False ..
make -j

cd $ROOT
./compile.sh

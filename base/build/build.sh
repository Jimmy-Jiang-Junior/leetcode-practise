
mkdir -p out
cd out
cmake ../ && make
cd -

./out/test

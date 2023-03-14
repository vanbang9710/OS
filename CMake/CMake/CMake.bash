cd CMake || exit
ls
make clean

chmod +x producer.bash
./producer.bash
chmod +x consumer.bash
./consumer.bash


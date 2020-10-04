
# If you have already google benchmark installed

``git clone https://github.com/AnChristos/Mult5x3.git``

# Also install google benchmark 
Assuming you want also the google bench mark code

``git clone --recursive https://github.com/AnChristos/Mult5x3.git``

``cd Mult5x3/``


The following will install the benchmark under `${HOME}/.local`

``source buildGoogleBenchmark.sh``

edit

``cmake -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_INSTALL_PREFIX=${HOME}/.local ../ ``

to change location


# Build with CMake 

``mkdir build; cd build``

``cmake ../Mult5x3``

``make``

``./mult5x3_bench --benchmark_report_aggregates_only=true --benchmark_repetitions=20``


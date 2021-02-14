# If you do not have already google benchmark installed

``git clone https://github.com/google/benchmark.git``

The following script from this repo will install the benchmark under ``${HOME}/.local``

``source buildGoogleBenchmark.sh``

# Install  RkUtils5x3

``git clone https://github.com/AnChristos/RkUtils5x3.git``

# Build with CMake 

``mkdir build; cd build``

``cmake ../RkUtils5x3``

``make``

``./RkUtils5x3_bench --benchmark_report_aggregates_only=true --benchmark_repetitions=20``


#!/bin/bash

#declare -a benchmark=("bzip2" "mcf" "hmmer" "sphinx3" "cactusADM")
declare -a benchmark=("astar" "h264ref" "gcc" "sjeng" "gamess")
run_num=run_5_Final_Benchmarks_run
policy=lru

for bench in "${benchmark[@]}"; do
	./build/X86/gem5.opt -d $run_num/$bench/$policy configs/spec2k6/run.py --benchmark=$bench --maxinsts=250000000 --cpu-type=DerivO3CPU --caches --l2cache --l3cache --fast-forward=1000000000 --warmup-insts=50000000 --standard-switch=50000000 --caches --l2cache --l3cache --l3_replacement_policy=$policy
done

wait

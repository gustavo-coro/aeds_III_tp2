#!/bin/bash

# Set up variables for the script
NUM_RUNS=50  # Number of times to run the process_data program
DATA_FILE="randomData.txt"  # Name of the input file to create

# Loop through the number of runs and generate random data each time
for (( i=1; i<=$NUM_RUNS; i++ ))
do
    # Generate random data and write it to the input file
    echo "Generating data for run $i..."
    ./data $DATA_FILE
    
    # Call the process_data program and pass it the input file
    echo "Running process_data for run $i..."
    #./main $DATA_FILE output_$i.txt
    ./tp2 1 $DATA_FILE
    ./tp2 2 $DATA_FILE

done
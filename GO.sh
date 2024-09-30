#!/bin/bash

rosparam set cmd_circuit 0
rosparam set cmd_gear 3

echo "Enter Your Circuit Number: "
read varCkt
rosparam set n_circuit $varCkt

rosparam set cmd_dbw 1

rosparam set cmd_gear 4


echo "Ready to GO ? type 1 to go"
read varGo

rosparam set cmd_circuit $varGo


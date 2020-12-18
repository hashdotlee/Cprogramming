#!/bin/bash
# set the STRING variable
STRING="Hello World!"
# print the contents of the variable on screen
echo $STRING
while true; do
  python3 auto-connect.py
  sleep 3600
done
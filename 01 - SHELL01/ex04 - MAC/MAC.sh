#!/bin/bash

ifconfig | grep -i ether | cut -d ' ' -f 2

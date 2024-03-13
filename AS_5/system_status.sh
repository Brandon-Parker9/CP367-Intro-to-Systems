#!/bin/bash

################################################################################
# Assignment: System Status Script
# Author: Brandon Parker
# Date: 03-12-2024
#
# Description:
#   This script monitors various system metrics such as CPU utilization, free memory,
#   and disk usage, and provides warnings if any metric exceeds a specified threshold.
#
# Instructions:
#   1. Complete the implementation of the following functions:
#      - cpu_utilization: Check CPU utilization and compare it with a threshold percentage.
#      - mem_free: Check free memory percentage and compare it with a threshold.
#      - disk_usage: Check disk usage percentage and compare it with a threshold.
#      - send_report: Send the system status report to the provided email address.

RETURN_OK=0
RETURN_BAD=1

cpu_utilization () {
# Function to check CPU Utilization and compare it with a threshold percentage
# Usage: cpu_utilization <cpu_threshold_percentage>
# Arguments:
#   - cpu_threshold_percentage: The threshold percentage for CPU usage (between 0 and 100)
# Returns:
#   - "cpu ok!!" if CPU utilization is below the threshold
#   - "cpu warning!!" if CPU utilization is above threshold

    # Check if exactly one argument is provided
    if [ "$#" -ne "1" ]
        then

        # Print a message and return an error code
        echo "Enter the CPU threshold percentage between 0 to 100"
        return $RETURN_BAD
    fi

    # Get the current CPU usage percentage
    cpu_usage=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\) id.*/\1/" | awk '{print 100 - $1}')

    echo "cpu utilization: $cpu_usage"
    echo

    # Compare the current CPU usage with the provided threshold
    if [ $(echo "$cpu_usage $1" | awk '{if ($1 < $2) print 1; else print 2}') -eq 1 ]
        then
        # Return a message indicating CPU is okay
        echo "cpu ok!!"
    else
        # Return a message indicating CPU warning
        echo "cpu warning!!"
    fi
   


}

mem_free () {
# Function to check the percentage of free memory and compare it with a threshold
# Usage: mem_free <free_memory_threshold_percentage>
# Arguments:
#   - free_memory_threshold_percentage: The threshold percentage of free memory (between 0 to 100)
# Returns:
#   - "memory warning!!" if the memory free is below the threshold
#   - "memory ok!!" if the memory free is above the threshold

    # Check if exactly one argument is provided
    if [ "$#" -ne "1" ]
        then
        # Print a message and return an error code
        echo "Enter the free memory threshold percentage between 0 to 100"
        return $RETURN_BAD
    fi

    # Get the current free memory
    free_mem=$(free | grep "Mem:" | awk '{print $4}')

    # Get the current total memory
    total_mem=$(free | grep "Mem:" | awk '{print $2}')

    #  Calculate the free memory percentage
    free_mem_perc=$(awk -v free_mem="$free_mem" -v total_mem="$total_mem" 'BEGIN { printf "%.2f", (free_mem / total_mem) * 100 }')

    echo "percent memory free is : $free_mem_perc %"
    echo

    # Compare the current memory percnetage with the provided threshold
    if [ $(echo "$free_mem_perc $1" | awk '{if ($1 < $2) print 1; else print 2}') -eq 1 ]
        then
        # Return a message indicating memory is okay
        echo "memory ok!!"
    else
        # Return a message indicating memory warning
        echo "memory warning!!"
    fi

}

disk_usage () {
# Function to check disk usage and display warning if it exceeds a threshold percentage
# Usage: disk_usage <disk_threshold_percentage>
# Arguments:
#   - disk_threshold_percentage: The threshold percentage for disk usage (0-100)
# Returns:
#   - "Disk ok!!" if disk usage is below the threshold
#   - "Disk warning!!" if disk usage is above the threshold

    # Check if exactly one argument is provided
    if [ "$#" -ne "1" ]
        then
        # Print a message and return an error code
        echo "Enter the disk usage threshold percentage between 0 to 100"
        return $RETURN_BAD
    fi

    # Get the current disk usage usage percentage
    disk_usage=$(df | grep -E "/dev/[hs]d[a-z]" | sed "s/%/ /" | awk '{ if ($5 > max || NR == 1) max = $5 } END { print max }')

    echo "Disk usage: $disk_usage"
    echo

    # Compare the current disk usage with the provided threshold
    if [ $(echo "$disk_usage $1" | awk '{if ($1 < $2) print 1; else print 2}') -eq 1 ]
        then
        # Return a message indicating disk is okay
        echo "Disk ok!!"
    else
        # Return a message indicating disk warning
        echo "Disk warning!!"
    fi

}

send_report () {
# Function to send a system status report via email
# Usage: send_report <email_address>
# Arguments:
#   - email_address: The email address to send the report to
    
    # Capture the output of check_all function and assign it to the body variable
    body=$(check_all)

    echo $body

    # Send email with the body content
    echo "$body" | mail -s "System Status Report" "$1"

}

check_all(){
# Function to check CPU utilization, free memory, and disk usage
# Usage: check_all  

    echo "##########################################"
    echo
    echo "Testing CPU utilization, free memory, disk usage status of the system on $(date)"
    echo
    echo "##########################################"
    echo
    
    cpu_utilization 80
    
    echo
    echo "##########################################"
    echo

    mem_free 95

    echo
    echo "##########################################"
    echo

    disk_usage 80
    
    echo
    echo "##########################################"
    echo

}

send_report "park3730@mylaurier.ca"
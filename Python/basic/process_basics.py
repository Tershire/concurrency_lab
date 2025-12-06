# process_basics.py

# Tershire

"""
first written:
    2025 DEC 06 (SAT)

references:
    Minchul Kang - <Self-learning CS> (Inflearn lecture)
"""

import os
import multiprocessing


# PCB(process control block)
# PID(PCB ID)

def child_f_A():
    print(f"[child_f_A] child PID: {os.getpid()}")
    print(f"[child_f_A] parent PID: {os.getppid()}")

def child_f_B():
    print(f"[child_f_B] child PID: {os.getpid()}")
    print(f"[child_f_B] parent PID: {os.getppid()}")

if __name__ == "__main__":
    print(f"main(parent) PID: {os.getpid()}")
    
    # initiate child processes
    child1 = multiprocessing.Process(target=child_f_A).start()
    child2 = multiprocessing.Process(target=child_f_A).start()
    child3 = multiprocessing.Process(target=child_f_B).start()


"""
ex. output:
main(parent) PID: 27064
[child_f_A] child PID: 11080
[child_f_A] parent PID: 27064
[child_f_A] child PID: 5624
[child_f_A] parent PID: 27064
[child_f_B] child PID: 20048
[child_f_B] parent PID: 27064
"""

# thread_basics.py

# Tershire

"""
first written:
    2025 DEC 06 (SAT)

references:
    Minchul Kang - <Self-learning CS> (Inflearn lecture)
"""

import os
import threading


# PCB(process control block)
# PID(PCB ID)

def f_A():
    print(f"[f_A] thread ID: {threading.get_native_id()}")
    print(f"[f_A] PID: {os.getpid()}")

def f_B():
    print(f"[f_B] thread ID: {threading.get_native_id()}")
    print(f"[f_B] PID: {os.getpid()}")

if __name__ == "__main__":
    print(f"main process PID: {os.getpid()}")
    
    # initiate threads
    thread1 = threading.Thread(target=f_A).start()
    thread2 = threading.Thread(target=f_A).start()
    thread3 = threading.Thread(target=f_B).start()


"""
ex. output:
main process PID: 19972
[f_A] thread ID: 7848
[f_A] PID: 19972
[f_A] thread ID: 24140
[f_B] thread ID: 27372
[f_B] PID: 19972
[f_A] PID: 19972
"""

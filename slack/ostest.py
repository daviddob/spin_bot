import os
import subprocess
if __name__ == "__main__":
    os.system('ls /dev/tty.* > bt.txt')
    with open('bt.txt') as txt:
        for line in txt:
            pass
            last = line
        bluetooth = line[:-1]
    os.system('rm bt.txt')

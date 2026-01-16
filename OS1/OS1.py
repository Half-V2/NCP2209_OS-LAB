import os
import sys

def main():
    try:
        pid = os.fork()
    except OSError as e:
        print(f"fork failed: {e}")
        sys.exit(1)

    if pid < 0:
        print("fork failed")
        sys.exit(1)
    elif pid == 0:
        # Child process
            os.execlp("whoami", "whoami")
            sys.exit(0)
    else:
        # Parent process
        print(f"Process ID is: {os.getpid()}")
        try:
            os.wait()
        except OSError as e:
            print(f"wait failed: {e}")
            sys.exit(1)
        sys.exit(0)

if __name__ == "__main__":
    main()

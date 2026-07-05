import serial
import time
import subprocess

PORT = 'COM3'
BAUD_RATE = 9600
PROJECT_DIR = 'c:\\Users\\Administrator\\Documents\\UAS PENGENDALIAN MOTOR\\ldr_reader'
PIO_PATH = 'C:\\Users\\Administrator\\.platformio\\penv\\Scripts\\pio.exe'

def upload_sketch():
    print("Uploading sketch...")
    try:
        subprocess.run([PIO_PATH, 'run', '-d', PROJECT_DIR, '--target', 'upload', '--upload-port', PORT], check=True)
        print("Upload complete.")
    except subprocess.CalledProcessError as e:
        print(f"Upload failed: {e}")
        exit(1)

def read_serial_data(num_batches=3, lines_per_batch=10, interval=3):
    print(f"Reading serial data from {PORT}...")
    try:
        ser = serial.Serial(PORT, BAUD_RATE, timeout=1)
        time.sleep(2)  # Give Arduino time to reset
        for batch in range(num_batches):
            print(f"\n--- Batch {batch + 1} ---")
            for _ in range(lines_per_batch):
                line = ser.readline().decode('utf-8').strip()
                if line:
                    print(line)
            time.sleep(interval)
        ser.close()
        print("Serial reading complete.")
    except serial.SerialException as e:
        print(f"Serial port error: {e}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    upload_sketch()
    read_serial_data()
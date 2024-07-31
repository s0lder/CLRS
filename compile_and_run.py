import os
import sys
import subprocess

def compile_and_run(directory, source_file="main.cpp"):
    # Validate directory path
    if not os.path.isdir(directory):
        print(f"Error: Directory {directory} does not exist.")
        return

    # Validate source file path
    source_path = os.path.join(directory, source_file)
    if not os.path.isfile(source_path):
        print(f"Error: File {source_file} does not exist in {directory}.")
        return

    # Extract the base name of the source file without extension
    base_name = os.path.splitext(source_file)[0]

    # Define the build directory relative to the script location
    script_dir = os.path.dirname(os.path.realpath(__file__))
    build_dir = os.path.join(script_dir, "build")
    build_subdir = os.path.join(build_dir, f"{os.path.basename(directory)}_build")
    exe_file = os.path.join(build_subdir, f"{base_name}.exe")

    # Save the current working directory
    original_directory = os.getcwd()

    try:
        # Create build directory if it doesn't exist
        if not os.path.exists(build_dir):
            os.makedirs(build_dir)

        # Create the specific build subdirectory if it doesn't exist
        if not os.path.exists(build_subdir):
            os.makedirs(build_subdir)

        # Compile the source file
        compile_command = ["g++", "-o", exe_file, source_path]
        result = subprocess.run(compile_command, capture_output=True)

        # Check if compilation was successful
        if result.returncode == 0:
            # Run the compiled program
            run_command = [exe_file]
            subprocess.run(run_command)
        else:
            print("Compilation failed.")
            print(result.stderr.decode())

    finally:
        # Change back to the original directory
        os.chdir(original_directory)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python compile_and_run.py <directory> [source_file]")
        sys.exit(1)

    directory = sys.argv[1]
    source_file = sys.argv[2] if len(sys.argv) > 2 else "main.cpp"

    compile_and_run(directory, source_file)

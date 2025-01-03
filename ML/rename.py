import os

def rename_files_in_folder(folder_path, prefix):
    """
    Rename all files in the folder to a specific format: prefix_i.

    Args:
        folder_path (str): Path to the folder containing files to rename.
        prefix (str): Prefix for the new file names (e.g., "test").
    """
    # Get a list of all files in the folder
    files = os.listdir(folder_path)

    # Iterate through each file and rename it
    for i, file_name in enumerate(files):
        # Build the new file name
        new_name = f"{prefix}_{i}"

        # Preserve the original file extension
        file_extension = os.path.splitext(file_name)[1]
        new_name += file_extension

        # Full path to old and new file
        old_file_path = os.path.join(folder_path, file_name)
        new_file_path = os.path.join(folder_path, new_name)

        # Rename the file
        os.rename(old_file_path, new_file_path)

        print(f"Renamed: {file_name} -> {new_name}")

# Example usage
folder_path = "screenshots2"  # Replace with the path to your folder
prefix = "Sylhet_versity_gate_V_"
rename_files_in_folder(folder_path, prefix)

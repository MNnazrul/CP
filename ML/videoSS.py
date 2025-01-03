import cv2
import os

# Path to the video file
video_path = '20250103_112946.mp4'

# Output directory for screenshots
output_dir = 'screenshots2'

# Create the output directory if it doesn't exist
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

# Open the video file
video = cv2.VideoCapture(video_path)

# Get the video's frame rate (frames per second)
fps = video.get(cv2.CAP_PROP_FPS)

# Get the total number of frames in the video
total_frames = int(video.get(cv2.CAP_PROP_FRAME_COUNT))

# Total time of the video in seconds
duration = total_frames / fps

# Target number of frames to capture (5 minutes = 300 screenshots)
num_screenshots = int(duration)  # Capture one screenshot per second

# Capture frames at equal intervals
interval = duration / num_screenshots

for i in range(num_screenshots):
    # Calculate the frame number to capture
    frame_time = interval * i
    frame_number = int(frame_time * fps)

    # Set the video capture to the desired frame
    video.set(cv2.CAP_PROP_POS_FRAMES, frame_number)

    # Read the frame
    ret, frame = video.read()

    if ret:
        # Save the frame as an image file
        screenshot_path = os.path.join(output_dir, f'screenshot_{i + 1:03d}.png')
        cv2.imwrite(screenshot_path, frame)

# Release the video capture object
video.release()

print(f"Captured {num_screenshots} screenshots.")

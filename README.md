# 🧵 Video Frame Stitcher

This project extracts frames from a video at regular intervals and stitches them together using OpenCV's stitching module. It's designed to create panoramas or scanned-like images from sequences in a video.

❗The algorithm performs poorly in scenarios with moving objects, shifting perspectives, or significant camera rotation, as these conditions disrupt the consistent alignment required for effective stitching.❗

## 📸 Features

- Extracts every `n`-th frame from a video
- Saves the frames into a directory
- Automatically stitches the extracted frames
- Outputs a high-resolution stitched image
- Uses OpenCV’s built-in `Stitcher` in `SCANS` mode (suitable for documents or linear motion)

## 🛠 Requirements

- Python 3.6+
- OpenCV (`opencv-python`)
- Matplotlib

Install the dependencies:

```bash
pip install opencv-python matplotlib
```
# 📖 Tutorial

This tutorial demonstrates the basics of image stitching. While OpenCV’s `Stitcher` class essentially performs the same process under the hood—with many more optimizations—it does so more efficiently and effectively.

# Base image with Python and build tools
FROM python:3.10-slim

# Install build tools
RUN apt-get update && apt-get install -y \
    cmake g++ pybind11-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set workdir
WORKDIR /app

# Copy all code
COPY . .

# Install Python dependencies
RUN pip install --no-cache-dir -r requirements.txt

# Build the shared library
RUN cmake -S . -B build && cmake --build build

# Expose app port
EXPOSE $PORT

# Start FastAPI
CMD uvicorn main:app --host 0.0.0.0 --port $PORT
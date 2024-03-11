# Cinder Multimedia Project

This repository contains the source code and Docker configurations for a simple GUI application using X11 forwarding with the Cinder library. This project is part of a multimodal discipline in a computer science course.

## Prerequisites

- Docker installed on your machine.
- An active X server on your host machine (required for GUI application display).

## Building and Running the Docker Image

```bash
docker compose up --build
```

This will build the Docker image and run the container with X11 forwarding, displaying the GUI application developed with the Cinder library.

## Customize for Your Cinder Application

1. **Dockerfile**: Modify the `Dockerfile` to include the necessary dependencies for your specific Cinder application.

2. **docker-compose.yml**: Update the `command` in the `docker-compose.yml` file to run your actual Cinder GUI application.

3. **Build and Run**: Use the provided command (`docker compose up --build`) to build and run your Docker container.

## Important Notes

- Ensure that your X server on the host machine is properly configured to allow connections from Docker containers.
- Be cautious about using `xhost +` for X server access, as it can have security implications. Consider more secure access control methods.

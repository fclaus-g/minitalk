# minitalk - 42 Project

## Introduction

**minitalk** is a project at 42 that involves creating a simple messaging system using Unix signals for inter-process communication. The goal is to develop a basic chat application where a client can send messages to a server using signals, demonstrating your understanding of signal handling, process control, and inter-process communication.

## Project Overview

The project includes:

- **Server**: A process that listens for incoming messages from clients and handles them appropriately.
- **Client**: A process that sends messages to the server using Unix signals.
- **Signals**: Use `SIGUSR1` and `SIGUSR2` signals to encode and decode messages.

## Features

- **Message Sending**: The client sends messages to the server using signals.
- **Signal Handling**: The server processes the signals to reconstruct and display the messages.
- **Encoding/Decoding**: Messages are encoded as sequences of signals and decoded by the server.

## Usage

1. Clone the repository and navigate to the project directory:

   ```bash
   git clone https://github.com/fclaus-g/minitalk.git
   cd minitalk
   ```

2. Compile the project using:

   ```bash
   make
   ```

3. Start the server in one terminal:

   ```bash
   ./server
   ```

   The server will display its process ID (PID), which is needed by the client.

4. Send a message from the client in another terminal:

   ```bash
   ./client [server_pid] "Your message here"
   ```

   Replace `[server_pid]` with the PID of the server process and `"Your message here"` with the message you want to send.


## Example

1. Start the server:

   ```bash
   ./server
   ```

2. Note the server PID (e.g., `12345`).

3. Send a message from the client:

   ```bash
   ./client 12345 "Hello, server!"
   ```

   The server will display the message `"Hello, server!"`.

## License

This project is part of the 42 curriculum and is intended for educational purposes. Feel free to use it for learning, but be mindful of 42’s collaboration policies.

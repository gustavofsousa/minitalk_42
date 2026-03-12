<h1 align="center">minitalk</h1>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/42-School-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-complete-brightgreen.svg" alt="Status">
</p>

<p align="center">
  Inter-process communication using only UNIX signals — encoding data at the bit level.
</p>

<p align="center">
  <a href="README.pt-br.md">🇧🇷 Leia em Português</a>
</p>

---

## Why this project matters

> "This project taught me how processes communicate at the OS level — using signals, PIDs, and bitwise operations. I understood what IPC (Inter-Process Communication) really means, a concept present in every operating system, distributed system, and even container orchestration platform."

Signal-based IPC is foundational knowledge for understanding how processes coordinate in Unix-like systems — the backbone of every Linux server in production today.

---

## How it works

Two separate programs communicate **exclusively through UNIX signals** (`SIGUSR1` and `SIGUSR2`):

```
CLIENT                          SERVER
  |                               |
  | --- SIGUSR1 (bit = 1) ------> |
  | --- SIGUSR2 (bit = 0) ------> |
  | --- SIGUSR1 (bit = 1) ------> |
  |        ... 8 signals ...      |
  |                               | assembles byte → prints character
  | <-- SIGUSR1 (acknowledgment)  |
```

- **`SIGUSR1`** represents bit `1`
- **`SIGUSR2`** represents bit `0`
- Each character is transmitted as **8 signals** (one per bit)
- The server reconstructs bytes using bit-shift operations
- On null character received, the server sends back an **acknowledgment** signal

### Bonus
The bonus version adds **acknowledgment signals** from server to client after each character, ensuring reliable delivery.

---

## A standout technical detail

The signal handler uses `sigaction` with `SA_SIGINFO` instead of the simpler `signal()` function. This allows the server to read `info->si_pid` — the PID of the sending process — directly from the signal metadata, without any shared global state or additional communication channel. A clean, professional approach to handling signals in C.

---

## Getting Started

```bash
git clone https://github.com/gustavofsousa/minitalk_42.git
cd minitalk_42
make
```

### Running

**Start the server first:**
```bash
./server
# Output: PID: 12345
```

**Send a message from the client:**
```bash
./client 12345 "Hello, World!"
```

### Bonus version
```bash
make bonus
./server_bonus
./client_bonus <PID> "Your message here"
```

---

## Project structure

```
minitalk_42/
├── server.c          # Signal receiver — assembles and prints messages
├── client.c          # Signal sender — encodes and transmits strings
├── server_bonus.c    # Server with acknowledgment
├── client_bonus.c    # Client with acknowledgment
├── libft/            # Personal C library (dependency)
└── Makefile
```

---

## Skills demonstrated

- UNIX signals (`SIGUSR1`, `SIGUSR2`, `sigaction`, `kill`, `pause`)
- Bitwise operations for encoding/decoding data
- Inter-Process Communication (IPC)
- Process identification (PID)
- Reliable communication protocols design

---

## License

This project was developed as part of the [42 School](https://42.fr) curriculum.

---

<p align="center">Made with ☕ at 42 Rio de Janeiro</p>

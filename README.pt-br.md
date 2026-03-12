<h1 align="center">minitalk</h1>

<p align="center">
  <img src="https://img.shields.io/badge/linguagem-C-blue.svg" alt="Linguagem">
  <img src="https://img.shields.io/badge/42-School-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-completo-brightgreen.svg" alt="Status">
</p>

<p align="center">
  Comunicação entre processos usando apenas sinais UNIX — codificando dados no nível de bits.
</p>

<p align="center">
  <a href="README.md">🇺🇸 Read in English</a>
</p>

---

## Por que este projeto importa

> "Este projeto me ensinou como processos se comunicam no nível do sistema operacional — usando sinais, PIDs e operações bitwise. Entendi o que IPC (Comunicação Entre Processos) realmente significa, um conceito presente em todo sistema operacional, sistema distribuído e até plataforma de orquestração de contêineres."

IPC baseado em sinais é conhecimento fundamental para entender como processos se coordenam em sistemas Unix-like — a espinha dorsal de todo servidor Linux em produção hoje.

---

## Como funciona

Dois programas separados se comunicam **exclusivamente através de sinais UNIX** (`SIGUSR1` e `SIGUSR2`):

```
CLIENTE                         SERVIDOR
  |                               |
  | --- SIGUSR1 (bit = 1) ------> |
  | --- SIGUSR2 (bit = 0) ------> |
  | --- SIGUSR1 (bit = 1) ------> |
  |        ... 8 sinais ...       |
  |                               | monta byte → imprime caractere
  | <-- SIGUSR1 (confirmação)     |
```

- **`SIGUSR1`** representa o bit `1`
- **`SIGUSR2`** representa o bit `0`
- Cada caractere é transmitido como **8 sinais** (um por bit)
- O servidor reconstrói bytes com operações de bit-shift
- Ao receber o caractere nulo, o servidor envia um sinal de **confirmação**

### Bônus
A versão bônus adiciona **sinais de confirmação** do servidor para o cliente após cada caractere, garantindo entrega confiável.

---

## Um detalhe técnico que se destaca

O handler de sinal usa `sigaction` com `SA_SIGINFO` em vez da função `signal()` mais simples. Isso permite que o servidor leia `info->si_pid` — o PID do processo que enviou — diretamente dos metadados do sinal, sem qualquer estado global compartilhado ou canal de comunicação adicional. Uma abordagem limpa e profissional para tratar sinais em C.

---

## Como usar

```bash
git clone https://github.com/gustavofsousa/minitalk_42.git
cd minitalk_42
make
```

### Executando

**Inicie o servidor primeiro:**
```bash
./server
# Saída: PID: 12345
```

**Envie uma mensagem pelo cliente:**
```bash
./client 12345 "Olá, Mundo!"
```

### Versão bônus
```bash
make bonus
./server_bonus
./client_bonus <PID> "Sua mensagem aqui"
```

---

## Estrutura do projeto

```
minitalk_42/
├── server.c          # Receptor de sinais — monta e imprime mensagens
├── client.c          # Emissor de sinais — codifica e transmite strings
├── server_bonus.c    # Servidor com confirmação
├── client_bonus.c    # Cliente com confirmação
├── libft/            # Biblioteca C pessoal (dependência)
└── Makefile
```

---

## Habilidades demonstradas

- Sinais UNIX (`SIGUSR1`, `SIGUSR2`, `sigaction`, `kill`, `pause`)
- Operações bitwise para codificação/decodificação de dados
- Comunicação Entre Processos (IPC)
- Identificação de processos (PID)
- Design de protocolos de comunicação confiável

---

## Licença

Este projeto foi desenvolvido como parte do currículo da [42 School](https://42.fr).

---

<p align="center">Feito com ☕ na 42 Rio de Janeiro</p>

# 🧵 POSIX Threads and Functions

---

## 📚 Introduction

This project involves learning the basics of threading in a process using POSIX threads (pthreads). The focus is on creating and managing threads, using mutexes to handle shared resources, and ensuring thread synchronization to avoid data races.

## ⚙️ Common Instructions

- **Language**: The project must be written in C.
- **Coding Standards**: Adhere to the project's coding norms. Any deviation, including norm errors, results in a zero score.
- **Error Handling**: Functions must not cause unexpected quits (e.g., segmentation faults, bus errors, double frees).
- **Memory Management**: All heap-allocated memory must be properly freed to avoid memory leaks.
- **Makefile Requirements**: Include rules for `all`, `clean`, `fclean`, `re`, and optionally `bonus`.
- **Library Usage**: If using a custom library (libft), include it in a separate directory with its own Makefile.
- **Testing**: Creating test programs is encouraged for easier validation of your work and for peer evaluations.
- **Git Repository**: Submit your work to the assigned git repository. Only the work in the repository will be graded.

## 📝 Overview

In this project, you will simulate the classic dining philosophers problem using threads and mutexes:

- Philosophers sit at a round table with a bowl of spaghetti.
- They alternate between eating, thinking, and sleeping.
- Each philosopher needs two forks to eat, one from their left and one from their right.
- The simulation ends when a philosopher dies of starvation.

## 🌍 Global Rules

- **Arguments**:
  - `number_of_philosophers`: Number of philosophers and forks.
  - `time_to_die`: Time in milliseconds a philosopher can go without eating before dying.
  - `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
  - `time_to_sleep`: Time in milliseconds a philosopher spends sleeping.
  - `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation stops after each philosopher has eaten this many times.

- **Philosopher States**: Each state change (taking a fork, eating, sleeping, thinking, dying) must be logged with a timestamp and philosopher number.
- **Data Races**: Ensure no data races in your program.

## 🎯 Mandatory Part

### Program Details

- **Program Name**: `philo`
- **Files**: `Makefile`, `*.h`, `*.c` in the `philo/` directory
- **Makefile Rules**: `NAME`, `all`, `clean`, `fclean`, `re`
- **Arguments**: As specified in the global rules
- **Allowed Functions**: 
  - `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`
  - POSIX thread functions: `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

### Implementation Details

- Each philosopher is represented by a thread.
- Forks are protected by mutexes to prevent duplication and ensure proper synchronization.
- Log state changes as specified to maintain clarity and order.

## 🎉 Bonus Part

### Program Details

- **Program Name**: `philo_bonus`
- **Files**: `Makefile`, `*.h`, `*.c` in the `philo_bonus/` directory
- **Makefile Rules**: Same as the mandatory part
- **Arguments**: Same as the mandatory part
- **Allowed Functions**:
  - `memset`, `printf`, `malloc`, `free`, `write`, `fork`, `kill`, `exit`, `pthread_create`, `pthread_detach`, `pthread_join`, `usleep`, `gettimeofday`, `waitpid`
  - Semaphore functions: `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`

### Implementation Details

- Forks are managed using semaphores instead of mutexes.
- Each philosopher is represented by a process.
- The main process should manage the philosopher processes but not be a philosopher itself.

## 📤 Submission and Peer-Evaluation

- Submit your work in your Git repository.
- Ensure correct file names and directory structure (`philo/` for mandatory and `philo_bonus/` for bonus parts).
- Peer evaluations will be conducted based on the submitted repository content.

# 🎨 Understanding Threads and Mutexes: A Visual Journey

---

## 🌐 Threads: The Superheroes of Concurrency

Imagine a city (your program) with multiple superheroes (threads) working simultaneously to protect it. Each superhero has a unique ability (task) but they all share the same headquarters (memory space).

### Key Concepts of Threads

| Concept              | Description                                                                 |
|----------------------|-----------------------------------------------------------------------------|
| 🏙️ **Concurrent Execution** | Superheroes can fight different villains (tasks) at the same time.          |
| 🔄 **Shared Resources**     | They all use the same gadgets and tools (data space) from their headquarters.|
| 🦸 **Independent Tasks**    | Each superhero handles different emergencies, ensuring the city remains safe and functional. |

### Creating Threads

In the world of C programming, we summon our superheroes using the POSIX thread library (`pthread`). Here's how we call them into action:

| Function            | Description                                        |
|---------------------|----------------------------------------------------|
| `pthread_create()`  | Summons a new superhero.                           |
| `pthread_join()`    | Waits for a superhero to finish their mission.     |
| `pthread_detach()`  | Allows a superhero to continue their mission independently. |
| `pthread_exit()`    | Retires the calling superhero.                     |

## 🔒 Mutexes: The Guardians of Order

To maintain order in the city, we have guardians (mutexes) that control access to critical resources. These guardians ensure that only one superhero can use a particular gadget (shared resource) at a time, preventing chaos (data races).

### Key Concepts of Mutexes

| Concept              | Description                                                                         |
|----------------------|-------------------------------------------------------------------------------------|
| 🚫 **Mutual Exclusion**    | Only one superhero can use a specific gadget at any given time.                     |
| 🛡️ **Preventing Data Races**| Guardians ensure that superheroes don’t clash when accessing shared resources.      |
| 🔗 **Thread Synchronization**| Guardians coordinate superheroes' actions, maintaining harmony.                   |

### Using Mutexes

In our programming city, we deploy these guardians using the POSIX thread library (`pthread`). Here’s how we manage them:

| Function                  | Description                                                 |
|---------------------------|-------------------------------------------------------------|
| `pthread_mutex_init()`    | Initializes a guardian.                                     |
| `pthread_mutex_lock()`    | Deploys a guardian to protect a resource.                   |
| `pthread_mutex_unlock()`  | Releases a guardian, allowing other superheroes to access the resource. |
| `pthread_mutex_destroy()` | Retires a guardian.                                         |

## 🍝 Dining Philosophers: A Visual Tale

Imagine a group of philosophers (threads) dining at a round table. They alternately think, eat, and sleep. However, they must share forks (resources) to eat. Let’s ensure no philosopher starves by using our superheroes and guardians effectively.

### Problem Description

| Scenario                          | Details                                                 |
|-----------------------------------|---------------------------------------------------------|
| Philosophers                      | Sit around a table with a bowl of spaghetti in the middle. |
| Actions                           | Think, eat, and sleep in turns.                         |
| Forks                             | Each philosopher needs two forks to eat.                |
| Simulation End                    | Ends when a philosopher starves.                        |

### Implementation with Threads and Mutexes

| Element               | Description                                                  |
|-----------------------|--------------------------------------------------------------|
| **Superheroes (Threads)** | Each philosopher is a superhero handling their eating, thinking, and sleeping tasks. |
| **Guardians (Mutexes)**   | Forks are guarded by mutexes to prevent clashes.          |


# 🎨 Understanding Semaphores and Processes: A Visual Journey

---

## 🌐 Semaphores: The Gatekeepers of Resources

Imagine a busy theme park (your program) with rides (resources) managed by gatekeepers (semaphores). Each gatekeeper ensures that only a certain number of visitors (processes) can use a ride at the same time.

### Key Concepts of Semaphores

| Concept                   | Description                                                                                     |
|---------------------------|-------------------------------------------------------------------------------------------------|
| 🚦 **Resource Control**       | Gatekeepers control access to resources, allowing only a set number of visitors at a time.       |
| 🚧 **Preventing Overcrowding**| Semaphores ensure that resources are not overused, preventing conflicts and ensuring smooth operation. |
| ⏳ **Synchronization**        | Semaphores coordinate the access to resources, maintaining order and efficiency.                   |

### Using Semaphores

In the world of C programming, we manage these gatekeepers using POSIX semaphore functions. Here’s how we deploy them:

| Function             | Description                                                       |
|----------------------|-------------------------------------------------------------------|
| `sem_open()`         | Initializes or opens a semaphore.                                 |
| `sem_wait()`         | Decreases (locks) the semaphore, waiting if necessary.            |
| `sem_post()`         | Increases (unlocks) the semaphore, signaling waiting processes.   |
| `sem_close()`        | Closes the semaphore.                                             |
| `sem_unlink()`       | Removes a named semaphore.                                        |

## 🔄 Processes: The Multiple Workers

In our theme park analogy, each visitor is a separate process, an independent worker executing concurrently. Unlike threads, processes have their own memory space but can still communicate and synchronize through semaphores.

### Key Concepts of Processes

| Concept                    | Description                                                                                       |
|----------------------------|---------------------------------------------------------------------------------------------------|
| 🧍‍♂️ **Independent Execution**  | Each worker (process) operates independently with its own memory space.                            |
| 🌐 **Separate Memory Space**    | Processes do not share memory directly, providing isolation and stability.                         |
| 📢 **Interprocess Communication** | Processes communicate and synchronize through mechanisms like semaphores.                          |

### Creating Processes

In C, we manage these workers using POSIX process functions. Here’s how we deploy them:

| Function            | Description                                               |
|---------------------|-----------------------------------------------------------|
| `fork()`            | Creates a new process.                                    |
| `waitpid()`         | Waits for a specific child process to change state.       |
| `kill()`            | Sends a signal to a process.                              |
| `exit()`            | Terminates the calling process.                           |

## 🍝 Dining Philosophers: The Bonus Tale

In the bonus version of the dining philosophers problem, we manage philosophers (processes) and forks (resources) using semaphores.

### Problem Description

| Scenario                          | Details                                                 |
|-----------------------------------|---------------------------------------------------------|
| Philosophers                      | Sit around a table with a bowl of spaghetti in the middle. |
| Actions                           | Think, eat, and sleep in turns.                         |
| Forks                             | Managed by semaphores to control access.                |
| Simulation End                    | Ends when a philosopher starves.                        |

### Implementation with Processes and Semaphores

| Element                    | Description                                                                 |
|----------------------------|-----------------------------------------------------------------------------|
| **Workers (Processes)**    | Each philosopher is a separate worker handling their eating, thinking, and sleeping tasks. |
| **Gatekeepers (Semaphores)**| Forks are managed by semaphores to ensure controlled access.                |

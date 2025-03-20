# 42 Philosopher Project 🤔🍴😴

## 🏛️ About the Project

The **Philosopher** project is part of the curriculum at **42** and is based on the **Dining Philosophers Problem**. It introduces key concepts of **multithreading, process synchronization, and concurrency control**. The main porpouse of the project is to make us understand what is envolved in the multi-threads application and to learn how the concept of race conditions, deadlocks, and resource sharing.

## 📜 The Problem Statement

A group of philosophers sits around a table with a fork for each philosopher. All of them have the same routine, they think, eat and sleep, and they cannot to them at the same time. To eat, a philosopher must pick up the two forks, his and the one from the philosopher on his right(in my program). The main challenge is to ensure that:

- No philosopher **starves**.
- There are no **deadlocks**.
- There are no **race conditions**.

## 🚀 Features

- **Multithreading** using `pthread`
- **Mutex synchronization** to avoid race conditions
- **Proper handling of concurrency issues**

## 🛠️ Installation and 🎮 Usage

Clone the repository:

```sh
$ git clone https://github.com/yourusername/philosopher.git
$ cd philosopher
```

Compile the project:

```sh
$ make
```

Run the program with the following arguments:

```sh
$ ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```sh
$ ./philo 5 800 200 200
```

### Parameters:
- `number_of_philosophers`: Total philosophers (and forks)
- `time_to_die`: Time (ms) before a philosopher dies if they don’t eat
- `time_to_eat`: Time (ms) taken to eat
- `time_to_sleep`: Time (ms) spent sleeping
- `[number_of_times_each_philosopher_must_eat]` (optional): If provided, simulation ends when all philosophers have eaten this many times

## 📌 Project Rules

- No **data races**.
- No **deadlocks**.
- Must use **mutexes** and **threads**.
- The program **must not crash**.
- The program should not have **memory leaks**.

## 🔍 Debugging Tips

- Use **Valgrind** to check for memory leaks:
  ```sh
  valgrind --leak-check=full ./philo 5 800 200 200
  ```
(you can also do that by using the fsanitizer=address)

## 🌟 Acknowledgments

Thanks to **42 Network** for this amazing learning experience!


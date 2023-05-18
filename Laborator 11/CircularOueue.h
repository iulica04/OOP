#pragma once

template <typename T>
class CircularQueue {
private:
	std::vector<T> buffer;
	int capacity, sizee, oldIndex;
public:
	CircularQueue(int capacity) : capacity(capacity), sizee(0), oldIndex(0) {
		buffer.resize(capacity);
	};
	void push(const T& element) {
		if (sizee == capacity) {
			oldIndex = (oldIndex + 1) % capacity;
		}
		else
			++sizee;
		buffer[(oldIndex + sizee - 1) % capacity] = element;
	}

	void pop() {
		if (empty()) {
			throw std::out_of_range("Queue is empty");
		}
		oldIndex = (oldIndex + 1) % capacity;
		--sizee;
	}

	T& front() {
		if (empty()) {
			throw std::out_of_range("Queue is empty");
		}
		return buffer[oldIndex];
	}
	T& back() {
		if (empty()) {
			throw std::out_of_range("Queue is empty");
		}
		return buffer[oldIndex + sizee - 1];
	}

	int size() const {
		return sizee;
	}
	bool empty() const {
		return sizee == 0;
	}
};
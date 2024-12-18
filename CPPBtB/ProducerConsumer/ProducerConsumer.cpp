#include <queue>
#include <thread>
#include <iostream>
#include <mutex>

int counter = 0;
bool done = false;

std::queue<int> goods;
std::mutex mtx;  //mutex lock

void producer() {
    std::cout << "Starting producer..." << std::endl;

    for (int i = 0; i < 500; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        goods.push(i);
        counter++;
    }

    std::lock_guard<std::mutex> lock(mtx);
    done = true;

    std::cout << "Finished producer..." << std::endl;
}

void consumer() {
    std::cout << "Starting consumer..." << std::endl;

    while (true) {
        {
            std::lock_guard<std::mutex> lock(mtx);

            if (done && goods.empty()) {
                break;
            }

            while (!goods.empty()) {
                goods.pop();
                counter--;
            }
        }
    }

    std::lock_guard<std::mutex> lock(mtx);

    std::cout << "Finished consumer..." << std::endl;
}

int main() {
    counter = 0;
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << std::endl;
}

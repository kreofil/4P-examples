// g++ -pthread ex02.cpp
#include <cstdlib>
#include <iostream>
#include <memory>
#include <unistd.h>
#include <pthread.h>
    
class Thread {
public:
    virtual ~Thread () {}
    virtual void run () = 0;
    int start () {
        return pthread_create( &_ThreadId, nullptr, Thread::thread_func, this ); 
    }
    int wait () { 
        return pthread_join( _ThreadId, NULL ); 
    }
protected:
    pthread_t _ThreadId;
    //Thread(const Thread&);
    static void* thread_func(void* d) {
        (static_cast <Thread*>(d))->run(); 
        return nullptr; 
    }
};

class TestingThread : public Thread {
public:
    TestingThread (const char* pcszText) : _pcszText( pcszText ) {}
    virtual void run () {
        for (unsigned int i = 0; i < 30; i++) {
            std::cout << _pcszText << "\n"; // << std::endl;
            sleep(1);
        }
    }
protected:
    const char* _pcszText;
};

int main (int argc, char *argv[], char *envp[]) {
    TestingThread Thread_a("abcdefghijklmnoprstuvwxyz");
    TestingThread Thread_A("ABCDEFGHIJKLMNOPRSTUVWXYZ");
    TestingThread Thread_0("012345678901234567890123456789");
    TestingThread Thread_9("987654321098765432109876543210");
    return Thread_a.start() || Thread_A.start() || Thread_0.start() || Thread_9.start()
        || Thread_a.wait()  || Thread_A.wait()  || Thread_0.wait()  || Thread_9.wait() 
             ? EXIT_FAILURE : EXIT_SUCCESS;
}

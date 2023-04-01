import java.util.concurrent.Semaphore;
import java.lang.Math;
class Monitor {
static Semaphore mutex = new Semaphore(1);
static Semaphore w = new Semaphore(1);
static int readerc = 0;
static class Reader implements Runnable {
@Override
public void run() {
while (true) {
try {
mutex.acquire();
readerc++;
if (readerc == 1) {
w.acquire();
}
mutex.release();
System.out.println(Thread.currentThread().getName() + " entered CS");
System.out.println(Thread.currentThread().getName() + " exiting CS");
mutex.acquire();
readerc--;
if (readerc == 0) {
w.release();
}
mutex.release();
} catch (InterruptedException e) {
System.out.println(e.getMessage());
}
try {
Thread.sleep((int) (Math.random() * 1250));
} catch (InterruptedException e) {
}
}
}
}
static class Writer implements Runnable {
@Override
public void run() {
while (true) {
try {
w.acquire();
System.out.println(Thread.currentThread().getName() + " entered CS");
System.out.println(Thread.currentThread().getName() + " exiting CS");
w.release();
} catch (InterruptedException e) {
System.out.println(e.getMessage());
}
try {
Thread.sleep((int) (Math.random() * 1250));
} catch (InterruptedException e) {
}
}
}
}
public static void main(String []args) throws Exception {
Reader r = new Reader();
Writer write = new Writer();
Thread t1 = new Thread(r);
t1.setName("Reader1");
Thread t2 = new Thread(r);
t2.setName("Reader2");
Thread t3 = new Thread(write);
t3.setName("Writer1");
Thread t4 = new Thread(write);
t4.setName("Writer2");
t1.start();
t2.start();
t3.start();
t4.start();
}
}

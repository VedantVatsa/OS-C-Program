import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
class Chopstick {
private boolean isAvail;
public Chopstick() {
isAvail = true;
}
public boolean getAvail() {
return isAvail;
}
public void setAvail(boolean flag) {
isAvail = flag;
}
}
class Monitor {
private Lock mutex = null;
private Condition[] cond;
private String[] state;
private int[] id;
private void output(int id) {
StringBuffer line = new StringBuffer();
for (int i = 0; i < 5; i++) {
line.append(state[i]);
}
if (line.charAt(id)=='T') {
System.out.println("Philosopher "+(id)+" is thinking");
}
if (line.charAt(id)=='H') {
System.out.println("Philosopher "+(id)+" is waiting");
}
if (line.charAt(id)=='E') {
System.out.println("Philosopher "+(id)+" is eating");
}
}
public Monitor() {
 id = new int[5];
mutex = new ReentrantLock();
state = new String[5];
cond = new Condition[5];
for (int i = 0; i < 5; i++) {
id[i] = i;
state[i] = "T";
cond[i] = mutex.newCondition();
}
}
public void setState(int id, String s) {
state[id] = s;
}
public void takeChopsticks(int id, Chopstick left, Chopstick right) {
mutex.lock();
try {
setState(id,"H");
while (!left.getAvail() || !right.getAvail())
cond[id].await();
left.setAvail(false);
right.setAvail(false);
setState(id,"E");
output(id);
} catch (InterruptedException e) {
e.printStackTrace();
} finally {
mutex.unlock();
}
}
public void putChopsticks(int id, Chopstick left, Chopstick right) {
mutex.lock();
try {
setState(id, "T");
left.setAvail(true);
right.setAvail(true);
cond[(id + 1) % 5].signalAll();
cond[(id + 4) % 5].signalAll();
output(id);
} finally {
mutex.unlock();
}
}
}
class philosopher implements Runnable {
private Monitor obj;
private Chopstick left, right;
private int id;
public philosopher(int id, Chopstick left, Chopstick right, Monitor i)
{
 public philosopher(int id, Chopstick left, Chopstick right, Monitor i)
 {
 this.obj = i;
 this.left = left;
 this.right = right;
 this.id = id;
}
private void eat() {
try {
Thread.sleep(5);
} catch (InterruptedException e) {
}
}
private void think() {
try {
Thread.sleep(5);
} catch (InterruptedException e) {
}
}
public void run() {
while (true) {
obj.takeChopsticks(id, left, right);
eat();
obj.putChopsticks(id, left, right);
think();
}
}
}
public class diningphilosopher {
private Chopstick[] s;
private philosopher[] f;
private Monitor obj;
private void init() {
s = new Chopstick[5];
f = new philosopher[5];
obj = new Monitor();
for (int i = 0; i < 5; i++)
s[i] = new Chopstick();
for (int i = 0; i < 5; i++) {
f[i] = new philosopher(i, s[i], s[(i + 4) % 5], obj);
new Thread(f[i]).start();
}
}
public diningphilosopher() {
init();
}
public static void main(String[] args) {
 for (int i = 0; i < 5; i++)
System.out.println("Philosopher " + i + " is thinking");
new diningphilosopher();
}
}

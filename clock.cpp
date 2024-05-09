#include <iostream>
#include <thread> // Para utilizar std::this_thread::sleep_for
#include <chrono> // Para utilizar std::chrono::seconds

class Time {
private:
    int h, m, s;
public:
    Time(int hours = 0, int mins = 0, int secs = 0) {
        setHours(hours);
        setMins(mins);
        setSecs(secs);
    }

    void setHours(int hours) {
        if (0 <= hours && hours < 24) {
            h = hours;
        } else {
            std::cerr << "Error: Invalid hours value!" << std::endl;
        }
    }

    void setMins(int mins) {
        if (0 <= mins && mins < 60) {
            m = mins;
        } else {
            std::cerr << "Error: Invalid minutes value!" << std::endl;
        }
    }

    void setSecs(int secs) {
        if (0 <= secs && secs < 60) {
            s = secs;
        } else {
            std::cerr << "Error: Invalid seconds value!" << std::endl;
        }
    }

    // Método para obtener la hora como una cadena de caracteres
    std::string getTimeString() const {
        return std::to_string(h) + ":" + std::to_string(m) + ":" + std::to_string(s);
    }

    // Operador de igualdad sobrecargado
    bool operator==(const Time& other) const {
        return h == other.h && m == other.m && s == other.s;
    }

    Time operator+(int secs) const {
        Time result = *this; // Creamos una copia del objeto actual
        result.s += secs;    // Añadimos los segundos a la copia
        return result;       // Devolvemos la copia modificada
    }

    bool operator<(const Time& other) const {
        return s < other.s;
    }

    bool operator>(const Time& other) const {
        return s > other.s;
    }

    // Método para incrementar los segundos y ajustar minutos y horas si es necesario
    void incrementSeconds() {
        ++s;
        if (s >= 60) {
            s = 0;
            ++m;
            if (m >= 60) {
                m = 0;
                ++h;
                if (h >= 24) {
                    h = 0;
                }
            }
        }
    }
};

class Clock {
private:
    Time time;
    Time alarm;
    int ALARM_DURATION = 5;
public:
    Clock(int hours = 0, int mins = 0, int secs = 0) : time(hours, mins, secs) {}

    void setTime(int hours, int mins, int secs) {
        time.setHours(hours);
        time.setMins(mins);
        time.setSecs(secs);
    }

    // Método para obtener la hora del reloj
    std::string getTime() const {
        return time.getTimeString();
    }

    // Método para establecer una alarma
    void setAlarm(int hours, int mins, int secs) {
        alarm.setHours(hours);
        alarm.setMins(mins);
        alarm.setSecs(secs);
    }

    // Método para verificar la alarma
    bool checkAlarm() const {
        return time > alarm && time < (alarm + ALARM_DURATION); // Usamos el operador de igualdad sobrecargado
    }

    // Método para simular el paso del tiempo
    void tick() {
        // Simulamos el paso de 1 segundo
        time.incrementSeconds();

        // Imprimir la hora en consola
        

        // Verificamos si la alarma se ha activado
        if (checkAlarm()) {
            std::cout << "\n¡Alarma!";
        } else {
            std::cout << "\rLa hora actual es: " << time.getTimeString() << std::flush;
        }

        // Esperar un segundo antes de la siguiente iteración
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};

int main() {
    int initialHours, initialMins, initialSecs;
    std::cout << "Ingrese la hora inicial (HH MM SS): ";
    std::cin >> initialHours >> initialMins >> initialSecs;

    int alarmHours, alarmMins, alarmSecs;
    std::cout << "Ingrese la hora de la alarma (HH MM SS): ";
    std::cin >> alarmHours >> alarmMins >> alarmSecs;

    Clock myClock;
    myClock.setTime(initialHours, initialMins, initialSecs);
    myClock.setAlarm(alarmHours, alarmMins, alarmSecs);

    // Simulamos el paso del tiempo hasta que se active la alarma
    while (true) {
        myClock.tick(); // Simular el paso del tiempo
    }
    return 0;
}

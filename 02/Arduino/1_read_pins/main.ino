#define ADDRESS_BUS_COUNT 16
#define DATA_BUS_COUNT 8
#define CLOCK_INTERRUPT_PIN 18
#define RWB_PIN 17

const byte DATA_BUS_PINS[DATA_BUS_COUNT] = {22, 24, 26, 28,
                                            30, 31, 32, 33};
const byte ADDRESS_BUS_PINS[ADDRESS_BUS_COUNT] = {34, 35, 36, 37, 38,
                                                  39, 40, 41, 42, 43,
                                                  44, 45, 46, 47, 48,
                                                  49};

void loop()
{
    // empty on purpose
}

void setup()
{
    for (int i = 0; i < ADDRESS_BUS_COUNT; ++i)
    {
        pinMode(ADDRESS_BUS_PINS[i], INPUT);
    }

    for (int i = 0; i < DATA_BUS_COUNT; ++i)
    {
        pinMode(DATA_BUS_PINS[i], INPUT);
    }

    pinMode(CLOCK_INTERRUPT_PIN, INPUT);
    pinMode(RWB_PIN, INPUT);

    attachInterrupt(digitalPinToInterrupt(CLOCK_INTERRUPT_PIN), onClock, RISING);

    Serial.begin(57600);
}

void onClock()
{
    unsigned int address = 0;
    for (int i = ADDRESS_BUS_COUNT - 1; i >= 0; --i)
    {
        int bit = digitalRead(ADDRESS_BUS_PINS[i]) ? 1 : 0;
        address = (address << 1) + bit;
    }

    Serial.print("    ");

    unsigned int data = 0;
    for (int i = DATA_BUS_COUNT - 1; i >= 0; --i)
    {
        int bit = digitalRead(DATA_BUS_PINS[i]) ? 1 : 0;
        data = (data << 1) + bit;
    }

    char rwb = digitalRead(RWB_PIN) ? 'R' : 'W';

    char output[64];
    sprintf(output, "%04x    %02x    %c", address, data, rwb);

    Serial.println(output);
}

#define MW_BASERATE_PRIORITY           250
#define MW_BASERATE_PERIOD             0.004
#define MW_NUMBER_SUBRATES             0
#define MW_NUMBER_APERIODIC_TASKS      0
#define MW_IS_CONCURRENT               0

extern void exitTask(void *arg);
extern void terminateTask(void* arg);
extern void baseRateTask(void *arg);
extern void subrateTask(void *arg);
extern pthread_t schedulerThread;
extern pthread_t terminateThread;
extern pthread_t baseRateThread;
extern pthread_t subRateThread[];
extern sem_t termSem;
extern sem_t stopSem;
extern sem_t baserateTaskSem;
extern sem_t subrateTaskSem[];
extern int taskId[];
extern int subratePriority[];

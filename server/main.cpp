#include "prepare.h"

int main(){

#ifdef _LOG_TEST
	LOG(LEV_INFO, "log print test\n");
	oal_int16 i = 666;
	LOG(LEV_INFO, "hello server！(%d)\n", i);
#endif

#ifdef _LOCKER_TEST
	LOG(LEV_INFO, "locker test\n");
	
	LOG(LEV_INFO, "create semaphore\n");
	oal_semaphore semu(0);
	LOG(LEV_INFO, "wait semaphore\n");
	semu.wait();
	LOG(LEV_INFO, "post semaphore\n");
	semu.post();
	
	LOG(LEV_INFO, "create mutex\n");
    oal_mutex_lock mutex_test;
	LOG(LEV_INFO, "lock mutex\n");
	mutex_test.lock();
	LOG(LEV_INFO, "unlock mutex\n");
	mutex_test.unlock();
	
	LOG(LEV_INFO, "create condition\n");
	oal_condition con_test;
	LOG(LEV_INFO, "signal condition\n");
	con_test.signal();
	LOG(LEV_INFO, "wait condition\n");
	con_test.wait();
	LOG(LEV_INFO, "signal condition\n");
	con_test.signal();
#endif

#ifdef _THREAD_TEST
	pthread_t test_thread_id;
	oal_condition cond_test_thread;
	
	pthread_create(&test_thread_id, NULL, test_thread, (oal_void*)&cond_test_thread);
	
	oal_sleep_s(1);
	LOG(LEV_INFO, "signal condition\n");
	cond_test_thread.signal();
	//oal_sleep_s(1);
	oal_void* pthread_ret;
	oal_int32 pjret = pthread_join(test_thread_id, &pthread_ret);
	
	LOG(LEV_INFO, "[%d],thread return[%d]\n", pjret, (oal_int32*)pthread_ret);
#endif

#ifdef _THREADPOOL_TEST
    threadpool_test thpt;
	threadpool<threadpool_test> m_threadpool;
	oal_bool ret = m_threadpool.append(&thpt);
	LOG(LEV_INFO, "append ret(%d)\n", ret);
    ret = m_threadpool.append(&thpt);
    LOG(LEV_INFO, "append ret(%d)\n", ret);
    ret = m_threadpool.append(&thpt);
    LOG(LEV_INFO, "append ret(%d)\n", ret);

    oal_sleep_s(3);
#endif
	return 0;
}
